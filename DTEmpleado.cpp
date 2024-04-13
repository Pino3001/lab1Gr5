#include "DTEmpleado.h"
#include "Empleado.h"
#include <string>

using namespace std;

DTEmpleado::DTEmpleado()
{
    this->nombre = "None";
    this->ci = "None";
    this->edad = 0;
    this->trabaja_en = "None";
    this->sueldo_mensual = 0;
}
DTEmpleado::DTEmpleado(Empleado *empleado)
{
    this->nombre = empleado->getNombre();
    this->ci = empleado->getCi();
    this->edad = empleado->getEdad();
    this->trabaja_en = empleado->getEmpresa()->getNombre();
    this->sueldo_mensual = empleado->get_sueldo_peso();
}

string DTEmpleado::getNombre(){
    return this->nombre;
}
string DTEmpleado::getCi(){
    return this->ci;
}
int DTEmpleado:: getEdad(){
    return this->edad;
}
string DTEmpleado::getTrabaja_en(){
    return this->trabaja_en;
}
float DTEmpleado:: getSueldoMensual(){
    return this->sueldo_mensual;
}