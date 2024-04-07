#include <string>
#include "Empresa.h"
using namespace std;

class Empleado
{
private:
    string nombre;
    string ci;
    int edad;
    Paga valor_hora;
    Empresa * emp;
public:
    Empleado();
    Empleado(string, string, int, Empresa, Paga);

    void setNombre(string);
    void setCi(string);
    void setEdad(int);
    void setValor_hora(Paga);
    
    string getNombre();
    string getCi();
    int getEdad();
    Paga getValorhora();

virtual int get_sueldo_peso()=0;
virtual int get_sueldo_dolar()=0;
virtual ~Empleado();

};

