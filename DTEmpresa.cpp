#include "DTEmpresa.h"
#include "Empresa.h"
#include "iostream"
#include <string>

using namespace std;

DTEmpresa::DTEmpresa()
{
    this->nombre = "None";
    this->nombre_legal = "None";
    this->rut = 0;
    this->total_sueldos_peso = 0;
    this->total_sueldos_dolar = 0;
}

DTEmpresa::DTEmpresa(Empresa *empresa)
{
    this->nombre = empresa->getNombre();
    this->nombre_legal = empresa->getNombre_legal();
    this->rut = empresa->getRut();
    // Setea el gasto total de la empresa en concepto de sueldo a unos de sus atributos.
    this->total_sueldos_peso = empresa->total_sueldo_peso();
    // Setea el gasto total de la empresa en concepto de sueldo a unos de sus atributos.
    this->total_sueldos_dolar = empresa->total_sueldo_dolar();
}

string DTEmpresa::getNombre()
{
    return this->nombre;
}

string DTEmpresa::getNombre_legal()
{
    return this->nombre_legal;
}

int DTEmpresa::getRut()
{
    return this->rut;
}
float DTEmpresa::getTotal_sueldos_peso()
{
    return this->total_sueldos_peso;
}
float DTEmpresa::getTotal_sueldos_dolar()
{
    return this->total_sueldos_dolar;
}

void DTEmpresa::detalles_empresa()
{ // Muestra los detalles de la empresa. 
    cout << "\t ############################### "; 
    cout << "\n\n\t-- Nombre: " << this->getNombre() << "\n";
    cout << "\t-- Razon social: " << this->getNombre_legal() << "\n";
    cout << "\t-- Rut: " << this->getRut() << "\n\n";
    cout << "\t ############################### \n\n"; 
}
void DTEmpresa::mostrar_total_pesos()
{ // Muestra el gasto total de la empresa en pesos.
    cout << "\n\n"
         << "Gasto total de "
         << this->getNombre();
    cout << " en concepto de sueldos es de "
         << this->getTotal_sueldos_peso()
         << " us. \n\n";
}
void DTEmpresa::mostrar_total_dolares()
{ // Muestra el gasto total de la empresa en dolares.
    cout << "\n\n"
         << "Gasto total de "
         << this->getNombre();
    cout << " en concepto de sueldos es de "
         << this->getTotal_sueldos_dolar()
         << " us. \n\n";
}