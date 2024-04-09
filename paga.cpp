#include "paga.h"

#include <string>
#include "moneda.h"
#include "Cambio.h"

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

float paga::getMonto()
{
    return this->monto;
}
moneda paga::getTipoMoneda()
{
    return this->tipo_moneda;
}

paga paga::a_peso()
{
    if (this->tipo_moneda == us)
    {
        return *this;
    }
    else
    {
        monto = Cambio::a_peso(this->monto);
        paga p = paga(monto, us);
        return p;
    }
}
paga paga::a_dolar()
{
    if (this->tipo_moneda == usd)
    {
        return *this;
    }
    else
    {

        monto = Cambio::a_dolar(this->monto);
        paga p(monto, usd);
        return p;
    }
}