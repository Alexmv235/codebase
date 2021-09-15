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
	string Plantas[4];
	string Surcos[9];
	int Terreno[9][4];
	int Precios[4];
	int NumPlanta[1];
	
public:
	clsColeccion()
	{
		int i=0;
		while (i<4)
		{
			Plantas[i]="";
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
	void definirPlantas()
	{
		for(int i=0;i<4; i++)
		{
			Plantas[0]="hortensias";
			Plantas[1]="rosas";
			Plantas[2]="tulipanes";
			Plantas[3]="helechos";
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
	void mostrarPlantas()
	{
		cout<<"Las Plantas son"<<endl;
		cout<<endl;
		for (int i=0;i<4; i++) 
		{
			cout<<"\t"<<Plantas[i]<<endl;
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
			cout<<Plantas[i];
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
	void espacioTiempo()
	{
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{
				Terreno[i][j]= -1;
			}
		}
		Sleep(50);
		cout<<endl<<"tiempo transcurrido: 0 semanas"<<endl;
		mostrarTerreno();
		
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{
				Terreno[i][j]= 0;
			}
		}
		Sleep(2000);
		cout<<endl<<"tiempo transcurrido: 1 semana"<<endl;
		mostrarTerreno();
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{
				Terreno[i][j]= 2;
			}
		}
		Sleep(2000);
		cout<<endl<<"tiempo transcurrido: 2 semanas"<<endl;
		mostrarTerreno();
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{
				Terreno[i][j]= 3;
			}
		}
		Sleep(2000);
		cout<<endl<<"tiempo transcurrido: 3 semanas"<<endl;
		mostrarTerreno();
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{
				Terreno[i][j]= 1;
			}
		}
		Sleep(2000);
		cout<<endl<<"tiempo transcurrido: 4 semana"<<endl;
		mostrarTerreno();
		
	}
	//Plantas crecen
	void plantasCrecen()
	{
		Sleep(4000);
		cout<<"Tiempo transcurrido: 6 semanas"<<endl;
		cout<<"Las plantas han crecido"<<endl;
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
	void conocerPlanta()
	{
		string nPlanta = " ";
		cout<<endl<<"dijite el nombre de la planta (escriba todo en minusculas)"<<endl;
		cin>>nPlanta;
		
		if (nPlanta == "hortensias" )
		{
			NumPlanta[1]=0;
		}
		else if (nPlanta == "rosas")
		{
			NumPlanta[1]=1;
		}
		else if (nPlanta == "tulipanes")
		{
			NumPlanta[1]=2;
		}
		else if (nPlanta == "helechos")
		{
			NumPlanta[1]=3;
		}
	}
	// Metodo para saber la cosecha de un tipo de planta
	void conocerCosecha()
	{
		int plantaNum=0;
		int cant=0;
		int cantM=0;
		plantaNum=NumPlanta[1];
			for(int i=0; i<10; i++)
			{
				if(Terreno[i][plantaNum]==3)
				{
					cant++;
				}
				{
					cantM=cant;
				}
				
			}
			cout<<endl<<"La planta: "<<Plantas[plantaNum]<< " tiene: "<<cantM<< " plantas disponibles para cosechar"<<endl;
			//cout<<endl<< "La ganancia de vender todas la plantas listas de: "<<Plantas[plantaNum]<<" es:" <<precioPlant<<endl;
	}
	// conocer plantas listas en todo el Terreno
	void conocerCosechaTerreno()
	{
		int cantB=0;
		int cantMB=0;
		for (int i=0; i<9; i++)
		{
			for(int j=0; j<4; j++)
			{	
			if(Terreno[i][j]==3)
			{
				cantB++;
			}
			{
				cantMB=cantB;
			}
			}
		}
		cout<<endl<<"En total hay: "<<cantMB<< " plantas disponibles para cosechar"<<endl;
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
	
	//Mostrar precio flor en específico
	void mostrarPrecioFlor()
	{
		int numPlanta=0;
		numPlanta=NumPlanta[1];
		cout<<"El precio de la planta: "<<Plantas[numPlanta]<<" es de:"<< Precios[numPlanta]<<endl;
	}
	// Ganacia de vender un tipo de plnta
	void gananciaPlanta()
	{
		int plantaNum=0;
		int cant=0;
		int cantM=0;
		int gananciaP=0;
		plantaNum=NumPlanta[1];
		
		for(int i=0; i<10; i++)
		{
			if(Terreno[i][plantaNum]==3)
			{
				cant++;
			}
			{
				cantM=cant;
			}
			
		}
		gananciaP= (cantM*Precios[plantaNum]);
		cout<<"La ganancia total de vender todas las plantas de: "<<Plantas[plantaNum]<<" es de: "<<gananciaP<<endl;
	}
	
	// Ganancia de todo un surco
	void montoTotalFila()
	{
		int cantH=0,cantR=0,cantT=0,cantE=0;
		int cantTH=0,cantTR=0, cantTT=0, cantTE=0;
		int precioTotal=0;
		int surco, numSurco =0;
		cout<<"escriba el número de surco que quiere consultar"<<endl;
		cin>>surco;
		numSurco= (surco - 1);
		if(Terreno[numSurco][0]==3)
		{
			cantH++;
		}
		{
			cantTH=cantH;
		}
		if(Terreno[numSurco][1]==3)
		{
			cantR++;
		}
		{
			cantTR=cantR;
		}
		if(Terreno[numSurco][2]==3)
		{
			cantT++;
		}
		{
			cantTT=cantT;
		}
		if(Terreno[numSurco][3]==3)
		{
			cantE++;
		}
		{
			cantTE=cantE;
		}
		precioTotal=(cantTH*Precios[0]+cantTR*Precios[1]+cantTT*Precios[2]+cantTE*Precios[3]);
		cout<<endl<<"La ganancia total en el surco "<<Surcos[numSurco]<< " es de: "<<precioTotal<<endl;
	}
	// Limpiar Intervalo
	void limpiarIntervalo()
	{
		int min=0, max=0, minR=0;
		cout<<"dijite el surco inicial"<<endl;
		cin>>min;
		minR=(min -1);
		cout<<"dijite el surco final"<<endl;
		cin>>max;
		for (int i=minR; i<max; i++)
		{
			for(int j=0; j<4; j++)
			{
				Terreno[i][j]= -1;
			}
		}
	}
	//Destructor
	~clsColeccion()
	{
		
	}
};
int main(int argc, char *argv[]) {
	cout<<"FARM MANAGER 2021"<<endl; 
	cout<<"Bienvenido:Granjero"<<endl;
	for(int i=0; i<6;i++){ 
		cout<<" - "; 
		Sleep(400);
	}
	cout<<endl;
	
	clsColeccion A1;
	
	A1.definirPlantas();
	A1.definirSurcos();
	A1.definirPrecios();
	A1.limpiarTerreno();

	int opc;
	{
		do
		{
			system("CLS");
			cout<<"1-Limpiar el terreno"<<endl;
			cout<<"2-Sembrar el terreno"<<endl;
			cout<<"3-Determinar si las plantas han crecido"<<endl;
			cout<<"4-Verificar el cambio en el huerto"<<endl;
			cout<<"5-Determinar la cantidad de un tipo de planta lista para cosechar"<<endl;
			cout<<"6-Determinar Total de plantas listas para cosechar"<<endl;
			cout<<"7-Determinar precio de planta"<<endl;
			cout<<"8-Determinar Ganancia por tipo de planta"<<endl;
			cout<<"9-Determinar Ganacia por las que estan listas en el surco"<<endl;
			cout<<"10-Limpiar rango"<<endl;
			cout<<"11-Mostrar terreno"<<endl;
			cout<<"12-Salir"<<endl;
			cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
			cin>>opc;
			switch(opc)
			{
			case 1:
				A1.limpiarTerreno();
				A1.mostrarTerreno();
				break;
			case 2:
				A1.sembrarTerreno();
				A1.mostrarTerreno();
				break;
			case 3:
				A1.espacioTiempo();
				break;
			case 4:
				A1.plantasCrecen();
				A1.mostrarTerreno();
				break;
			case 5:
				A1.mostrarPlantas();
				A1.conocerPlanta();
				A1.conocerCosecha();
				break;
			case 6:
				A1.conocerCosechaTerreno();
				break;
			case 7:
				A1.mostrarPlantas();
				A1.conocerPlanta();
				A1.mostrarPrecioFlor();
				break;
			case 8:
				A1.mostrarPlantas();
				A1.conocerPlanta();
				A1.gananciaPlanta();
				break;
			case 9:
				A1.mostrarSurcos();
				A1.montoTotalFila();
				break;
			case 10:
				A1.mostrarSurcos();
				A1.limpiarIntervalo();
				break;
			case 11:
				A1.mostrarTerreno();
				break;
			case 12:
				cout<<"tenga buena cosecha"<<endl;
				for(int i=0; i<6;i++){ 
					cout<<" - "; 
					Sleep(400);
				}
				cout<<endl;
				break;
			}
			system("PAUSE"); 
		} while(opc!=12);
		
	}
	return 0;
}

