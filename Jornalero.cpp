#include "Jornalero.h"
#include "Empleado.h"
#include "Cambio.h"
#include <string>
using namespace std;

Jornalero::Jornalero() : Empleado()
{
    this->horas = 0;
}
Jornalero::Jornalero(string nombre, string ci, int edad, Empresa *emp, paga valHora, int horas)
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
{
    float temp;
    temp = this->getValorhora().getMonto() * this->horas;
    if (this->getValorhora().getTipoMoneda() == usd)
    {
        temp = Cambio::a_peso(temp);
    }
    else
    {
        return temp;
    }
}
float Jornalero::get_sueldo_dolar()
{
    float temp;
    temp = this->getValorhora().getMonto() * this->horas;
    if (this->getValorhora().getTipoMoneda() == us)
    {
        temp = Cambio::a_dolar(temp);
    }
    else
    {
        return temp;
    }
}