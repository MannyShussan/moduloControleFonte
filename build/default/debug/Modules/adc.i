# 1 "Modules/adc.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.46\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Modules/adc.c" 2

# 1 "Modules/adc.h" 1





extern void ADC_Init();
extern unsigned int ADC(unsigned int ch);
# 2 "Modules/adc.c" 2



void ADC_Init() {
    ADCON0 = 0x81;
    ADCON1 = 0x8E;
    TRISA |= 0x03;
    ADIE = 1;
}

unsigned int ADC(unsigned int ch) {
    unsigned int channel = ch << 2;
    unsigned int result = 0;
    ADCON0 &= 0xC3;
    ADCON0 |= channel;
    GO_DONE = 1;

    return (unsigned int) ((ADRESH << 8) | ADRESL);
}
