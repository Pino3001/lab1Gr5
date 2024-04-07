#ifndef FIJO_H
#define FIJO_H

#include <string>
#include "Empleado.h"
using namespace std;

class Fijo : public Empleado
{

public:
    Fijo();
    Fijo(string, string);

    int get_sueldo_peso();
    int get_sueldo_dolar();

    ~Fijo();
};
#endif