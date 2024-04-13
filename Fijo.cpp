#include "Fijo.h"
#include "Empleado.h"
#include "Cambio.h"
#include <string>
using namespace std;

Fijo ::Fijo() : Empleado() {}
Fijo ::Fijo(string nombre, string ci, int edad, Empresa *emp, Paga valHora)
    : Empleado(nombre, ci, edad, emp, valHora) {}

float Fijo::get_sueldo_peso()
{
    float temp;
    temp = this->getValorhora().getMonto() * 40;
    if (this->getValorhora().getTipoMoneda() == usd)
    {
        temp = Cambio::a_peso(temp);
    }
    else
    {
        return temp;
    }
    return temp;
}
float Fijo::get_sueldo_dolar()
{
    float temp;
    temp = this->getValorhora().getMonto() * 40;
    if (this->getValorhora().getTipoMoneda() == us)
    {
        temp = Cambio::a_dolar(temp);
    }
    else
    {
        return temp;
    }
    return temp;
}

Fijo::~Fijo(){};