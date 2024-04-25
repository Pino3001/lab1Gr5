#ifndef DTEMPRESA_H
#define DTEMPRESA_H

#include "Empresa.h"
#include <string>

using namespace std;

class DTEmpresa
{
private:
    string nombre;
    string nombre_legal;
    int rut;

public:
    DTEmpresa();
    DTEmpresa(Empresa *empresa);

    string getNombre();
    string getNombre_legal();
    int getRut();

    void detalles_empresa();
};

#endif