#ifndef CONTENEDOR_H
#define CONTENEDOR_H

#include "Planeta.h"
#include <iostream>
#include <sstream>
using namespace std;

class Contenedor {
private:
	Planeta planetas[30];
	int tamano;
	int cantidad;
public:
	Contenedor(int );
	int getCantidad();
	int getTamano();
	void setCantidad(int);
	void setTamano(int);
	void insertarElemento(string);
	string toString();
};

#endif