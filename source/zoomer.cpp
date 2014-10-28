#include "zoomer.h"
#include <math.h>
#include <curses.h>
#include <stdlib.h>

#define PI 3.1415926535897932384626433832795f

void drawZommer()
{
    int w,h;
    getmaxyx(stdscr,h,w);
    erase();
    attron(COLOR_PAIR(2));
    static float time=0;
    time+=0.001f;

    float posoffset_x=sin(time)/PI*w;
    float posoffset_y=cos(time)/PI*h;

    for(unsigned int y=0;y<h;y++)
    {
        float ypos=(float)y/(float)h-0.5f;

        for(unsigned int x=0;x<w;x++)
        {
            float xpos=(float)x/(float)w-0.5f;
            float angle=atan(ypos/xpos)+time*0.5;
            float dist=sqrt(xpos*xpos+ypos*ypos)-time;
            bool result=int(angle*2)%2;
            bool result2=int(dist*10)%2;
            if(result&&result2)
            {
                mvprintw(y,x, "x");
            }
        }
    }

    refresh();
}
