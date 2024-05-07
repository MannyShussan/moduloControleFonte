void I2C_Slave_Init(short address) {
    SSPSTAT = 0x80;
    SSPADD = address; //Setting address
    SSPCON = 0x36; //As a slave device
    TRISC3 = 1; //Setting as input as given in datasheet
    TRISC4 = 1; //Setting as input as given in datasheet
    GIE = 1; //Global interrupt enable
    PEIE = 1; //Peripheral interrupt enable
    SSPIF = 0; //Clear interrupt flag
    SSPIE = 1; //Synchronous serial port interrupt enable
}

void interrupt I2C_Slave_Read() {
    unsigned char z;
    if (SSPIF) {
        SSPCONbits.CKP = 0;

        if ((SSPCONbits.SSPOV) || (SSPCONbits.WCOL)) //If overflow or collision
        {
            z = SSPBUF; // Read the previous value to clear the buffer
            SSPCONbits.SSPOV = 0; // Clear the overflow flag
            SSPCONbits.WCOL = 0; // Clear the collision bit
            SSPCONbits.CKP = 1;
        }

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