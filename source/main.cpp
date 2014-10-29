#include <curses.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "zoomer.h"
#include "cubes.h"
#include "palette.h"

void drawRandom()
{
    static unsigned int frames = 0;
    static unsigned int drawfor = rand() % 250;
    static unsigned int effect = rand() % 3;
    frames++;

    if(frames >= drawfor)
    {
        drawfor = rand() % 1000 + 2000;
        frames = 0;
        effect = rand() % 3;
    }

    switch(effect)
    {
        case 0:
        {
            drawZoomer();
            break;
        }

        case 1:
        {
            drawCubes(0);
            break;
        }

        case 2:
        {
            drawCubes(1);
            break;
        }

        default:
            break;
    }

}

int main(int argc, char *argv[])
{

    int c;
    bool cubes = 0;
    bool zoomer = 0;

    while((c = getopt(argc, argv, "czh")) != -1)
    {
        switch(c)
        {
            case 'c':
                cubes = 1;
                break;

            case 'z':
                zoomer = 1;
                break;

            case 'h':
                printf("options:\n\t-c cubes\n\t-z zoomer\n");
                return 0;
                break;

            default:
                break;
        }
    }

    calcGradient();
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    start_color();
    use_default_colors();

    init_pair(1 , COLOR_GREEN   , COLOR_GREEN);
    init_pair(2 , COLOR_RED     , COLOR_RED);
    init_pair(3 , COLOR_YELLOW  , COLOR_YELLOW);
    init_pair(4 , COLOR_WHITE   , COLOR_WHITE);
    init_pair(5 , COLOR_BLUE    , COLOR_BLUE);
    init_pair(6 , COLOR_CYAN    , COLOR_CYAN);
    init_pair(7 , COLOR_MAGENTA , COLOR_MAGENTA);
    init_pair(8 , COLOR_BLACK , COLOR_GREEN);
    init_pair(9 , COLOR_BLACK , COLOR_RED);
    init_pair(10, COLOR_BLACK , COLOR_YELLOW);
    init_pair(11, COLOR_BLACK , COLOR_WHITE);
    init_pair(12, COLOR_BLACK , COLOR_BLUE);
    init_pair(13, COLOR_BLACK , COLOR_CYAN);
    init_pair(14, COLOR_BLACK , COLOR_MAGENTA);

    //while(1)
    //{
    //drawZommer();
    //}

    bool wireframe = 0;

    while(1)
    {
        switch(getch())
        {
            case 'w':
                wireframe = !wireframe;
                break;

            case 'q':
                endwin();
                return 0;
                break;
        }

        if(cubes)
        {
            drawCubes(wireframe);
        }
        else if(zoomer)
        {
            drawZoomer();
        }
        else
        {
            drawRandom();
        }
    }

    endwin();
    return 0;
}
