#ifndef INIT_HEAD

#include <xc.h>
#endif

#ifndef PIC

#include <pic16f677.h>
#include "adc.h"
#include "extInt.h"
#include "iic.h"

#endif

#define _XTAL_FREQ 8000000

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select bit (MCLR pin function is MCLR)
#pragma config CP = ON          // Code Protection bit (Program memory code protection is enabled)
#pragma config CPD = ON         // Data Code Protection bit (Data memory code protection is enabled)
#pragma config BOREN = OFF      // Brown-out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)

// Definições do Systema
#define adc1 0
#define adc2 1







// Estruturas

typedef struct {
    double tensao;
    double corrente;
    unsigned int adcTensao;
    unsigned int adcCorrente;
    unsigned int R1Tensao;
    unsigned int R2Tensao;
    float coeficienteDeConversaoCorrente;
} medicao;

extern void System_init();