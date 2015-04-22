#include "fire.h"
#include "palette.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

unsigned char firepal[100];


void setupFirepal()
{
    for(int i = 0; i < 24; i++)
    {
        firepal[i] = lerp(0, 0, 0, 96, 96, 96, (float)i / 24);
    }

    for(int i = 0; i < 24; i++)
    {
        firepal[i + 25] = lerp(96, 96 , 96, 255, 0, 0, (float)i / 24);
    }

    for(int i = 0; i < 32; i++)
    {
        firepal[i + 50] = lerp(255, 0, 0, 255, 255, 0, (float)i / 24);
    }

    for(int i = 0; i < 24; i++)
    {
        firepal[i + 75] = lerp(255, 255, 0, 255, 255, 255, (float)i / 24);
    }

}

void drawFire()
{

    static unsigned int w, h;
    getmaxyx(stdscr, h, w);
    static unsigned int bufferw = 99999;
    static unsigned int bufferh = 99999;
    static unsigned char *buffer = 0;

    if(bufferw != w || bufferh != h+2)
    {
        bufferw = w;
        bufferh = h+2;

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
        buffer[bufferw * (bufferh - 1) + rand() % bufferw] = (rand() % 10) * 8 + 20;
        //buffer[rand() % bufferw] = rand()%100;
    }

    buffer[rand() % (bufferw * bufferh)] = 99;
    buffer[rand() % (bufferw * bufferh)] = 99;
    buffer[rand() % (bufferw * bufferh)] = 99;

    for(unsigned int y = 0; y < h; y++)
    {
        buffer[0 + y * w] = 0;
        buffer[w-1 + y * w] = 0;
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
