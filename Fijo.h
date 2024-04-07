#include <string>
#include "Empleado.h"
using namespace std;

class Fijo : public Empleado
{

public:
    Fijo() : Empleado();
    Fijo(string, string);

    int get_sueldo_peso();
    int get_sueldo_dolar();

    ~Fijo();
}