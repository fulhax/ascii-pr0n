#include "bars.h"
#include "palette.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

void drawBars()
{
    static unsigned int w, h;
    getmaxyx(stdscr, h, w);
    static unsigned int bufferw = 99999;
    static unsigned int bufferh = 99999;
    static unsigned char *buffer = 0;
    static unsigned int time = 0;
    time += 1;

    if(bufferw != w || bufferh != h)
    {
        bufferw = w;
        bufferh = h;

        if(buffer != 0)
        {
            delete buffer;
        }

        buffer = new unsigned char[bufferw * bufferh];
        memset(buffer, 0, bufferw * bufferh);
    }

    for(unsigned int y = 0; y < h; y++)
    {

        for(unsigned int x = 0; x < w; x++)
        {
            buffer[x + y * bufferw] = 0;
        }
    }

    for(unsigned int i = 0; i < bufferh; i++)
    {
        float s = sin((float)i / 5.0f + (float)time / 60.0f)*0.9;
        s*=(float)i/(float)bufferh;
        s*=bufferw/2;
        s = s + bufferw / 2; // center
        unsigned char c = ((time/10)+i) % 239;
        unsigned char b = 50;
        unsigned int pos = s;

        for(unsigned int j = i; j < bufferh; j++)
        {
            buffer[j * bufferw + pos + 3] = colorGradient[b + 35][c];
            buffer[j * bufferw + pos - 3] = colorGradient[b - 35][c];
            buffer[j * bufferw + pos + 2] = colorGradient[b + 25][c];
            buffer[j * bufferw + pos - 2] = colorGradient[b - 25][c];
            buffer[j * bufferw + pos + 1] = colorGradient[b + 12][c];
            buffer[j * bufferw + pos - 1] = colorGradient[b - 12][c];
            buffer[j * bufferw + pos]     = colorGradient[b][c];

        }
    }

    erase();

    for(unsigned int y = 0; y < h; y++)
    {

        for(unsigned int x = 0; x < w; x++)
        {
            unsigned char color = buffer[x + y * w];

            if(color != 0)
            {
                attron(COLOR_PAIR(color));
                mvprintw(y, x, "x");
            }
        }
    }

    refresh();

}
