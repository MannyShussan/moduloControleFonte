#include "Modules/sys.h"

double calcularTensao(medicao *m);

medicao tensao;

void main(void) {
    System_init();
    while (1) {

    }
}


void __interrupt() ISR(void){
    
}

double calculaTensao(medicao *m) {
    double coeficiente = (double) m->R2Tensao / ((double) (m->R1Tensao + m->R2Tensao));
    double tensaoMedida = m->adcTensao * 0.0048828125;
    return (double) (tensaoMedida / coeficiente);
}

double calculaCorrente(medicao *c) {
    return (double) (c->adcCorrente * c->coeficienteDeConversaoCorrente);
}