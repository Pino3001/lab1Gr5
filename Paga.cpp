#include "Paga.h"

#include <string>
#include "moneda.h"
#include "Cambio.h"

using namespace std;

Paga::Paga()
{
    this->monto = 0;
    this->tipo_moneda = us;
}
Paga::Paga(float monto, moneda moneda)
{
    this->monto = monto;
    this->tipo_moneda = moneda;
}

float Paga::getMonto()
{
    return this->monto;
}
moneda Paga::getTipoMoneda()
{
    return this->tipo_moneda;
}

Paga Paga::a_peso()
{
    if (this->tipo_moneda == us)
    {
        return *this;
    }
    else
    {
        monto = Cambio::a_peso(this->monto);
        Paga p = Paga(monto, us);
        return p;
    }
}
Paga Paga::a_dolar()
{
    if (this->tipo_moneda == usd)
    {
        return *this;
    }
    else
    {

        monto = Cambio::a_dolar(this->monto);
        Paga p(monto, usd);
        return p;
    }
}