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
    list<Empresa *> *listaEmpresas = new list<Empresa *>;
    bool salir = false;
    int opt;
    do
    {

        cout << "\n\n\t \t ++ Sistema de sueldos. ++ \n\n\n";
        cout << "> [1] Nueva empresa.\n";
        cout << "> [2] Ingresar en empresa.\n";
        cout << "> [3] Quitar empresa del sistema.\n";
        cout << "> [4] Salir.\n\n";
        cout << "[Opcion] ~ ";
        cin >> opt;

        if (opt == 1)
        {
            bool exit_1 = false;
            string nomE, RS, save;
            int rut;

            cout << "\t \t ++ Registro de empresa. ++\n\n\n";
            cout << " - A continuacion siga los pasos para dar registro a su nueva empresa.\n";
            do
            {
                string nomE, RS, save;
                int rut;

                cout << "\n >> Ingrese un nombre para su empresa: ";
                cin >> nomE;
                cout << "\n >> Ingrese la razon social de su empresa: ";
                cin >> RS;
                cout << "\n >> Engrese el numero de rut: ";
                cin >> rut;
                cout << "\n"
                        "\n \t\t -- Guardar nueva empresa? -- [S/N]: ";
                cin >> save;
                if (save == "s" || save == "S")
                {
                    string otraE;
                    Empresa *e = new Empresa(nomE, RS, rut);

                    listaEmpresas->push_front(e);

                    cout << "\n \t -- Desea ingresar una nueva empresa al sistema? -- [S/N]: ";
                    cin >> otraE;
                    if (otraE != "S" && otraE != "s")
                    {

                        exit_1 = true;
                    }
                }
                else
                {
                    string otraE;

                    cout << "\n \t -- Desea ingresar una nueva empresa al sistema? -- [S/N]: ";
                    cin >> otraE;
                    if (otraE != "S" && otraE != "s")
                    {
                        exit_1 = true;
                    }
                }
            } while (!exit_1);
        }
        else if (opt == 2)
        {
            int y, rut;
            string RS;
            Empresa *emp = NULL;
            cout << "\n\n\t\t ++ Sistema de empresas. ++ \n";
            cout << "\n > Buscar empresa por RUT o RAZON SOCIAL:  [1-RUT / 2-RAZON SOCIAL] : ";
            cin >> y;
            if (y == 1)
            {
                cout << "\n >> Ingrese el RUT de la empresa a ingresar: ";
                cin >> rut;
                for (auto &&e : *listaEmpresas)
                {
                    if (e->getRut() == rut)
                    {
                        emp = e;
                        break;
                    }
                }
            }
            else if (y == 2)
            {
                cout << "\n >> Ingrese la RAZON SOCIAL de la empresa a ingresar: ";
                cin >> RS;
                for (Empresa *e : *listaEmpresas)
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
                cout << "\n \t\t -- Opcion invalida!!! --";
            }
            if (emp == NULL)
            {
                cout << "\n\n \t\t -- No se encontro la empresa en el sistema. --\n";
            }
            else
            {
                bool exit_2 = false;
                DTEmpresa dtempresa(emp);
                do
                {
                    int optEmp;
                    cout << "\n\n\t\t ++ Sistema de gestion de " << emp->getNombre() << " ++\n\n";
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
                        bool exit_2_1 = false;
                        string a;
                        do
                        {
                            dtempresa.detalles_empresa();
                            cout << "\n [ Salir -S ] : ";
                            cin >> a;
                            if (a == "s" || a == "S")
                            {
                                exit_2_1 = true;
                            }
                        } while (!exit_2_1);
                    }
                    else if (optEmp == 2)
                    {
                        bool exit_2_2 = false;
                        cout << "\n\n\t \t ++ Registro de empleado. ++ \n\n\n";
                        cout << " - A continuacion siga los pasos para dar registro a un nuevo empleado. -\n";
                        do
                        {
                            string nombre, CI, save;
                            int edad, monto_hora, horasT, auxMoneda, auxTipo, cant_horas;
                            moneda mon = us;

                            cout << "\n >> Elija el tipo de empleado a ingresar: [1- Jornalero/ 2- Fijo] :";
                            cin >> auxTipo;
                            cout << "\n >> Ingrese el nombre: ";
                            cin >> nombre;
                            cout << "\n >> Ingrese la C.I: ";
                            cin >> CI;
                            cout << "\n >> Ingrese la edad: ";
                            cin >> edad;
                            cout << "\n >> Ingrese el sueldo por hora del empleado: ";
                            cin >> monto_hora;
                            cout << "\n >> Elija el tipo de cambio para el sueldo seleccionado: [1- Pesos/ 2-Dolares] : ";
                            cin >> auxMoneda;
                            if (auxMoneda == 1)
                            {
                                mon = us;
                            }
                            else if (auxMoneda == 2)
                            {
                                mon = usd;
                            }
                            else
                            {
                                cout << "\n \t\t -- Tipo de moneda incorrecta!!! -- ";
                            }
                            if (auxTipo == 1 || auxTipo == 2)
                            {
                                if (auxTipo == 1)
                                {
                                    cout << "\n >> Ingrese la cantidad de horas que trabajara el jornalero: ";
                                    cin >> cant_horas;
                                }
                            }
                            else
                            {
                                cout << "\n \t\t --Tipo de empleado invalido!!! -- ";
                            }
                            cout << "\n \t \t --Guardar nuevo Empleado?-- [S/N] : ";
                            cin >> save;
                            if (save == "s" || save == "S")
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
                                cout << "\n \t\t --Desea ingresar un nuevo empleado al sistema?-- [S/N] : ";
                                cin >> otroEmpl;
                                if (otroEmpl != "S" && otroEmpl != "s")
                                {
                                    exit_2_2 = true;
                                }
                            }
                            else
                            {
                                string otroE;

                                cout << "\n \t\t --Desea ingresar un nuevo empleado al sistema?-- [S/N] : ";
                                cin >> otroE;
                                if (otroE != "S" && otroE != "s")
                                {
                                    exit_2_2 = true;
                                }
                            }
                        } while (!exit_2_2);
                    }
                    else if (optEmp == 3)
                    {
                        string cedula;

                        cout << "\n\n\t \t ++ Buscar empleado. ++ \n\n\n";
                        cout << "\n >> Ingrese la cedula de identidad del empleado que desea buscar: ";
                        cin >> cedula;
                        Empleado *empleado;
                        empleado = emp->buscar_empleado(cedula);
                        if (empleado == NULL)
                        {
                            cout << "\n \t\t -- No se encontro el empleado en el sistema. -- ";
                        }
                        else
                        {
                            DTEmpleado dtemple(empleado);
                            dtemple.mostrar_datos_empleados();
                            cout << "\n\t\t Empleados: \n"
                                 << dtempresa.getNombre();
                        }
                    }
                    else if (optEmp == 4)
                    {
                        string cedula;
                        cout << "\n\n\t \t ++ Eliminar empleado. ++ \n\n\n";
                        cout << "\n >> Ingrese la cedula de identidad del empleado que desea eliminar: ";
                        cin >> cedula;
                        Empleado *empleado = emp->buscar_empleado(cedula);
                        if (empleado == NULL)
                        {
                            cout << "\n \t\t --No se encontro el empleado en el sistema.-- ";
                        }
                        else
                        {
                            string aux;
                            cout << "\n \t\t --Desea Quitar a " << empleado->getNombre() << " de la Empresa " << dtempresa.getNombre() << "-- [S/N] :";
                            cin >> aux;
                            if (aux == "s" || aux == "S")
                            {
                                emp->removEmpleado(empleado);
                                cout << "\n\t\t --El empleado a sido eliminado de la empresa!!!-- ";
                            }
                        }
                    }
                    else if (optEmp == 5)
                    {
                        int aux;
                        cout << "\n\t\t ++ Total de sueldos a pagar por." << dtempresa.getNombre() << " ++\n\n";
                        cout << "\n Ingrese el tipo de moneda en el que quiere calcular: [1- Pesos/ 2- Dolares]: ";
                        cin >> aux;
                        if (aux == 1)
                        {
                            dtempresa.mostrar_total_pesos();
                        }
                        else if (aux == 2)
                        {
                            dtempresa.mostrar_total_dolares();
                        }
                        else
                        {
                            cout << "\n \t\t-- Opcion invalida!!! --";
                        }
                    }
                    else
                    {
                        exit_2 = true;
                    }

                } while (!exit_2);
            }
        }
        else if (opt == 3)
        {
            int y, rut;
            string RS;
            Empresa *emp = NULL;
            cout << "\n\t\t ++ Eliminar empresas. ++\n\n";
            cout << "\n Buscar empresa por RUT o RAZON SOCIAL: [1-RUT / 2-RAZON SOCIAL]: ";
            cin >> y;
            if (y == 1)
            {
                cout << "\n >> Ingrese el RUT de la empresa a eliminar: ";
                cin >> rut;
                for (auto *e : *listaEmpresas)
                {
                    if (e->getRut() == rut)
                    {
                        emp = e;
                        break;
                    }
                }
            }
            else if (y == 2)
            {
                cout << "\n >> Ingrese la RAZON SOCIAL de la empresa a eliminar: ";
                cin >> RS;
                for (Empresa *e : *listaEmpresas)
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
                cout << "\n \t\t-- Opcion invalida!!! --";
            }
            if (emp == NULL)
            {
                listaEmpresas->remove(emp);
                delete emp;
                cout << "\n\n \t\t-- No se encontro la empresa en el sistema. -- \n";
            }
            else
            {
                listaEmpresas->remove(emp);
                delete emp;
            }
        }
        else
        {
            salir = true;
        }
    } while (salir == false);

    return 0;
}