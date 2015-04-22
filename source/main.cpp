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
#include "rotozoomer.h"
#include "bars.h"
#include "tunnel.h"
#include "sand.h"

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
        effect = rand() % 8;
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

        case 5:
            {
                drawRotozoomer();
                break;
            }

        case 6:
            {
                drawBars();
                break;
            }

        case 7:
            {
                drawTunnel();
                break;
            }

        default:
            break;
    }

}

int main(int argc, char *argv[])
{

    int c;
    bool cubes      = 0;
    bool zoomer     = 0;
    bool pattern    = 0;
    bool fire       = 0;
    bool rotozoomer = 0;
    bool bars       = 0;
    bool tunnel     = 0;
    bool sand       = 0;

    while((c = getopt(argc, argv, "bczprftsh")) != -1)
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

            case 'r':
                {
                    rotozoomer = 1;
                    break;
                }

            case 'b':
                {
                    bars = 1;
                    break;
                }

            case 't':
                {
                    tunnel = 1;
                    break;
                }
            case 's':
                {
                    sand = 1;
                    break;
                }

            case 'h':
                {
                    printf("options:\n");
                    printf("\t-b bars\n");
                    printf("\t-c cubes\n");
                    printf("\t-f fire\n");
                    printf("\t-p pattern\n");
                    printf("\t-t tunnel\n");
                    printf("\t-z zoomer\n");
                    printf("\t-s sand\n");
                    return 0;
                    break;
                }

            default:
                break;
        }
    }

    calcGradient();
    correctImageColors();
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
        else if(rotozoomer)
        {
            drawRotozoomer();
        }
        else if(bars)
        {
            drawBars();
        }
        else if(tunnel)
        {
            drawTunnel();
        }
        else if(sand)
        {
            drawSand();
        }
        else
        {
            drawRandom();
        }
    }

    endwin();
    return 0;
}
