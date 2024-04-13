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
    Jornalero(string Nombre, string CI, int Edad, Empresa*, Paga valor_hora, int Horas);

    void setHoras(int);

    int getHoras();

    float get_sueldo_peso();
    float get_sueldo_dolar();

    ~Jornalero();
};
#endif