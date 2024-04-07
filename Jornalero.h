#ifndef JORNALERO_H
#define JORNALERO_H

#include <string>
#include "Empleado.h"
using namespace std;

class Jornalero : public Empleado
{
private:
    int horas;
public:
    Jornalero();
    Jornalero(string, string, int);

    void setHoras(int);

    int getHoras();

    int get_sueldo_peso();
    int get_sueldo_dolar();

    ~Jornalero();
};
#endif