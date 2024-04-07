todo: main.o Empleado.o Empresa.o Fijo.o Jornalero.o paga.o
	g++ -o main main.o Empleado.o Empresa.o Fijo.o Jornalero.o paga.o

main.o: main.cpp
	g++ -c main.cpp

Empleado.o: Empleado.h Empleado.cpp
	g++ -c Empleado.cpp

Empresa.o: Empresa.h Empresa.cpp
	g++ -c Empresa.cpp

Jornalero.o: Jornalero.h Jornalero.cpp
	g++ -c Jornalero.cpp

limpiar:
	rm *.o
	rm main