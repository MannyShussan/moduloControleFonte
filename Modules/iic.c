#ifndef IIC
#include "iic.h"
#endif

void I2C_Slave_Init(short address) {
    SSPSTAT = 0x80;
    SSPADD = 0x55; //Setting address
    SSPCON = 0x36; //As a slave device
    //    TRISC3 = 1; //Setting as input as given in datasheet
    //    TRISC4 = 1; //Setting as input as given in datasheet
    GIE = 1; //Global interrupt enable
    PEIE = 1; //Peripheral interrupt enable
    SSPIF = 0; //Clear interrupt flag
    SSPIE = 1; //Synchronous serial port interrupt enable
}

void I2C_Slave_Read() {
    if (SSPIF) {
        unsigned char z;
        SSPCONbits.CKP = 0;

        if (!SSPSTATbits.D_nA && !SSPSTATbits.R_nW) //If last byte was Address + Write
        {
            z = SSPBUF;
            while (!BF);
            //            PORTD = SSPBUF;
            SSPCONbits.CKP = 1;
        } else if (!SSPSTATbits.D_nA && SSPSTATbits.R_nW) //If last byte was Address + Read
        {
            z = SSPBUF;
            BF = 0;
            SSPBUF = PORTB;
            SSPCONbits.CKP = 1;
            while (SSPSTATbits.BF);
        }

        SSPIF = 0;
    }
}