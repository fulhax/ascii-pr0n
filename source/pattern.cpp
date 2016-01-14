#include "pattern.h"
#include "palette.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>

void drawPattern()
{
    int w, h;
    getmaxyx(stdscr, h, w);
    erase();
    static unsigned int time = 0;
    time += 2;
    //unsigned char color = (time / 20) % 240;

    for(unsigned int y = 0; y < h; y++)
    {

        for(unsigned int x = 0; x < w; x++)
        {
            int brightness = (int)((float)(40 * x) / (float)w * (float)(40 * y) / (float)h + time) % 100;
            attron(COLOR_PAIR(colorGradient[brightness][239]));
            mvaddch(y, x, 'x');
        }
    }

    refresh();
}
