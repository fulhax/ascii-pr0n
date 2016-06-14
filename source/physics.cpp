#include "physics.h"
#include "fire.h"
#include "palette.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

struct ball
{
    float x, y, r;
    float vx, vy;
};
void updatePhysics(ball& b, unsigned int bufferw, unsigned int bufferh)
{
    b.x += b.vx * 0.1;
    b.y += b.vy * 0.1;

    if(b.x > bufferw)
    {
        b.vx *= -1;
        b.x = bufferw - 1;
    }

    if(b.y > bufferh)
    {
        b.vy *= -1;
        b.y = bufferh - 1;
    }

    if(b.x <= 0)
    {
        b.vx *= -1;
        b.x = 0;
    }

    if(b.y <= 0)
    {
        b.vy *= -1;
        b.y = 0;
    }

    b.vy += 0.2;

}
void drawPhysicsSim()
{

    static unsigned int w, h;
    getmaxyx(stdscr, h, w);
    static unsigned int bufferw   = 99999;
    static unsigned int bufferh   = 99999;
    static unsigned char* buffer  = 0;
    static unsigned char* buffer2 = 0;
    static ball balls[100];


    if(bufferw != w || bufferh != h + 2)
    {
        bufferw = w;
        bufferh = h + 2;

        if(buffer != 0)
        {
            delete buffer;
        }

        if(buffer2 != 0)
        {
            delete buffer2;
        }

        buffer = new unsigned char[bufferw * bufferh];
        buffer2 = new unsigned char[bufferw * bufferh];
        memset(buffer, 0, bufferw * bufferh);
        memset(buffer2, 1, bufferw * bufferh);
        setupFirepal();

        for(int i = 0; i < 100; i++)
        {
            balls[i].x = rand() % bufferw;
            balls[i].y = rand() % bufferh;
            balls[i].vx = (float)(rand() % 200) / 10.0f - 10.0f;
            balls[i].vy = (float)(rand() % 200) / 10.0f - 10.0f;
        }
    }


    for(int i = 0; i < 100; i++)
    {
        updatePhysics(balls[i], bufferw, bufferh);
        buffer[(int)balls[i].x + (int)balls[i].y * bufferw] = rand() % 20 + 79;
    }

    for(unsigned int y = 0; y < h; y++)
    {
        buffer[0 + y * w] = 0;
        buffer[w - 1 + y * w] = 0;
    }

    for(unsigned int  x = 0; x < bufferw; x++)
    {
        if(buffer[x + (bufferh - 1) * (bufferw)] > 0)
        {
            buffer[x + (bufferh - 1) * (bufferw)] -= 1;
        }
    }

    for(unsigned int y = 0; y < bufferh - 1; y++)
    {

        for(unsigned int x = 1; x < w - 1; x++)
        {
            unsigned int pos = x + y * w;
            unsigned short heat = 0;
            heat += buffer[pos];
            heat += buffer[pos - 1];
            heat += buffer[pos + 1];
            heat += buffer[pos + w] * 6;
            buffer[pos] = heat / 9;

        }
    }

    //erase();
    unsigned char lastcolor = 0;
    attron(COLOR_PAIR(lastcolor));

    for(unsigned int y = 0; y < h; y++)
    {
        unsigned int yoffset = y * w;

        for(unsigned int x = 0; x < w; x++)
        {

            unsigned char brightness = buffer[x + yoffset];

            unsigned char color = firepal[brightness];

            if(color != lastcolor)
            {
                attron(COLOR_PAIR(color));
                lastcolor = color;
            }

            if(color != buffer2[x + yoffset])
            {
                mvaddch(y, x, 'x');
                buffer2[x + yoffset] = color;
            }
        }
    }

    refresh();
}
