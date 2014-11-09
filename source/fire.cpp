#include "fire.h"
#include "palette.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

unsigned char firepal[100];

unsigned char lerp(float r, float g, float b, float r2, float g2, float b2, float f)
{
    float invf = 1.0f - f;
    return getclosestcolor(r * invf + r2 * f, g * invf + g2 * f, b * invf + b2 * f);
}

void setupFirepal()
{
    for(int i = 0; i < 32; i++)
    {
        firepal[i] = lerp(0, 0, 0, 255, 0, 0, (float)i / 32);
    }

    for(int i = 0; i < 32; i++)
    {
        firepal[i + 33] = lerp(255, 0, 0, 255, 255, 0, (float)i / 32);
    }

    for(int i = 0; i < 33; i++)
    {
        firepal[i + 66] = lerp(255, 255, 0, 255, 255, 255, (float)i / 33);
    }

}

void drawFire()
{

    static unsigned int w, h;
    getmaxyx(stdscr, h, w);
    static unsigned int bufferw = 99999;
    static unsigned int bufferh = 99999;
    static unsigned char *buffer = 0;

    if(bufferw != w || bufferh != h)
    {
        bufferw = w;
        bufferh = h;

        if(buffer != 0)
        {
            delete buffer;
        }

        setupFirepal();
        buffer = new unsigned char[bufferw * bufferh];
        memset(buffer, 0, bufferw * bufferh);
    }

    for(int i = 0; i < 60; i++)
    {
        buffer[bufferw * (bufferh - 1) + rand() % bufferw] = (rand() % 10) * 10;
        //buffer[rand() % bufferw] = rand()%100;
    }

    for(unsigned int y = 0; y < h - 1; y++)
    {

        for(unsigned int x = 1; x < w - 1; x++)
        {
            unsigned int pos = x + y * w;
            unsigned short heat = 0;
            heat += buffer[pos];
            heat += buffer[pos - 1];
            heat += buffer[pos + 2];
            heat += buffer[pos + w] * 4;
            buffer[pos] = heat / 7;

        }
    }

    erase();

    for(unsigned int y = 0; y < h; y++)
    {

        for(unsigned int x = 0; x < w; x++)
        {
            unsigned char brightness = buffer[x + y * w];
            attron(COLOR_PAIR(firepal[brightness]));
            mvprintw(y, x, "x");
        }
    }

    refresh();
}
