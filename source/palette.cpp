#include <math.h>
#include <stdio.h>
#include "palette.h"

unsigned char colorGradient[GRADIENT_LEVELS][240];

unsigned char inputpal[720] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x87,
    0x00, 0x00, 0xaf, 0x00, 0x00, 0xd7, 0x00, 0x00, 0xff,
    0x00, 0x5f, 0x00, 0x00, 0x5f, 0x5f, 0x00, 0x5f, 0x87,
    0x00, 0x5f, 0xaf, 0x00, 0x5f, 0xd7, 0x00, 0x5f, 0xff,
    0x00, 0x87, 0x00, 0x00, 0x87, 0x5f, 0x00, 0x87, 0x87,
    0x00, 0x87, 0xaf, 0x00, 0x87, 0xd7, 0x00, 0x87, 0xff,
    0x00, 0xaf, 0x00, 0x00, 0xaf, 0x5f, 0x00, 0xaf, 0x87,
    0x00, 0xaf, 0xaf, 0x00, 0xaf, 0xd7, 0x00, 0xaf, 0xff,
    0x00, 0xd7, 0x00, 0x00, 0xd7, 0x5f, 0x00, 0xd7, 0x87,
    0x00, 0xd7, 0xaf, 0x00, 0xd7, 0xd7, 0x00, 0xd7, 0xff,
    0x00, 0xff, 0x00, 0x00, 0xff, 0x5f, 0x00, 0xff, 0x87,
    0x00, 0xff, 0xaf, 0x00, 0xff, 0xd7, 0x00, 0xff, 0xff,
    0x5f, 0x00, 0x00, 0x5f, 0x00, 0x5f, 0x5f, 0x00, 0x87,
    0x5f, 0x00, 0xaf, 0x5f, 0x00, 0xd7, 0x5f, 0x00, 0xff,
    0x5f, 0x5f, 0x00, 0x5f, 0x5f, 0x5f, 0x5f, 0x5f, 0x87,
    0x5f, 0x5f, 0xaf, 0x5f, 0x5f, 0xd7, 0x5f, 0x5f, 0xff,
    0x5f, 0x87, 0x00, 0x5f, 0x87, 0x5f, 0x5f, 0x87, 0x87,
    0x5f, 0x87, 0xaf, 0x5f, 0x87, 0xd7, 0x5f, 0x87, 0xff,
    0x5f, 0xaf, 0x00, 0x5f, 0xaf, 0x5f, 0x5f, 0xaf, 0x87,
    0x5f, 0xaf, 0xaf, 0x5f, 0xaf, 0xd7, 0x5f, 0xaf, 0xff,
    0x5f, 0xd7, 0x00, 0x5f, 0xd7, 0x5f, 0x5f, 0xd7, 0x87,
    0x5f, 0xd7, 0xaf, 0x5f, 0xd7, 0xd7, 0x5f, 0xd7, 0xff,
    0x5f, 0xff, 0x00, 0x5f, 0xff, 0x5f, 0x5f, 0xff, 0x87,
    0x5f, 0xff, 0xaf, 0x5f, 0xff, 0xd7, 0x5f, 0xff, 0xff,
    0x87, 0x00, 0x00, 0x87, 0x00, 0x5f, 0x87, 0x00, 0x87,
    0x87, 0x00, 0xaf, 0x87, 0x00, 0xd7, 0x87, 0x00, 0xff,
    0x87, 0x5f, 0x00, 0x87, 0x5f, 0x5f, 0x87, 0x5f, 0x87,
    0x87, 0x5f, 0xaf, 0x87, 0x5f, 0xd7, 0x87, 0x5f, 0xff,
    0x87, 0x87, 0x00, 0x87, 0x87, 0x5f, 0x87, 0x87, 0x87,
    0x87, 0x87, 0xaf, 0x87, 0x87, 0xd7, 0x87, 0x87, 0xff,
    0x87, 0xaf, 0x00, 0x87, 0xaf, 0x5f, 0x87, 0xaf, 0x87,
    0x87, 0xaf, 0xaf, 0x87, 0xaf, 0xd7, 0x87, 0xaf, 0xff,
    0x87, 0xd7, 0x00, 0x87, 0xd7, 0x5f, 0x87, 0xd7, 0x87,
    0x87, 0xd7, 0xaf, 0x87, 0xd7, 0xd7, 0x87, 0xd7, 0xff,
    0x87, 0xff, 0x00, 0x87, 0xff, 0x5f, 0x87, 0xff, 0x87,
    0x87, 0xff, 0xaf, 0x87, 0xff, 0xd7, 0x87, 0xff, 0xff,
    0xaf, 0x00, 0x00, 0xaf, 0x00, 0x5f, 0xaf, 0x00, 0x87,
    0xaf, 0x00, 0xaf, 0xaf, 0x00, 0xd7, 0xaf, 0x00, 0xff,
    0xaf, 0x5f, 0x00, 0xaf, 0x5f, 0x5f, 0xaf, 0x5f, 0x87,
    0xaf, 0x5f, 0xaf, 0xaf, 0x5f, 0xd7, 0xaf, 0x5f, 0xff,
    0xaf, 0x87, 0x00, 0xaf, 0x87, 0x5f, 0xaf, 0x87, 0x87,
    0xaf, 0x87, 0xaf, 0xaf, 0x87, 0xd7, 0xaf, 0x87, 0xff,
    0xaf, 0xaf, 0x00, 0xaf, 0xaf, 0x5f, 0xaf, 0xaf, 0x87,
    0xaf, 0xaf, 0xaf, 0xaf, 0xaf, 0xd7, 0xaf, 0xaf, 0xff,
    0xaf, 0xd7, 0x00, 0xaf, 0xd7, 0x5f, 0xaf, 0xd7, 0x87,
    0xaf, 0xd7, 0xaf, 0xaf, 0xd7, 0xd7, 0xaf, 0xd7, 0xff,
    0xaf, 0xff, 0x00, 0xaf, 0xff, 0x5f, 0xaf, 0xff, 0x87,
    0xaf, 0xff, 0xaf, 0xaf, 0xff, 0xd7, 0xaf, 0xff, 0xff,
    0xd7, 0x00, 0x00, 0xd7, 0x00, 0x5f, 0xd7, 0x00, 0x87,
    0xd7, 0x00, 0xaf, 0xd7, 0x00, 0xd7, 0xd7, 0x00, 0xff,
    0xd7, 0x5f, 0x00, 0xd7, 0x5f, 0x5f, 0xd7, 0x5f, 0x87,
    0xd7, 0x5f, 0xaf, 0xd7, 0x5f, 0xd7, 0xd7, 0x5f, 0xff,
    0xd7, 0x87, 0x00, 0xd7, 0x87, 0x5f, 0xd7, 0x87, 0x87,
    0xd7, 0x87, 0xaf, 0xd7, 0x87, 0xd7, 0xd7, 0x87, 0xff,
    0xd7, 0xaf, 0x00, 0xd7, 0xaf, 0x5f, 0xd7, 0xaf, 0x87,
    0xd7, 0xaf, 0xaf, 0xd7, 0xaf, 0xd7, 0xd7, 0xaf, 0xff,
    0xd7, 0xd7, 0x00, 0xd7, 0xd7, 0x5f, 0xd7, 0xd7, 0x87,
    0xd7, 0xd7, 0xaf, 0xd7, 0xd7, 0xd7, 0xd7, 0xd7, 0xff,
    0xd7, 0xff, 0x00, 0xd7, 0xff, 0x5f, 0xd7, 0xff, 0x87,
    0xd7, 0xff, 0xaf, 0xd7, 0xff, 0xd7, 0xd7, 0xff, 0xff,
    0xff, 0x00, 0x00, 0xff, 0x00, 0x5f, 0xff, 0x00, 0x87,
    0xff, 0x00, 0xaf, 0xff, 0x00, 0xd7, 0xff, 0x00, 0xff,
    0xff, 0x5f, 0x00, 0xff, 0x5f, 0x5f, 0xff, 0x5f, 0x87,
    0xff, 0x5f, 0xaf, 0xff, 0x5f, 0xd7, 0xff, 0x5f, 0xff,
    0xff, 0x87, 0x00, 0xff, 0x87, 0x5f, 0xff, 0x87, 0x87,
    0xff, 0x87, 0xaf, 0xff, 0x87, 0xd7, 0xff, 0x87, 0xff,
    0xff, 0xaf, 0x00, 0xff, 0xaf, 0x5f, 0xff, 0xaf, 0x87,
    0xff, 0xaf, 0xaf, 0xff, 0xaf, 0xd7, 0xff, 0xaf, 0xff,
    0xff, 0xd7, 0x00, 0xff, 0xd7, 0x5f, 0xff, 0xd7, 0x87,
    0xff, 0xd7, 0xaf, 0xff, 0xd7, 0xd7, 0xff, 0xd7, 0xff,
    0xff, 0xff, 0x00, 0xff, 0xff, 0x5f, 0xff, 0xff, 0x87,
    0xff, 0xff, 0xaf, 0xff, 0xff, 0xd7, 0xff, 0xff, 0xff,
    0x08, 0x08, 0x08, 0x12, 0x12, 0x12, 0x1c, 0x1c, 0x1c,
    0x26, 0x26, 0x26, 0x30, 0x30, 0x30, 0x3a, 0x3a, 0x3a,
    0x44, 0x44, 0x44, 0x4e, 0x4e, 0x4e, 0x58, 0x58, 0x58,
    0x60, 0x60, 0x60, 0x66, 0x66, 0x66, 0x76, 0x76, 0x76,
    0x80, 0x80, 0x80, 0x8a, 0x8a, 0x8a, 0x94, 0x94, 0x94,
    0x9e, 0x9e, 0x9e, 0xa8, 0xa8, 0xa8, 0xb2, 0xb2, 0xb2,
    0xbc, 0xbc, 0xbc, 0xc6, 0xc6, 0xc6, 0xd0, 0xd0, 0xd0,
    0xda, 0xda, 0xda, 0xe4, 0xe4, 0xe4, 0xee, 0xee, 0xee
};

void calcGradient()
{
    for(int i = 0; i < GRADIENT_LEVELS; i++)
    {
        float percentage = (float)i / (GRADIENT_LEVELS - 1);

        for(int j = 0; j < 240; j++)
        {
            colorGradient[i][j] = getclosestcolor(
                                      (float)(inputpal[j * 3]) * percentage,
                                      (float)(inputpal[j * 3 + 1]) * percentage,
                                      (float)(inputpal[j * 3 + 2]) * percentage
                                  );
        }
    }
}
// don't use slow
unsigned char getclosestcolor(unsigned char r, unsigned char g, unsigned char b)
{
    unsigned char closest = 0;
    float closestdist = 10000000.0f;

    for(unsigned short i = 0; i < 240; i ++)
    {
        short rdist = r - inputpal[i * 3];
        short gdist = g - inputpal[i * 3 + 1];
        short bdist = b - inputpal[i * 3 + 2];
        float dist  = rdist * rdist + gdist * gdist + bdist * bdist;

        if(dist < closestdist)
        {
            closestdist = dist;
            closest = i;
        }
    }

    return closest+17;
}

unsigned char lerp(float r, float g, float b, float r2, float g2, float b2, float f)
{
    float invf = 1.0f - f;
    return getclosestcolor(r * invf + r2 * f, g * invf + g2 * f, b * invf + b2 * f);
}
