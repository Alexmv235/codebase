#ifndef  PLANETA_H
#define PLANETA_H
#include <iostream>
#include "satellite.h"
using namespace std;

class Planeta {

private:
	string nombre;
	float tamano;
	string composicion;
	bool atmosfera, habitable;
	Satelite satelites[100];

public:
	Planeta();
	~Planeta();

//Metodos SET y GET para cada atributo.

	void setNombre(string n);
	string getNombre();
	void setTamano(float t);
	float getTamano();
	float rotacion();
	float translacion();

};

#endif // ! PLANETA_H
