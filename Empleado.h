#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include "Empresa.h"
#include "paga.h"
using namespace std;

class Empleado
{
private:
    string nombre;
    string ci;
    int edad;
    paga valor_hora;
    Empresa * empresa;
public:
    Empleado();
    Empleado(string, string, int, Empresa*, paga);

    void setNombre(string);
    void setCi(string);
    void setEdad(int);
    void setValor_hora(paga);
    void setEmpresa(Empresa*);
    
    string getNombre();
    string getCi();
    int getEdad();
    paga getValorhora();
    Empresa* getEmpresa();

virtual int get_sueldo_peso()=0;
virtual int get_sueldo_dolar()=0;
virtual ~Empleado();

};

#endif