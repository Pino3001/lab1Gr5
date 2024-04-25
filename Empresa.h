#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include <list>
#include "definiciones.h"

class Empleado; // Declaracion de intencion, evita circularidad al compilar.
class DTEmpleado;

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
    Empresa(string nombre, string nombre_legal, int rut);
    // Empresa(Empleado);

    void setNombre(string);
    void setNombre_legal(string);
    void setRut(int);
    void setEmpleado(Empleado *);

    string getNombre();
    string getNombre_legal();
    int getRut();
    Empleado* getEmpleados();

    void addEmpleado(Empleado *);
    void removEmpleado(Empleado *);

    float total_sueldo_peso();
    float total_sueldo_dolar();

    Empleado* buscar_empleado(string Ci);
    list <DTEmpleado> listar_empleados();
    ~Empresa();
};
#endif