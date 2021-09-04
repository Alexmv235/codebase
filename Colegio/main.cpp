//Colegio Cientifico, PZ
//Desarrollado por:
//AlexanderMonteroVargas
//2021
#include<iostream>
#include<time.h>
#include<string.h>
#include<sstream>
using namespace std;
class clsColegio
{
private:
	string Estudiantes[5];
	string Cursos[5];
	float Notas[5][5];
public:
	clsColegio()
	{
		int i=0;
		while (i<5)
		{
			Estudiantes[i]="";
			i++;
		}
		i=0;
		do
		{
			Cursos[i]="";
			i++;
		} while (i<5);
		
		/*for (int j=0; j<5; j++)
		{
		Estudiantes[j]="";
		Cursos[j]="";
		}*/
		for(int x=0; x<5; x++)
		{
			for(int y=0; y<5; y++)
			{
				Notas[x][y]=0;
			}
		}
	}
	void solicitarEstudiantes()
	{
		for(int i=0;i<5; i++)
			/*{
			cout<< "ingrese el nombre del estudiante numero" <<i+1<<endl;
			cin>> Estudiantes[i];
		}*/
		{
			Estudiantes[0]="Juan";
			Estudiantes[1]="Pedro";
			Estudiantes[2]="Lucas";
			Estudiantes[3]="Messi";
			Estudiantes[4]="Josias";
		}
	}
	void solicitarCursos()
	{
		for(int i=0;i<5; i++)
			/*{
			cout<< "ingrese el nombre del curso numero" <<i+1<<endl;
			cin>> Cursos[i];
		}*/
		{
			Cursos[0]="Info";
			Cursos[1]="Mate";
			Cursos[2]="Fisica";
			Cursos[3]="Ingles";
			Cursos[4]="Quimica";
		}
	}	
	
	void solicitarNotas()
	{
		srand(time(NULL));
		for (int i=0; i<5; i++)
		{
			for(int j=0; j<5; j++)
			{
				/*cout<<"Ingrese la nota de"<<Cursos[i]<<"para el esdudiante"
				<<Estudiantes[j]<<endl;
				cin>>Notas[i][j];*/
				Notas[i][j]=(rand()%100) +1;
			}
		}
	}
	void mostrarEstudiantes()
	{
		cout<<"Los estudiantes son"<<endl;
		cout<<endl;
		for (int i=0;i<5; i++) 
		{
			cout<<"\t"<<Estudiantes[i]<<endl;
		}
		cout<<endl;
	}
	void mostrarCursos()
	{
		cout<<"Los cursos son"<<endl;
		cout<<endl;
		for (int i=0;i<5; i++) 
		{
			cout<<"\t"<<Cursos[i]<<endl;
		}
		cout<<endl;
	}
	void mostrarNotas()
	{
		cout<<endl;
		cout<<endl;
		cout.width(7);
		cout<<"Cursos";
		for (int i=0; i<5; i++) 
		{
			cout.width(7);
			cout<<Estudiantes[i];
		}
		cout<<endl;
		for(int x=0; x<5; x++)
		{
			cout.width(7);
			cout<<Cursos[x];
			for(int y=0; y<5; y++)
			{
				cout.width(7);
				cout<<Notas[x][y];
			}
			cout<<endl;
		}
	}
	//Estudiante con el mejor promedio
	void estMejorPromedio()
		
	{
		float promedio=0;
		float MPromedio;
		int mejor=0;
		for(int i=0; i<5; i++)
		{
			promedio=0;
			for(int j=0; j<5; j++)
			{
				promedio=promedio+Notas[j][i];
			}
			promedio=promedio/5;
			if (promedio>MPromedio)
			{
				MPromedio=promedio;
				mejor=i;
			}
		}
		cout<<endl<<"El mejor promedio es: " <<Estudiantes[mejor]<< " con un pormedio de: " <<MPromedio<<endl;
	}
	
	//Materia mejor ponderado.
	void mejorPonderadoMateria()
	{
		float Ponderado=0;
		float MPonderado;
		int mejor=0;
		for(int j=0; j<5; j++)
		{
			Ponderado=0;
			for(int i=0; i<5; i++)
			{
				Ponderado=Ponderado+Notas[j][i];
			}
			Ponderado=Ponderado/5;
			if (Ponderado>MPonderado)
			{
				MPonderado=Ponderado;
				mejor=j;
			}
		}
		cout<<endl<<"El mejor ponderado es : " <<MPonderado<<" en la materia :"<<Cursos[mejor]<< endl; 
	}
	
	//Materia con mas reprobados
	void materiaMasBaja()
	{
		int cant=0;
		int cantM=0;
		int mat=0;
		for(int i=0; i<5; i++)
		{
			cant=0;
			for(int j=0; j<5; j++)
			{
				if(Notas[i][j]<70)
				{
					cant++;
				}
			}
			if (cant>cantM)
			{
				cantM=cant;
				mat=i;
			}
		}
		cout<<endl<<"La materia con mas estudiantes reprobados es: "<<Cursos[mat]<< " con "<<cantM<< " de estudiantes"<<endl;
	}
};
int main (int argc, char *argv[]) {
	clsColegio Obj;
	int opc;
	{
		do
		{
			system("CLS");
			cout<<"1-ingresar notas"<<endl;
			cout<<"2-mostrar estudiantes"<<endl;
			cout<<"3-mostrar materias"<<endl;
			cout<<"4-mostrar notas"<<endl;
			cout<<"5-estudiante con mejor promedio"<<endl;
			cout<<"6-materia con mejor promedio"<<endl;
			cout<<"7-materia con mas reprobados"<<endl;
			cout<<"8-salir"<<endl;
			cin>>opc;
			Obj.solicitarEstudiantes();
			Obj.solicitarCursos();
			switch(opc)
			{
			case 1:
				Obj.solicitarNotas();
				cout<<endl;
				cout<<"Notas registradas"<<endl;
				cout<<endl;
				break;
			case 2:
				Obj.mostrarEstudiantes();
				break;
			case 3:
				Obj.mostrarCursos();
				break;
			case 4:
				Obj.mostrarNotas();
				break;
			case 5:
				Obj.estMejorPromedio();
				break;
			case 6:
				Obj.mejorPonderadoMateria();
				break;
			case 7:
				Obj.materiaMasBaja();
				break;
			case 8:
				break;
			}
			system("PAUSE"); 
		} while(opc!=8);

	}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//Cambiar la notas que permitan que se queden //Listo
	//Obtener el estudiante con el mejor promedio //Listo
	//La materia con más estudiantes quedados //Profe
	//La materia con el mejor promedio ponderado // Est
	
	return 0;
}
