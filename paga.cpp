#include "paga.h"

#include <string>
#include "moneda.h"

using namespace std;

paga::paga()
{
    this->monto = 0;
    this->tipo_moneda = us;
}
paga::paga(float monto, moneda moneda)
{
    this->monto = monto;
    this->tipo_moneda = moneda;
}

void paga::setMonto(float monto)
{
    this->monto = monto;
}
void paga::setTipoMoneda(moneda moneda)
{
    this->tipo_moneda = moneda;
}

float paga::getMonto()
{
    return this->monto;
}
moneda paga::getTipoMoneda()
{
    return this->tipo_moneda;
}

paga paga::a_peso(float monto){
    if (this->tipo_moneda == us){
        return *this;
    }else{
        setTipoMoneda(us);
        setMonto(a_pesos(monto));
        return *this;
    }
}
paga paga::a_dolar(float monto){
    if (this->tipo_moneda == usd){
        return *this;
    }else{
        setTipoMoneda(usd);
        setMonto(a_dolar(monto));
        return *this;
    }
}