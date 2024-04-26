#include "Empresa.h"

#include "Empleado.h"
#include "DTEmpleado.h"
#include <string>
#include <list>
#include "iostream"

using namespace std;

Empresa::Empresa()
{
    this->nombre = "Sin Nombre";
    this->nombre_legal = "Sin Nombre";
    this->rut = 00000000000;
    for (int i = 0; i < MAX_EMPLEADO; ++i)
    {
        this->empleados[i] = NULL; // Inicializa cada elemento como NULL en el arreglo de empleados.
    }
}
Empresa::Empresa(string nombre, string nombre_legal, int rut)
{
    this->nombre = nombre;
    this->nombre_legal = nombre_legal;
    this->rut = rut;
    for (int i = 0; i < MAX_EMPLEADO; ++i)
    {
        this->empleados[i] = NULL; // Inicializa cada elemento como NULL en el arreglo de empleados.
    }
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
Empleado *Empresa::getEmpleados()
{
    return *this->empleados;
}

void Empresa::addEmpleado(Empleado *emp)
{
    /*Cambiar por for si se pueden usar return o break*/
    bool flag = true;
    int i = 0;
    while (flag && i < MAX_EMPLEADO)
    { // Recorro el arreglo de empleados y coloco el empleado pasado en un lugar vacio
        if (empleados[i] == NULL)
        {
            this->empleados[i] = emp;
            flag = false;
        }
        i++;
    }
    if (flag)
    { // Caso donde el arreglo esta lleno.
        cout << "\n-- No es posible ingresar un nuevo empleado al sistema. --";
    }
}
void Empresa::removEmpleado(Empleado *emp)
{ // Elimina un empleado del arreglo de empleados de la empresa y deja la posicion apuntando a NULL.
    for (int i = 0; i < MAX_EMPLEADO; i++)
    {
        if (this->empleados[i] == emp)
        {
            this->empleados[i] = NULL;
            delete emp;
        }
    }
}

float Empresa::total_sueldo_peso()
{ // Recorro areglo de empleados de la empresa y sumo todos los sueldos.

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
float Empresa::total_sueldo_dolar()
{ // Recorro areglo de empleados de la empresa y sumo todos los sueldos.
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

Empleado *Empresa::buscar_empleado(string CI)
{ // Busca un empleado con la cedula dada dentro de el arreglo de empleados en la empresa.
    for (int i = 0; i < MAX_EMPLEADO; i++)
    {
        if (this->empleados[i] != NULL)
        {
            if (this->empleados[i]->getCi() == CI)
            {
                return this->empleados[i];
            }
        }
    }
    return NULL;
}

list<DTEmpleado> Empresa::listar_empleados()
{
    list<DTEmpleado> listDT;

    for (int i = 0; i < MAX_EMPLEADO; i++)
    {
        if (this->empleados[i] != NULL)
        {
            DTEmpleado dtemp(this->empleados[i]);
            listDT.push_front(dtemp);
        }
    }
    return listDT;
}

Empresa::~Empresa()
{ // Borra todos los empleados contenidos en la empresa.
    for (int i = 0; i < MAX_EMPLEADO; i++)
    {
        if (this->empleados[i] != NULL)
        {
            removEmpleado(this->empleados[i]);
        }
    }
}