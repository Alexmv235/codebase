#include "contenedor.h"
#include <iostream>
#include <sstream>
#include "Planeta.h"

using namespace std;

int main(int argc, char* argv[])
{
    Contenedor planetas(15);
    planetas.insertarElemento("Mercurio");

    cout << planetas.toString() << endl; 
}
