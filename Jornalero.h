#ifndef JORNALERO_H
#define JORNALERO_H

#include <string>
#include "Empleado.h"
#include "Cambio.h"
using namespace std;

class Jornalero : public Empleado
{
private:
    int horas;
public:
    Jornalero();
    Jornalero(string, string, int, Empresa*, paga, int);

    void setHoras(int);

    int getHoras();

    float get_sueldo_peso();
    float get_sueldo_dolar();

    //~Jornalero();
};
#endif