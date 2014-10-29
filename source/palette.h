#ifndef __PALETTE_H__
#define __PALETTE_H__
#define GRADIENT_LEVELS 100

extern unsigned char colorGradient[GRADIENT_LEVELS][240];
void calcGradient();
unsigned char getclosestcolor(unsigned char r,unsigned char g,unsigned char b);

#endif //__PALETTE_H__
