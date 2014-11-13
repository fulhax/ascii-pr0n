#include "tunnel.h"
#include "palette.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

void drawTunnel()
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

    int voffset = sin((float)((bufferh / 3)+time/15) / 5.0f) * 4;

    for(unsigned int y = 0; y < h; y++)
    {

        int minx = bufferh / 3 + voffset;
        int maxx = bufferw - bufferh / 3 + voffset;

        if(minx < 0)
        {
            minx = 0;
        }

        if(maxx >= bufferw)
        {
            maxx = bufferw;
        }

        for(unsigned int x = 0; x < minx; x++)
        {
            unsigned char brightness = 100 - (float)(x) / minx * 80;
            buffer[x + y * bufferw] = colorGradient[brightness][239];
        }

        for(unsigned int x = maxx; x < bufferw; x++)
        {
            //unsigned char brightness = (float)(x - maxx) / maxx * 80+20;
            unsigned char brightness = 100 - (1.0f-(float)(x-maxx) / maxx) * 80;
            buffer[x + y * bufferw] = colorGradient[brightness][239];
        }
    }

    for(unsigned int y = 0; y < h / 3; y++)
    {
        unsigned char brightness = 100 - (float)(y) / (h / 3) * 80;
        int offset = sin((float)(y +time/15)/ 5.0f) * 4;
        int minx = y + offset;
        int maxx = bufferw - y + offset;

        if(minx < 0)
        {
            minx = 0;
        }

        if(maxx >= bufferw)
        {
            maxx = bufferw;
        }

        for(unsigned int x = minx ; x < maxx ; x++)
        {
            buffer[x + y * bufferw] = colorGradient[brightness][239];
            buffer[bufferw * bufferh - (bufferw - x + y * bufferw) ] = colorGradient[brightness][(y + time / 125) % 239];
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
