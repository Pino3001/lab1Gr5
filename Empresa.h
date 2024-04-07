#include <string>
#include "Empleado.h"

using namespace std;

class Empresa
{
private:
    string nombre;
    string nombre_legal;
    int rut;
    Empleado * empleados[MAX_EMPLEADO];

public:
    Empresa();
    Empresa(string, string, int);
    Empresa(Empleado);

    void setNombre(string);
    void setNombre_legal(string);
    void setRut(int);
    void setEmpleado(Empleado);

    string getNombre();
    string getNombre_legal();
    string getRut();

    int total_sueldo_peso(int);
    int total_sueldo_dolar(int);
    


};