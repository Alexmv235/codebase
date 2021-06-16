//Colegio Científico, PZ
//Desarrollado por:
//AlexanderMonteroVargas
//OscarMarioEspinozaCamacho
//GeiselThaisHernandezQuesada
//2021

#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

class Contenedor
{
private:
	char hilera[30];
	int tamano;
	int cantidad;

public:
	Contenedor(int n)
	{
		cantidad = 0;
		tamano = n;
		for (int i = 0; i < tamano; i++)
			hilera[i] = ' ';
	}
	//Set&Get
	int getCantidad()
	{
		return this->cantidad;
	}
	int getTamano()
	{
		return this->tamano;
	}
	void setCantidad(int cantidad)
	{
		this->cantidad = cantidad;
	}
	void setTamano(int tamano)
	{
		this->tamano = tamano;
	}
	//Insertar Elemento en el vector hilera
	void insertarElemento(char elem)
	{
		if (cantidad < tamano)
		{
			hilera[cantidad] = elem;
			cantidad++;
		}
	}
	// To string para imprimir hilera
	string toString()
	{
		stringstream s;
		for (int i = 0; i < cantidad; i++)
			s << hilera[i];
		s << endl;
		return s.str();
	}
	// Metodo para insertar la palabra convertida en minuscula en insertar elemento
	void insertarPalabraMinuscula(char letra)
	{
		int numAscii = (int)letra;
		if (numAscii > 64 && numAscii < 91)
		{
			numAscii += 32;
		}
		char nuevaLetra = (char)numAscii;
		insertarElemento(nuevaLetra);
	}
	//Metodo para convertir la palabra almacenada en hilera en plural
	void plural()
	{
		char ultLetra = hilera[cantidad - 1];
		if (ultLetra != 's')
		{
			if (ultLetra != 'a' && ultLetra != 'e' && ultLetra != 'i' && ultLetra != 'o' && ultLetra != 'u' && ultLetra != 'z')
			{
				hilera[cantidad] = 'e';
				hilera[cantidad + 1] = 's';
				cantidad += 2;
			}
			else
			{
				if (ultLetra == 'z')
				{
					hilera[cantidad - 1] = 'c';
					hilera[cantidad] = 'e';
					hilera[cantidad + 1] = 's';
					cantidad += 2;
				}
				else
				{
					hilera[cantidad] = 's';
					cantidad += 1;
				}
			}
		}
	}
	//Metodo para codificar las vocales en numeros correspondientes
	void codifica()
	{
		for (int i = 0; i < cantidad; i++)
		{
			switch (hilera[i])
			{
			case 'a':
				hilera[i] = '1';
				break;
			case 'e':
				hilera[i] = '2';
				break;
			case 'i':
				hilera[i] = '3';
				break;
			case 'o':
				hilera[i] = '4';
				break;
			case 'u':
				hilera[i] = '5';
				break;
			}
		}
	}
	//Metodo bool para verificar si la palabra es palindroma
	bool esPalindroma()
	{
		int temp = cantidad - 1;
		for (int i = 0; i < cantidad; i++)
		{ //i=0  temp= cant -
			if (hilera[i] != hilera[temp])
			{
				return false;
			}
			temp--;
		}
		return true;
	}
};

int main(int argc, char *argv[])
{
	// Objetos
	Contenedor contenedor(30);
	Contenedor contenedor2(30);
	Contenedor contenedor3(30);
	string palabra;
	//Variable n para cantidad de letras
	int n;
	// Solicitud de palabra para utilizar los metodos
	cout << "********** Comprobador de palabras******" << endl;
	cout << "Palabra 1: ";
	cin >> palabra;
	cout << "Dijite la cantidad de letras que tiene la palabra" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		contenedor.insertarPalabraMinuscula(palabra[i]);
	}
	cout << "Palabra en minuscula: ";

	cout << (contenedor.toString());

	if (contenedor.esPalindroma())
	{
		cout << "Es palindroma";
	}
	else
	{
		cout << "No es palindroma";
	}
	contenedor.plural();
	cout << endl
		 << "Palabra en plural: ";
	cout << (contenedor.toString());

	contenedor.codifica();
	cout << "Palabra codificada: ";
	cout << (contenedor.toString());
	cout << endl;
	// Prueba de los metodos
	//Palabra 1, no es palindroma
	palabra = "AtRAsa";
	cout << "********************************" << endl;
	cout << "Palabra 2: " << palabra << endl;


	for (int i = 0; i < 6; i++)
	{
	contenedor2.insertarPalabraMinuscula(palabra[i]);
	}

	cout << "Palabra en minuscula: ";
	cout << (contenedor2.toString());

	if (contenedor2.esPalindroma())
	{
		cout << "Es palindroma";
	}
	else
	{
		cout << "No es palindroma";
	}
	contenedor2.plural();
	cout << endl
		<< "Palabra en plural: ";
	cout << (contenedor2.toString());

	contenedor.codifica();
	cout << "Palabra codificada: ";
	cout << (contenedor2.toString());

	//Prueba 2 palabra palindroma
	cout << endl << "********************************" << endl;
	palabra = "ReConoCER";
	cout << "Palabra 3: " << palabra << endl;

	for (int i = 0; i < 9; i++)
	{
		contenedor3.insertarPalabraMinuscula(palabra[i]);
	}

	cout << "Palabra en minuscula: ";
	cout << (contenedor3.toString());

	if (contenedor3.esPalindroma())
	{
		cout << "Es palindroma";
	}
	else
	{
		cout << "No es palindroma";
	}

	contenedor3.plural();
	cout << endl
		<< "Palabra en plural: ";
	cout << (contenedor3.toString());

	contenedor3.codifica();
	cout << "Palabra codificada: ";
	cout << (contenedor3.toString());
	cout << endl;
	return 0;
}

