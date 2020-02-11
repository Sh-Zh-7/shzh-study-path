#ifndef __DELAY_H
#define __DELAY_H

#if defined USE_UCOSII
#include "includes.h"
#endif

void delay_ms(unsigned int t);
void delay_us(unsigned int t);

#endif

