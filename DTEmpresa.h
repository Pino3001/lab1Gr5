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
    float total_sueldos_peso;
    float total_sueldos_dolar;

public:
    DTEmpresa();
    DTEmpresa(Empresa *empresa);

    string getNombre();
    string getNombre_legal();
    int getRut();
    float getTotal_sueldos_peso();
    float getTotal_sueldos_dolar();

    void detalles_empresa();
    void mostrar_total_pesos();
    void mostrar_total_dolares();
};

#endif