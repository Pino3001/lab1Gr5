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

    void setMonto(float);
    void setTipoMoneda(moneda);

    float getMonto();
    moneda getTipoMoneda();

    paga a_peso(float);
    paga a_dolar(float);

    ~paga();
};




#endif