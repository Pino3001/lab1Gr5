#include "Empleado.h"

#include <string>
#include "Empresa.h"
#include "paga.h"
#include "Cambio.h"

using namespace std;

Empleado::Empleado()
{
    this->nombre = "Sin Nombre";
    this->ci = "0000000-0";
    this->edad = 0;
}
Empleado::Empleado(string nombre, string ci, int edad, Empresa *emp, paga valHora)
{
    this->nombre = nombre;
    this->ci = ci;
    this->edad = edad;
    this->valor_hora = valHora;

    /*Setear empleado en la empresa*/
    this->empresa = emp;
    this->empresa->addEmpleado(this);
}

void Empleado::setNombre(string nombre)
{
    this->nombre = nombre;
}
void Empleado::setCi(string ci)
{
    this->ci = ci;
}
void Empleado::setEdad(int edad)
{
    this->edad = edad;
}
void Empleado::setValor_hora(paga valorH)
{
    this->valor_hora = valorH;
}
void Empleado::setEmpresa(Empresa *emp)
{   // Elimino empleado de la anterior empresa y lo asigno a la nueva.
    this->empresa->removEmpleado(this);
    this->empresa = emp;
    this->empresa->addEmpleado(this);
    /*Setear empleado en empresa*/
}

string Empleado::getNombre()
{
    return this->nombre;
}
string Empleado::getCi()
{
    return this->ci;
}
int Empleado::getEdad()
{
    return this->edad;
}
paga Empleado::getValorhora()
{
    return this->valor_hora;
}
Empresa *Empleado::getEmpresa()
{
    return this->empresa;
}
Empleado::~Empleado()
{
    this->empresa->removEmpleado(this);
}
