todo: main.o Empleado.o Empresa.o Fijo.o Jornalero.o Paga.o Cambio.o DTEmpresa.o DTEmpleado.o
	g++ -o main main.o Empleado.o Empresa.o Fijo.o Jornalero.o Paga.o Cambio.o DTEmpresa.o DTEmpleado.o

main.o: main.cpp
	g++ -c main.cpp

Empresa.o: Empresa.h Empresa.cpp
	g++ -c Empresa.cpp

Empleado.o: Empleado.h Empleado.cpp
	g++ -c Empleado.cpp

Fijo.o: Fijo.h Fijo.cpp
	g++ -c Fijo.cpp

Jornalero.o: Jornalero.h Jornalero.cpp
	g++ -c Jornalero.cpp

Paga.o: Paga.h Paga.cpp
	g++ -c Paga.cpp

Cambio.o: Cambio.h Cambio.cpp
	g++ -c Cambio.cpp

DTEmpresa.o: DTEmpresa.h DTEmpresa.cpp
	g++ -c DTEmpresa.cpp

DTEmpleado.o: DTEmpleado.h DTEmpleado.cpp
	g++ -c DTEmpleado.cpp

clean:
	rm -f *.o
	rm -f main