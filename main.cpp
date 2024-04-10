#include "Empresa.h"
#include "Empleado.h"
#include "Jornalero.h"
#include "paga.h"
#include "moneda.h"

#include <string>
#include "iostream"
using namespace std;
int main()
{
    Empresa *e = new Empresa("string nombre", "string nombre_legal", 15);
    cout << e->getNombre() << "\n";
    paga p = paga(1000, us);
    Jornalero *j = new Jornalero("aaa", "0000", 40, e, p, 10);
    Jornalero *j2 = new Jornalero("aaa", "0000", 40, e, p, 5);

    cout<<e->total_sueldo_dolar();
    bool salir = false;
    int opt;
    do
    {
        cout << "\t \t Sistema de sueldos.\n\n\n";
        cout << "> [1] Nueva empresa.\n";
        cout << "> [2] Ingresar en empresa.\n";
        cout << "> [3] Quitar empresa del sistema.\n";
        cout << "> [4] Salir.\n\n";
        cout << "[Opcion] ~ ";
        cin >> opt;

        if (opt == 1)
        {
            cout << "\t \t Registro de empresa.\n\n\n";
            /* code */
        }
        else if (opt == 2)
        {
            /* code */
        }
        else if (opt == 3)
        {
            /* code */
        }
        else
        {
            salir = true;
        }
    } while (salir == false);

    return 0;
}