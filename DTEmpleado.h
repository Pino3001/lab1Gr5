#ifndef DTEEMPLEADO_H
#define DTEMPLEADO_H

#include "Empleado.h"
#include <string>

using namespace std;

class DTEmpleado
{
private:
    string nombre;
    string ci;
    int edad;
    string trabaja_en;
    float sueldo_mensual;
public:
    DTEmpleado();
    DTEmpleado(Empleado * empleado);

    string getNombre();
    string getCi();
    int getEdad();
    string getTrabaja_en();
    float getSueldoMensual();
};
#endif