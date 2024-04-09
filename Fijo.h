#ifndef FIJO_H
#define FIJO_H

#include <string>
#include "Empleado.h"
using namespace std;

class Fijo : public Empleado
{

public:
    Fijo();
    Fijo(string, string, int, Empresa*, paga);

    float get_sueldo_peso();
    float get_sueldo_dolar();

    //~Fijo();
};
#endif