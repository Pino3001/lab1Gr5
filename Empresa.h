#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
class Empleado;

#define MAX_EMPLEADO 100

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

    int total_sueldo_peso();
    int total_sueldo_dolar();
};
#endif