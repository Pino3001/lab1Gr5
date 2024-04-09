#ifndef PAGA_H
#define PAGA_H

#include "moneda.h"

class paga
{
private:
    float monto;
    moneda tipo_moneda;
public:
    paga();
    paga(float, moneda);

    float getMonto();
    moneda getTipoMoneda();

    paga a_peso();
    paga a_dolar();

};

#endif