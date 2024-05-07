#include "Modules/sys.h"
#include <stdio.h>

double calcularTensao(medicao *m);

void main(void) {
    System_init();
    while (1) {

    }
}

double calcularTensao(medicao *m) {
    double coeficiente = (double) m->R2Tensao / ((double) (m->R1Tensao + m->R2Tensao));
    double tensaoMedida = m->adcTensao * 0.0048828125;
    return (double) (tensaoMedida / coeficiente);
}

double calculaCorrente(medicao *c) {
    return (double) (c->adcCorrente * c->coeficienteDeConversaoCorrente);
}