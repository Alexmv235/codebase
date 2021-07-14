#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include <iostream>
#include <sstream>
using namespace std;
class Contenedor {
private:
	char hilera[30];
	int tamano;
	int cantidad;
public:
	Contenedor(int);
	int getCantidad();
	int getTamano();
	void setCantidad(int);
	void setTamano(int);
	void insertarElemento(char);
	string toString();
};

#endif
