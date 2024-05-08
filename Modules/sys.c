#ifndef PIC
#include <xc.h>
#include <pic16f677.h>
#include "sys.h"
#endif

void System_init() {
    OSCCON |= 0x70;
    ADC_Init();
    externalInterrup_Init();
    
}