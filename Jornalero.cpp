#include "Jornalero.h"
#include "Empleado.h"
#include "Cambio.h"
#include <string>
using namespace std;

Jornalero::Jornalero() : Empleado()
{
    this->horas = 0;
}
Jornalero::Jornalero(string nombre, string ci, int edad, Empresa *emp, Paga valHora, int horas)
    : Empleado(nombre, ci, edad, emp, valHora)
{
    this->horas = horas;
}

void Jornalero::setHoras(int horas)
{
    this->horas = horas;
}

int Jornalero::getHoras()
{
    return this->horas;
}

float Jornalero::get_sueldo_peso()
{ // Retorno el sueldo del empleado en pesos.
    float temp;
    
    temp = this->getValorhora().getMonto() * this->horas;
    if (this->getValorhora().getTipoMoneda() == usd)
    { // Si el sueldo esta en dolares lo calculo en pesos.
        temp = Cambio::a_peso(temp);
    }
    else
    {
        return temp;
    }
    return temp;
}
float Jornalero::get_sueldo_dolar()
{ // Retorno el sueldo del empleado en dolares.
    float temp;

    temp = this->getValorhora().getMonto() * this->horas;

    if (this->getValorhora().getTipoMoneda() == us)
    { // Si el sueldo esta en pesos lo calculo en dolares.
        temp = Cambio::a_dolar(temp);
    }
    else
    {
        return temp;
    }
    return temp;
}

Jornalero::~Jornalero(){};