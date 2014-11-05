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
    static unsigned int time=0;
    time+=8;
    for(unsigned int y = 0; y < h; y++)
    {

        for(unsigned int x = 0; x < w; x++)
        {
            int brightness=((50*x)/w*(50*y)/h+time)%100;
            attron(COLOR_PAIR(colorGradient[brightness][(time/20)%240]));
            mvprintw(y, x, "x");
        }
    }

    refresh();
}
