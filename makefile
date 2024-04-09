todo: main.o Empleado.o Empresa.o Fijo.o Jornalero.o paga.o Cambio.o
	g++ -o main main.o Empleado.o Empresa.o Fijo.o Jornalero.o paga.o Cambio.o

main.o: main.cpp
	g++ -c main.cpp

Empleado.o: Empleado.h Empleado.cpp
	g++ -c Empleado.cpp

Empresa.o: Empresa.h Empresa.cpp
	g++ -c Empresa.cpp

Fijo.o: Fijo.h Fijo.cpp
	g++ -c Fijo.cpp

Jornalero.o: Jornalero.h Jornalero.cpp
	g++ -c Jornalero.cpp

paga.o: paga.h paga.cpp
	g++ -c paga.cpp

Cambio.o: Cambio.h Cambio.cpp
	g++ -c Cambio.cpp

clean:
	rm -f *.o
	rm -f main