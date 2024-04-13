#include "Empresa.h"
#include "Empleado.h"
#include "Jornalero.h"
#include "Fijo.h"
#include "Paga.h"
#include "DTEmpleado.h"
#include "DTEmpresa.h"
#include "moneda.h"
#include "definiciones.h"

#include <list>
#include <string>
#include "iostream"

using namespace std;

int main()
{

    Empresa *e = new Empresa("string nombre", "string nombre_legal", 15);
    cout << e->getNombre() << "\n";
    Paga p = Paga(1000, us);
    Jornalero *j = new Jornalero("aaa", "0000", 40, e, p, 10);
    Jornalero *j2 = new Jornalero("aaa", "0000", 40, e, p, 5);

    cout << e->total_sueldo_dolar();

    list<Empresa*> *listaEmpresas = new list<Empresa*>;
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
            bool exi1 = false;
            cout << "\t \t Registro de empresa.\n\n\n";
            cout << " - A continuacion siga los pasos para dar registro a su nueva empresa.\n";
            do
            {
                string nomE, RS, save;
                int rut;

                cout << "\n Ingrese un nombre para su empresa: ";
                cin >> nomE;
                cout << "\n Ingrese la razon social de su empresa: ";
                cin >> RS;
                cout << "\n Engrese el numero de rut: ";
                cin >> rut;
                cout << "\n"
                        "\n \tGuardar nueva empresa?  S/N: ";
                cin >> save;
                if (save == "s" || save == "S")
                {
                    string otraE;

                    Empresa *e = new Empresa(nomE, RS, rut);
                    listaEmpresas->push_front(e);

                    cout << "\n Desea ingresar una nueva empresa al sistema? S/N: ";
                    cin >> otraE;
                    if (otraE != "S" && otraE != "s")
                    {
                        exi1 = true;
                    }
                }
                else
                {
                    string otraE;

                    cout << "\n Desea ingresar una nueva empresa al sistema? S/N: ";
                    cin >> otraE;
                    if (otraE != "S" && otraE != "s")
                    {
                        exi1 = true;
                    }
                }
            } while (!exi1);
        }
        else if (opt == 2)
        {
            int y, rut;
            string RS;
            Empresa *emp = NULL;
            cout << "\t\t Sistema de empresas.\n";
            cout << "\n Buscar empresa por RUT o RAZON SOCIAL: \n\t[1] RUT / [2] RAZON SOCIAL : ";
            cin >> y;
            int a = listaEmpresas->size();
            cout << "     llll " << a << "-----";
            if (y == 1)
            {
                cout << "\n Ingrese el RUT de la empresa a ingresar: ";
                cin >> rut;
                for (auto &&e : *listaEmpresas)
                {
                    cout << "busco";
                    if (e->getRut() == rut)
                    {
                         emp = e;
                        cout << "encontro";
                        break;
                    }
                }
            }
            else if (y == 2)
            {
                cout << "\n Ingrese la RAZON SOCIAL de la empresa a ingresar: ";
                cin >> RS;
                for (Empresa* e : *listaEmpresas)
                {
                    if (e->getNombre_legal() == RS)
                    {
                        emp = e;
                        break;
                    }
                }
            }
            else
            {
                cout << "\n \t\tOpcion invalida!!!";
            }
            if (emp == NULL)
            {
                cout << "\n\n No se encontro la empresa en el sistema. \n";
            }
            else
            {
                bool salEmpl = false;
                do
                {
                    int optEmp;
                    cout << "\n\t\t -- " << emp->getNombre() << " --\n\n";
                    cout << " [1] - Ver datos de la empresa. \n";
                    cout << " [2] - Ingresar nuevo empleado.\n";
                    cout << " [3] - Ver empleado en el sistema. \n";
                    cout << " [4] - Quitar empledo de empresa. \n";
                    cout << " [5] - Egresos mensuales en concepto de sueldo. \n";
                    cout << " [6] - Salir. \n\n";
                    cout << "[Opcion] ~ ";
                    cin >> optEmp;
                    if (optEmp == 1)
                    {
                        bool salgo = false;
                        string a;
                        do{
                        DTEmpresa dte = DTEmpresa(emp);
                        cout << "\n\n Nombre: " << dte.getNombre() << "\n";
                        cout << " Razon social: " << dte.getNombre_legal() << "\n";
                        cout << " Rut: " << dte.getRut() << "\n\n";
                        cout << "\n [ Salir -S ] : ";
                        cin >> a;
                        if(a == "s" || a=="S"){
                            salgo = true;
                        }                        
                        }while (!salgo);
                        
                    }
                    else if (optEmp == 2)
                    {
                        bool exitEmple = false;
                        cout << "\t \t Registro de empleado.\n\n\n";
                        cout << " - A continuacion siga los pasos para dar registro a un nuevo empleado.\n";
                        do
                        {
                            string nombre, CI, save;
                            int edad, monto_hora, horasT, auxMoneda, auxTipo, cant_horas;
                            moneda mon = us;

                            cout << "\n Elija el tipo de empleado a ingresar: 1- Jornalero/ 2- Fijo :";
                            cin >> auxTipo;
                            cout << "\n Ingrese el nombre: ";
                            cin >> nombre;
                            cout << "\n Ingrese la C.I: ";
                            cin >> CI;
                            cout << "\n Ingrese la edad: ";
                            cin >> edad;
                            cout << "\n Ingrese el sueldo por hora del empleado: ";
                            cin >> monto_hora;
                            cout << "\n Elija el tipo de cambio para el sueldo seleccionado: 1- Pesos/ 2-Dolares : ";
                            cin >> auxMoneda;
                            if (auxMoneda == 1)
                            {
                                mon = us;
                            }
                            else if (auxMoneda == 2)
                            {
                                mon = usd;
                            }
                            if (auxTipo == 1)
                            {
                                cout << "\n Ingrese la cantidad de horas que trabajara el jornalero: ";
                                cin >> cant_horas;
                            }
                            cout << "\n \tGuardar nuevo Empleado?  S/N: ";
                            cin >> save;
                            if (save == "s" && save == "S")
                            {
                                string otroEmpl;
                                Paga p = Paga(monto_hora, mon);
                                if (auxTipo == 1)
                                {
                                    Jornalero *j = new Jornalero(nombre, CI, edad, emp, p, horasT);
                                }
                                else if (auxTipo == 2)
                                {
                                    Fijo *f = new Fijo(nombre, CI, edad, emp, p);
                                }
                                cout << "\n Desea ingresar un nuevo empleado al sistema? S/N: ";
                                cin >> otroEmpl;
                                if (otroEmpl != "S" && otroEmpl != "s")
                                {
                                    exitEmple = true;
                                }
                            }
                            else
                            {
                                string otroE;

                                cout << "\n Desea ingresar un nuevo empleado al sistema? S/N: ";
                                cin >> otroE;
                                if (otroE != "S" && otroE != "s")
                                {
                                    exitEmple = true;
                                }
                            }
                        } while (!exitEmple);
                    }
                    else if (optEmp == 3)
                    {
                        string cedula;
                        cout << "\n Ingrese la cedula de identidad del empleado que desea buscar: ";
                        cin >> cedula;
                        Empleado *empleado = emp->buscar_empleado(cedula);
                        if (empleado == NULL)
                        {
                            cout << "\n No se encontro el empleado en el sistema. ";
                        }
                        else
                        {
                            DTEmpleado dtemple = DTEmpleado(empleado);
                            cout << "\n\t\t Empleados: \n"
                                 << emp->getNombre();
                            cout << "\n\n";
                            cout << "\n Nombre: " << dtemple.getNombre();
                            cout << "\n Cedula de identidad: " << dtemple.getCi();
                            cout << "\n Edad: " << dtemple.getEdad();
                            cout << "\n Sueldo mensual: " << dtemple.getSueldoMensual();
                            cout << "\n\n";
                        }
                    }
                    else if (optEmp == 4)
                    {
                        string cedula;
                        cout << "\n Ingrese la cedula de identidad del empleado que desea buscar: ";
                        cin >> cedula;
                        Empleado *empleado = emp->buscar_empleado(cedula);
                        if (empleado == NULL)
                        {
                            cout << "\n No se encontro el empleado en el sistema. ";
                        }
                        else
                        {
                            emp->removEmpleado(empleado);
                            cout << "\n El empleado a sido eliminado de la empresa. ";
                        }
                    }
                    else if (optEmp == 5)
                    {
                        cout << "\n\t\t Total de sueldos empresa.\n\n";
                        cout << "\n Ingrese el tipo de moneda en el que quiere calcular: [1] - Pesos/ [2] - Dolares: ";
                    }
                    else
                    {
                        salEmpl = true;
                    }

                } while (!salEmpl);
            }
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