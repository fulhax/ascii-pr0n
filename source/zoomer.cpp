#include "zoomer.h"
#include "palette.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>
#define PI 3.1415926535897932384626433832795f

void drawZoomer()

{
    int w, h;
    getmaxyx(stdscr, h, w);
    erase();
    static float time = 0;
    time += 0.001f;

    if(time >= 32768.0f) // max a float can get to with +=0.001f
    {
        time = 0.0f;
    }

    float posoffset_x = sin(time) / PI;
    float posoffset_y = cos(time) / PI;

    for(unsigned int y = 0; y < h; y++)
    {
        float ypos = (float)y / (float)h - 0.5f + posoffset_y;

        for(unsigned int x = 0; x < w; x++)
        {
            float xpos   = (float)x / (float)w - 0.5f + posoffset_x;
            float angle  = atan(ypos / xpos) + time * 0.5;
            float dist   = sqrt(xpos * xpos + ypos * ypos);
            float distwithtime   = dist - time;
            bool result  = int(angle * 2) % 2;
            bool result2 = int(distwithtime * 10) % 2;
            int brightness = dist * 200;

            if(brightness >= 100)
            {
                brightness = 99;
            }

            if(result && result2)
            {
                attron(COLOR_PAIR(colorGradient[brightness][(int)(-distwithtime * 7) % 240]));
                mvaddch(y, x, 'x');
            }
        }
    }

    refresh();
}
