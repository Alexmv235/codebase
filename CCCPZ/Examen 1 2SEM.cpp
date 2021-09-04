//Colegio Cientifico, PZ
//Desarrollado por:
//AlexanderMonteroVargas
//2021
#include <iostream>
#include <windows.h> 
#include <conio.h>
using namespace std;
class clsColeccion
{
private: 
	string Flores[4];
	string Surcos[9];
	int Terreno[4][9];
	int Precios[4];
	
public:
	clsColeccion()
	{
		int i=0;
		while (i<4)
		{
			Flores[i]="";
			i++;
		}
		i=0;
		do
		{
			Surcos[i]="";
			i++;
		} while (i<4);
		
		for(int x=0; x<4; x++)
		{
			for(int y=0; y<9; y++)
			{
				Terreno[x][y]=0;
			}
		}
	}
	void definirFlores()
	{
		for(int i=0;i<4; i++)
		{
			Flores[0]="Hortensias";
			Flores[1]="Rosas";
			Flores[2]="Tulipanes";
			Flores[3]="Helechos";
		}
	}
	void definirSurcos()
	{
		for(int i=0;i<9; i++)
		{
			Surcos[0]="Surco1";
			Surcos[1]="Surco2";
			Surcos[2]="Surco3";
			Surcos[3]="Surco4";
			Surcos[4]="Sruco5";
			Surcos[5]="Surco6";
			Surcos[6]="Surco7";
			Surcos[7]="Surco8";
			Surcos[8]="Surco9";
		}
	}	
	void mostrarFlores()
	{
		cout<<"Las flores son"<<endl;
		cout<<endl;
		for (int i=0;i<4; i++) 
		{
			cout<<"\t"<<Flores[i]<<endl;
		}
		cout<<endl;
	}
	void mostrarSurcos()
	{
		cout<<"Los surcos son"<<endl;
		cout<<endl;
		for (int i=0;i<9; i++) 
		{
			cout<<"\t"<<Surcos[i]<<endl;
		}
		cout<<endl;
	}
	
	//Vaciar el Terreno
	void limpiarTerreno()
	{
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{
				Terreno[i][j]= -1;
			}
		}
	}
	//Mostrar el Terreno
	void mostrarTerreno()
	{
		cout<<endl;
		cout<<endl;
		cout.width(11);
		cout<<"Surcos";
		for (int i=0; i<4; i++) 
		{
			cout.width(11);
			cout<<Flores[i];
		}
		cout<<endl;
		for(int x=0; x<9; x++)
		{
			cout.width(11);
			cout<<Surcos[x];
			for(int y=0; y<4; y++)
			{
				cout.width(11);
				cout<<Terreno[x][y];
			}
			cout<<endl;
		}
	}
	//Sembrar el Terreno
	void sembrarTerreno()
	{
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{
				Terreno[i][j]= 0;
			}
		}
	}
	
	//Espacio de tiempo
	//Plantas crecen
	void plantasCrecen()
	{
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{
				Terreno[i][j]=(rand()%4);
			}
		}
	}
	
	
};
int main(int argc, char *argv[]) {
	cout<<"FARM MANAGER 2021"<<endl; 
	cout<<"Bienvenido:Granjero"<<endl;
	cout<< "- - - - - - - - - -"<<endl;
	
	clsColeccion Obj;
	
	Obj.definirFlores();
	Obj.definirSurcos();
	Obj.mostrarFlores();
	Obj.mostrarSurcos();
	Obj.limpiarTerreno();
	Obj.mostrarTerreno();
	Obj.sembrarTerreno();
	Obj.mostrarTerreno();
	Obj.plantasCrecen();
	Obj.mostrarTerreno();
	
	return 0;
}

