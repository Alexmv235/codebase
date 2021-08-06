#include "planeta.h"

Planeta::Planeta() {
	//Aqui se construye el objeto

	nombre = "";
	tamano = 1200; //km
	composicion = "rocoso";
	atmosfera = false;
	satelites = 0;
	habitable = false;

}

Planeta::~Planeta() {
}

void Planeta::setNombre(string n)
{
	nombre = n;
}

string Planeta::getNombre()
{
	return nombre;
}

void Planeta::setTamano(float t)
{
	tamano = t;
}

float Planeta::getTamano()
{
	return tamano;
}

float Planeta::rotacion()
{
	int valor = 0;
	if (composicion == "rocoso")
		valor = 25;
	else
		valor = 50;
	return tamano / valor;
}

float Planeta::translacion()
{
	return tamano * (satelites + 1);
}