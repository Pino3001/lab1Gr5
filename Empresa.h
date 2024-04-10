#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include "definiciones.h"
class Empleado; // Declaracion de intencion, evita circularidad al compilar.


using namespace std;

class Empresa
{
private:
    string nombre;
    string nombre_legal;
    int rut;
    Empleado *empleados[MAX_EMPLEADO];

public:
    Empresa();
    Empresa(string, string, int);
    // Empresa(Empleado);

    void setNombre(string);
    void setNombre_legal(string);
    void setRut(int);
    void setEmpleado(Empleado *);

    string getNombre();
    string getNombre_legal();
    int getRut();

    void addEmpleado(Empleado *);
    void removEmpleado(Empleado *);

    float total_sueldo_peso();
    float total_sueldo_dolar();
    ~Empresa();
};
#endif