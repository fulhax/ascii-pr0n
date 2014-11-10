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

    float angle = (float)time/50;
    angle = sin(angle);
    float scale = 10*(sin((float)time/50)+1.5);
    scale=1;
    float sa = scale * sin(angle);
    float ca = scale * cos(angle);

    for(int y = 0; y < h; y++)
    {
        for(int x = 0; x < w; x++)
        {
            int ix=sa*(float)x;
            int iy=ca*(float)y;
            ix%=IMAGEW;
            iy%=IMAGEH;
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
