#include "planeta.h"


Planeta::Planeta(){
	tamano = 1200;
	compocision = "rocoso";
	atmosfera = false;
	satelite = 0;
	habitable = false;
	
Planeta::~Planeta(){}

void Planeta::setTamano(float tamano){
	this->tamano = tamano;
}
float Planeta::getTamano() {
	return this->tamano; }
