#include "sand.h"
#include "palette.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

unsigned char sandpal[100];

void setupSandpal()
{
    sandpal[0] = 17;

    for(int i = 1; i < 24; i++)
    {
        sandpal[i] = lerp(96, 96, 96, 255, 255, 255, (float)i / 24);
    }

    for(int i = 0; i < 24; i++)
    {
        sandpal[i + 25] = lerp(96, 96 , 96, 255, 192, 192, (float)i / 24);
    }

    for(int i = 0; i < 32; i++)
    {
        sandpal[i + 50] = lerp(100, 100, 50, 255, 255, 192, (float)i / 24);
    }

    for(int i = 0; i < 24; i++)
    {
        sandpal[i + 75] = lerp(100, 200, 150, 255, 255, 255, (float)i / 24);
    }

}
void drawSand()
{
    static unsigned int w, h;
    getmaxyx(stdscr, h, w);
    static unsigned int bufferw = 99999;
    static unsigned int bufferh = 99999;
    static unsigned char *buffer = 0;

    if(bufferw != w || bufferh != h + 2)
    {
        bufferw = w;
        bufferh = h + 2;

        if(buffer != 0)
        {
            delete buffer;
        }

        setupSandpal();
        buffer = new unsigned char[bufferw * bufferh];
        memset(buffer, 0, bufferw * bufferh);
    }

    // sand logic here
    static unsigned char sandBrightness = 99;
    static unsigned int frame = 0;
    frame++;

    if(frame > 4)
    {
        sandBrightness = (sandBrightness + 1) % 100;
        frame = 0;
    }

    for(unsigned int  i = 0; i < bufferw ; i++)
    {
        if(rand() % 10 == 0)
        {
            buffer[i] = sandBrightness;
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

    for(unsigned int y = bufferh - 1; y > 1; y--)
    {
        unsigned int offset1 = y * bufferw;
        unsigned int offset2 = y * bufferw - bufferw;
        unsigned int offset3 = y * bufferw + bufferw;

        for(unsigned int x = 0; x < bufferw - 1; x++)
        {
            if(buffer[offset1 + x + 1] == 0 && buffer[offset3 + x] != 0)
            {
                buffer[offset1 + x + 1] = buffer[offset2 + x ];
                buffer[offset2 + x ] = 0;
            }
        }
    }

    for(unsigned int y = bufferh - 1; y > 1; y--)
    {
        unsigned int offset1 = y * bufferw;
        unsigned int offset2 = y * bufferw - bufferw;
        unsigned int offset3 = y * bufferw + bufferw;

        for(unsigned int x = 0; x < bufferw ; x++)
        {
            if(buffer[offset1 + x - 1] == 0 && buffer[offset3 + x] != 0)
            {
                buffer[offset1 + x - 1] = buffer[offset2 + x ];
                buffer[offset2 + x ] = 0;
            }
        }
    }

    static int holepos           = 0;
    static unsigned int holew    = 1;
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
        unsigned char jitteramount=holew/2;
        if(jitteramount<=1)
        {
            jitteramount=2;
        }
        unsigned int offset = bufferw * (bufferh - 1);
        int holejitteredpos = holepos + rand() % jitteramount - jitteramount/2;

        for(int i = 0; i < holew; i++)
        {
            if((i + holejitteredpos) >= 0 && (i + holejitteredpos) < bufferw)
            {
                buffer[offset + i + holejitteredpos] = 0;
            }
        }
    }

    // end of sand logic



    erase();

    for(unsigned int y = 0; y < h; y++)
    {

        for(unsigned int x = 0; x < w; x++)
        {
            unsigned char color = buffer[x + y * w + w];
            attron(COLOR_PAIR(sandpal[color]));
            mvaddch(y, x, 'x');
        }
    }

    refresh();

}
