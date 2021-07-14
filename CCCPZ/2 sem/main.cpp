#include <iostream>
#include "contenedor.h"
using namespace std; 

int main(int argc, char *argv[]) {
	Contenedor palabra(15);
	palabra.insertarElemento('A');
	cout<<palabra.toString() <<endl;
	return 0;
}

