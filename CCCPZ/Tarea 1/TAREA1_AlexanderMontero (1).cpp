#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;

class Vehiculo
{
private:
	long precio;
	int annio;
	string modelo;
	int placa;
public:
	Vehiculo()
	{
		precio=0;
		annio=0;
		modelo="";
		placa=0;
	}
	Vehiculo(long pr, int an, string mod, int pl)
	{
		precio=pr;
		annio=an;
		modelo=mod;
		placa=pl;
	}
	//set & get
	void setPrecio(long pr)
	{
		precio=pr;
	}
	long getPrecio ()
	{
		return precio;
	}
	void setAnnio (int an)
	{
		annio=an;
	}
	int getAnnio()
	{
		return annio;
	}
	void setModelo (string mod)
	{
		modelo=mod;
	}
	string getModelo()
	{
		return modelo;
	}
	void setPlaca (int pl)
	{
		placa=pl;
	}
	int getPlaca ()
	{
		return placa;
	}
	
	//Otros metodos
	string determinaRestriccion()
	{
		string restricion;
		int ud;
		
		ud = placa % 10;
		
		switch (ud)
		{
		case 0: restricion = "Viernes"; break;
		case 1: restricion = "Lunes"; break;
		case 2: restricion = "Lunes"; break;
		case 3: restricion = "Martes"; break;
		case 4: restricion = "Martes"; break;
		case 5: restricion = "Miercoles"; break;
		case 6: restricion = "Miercoles"; break;
		case 7: restricion = "Jueves"; break;
		case 8: restricion = "Jueves"; break;
		case 9: restricion = "Viernes"; break;
		default:
			restricion = "No es un numero de placa"; break;
		}
		
		return restricion;
	}
	float calcularMarchamo()
	{
		float marchamo;
		if (annio == 2021)
		{
			marchamo = precio * 0.01;
		}
		else if (annio >= 2011)
		{
			marchamo = precio * 0.05;
		}
		else if (annio <= 2010)
		{
			marchamo = precio * 0.02;
		}
		return marchamo;
	}
	
	string informacion()
	{
		stringstream s;
		
		s << endl << endl;
		s << "Los datos del vehiculo son:" << endl;
		s << "Modelo: " << modelo << endl;
		s << "Placa: " << placa << endl;
		s << "Annio:" << annio << endl;
		s << "Precio: " << precio << endl;
		s << "Costo del marchamo: "<< calcularMarchamo() << endl;
		s << "Dia de restriccion vehicular:" <<determinaRestriccion() << endl;
		s << endl << endl;
		
		return s.str();
	}
	
	//Destructor
	~Vehiculo()
	{
		
	}
	
};
	
int main (int argc, char *argv[]) {
	
	float Prec;
    int Ano, Plc, Salir;
    string Mode;
	
	Vehiculo A (6000000.0, 2009, "corolla", 152636);
	
	cout <<A.informacion();
	
	Vehiculo B;
	
	do{
	cout <<"Digite el modelo del vhiculo:\n";
	cin >> Mode;
	B.setModelo (Mode);
	
	cout <<"Digite el numero de placa del vehiculo:\n";
	cin>> Plc; 	
	B.setPlaca (Plc);
	
	cout <<"Digite el precio del vehiculo:\n";
	cin >> Prec;
	B.setPrecio(Prec);

	cout <<"Digite el annio del vehiculo:\n";
	cin >> Ano;
	B.setAnnio(Ano);

	cout << B.informacion();

	cout << "Digite 0 para salir del programa o presione otro numero para continuar: " << endl;
	cin >> Salir;
	if ( Salir == 0)
	{
		cout << "Terminando el programa" << endl;
	}
	
	} while( Salir != 0);
	
	
	
	
	
	
	return 0;
}

