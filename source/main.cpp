#include <curses.h>
#include <math.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "zoomer.h"
#include "cubes.h"
#include "pattern.h"
#include "palette.h"
#include "fire.h"

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
        effect = rand() % 5;
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

        case 3:
        {
            drawPattern();
            break;
        }

        case 4:
        {
            drawFire();
            break;
        }

        default:
            break;
    }

}

int main(int argc, char *argv[])
{

    int c;
    bool cubes   = 0;
    bool zoomer  = 0;
    bool pattern = 0;
    bool fire    = 0;

    while((c = getopt(argc, argv, "czpfh")) != -1)
    {
        switch(c)
        {
            case 'c':
            {
                cubes = 1;
                break;
            }

            case 'z':
            {
                zoomer = 1;
                break;
            }

            case 'p':
            {
                pattern = 1;
                break;
            }

            case 'f':
            {
                fire = 1;
                break;
            }

            case 'h':
            {
                printf("options:\n\t-c cubes\n\t-z zoomer\n-p pattern\n-f fire\n");
                return 0;
                break;
            }

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

    // make all pairs use the same background as forground color
    for(int i = 0; i < 256; i++)
    {
        init_pair(i + 1, i, i);
    }


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
        else if(pattern)
        {
            drawPattern();
        }
        else if(fire)
        {
            drawFire();
        }
        else
        {
            drawRandom();
        }
    }

    endwin();
    return 0;
}
