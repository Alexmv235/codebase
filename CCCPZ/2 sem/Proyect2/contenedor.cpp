#include <iostream>
#include "contenedor.h"

	SistPlanetario::SistPlanetario(int n) {
		cantidad = 0;
		tamano = n;
		/*for (int i = 0; i < tamano; i++)
			planetas[i] = " ";*/

	}
	int SistPlanetario::getCantidad() {
		return this->cantidad;
	}
	int SistPlanetario::getTamano() {
		return this->tamano;
	}
	void SistPlanetario::setCantidad(int cantidad) {
		this->cantidad = cantidad;
	}
	void SistPlanetario::setTamano(int tamano) {
		this->tamano = tamano;
	}
	void SistPlanetario::setInsertarPlaneta(planeta plan) {
		this->tamano = tamano;
	}
	/* void SistPlanetario::insertarElemento(string elem) {
		if (cantidad < tamano) {
			planetas[cantidad] = elem;
			cantidad++;
		}
	} */
	string SistPlanetario:: toString() {
		stringstream s;
		/*for (int i = 0; i < cantidad; i++)
			s << planetas[i];
		s << endl;*/
		return s.str();
	}
