//fun��o de leitura ADC
#ifndef INIT_HEAD

#include <xc.h>
#endif

void ADC_Init() {
    ADCON0 = 0x81;
    ADCON1 = 0x8E;
    TRISA |= 0x03;
}

unsigned int ADC(unsigned int ch) {
    unsigned int channel = ch << 2;
    unsigned int result = 0;
    ADCON0 &= 0xC3;
    ADCON0 |= channel;
    GO_DONE = 1;
    while (GO_DONE);
    result = (unsigned int) ((ADRESH << 8) | ADRESL);
    return result;
}

