#include "DTEmpleado.h"
#include "Empleado.h"
#include <string>
#include "iostream"

using namespace std;

DTEmpleado::DTEmpleado()
{
    this->nombre = "None";
    this->ci = "None";
    this->edad = 0;
    this->trabaja_en = "None";
    this->sueldoPesos = 0;
}
DTEmpleado::DTEmpleado(Empleado *empleado)
{
    this->nombre = empleado->getNombre();
    this->ci = empleado->getCi();
    this->edad = empleado->getEdad();
    // Setea la empresa en la que trabaja el empleado.
    this->trabaja_en = empleado->getEmpresa()->getNombre();
    // Calcula el sueldo del empleado en pesos y lo setea al atributo.
    this->sueldoPesos = empleado->get_sueldo_peso();
}

string DTEmpleado::getNombre()
{
    return this->nombre;
}
string DTEmpleado::getCi()
{
    return this->ci;
}
int DTEmpleado::getEdad()
{
    return this->edad;
}
string DTEmpleado::getTrabaja_en()
{
    return this->trabaja_en;
}
float DTEmpleado::getSueldoPesos()
{
    return this->sueldoPesos;
}
void DTEmpleado::mostrar_datos_empleados()
{ //Muestra todos los datos del empleado.
    cout << "\n\n";
    cout << "\t ################################## "; 
    cout << "\n\n\t -- Nombre: " << this->getNombre();
    cout << "\n\t -- Cedula de identidad: " << this->getCi();
    cout << "\n\t -- Edad: " << this->getEdad();
    cout << "\n\t -- Sueldo semanal: " << this->getSueldoPesos() <<" us";
    cout << "\n\n";
    cout << "\t ################################## "; 
}