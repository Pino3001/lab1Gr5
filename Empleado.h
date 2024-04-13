#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>
#include "Empresa.h"
#include "Paga.h"
#include "Cambio.h"
using namespace std;

class Empleado
{
private:
    string nombre;
    string ci;
    int edad;
    Paga valor_hora;
    Empresa * empresa;
public:
    Empleado();
    Empleado(string nombre, string ci, int edad, Empresa* empresa, Paga valor_hora);

    void setNombre(string);
    void setCi(string);
    void setEdad(int);
    void setValor_hora(Paga);
    void setEmpresa(Empresa*);
    
    string getNombre();
    string getCi();
    int getEdad();
    Paga getValorhora();
    Empresa* getEmpresa();

virtual float get_sueldo_peso()=0;
virtual float get_sueldo_dolar()=0;
virtual ~Empleado();

};
#endif