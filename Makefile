# MAKEFILE: utilidad para preparar ejecutables en los que intervienen
# varias clases, de forma que con una unica instruccion se compilan o linkan
# los ficheros estrictamente necesarios.
#

all: Supermercat.o Client.o Producte.o Rellotge.o main.o main.exe
	
Supermercat.o: Supermercat.cc Supermercat.hh
	g++ -c Supermercat.cc -D_GLIBCXX_DEBUG
 
Client.o: Client.cc Client.hh
	g++ -c Client.cc -D_GLIBCXX_DEBUG
 
Producte.o: Producte.cc Producte.hh
	g++ -c Producte.cc -D_GLIBCXX_DEBUG
 
Rellotge.o: Rellotge.cc Rellotge.hh
	g++ -std=c++11 -c Rellotge.cc -D_GLIBCXX_DEBUG
 
main.o: main.cc
	g++ -c main.cc -D_GLIBCXX_DEBUG
 
main.exe: Supermercat.o Client.o Producte.o Rellotge.o main.o
	g++ -o main Supermercat.o Client.o Producte.o Rellotge.o main.o
	
#practica.tar: 	Agenda.cc Agenda.hh Makefile program.cc Rellotge.cc Rellotge.hh Tasca.cc Tasca.hh
#	tar -cvf practica.tar Agenda.cc Agenda.hh Makefile program.cc Rellotge.cc Rellotge.hh Tasca.cc Tasca.hh
clean:
	rm *.o
	rm *.exe
