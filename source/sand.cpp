#include "sand.h"
#include "palette.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

void drawSand()
{
    static unsigned int w, h;
    getmaxyx(stdscr, h, w);
    static unsigned int bufferw = 99999;
    static unsigned int bufferh = 99999;
    static unsigned char *buffer = 0;

    if(bufferw != w || bufferh != h + 1)
    {
        bufferw = w;
        bufferh = h + 1;

        if(buffer != 0)
        {
            delete buffer;
        }

        //setupFirepal();
        buffer = new unsigned char[bufferw * bufferh];
        memset(buffer, 0, bufferw * bufferh);
    }

    // sand logic here

    for(unsigned int  i = 0; i < bufferw; i++)
    {
        if(rand() % 10 == 0)
        {
            buffer[i] = rand() % 255;
        }
        else
        {
            buffer[i] = 0;
        }
    }

    for(unsigned int y = bufferh - 1; y > 0; y--)
    {
        unsigned int offset1 = y * bufferw;
        unsigned int offset2 = y * bufferw - bufferw;

        for(unsigned int x = 0; x < bufferw; x++)
        {
            if(buffer[offset2 + x] != 0)
            {

                if(buffer[offset1 + x] == 0)
                {
                    buffer[offset1 + x] = buffer[offset2 + x];
                    buffer[offset2 + x] = 0;
                }
            }
        }
    }

    static int holepos           = 0;
    static unsigned int holew    = 0;
    static unsigned int openhole = 0;
    static unsigned char holedepth = 5;

    if(rand() % 10 && openhole >= holedepth)
    {
        holepos = rand() % bufferw;
        holew = rand() % bufferw / 5 + 5;
        openhole = 0;
        holedepth = rand() % bufferh / 2 + 2;
    }

    if(openhole < holedepth)
    {
        openhole++;
        unsigned int offset = bufferw * (bufferh - 1);

        for(int i = 0; i < holew; i++)
        {
            if((i + holepos) >= 0 && (i + holepos) < bufferw)
            {
                buffer[offset + i + holepos] = 0;
            }
        }
    }

    // end of sand logic



    erase();

    for(unsigned int y = 0; y < h; y++)
    {

        for(unsigned int x = 0; x < w; x++)
        {
            unsigned char color = buffer[x + y * w];
            attron(COLOR_PAIR(colorGradient[99][color]));
            mvprintw(y, x, "x");
        }
    }

    refresh();

}
