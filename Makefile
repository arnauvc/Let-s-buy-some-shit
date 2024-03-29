# MAKEFILE: utilidad para preparar ejecutables en los que intervienen
# varias clases, de forma que con una unica instruccion se compilan o linkan
# los ficheros estrictamente necesarios.


all: Supermercat.o Client.o Producte.o Rellotge.o program.o program.exe
	
Supermercat.o: Supermercat.cc Supermercat.hh
	g++ -g -c Supermercat.cc -D_GLIBCXX_DEBUG
 
Client.o: Client.cc Client.hh
	g++ -g -c Client.cc -D_GLIBCXX_DEBUG
 
Producte.o: Producte.cc Producte.hh
	g++ -g -c Producte.cc -D_GLIBCXX_DEBUG
 
Rellotge.o: Rellotge.cc Rellotge.hh
	g++ -g -std=c++11 -c Rellotge.cc -D_GLIBCXX_DEBUG
 
program.o: program.cc
	g++ -g -c program.cc -D_GLIBCXX_DEBUG
 
program.exe: Supermercat.o Client.o Producte.o Rellotge.o program.o
	g++ -o program.exe Supermercat.o Client.o Producte.o Rellotge.o program.o
	
#practica.tar: 	Supermercat.hh Supermercat.cc Makefile program.cc Rellotge.hh Rellotge.cc Client.hh Client.cc Producte.hh Producte.cc
	tar -cvf practica.tar Supermercat.hh Supermercat.cc Makefile program.cc Rellotge.hh Rellotge.cc Client.hh Client.cc Producte.hh Producte.cc

clean:
	rm *.o
	rm *.exe
