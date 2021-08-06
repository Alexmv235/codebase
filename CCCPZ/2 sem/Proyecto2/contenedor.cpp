#include <iostream>
#include "contenedor.h"

Contenedor::Contenedor(int n) {
	cantidad = 0;
	tamano = n;
	for(int i = 0; i < tamano; i++)
		hilera[i] = ' ';
	
}
int Contenedor::getCantidad() {
	return this->cantidad;
}
int Contenedor::getTamano() {
	return this->tamano;
}
void Contenedor::setCantidad(int cantidad) {
	this->cantidad = cantidad;
}
void Contenedor::setTamano(int tamano) {
	this->tamano = tamano;
}
void Contenedor::insertarElemento(char elem) {
	if (cantidad < tamano) {
		hilera[cantidad] = elem;
		cantidad++;
	}
}
string Contenedor::toString() {
	stringstream s;
	for (int i = 0; i < cantidad; i++)
		s << hilera[i];
	s << endl;
	return s.str();
	}

