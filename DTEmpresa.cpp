#include "DTEmpresa.h"
#include "Empresa.h"

#include <string>

using namespace std;

DTEmpresa::DTEmpresa(){
    this->nombre = "None";
    this->nombre_legal = "None";
    this->rut = 0;
}

DTEmpresa::DTEmpresa(Empresa * empresa){
    this->nombre = empresa->getNombre();
    this->nombre_legal = empresa->getNombre_legal();
    this->rut = empresa->getRut();
}

string DTEmpresa::getNombre(){
    return this->nombre;
}

string DTEmpresa::getNombre_legal(){
    return this->nombre_legal;
}

int DTEmpresa::getRut(){
    return this->rut;
}
