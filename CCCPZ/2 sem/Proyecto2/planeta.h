#ifndef PLANETA_H
#define PLANETA_H

#include <iostream>
using namespace std;

class Planeta {
private:
	string nombre[n];
	float tamano;
	string compocision;
	bool atmosfera, habitable;
	int satelite;
public:
	Planeta();
	~Planeta();
	//Metdos set&get
	
	float getTamano();
	void setTamano(int);
	string toString();
	
	//metodos de calculo
	float rotacion;
	float traslacion;
};

#endif
