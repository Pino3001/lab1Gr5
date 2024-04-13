#ifndef PAGA_H
#define PAGA_H

#include "moneda.h"

class Paga
{
private:
    float monto;
    moneda tipo_moneda;
public:
    Paga();
    Paga(float, moneda);

    float getMonto();
    moneda getTipoMoneda();

    Paga a_peso();
    Paga a_dolar();

};
#endif