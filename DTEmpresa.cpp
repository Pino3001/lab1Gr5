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
}

DTEmpresa::DTEmpresa(Empresa *empresa)
{
    this->nombre = empresa->getNombre();
    this->nombre_legal = empresa->getNombre_legal();
    this->rut = empresa->getRut();
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

void DTEmpresa::detalles_empresa()
{ // Muestra los detalles de la empresa. 
    cout << "\t ############################### "; 
    cout << "\n\n\t-- Nombre: " << this->getNombre() << "\n";
    cout << "\t-- Razon social: " << this->getNombre_legal() << "\n";
    cout << "\t-- Rut: " << this->getRut() << "\n\n";
    cout << "\t ############################### \n\n"; 
}
