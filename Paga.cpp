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
{ // Si esta en pesos no es nesecito hacer cambios.
    if (this->tipo_moneda == us)
    {
        return *this;
    }
    else
    { // Si esta en dolares, hago el cambio a pesos.
        monto = Cambio::a_peso(this->monto);
        Paga p = Paga(monto, us);
        // Retorno el nuevo Paga.
        return p;
    }
}
Paga Paga::a_dolar()
{ // Si esta en dolares no es nesecito hacer cambios.
    if (this->tipo_moneda == usd)
    {
        return *this;
    }
    else
    { // Si esta en pesos, hago el cambio a dolares.
        monto = Cambio::a_dolar(this->monto);
        Paga p(monto, usd);
        // Retorno el nuevo Paga.
        return p;
    }
}