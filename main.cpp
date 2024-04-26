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

            cout << "\n\t \t ++ Registro de empresa. ++\n\n\n";
            cout << " - A continuacion siga los pasos para dar registro a su nueva empresa.";
            do
            {
                string nomE, RS, save;
                int rut;

                cin.ignore(); // Limpiar entrada para el getline;
                cout << "\n\n >> Ingrese un nombre para su empresa: ";
                getline(cin, nomE); // Toma toda la entrada de linea, incluyendo los espacios.
                cout << "\n >> Ingrese la razon social de su empresa: ";
                getline(cin, RS);
                cout << "\n >> Ingrese el numero de rut: ";
                cin >> rut;
                cout << "\n"
                        "\n \t\t -- Guardar nueva empresa? -- [S/N]: ";
                cin >> save;
                if (save == "s" || save == "S")
                {
                    string otraE;
                    Empresa *e = new Empresa(nomE, RS, rut);
                    // Ingreso la empresa en la lista arriba definida.
                    listaEmpresas->push_front(e);

                    cout << "\n \t -- Desea ingresar una nueva empresa al sistema? -- [S/N]: ";
                    cin >> otraE;
                    if (otraE != "S" && otraE != "s")
                    { // Si no se desea ingresar nuevas empresas, salgo de la iteracion.
                        exit_1 = true;
                    }
                }
                else
                {
                    string otraE;
                    // Si no se desea ingresar nuevas empresas, salgo de la iteracion.
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
            cout << "\n > Buscar empresa, por RUT o RAZON SOCIAL:  [1-RUT / 2-RAZON SOCIAL] : ";
            cin >> y;

            if (y == 1)
            { // Busco empresa por RUT.
                cout << "\n >> Ingrese el RUT de la empresa a ingresar: ";
                cin >> rut;
                for (auto *e : *listaEmpresas)
                {
                    if (e->getRut() == rut)
                    { // Encontre la empresa en la lista.
                        emp = e;
                        break;
                    }
                }
            }
            else if (y == 2)
            { // Busco empresa por su razon social.
                cout << "\n >> Ingrese la RAZON SOCIAL de la empresa a ingresar: ";
                cin >> RS;
                for (Empresa *e : *listaEmpresas)
                {
                    if (e->getNombre_legal() == RS)
                    { // Encontre la empresa en la lista.
                        emp = e;
                        break;
                    }
                }
            }

            if (y != 2 && y != 1)
            {
                cout << "\n \t\t -- Opcion invalida!!! -- \n";
            }
            else if (emp == NULL)
            {
                cout << "\n \t\t -- No se encontro la empresa en el sistema. --\n";
            }
            else
            { // Se encontro la empresa a buscar, entra en las opciones para interactuar con esta empresa encontrada.
                bool exit_2 = false;
                do
                {
                    int optEmp;
                    DTEmpresa dtempresa(emp);
                    cout << "\n\n\t\t ++ Sistema de gestion de \"" << emp->getNombre() << "\" ++\n\n";
                    cout << " [1] - Ver datos de la empresa. \n";
                    cout << " [2] - Ingresar nuevo empleado.\n";
                    cout << " [3] - Ver empleado en el sistema. \n";
                    cout << " [4] - Quitar empledo de empresa. \n";
                    cout << " [5] - Egresos mensuales en concepto de sueldo. \n";
                    cout << " [6] - Salir. \n\n";
                    cout << "[Opcion] ~ ";
                    cin >> optEmp;

                    if (optEmp == 1)
                    { // Muestra los datos de la empresa.
                        bool exit_2_1 = false;
                        string a;
                        do
                        { // Mantengo los datos Empresa.
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
                    { // Ingresa un empleado a la empresa.
                        bool exit_2_2 = false;

                        cout << "\n\n\t \t ++ Registro de empleado. ++ \n\n\n";
                        cout << " - A continuacion siga los pasos para dar registro a un nuevo empleado. -\n";
                        do
                        {
                            string nombre, CI, save;
                            int edad, monto_hora, auxMoneda, auxTipo, cant_horas;
                            moneda mon = us;

                            cout << "\n >> Elija el tipo de empleado a ingresar: [1- Jornalero/ 2- Fijo] :";
                            cin >> auxTipo;
                            cout << "\n >> Ingrese el nombre: ";
                            cin.ignore();
                            getline(cin, nombre);
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
                                cout << "\n \t\t -- Tipo de cambio se coloco automaticamente en us!!! -- ";
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
                                { // Ingresa un empleado de tipo Jornalero.
                                    Jornalero *j = new Jornalero(nombre, CI, edad, emp, p, cant_horas);
                                }
                                else if (auxTipo == 2)
                                { // Ingresa un empleado de tipo Fijo.
                                    Fijo *f = new Fijo(nombre, CI, edad, emp, p);
                                }

                                cout << "\n \t\t --Desea ingresar un nuevo empleado al sistema?-- [S/N] : ";
                                cin >> otroEmpl;

                                if (otroEmpl != "S" && otroEmpl != "s")
                                { // No se desea ingresar nuevos empleados.
                                    exit_2_2 = true;
                                }
                            }
                            else
                            {
                                string otroE;

                                cout << "\n \t\t --Desea ingresar un nuevo empleado al sistema?-- [S/N] : ";
                                cin >> otroE;
                                if (otroE != "S" && otroE != "s")
                                { // No se desea ingresar nuevos empleados.
                                    exit_2_2 = true;
                                }
                            }
                        } while (!exit_2_2);
                    }
                    else if (optEmp == 3)
                    { // Muestra los detalles de un empleado a buscar.
                        string cedula;
                        int optc;
                        Empleado *empleado;

                        cout << "\n\n\t \t ++ Buscar empleado. ++ \n\n";
                        cout << "\n [1] Listar empleados de la empresa.";
                        cout << "\n [2] Buscar un empleado. \n\n";
                        cout << "[Opcion] ~ ";
                        cin >> optc;

                        if (optc == 1)
                        {
                            list<DTEmpleado> listDtEmp;
                            listDtEmp = emp->listar_empleados();
                            for (auto ldt : listDtEmp)
                            {
                                ldt.mostrar_datos_empleados();
                            }
                            cout << "\n";
                        }
                        else
                        {
                            cout << "\n >> Ingrese la cedula de identidad del empleado que desea buscar: ";
                            cin >> cedula;
                            // Busca el empleado dentro de la empresa.
                            empleado = emp->buscar_empleado(cedula);

                            if (empleado == NULL)
                            { // No encontro el empleado
                                cout << "\n \t\t -- No se encontro el empleado en el sistema. -- ";
                            }
                            else
                            { // Encontre empleado y creo un Datatype para mostrar sus detalles.
                                DTEmpleado dtemple(empleado);
                                dtemple.mostrar_datos_empleados();
                            }
                        }
                    }
                    else if (optEmp == 4)
                    { // Elimina un empleado de la empresa.
                        string cedula;
                        Empleado *empleado;

                        cout << "\n\n\t \t ++ Eliminar empleado. ++ \n\n\n";
                        cout << "\n >> Ingrese la cedula de identidad del empleado que desea eliminar: ";
                        cin >> cedula;

                        empleado = emp->buscar_empleado(cedula);

                        if (empleado == NULL)
                        { // No encontre empleado.
                            cout << "\n \t\t --No se encontro el empleado en el sistema.-- ";
                        }
                        else
                        { // Encontre
                            string aux;

                            cout << "\n \t\t --Desea Quitar a " << empleado->getNombre() << " de la Empresa " << dtempresa.getNombre() << "-- [S/N] :";
                            cin >> aux;

                            if (aux == "s" || aux == "S")
                            { // Llamo a una funcion de Empresa que me elimina un empleado de la empresa.
                                emp->removEmpleado(empleado);
                                cout << "\n\t\t --El empleado a sido eliminado de la empresa!!!-- ";
                            }
                        }
                    }
                    else if (optEmp == 5)
                    { // Calculo el gasto de la empresa sumando el sueldo de todos sus empleados.
                        int aux;

                        cout << "\n\t\t ++ Total de sueldos a pagar por.\" " << dtempresa.getNombre() << "\"  ++\n\n";
                        cout << "\n Ingrese el tipo de moneda en el que quiere calcular: [1- Pesos/ 2- Dolares]: ";
                        cin >> aux;

                        if (aux == 1)
                        { // Calculo en pesos.
                            cout << "\n\n || El gasto semanal de la empresa en concepto de sueldo es de: "
                                 << emp->total_sueldo_peso() << " Pesos. || \n";
                        }
                        else if (aux == 2)
                        { // Calculo en dolares.
                            cout << "\n\n || El gasto semanal de la empresa en concepto de sueldo es de: "
                                 << emp->total_sueldo_dolar() << " Dolares. || \n";
                        }
                        else
                        {
                            cout << "\n \t\t-- Opcion invalida!!! --";
                        }
                    }
                    else
                    { // Salgo del menu de la empresa.
                        exit_2 = true;
                    }

                } while (!exit_2);
            }
        }
        else if (opt == 3)
        { // Elimina una empresa de la lista.
            int y, rut;
            string RS;
            Empresa *emp = NULL;

            cout << "\n\t\t ++ Eliminar empresa. ++\n\n";
            cout << "\n Buscar empresa por RUT o RAZON SOCIAL: [1-RUT / 2-RAZON SOCIAL]: ";
            cin >> y;

            if (y == 1)
            { // Busco la empresa por Rut.
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
            { // Busco la empresa por su razon social.
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
            { // No se encontro la empresa.
                cout << "\n\n\n  \t\t-- No se encontro la empresa en el sistema. -- \n";
            }
            else
            {
                char save;
                cout << "\n \t\t --Desea Quitar a " << emp->getNombre() << " del sistema? "
                     << "-- [S/N] :";
                if (save == 's' || save == 'S')
                {
                    listaEmpresas->remove(emp); // Quito de la lista.
                    delete emp;                 // Elimina la instancia de empresa, junto con los de Empleados asociados.
                    cout << "\n \t\t --Se a quitado la empresa del sistema. ";
                }
            }
        }
        else
        { // Salgo del sistema.
            salir = true;
        }
    } while (salir == false);

    return 0;
}