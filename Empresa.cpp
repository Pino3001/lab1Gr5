#include "Empresa.h"

#include <string>
#include "Empleado.h"

#define MAX_EMPLEADO 100

using namespace std;

Empresa::Empresa()
{
    this->nombre = "Sin Nombre";
    this->nombre_legal = "Sin Nombre";
    this->rut = 00000000000;
    for (int i = 0; i < MAX_EMPLEADO; ++i)
    {
        this->empleados[i] = NULL; // Inicializar cada elemento como null
    }
}
Empresa::Empresa(string nombre, string nombre_legal, int rut)
{
    this->nombre = nombre;
    this->nombre_legal = nombre_legal;
    this->rut = rut;
}

void Empresa::setNombre(string nombre)
{
    this->nombre = nombre;
}
void Empresa::setNombre_legal(string nombreLegal)
{
    this->nombre_legal = nombreLegal;
}
void Empresa::setRut(int rut)
{
    this->rut = rut;
}
void Empresa::setEmpleado(Empleado *emp)
{
    *this->empleados = emp;
}

string Empresa::getNombre()
{
    return this->nombre;
}
string Empresa::getNombre_legal()
{
    return this->nombre_legal;
}
int Empresa::getRut()
{
    return this->rut;
}
/*Ver como manejar el getter de empleados sin dar acceso a la clase y permitir que se modifique*/

void Empresa::addEmpleado(Empleado *emp)
{
    /*Cambiar por for si se pueden usar return o break*/
    bool flag = true;
    int i = 0;
    while (i < MAX_EMPLEADO && flag == true)
    { // Recorro el arreglo de empleados y coloco el empleado pasado en un lugar vacio
        if (empleados[i] == NULL)
        {
            this->empleados[i] = emp;
            flag = false;
        }
    }
    /*VER COMO MANEJAR LOS CASOS DE DONDE EL ARREGLO ESTE LLENO*/
}
void Empresa:: removEmpleado(Empleado *emp){
    for (int i = 0; i < MAX_EMPLEADO; i++)
    {
        if (this->empleados[i] == emp)
        {
            this->empleados[i] = NULL;
        }
        
    }
    
}

int Empresa::total_sueldo_peso()
{

    int tot = 0;
    for (int i = 0; i < MAX_EMPLEADO; i++)
    {
        if (empleados[i] != NULL)
        {
            tot += empleados[i]->get_sueldo_peso();
        }
    }
    return tot;
}
int Empresa::total_sueldo_dolar()
{ // Recorro areglo de empleados de la empresa y sumo todos los sueldos
    int tot = 0;
    for (int i = 0; i < MAX_EMPLEADO; i++)
    {
        if (empleados[i] != NULL)
        {
            tot += empleados[i]->get_sueldo_dolar();
        }
    }
    return tot;
}