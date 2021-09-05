//Colegio Cientifico, PZ
//Desarrollado por:
//AlexanderMonteroVargas
//2021
#include <iostream>
#include <windows.h> 
#include <conio.h>
#include<time.h>
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
			Flores[0]="hortensias";
			Flores[1]="rosas";
			Flores[2]="tulipanes";
			Flores[3]="helechos";
		}
	}
	
	void definirPrecios()
	{
		for(int i=0;i<4; i++)
		{
			Precios[0]=2000;
			Precios[1]=1000;
			Precios[2]=3000;
			Precios[3]=500;
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
		srand(time(NULL));
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{
				Terreno[i][j]=(rand()%4);
			}
		}
	}
	
    //Metodo para saber cual planta
	void conocerCosecha()
	{
		string nPlanta = " ";
		int plantaNum =0;
		int precioPlant =0;
		cout<<endl<<"dijite el nombre de la planta (escriba todo en minusculas)"<<endl;
		cin>>nPlanta;
		
		if (nPlanta == "hortensias" )
		{
			plantaNum = 0;
		}
		else if (nPlanta == "rosas")
		{
			plantaNum = 1;
		}
		else if (nPlanta == "tulipanes")
		{
			plantaNum = 2;
		}
		else if (nPlanta == "helechos")
		{
			plantaNum = 3;
		}
		int cant=-1;
		int cantM=0;
			for(int i=0; i<9; i++)
			{
				if(Terreno[i][plantaNum]>2)
				{
					cant++;
				}
				if (cant>cantM)
				{
					cantM=cant;
					precioPlant=(Precios[plantaNum] * cantM);
				}
				
			}
			cout<<endl<<"La planta: "<<Flores[plantaNum]<< " tiene: "<<cantM<< " plantas disponibles para cosechar"<<endl;
			cout<<endl<< "La ganancia de vender todas la plantas listas de: "<<Flores[plantaNum]<<" es:" <<precioPlant<<endl;
	}
	// conocer plantas listas en todo el Terreno
	void conocerCosechaTerreno()
	{
		int cant=0;
		int cantM=0;
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{	
			if(Terreno[i][j]>2)
			{
				cant++;
			}
			if (cant>cantM)
			{
				cantM=cant;
			}
			}
		}
		cout<<endl<<"En total hay: "<<cantM<< " plantas disponibles para cosechar"<<endl;
	}
	
	//Precios
	void mostrarPrecios()
	{
		cout<<"Los precios son"<<endl;
		cout<<endl;
		for (int i=0;i<4; i++) 
		{
			cout<<"\t"<<Precios[i]<<endl;
		}
		cout<<endl;
	}
	
	// Monto total Fila
	void montoTotalFila()
	{
		int cantH,cantR,cantT,cantE=0;
		int cantTH, cantTR,cantTT,cantTE=0;
		int precioH, precioR, precioT, precioE =0;
		int surco, numSurco =0;
		cout<<"escriba el número de surco que quiere consultar"<<endl;
		cin>>surco;
		numSurco= (surco - 1);
			for(int j=0; j<4; j++)
			{	
				if(Terreno[numSurco][j]>2)
				{
					cantH++;
				}
				if (cantH>cantTH)
				{
					cantTH=cantH;
					precioH=(Precios[plantaNum] * cantM);
				}
			}
		cout<<endl<<"En total hay: "<<cantH<< " plantas disponibles para cosechar"<<endl;
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
	Obj.definirPrecios();
	Obj.mostrarPrecios();
	Obj.conocerCosecha();
	Obj.conocerCosechaTerreno();
	
	
	
	
	return 0;
}

