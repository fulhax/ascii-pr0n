#include "rotozoomer.h"
#include "palette.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>

#include "rotozoomerimage.h"

unsigned char imagecorrectedcolors[IMAGEW *IMAGEH] = {0};

void correctImageColors()
{
    for(int y = 0; y < IMAGEH; y++)
    {
        unsigned int offset = image.width * 3 * y;

        for(int x = 0; x < IMAGEW; x++)
        {
            unsigned int x3 = x * 3;
            unsigned char r = image.pixel_data[x3 + offset];
            unsigned char g = image.pixel_data[x3 + offset + 1];
            unsigned char b = image.pixel_data[x3 + offset + 2];
            imagecorrectedcolors[x + y * IMAGEW] = getclosestcolor(r, g, b);

            if(r == 255 && g == 0 && b == 255)
            {
                imagecorrectedcolors[x + y * IMAGEW] = 0;
            }
        }
    }
}

void drawRotozoomer()
{
    int w, h;
    getmaxyx(stdscr, h, w);
    erase();
    static unsigned int time = 0;
    time += 2;

    float angle = (float)time / 500.0f;
    //angle = sin(angle);
    float scale = 4 * (sin((float)time / 1000.0f) + 0.2);
    //scale = 2.5;
    float sa = scale * sin(angle);
    float ca = scale * cos(angle);

    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            int pixelx = x / 2 - w / 4;
            int pixely = y - h / 2;
            int ix = sa * (float)pixelx + ca * pixely;
            int iy = sa * (float)pixely - ca * pixelx;

            if(ix < 0)
            {
                ix = IMAGEW - ix & 0x7fffffff;
            }

            if(iy < 0)
            {
                iy = IMAGEH - iy & 0x7fffffff;
            }

            ix %= IMAGEW;
            iy %= IMAGEH;
            unsigned char color = imagecorrectedcolors[ix + iy * IMAGEW];

            if(color != 0)
            {
                attron(COLOR_PAIR(color));
                mvprintw(y, x , "x");
            }
        }
    }

    refresh();
}
