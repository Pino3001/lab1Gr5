#ifndef FIJO_H
#define FIJO_H

#include <string>
#include "Empleado.h"
using namespace std;

class Fijo : public Empleado
{

public:
    Fijo();
    Fijo(string nombre, string ci, int edad, Empresa*, Paga valor_hora);

    float get_sueldo_peso();
    float get_sueldo_dolar();
    
    ~Fijo();
};
#endif