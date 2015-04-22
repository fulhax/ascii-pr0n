#ifndef __PALETTE_H__
#define __PALETTE_H__
#define GRADIENT_LEVELS 100

extern unsigned char colorGradient[GRADIENT_LEVELS][240];
void calcGradient();
unsigned char getclosestcolor(unsigned char r,unsigned char g,unsigned char b);
unsigned char lerp(float r, float g, float b, float r2, float g2, float b2, float f);

#endif //__PALETTE_H__
