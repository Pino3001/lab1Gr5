#include "Fijo.h"
#include "Empleado.h"
#include "Cambio.h"
#include <string>
using namespace std;

Fijo ::Fijo() : Empleado() {}
Fijo ::Fijo(string nombre, string ci, int edad, Empresa *emp, Paga valHora)
    : Empleado(nombre, ci, edad, emp, valHora) {}

float Fijo::get_sueldo_peso()
{ // Retorno el sueldo del empleado en pesos.
    float temp;
    temp = this->getValorhora().getMonto() * 40;
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
float Fijo::get_sueldo_dolar()
{ // Retorno el sueldo del empleado en dolares.
    float temp;
    temp = this->getValorhora().getMonto() * 40;
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

Fijo::~Fijo(){};