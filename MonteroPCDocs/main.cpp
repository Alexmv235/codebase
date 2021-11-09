#include<iostream>
//Alexander Montero
using namespace std;
class nodo
{
private: 
	int n;
	nodo *sig;
	nodo *ant;
public:
	nodo()
	{
		n=0;
		sig=NULL;
		ant=NULL;
	}
	nodo (int nu, nodo *s, nodo *a)
	{
		n=nu;
		sig=s;
		ant=a;
	}
	void setN(int nu)
	{
		n=nu;
	}
	void setSig(nodo *s)
	{
		sig=s;
	}
	void setAnt(nodo *a)
	{
		ant=a;
	}
	int getN()
	{
		return n;
	}
	nodo* getSig()
	{
		return sig;
	}
	nodo* getAnt()
	{
		return ant;
	}
	
};
class lista
{
private:
	nodo *ini;
public:
	lista()
	{
		ini=NULL;
	}
	lista (nodo *i)
	{
		ini=i;
	}
	void setIni(nodo *i)
	{
		ini=i;
	}
	nodo* getIni()
	{
		return ini;
	}
	// Metodos
	// Instertar
	void insertar(int n)
	{
		nodo *aux=NULL,*dato=NULL;
		aux=ini;
		if(aux==NULL)
		{
			ini=new class nodo(n,NULL,NULL);
		}
		else
		{
			if (n<aux->getN())
			{
				dato=new class nodo();
				dato->setN(n);
				dato->setAnt(NULL);
				dato->setSig(ini);
				ini=dato;
			}
			else
			{
				bool bandera=false;
				while(aux->getSig()!=NULL && !bandera)
				{
					if (aux->getN()<n && aux->getSig()->getN()>n)
					{
						bandera=true;
					}
					else
					{	
						aux=aux->getSig();
					}
				}
				dato=new class nodo();
				dato->setN(n);
				dato->setAnt(aux);
				dato->setSig(aux->getSig());
				aux->setSig(dato);
			}
		}
	}
	
	
	void mostrar()
	{
		nodo *aux;
		aux=ini;
		while(aux!=NULL)
		{
			cout<<aux->getN()<<" -> ";
			aux=aux->getSig();
		}
		cout<<"NULL"<<endl;
	}
	//Sumar
	void sumar()
	{
		int sum=0;
		nodo *aux;
		aux=ini;
		while(aux!=NULL)
		{
			sum=sum+aux->getN();
			aux=aux->getSig();
		}
		cout<<sum<<endl;
	}
	//promedio
	void promedio()
	{
		float sum=0, cont=0, prom=0;
		nodo *aux;
		aux=ini;
		while(aux!=NULL)
		{
			sum=sum+aux->getN();
			aux=aux->getSig();
			cont++;
		}
		prom= (sum/cont);
		cout<<prom<<endl;
	}
	//buscar valor
	void buscar()
	{
		int cons=0;
		cout<<"dijite el numero"<<endl;
		cin>>cons;
		bool presente=false;
		nodo *aux;
		aux=ini;
		while(aux!=NULL)
		{
			if(aux->getN()==cons)
			{
				presente=true;
			}
			aux=aux->getSig();
		}
		if (presente==true)
		{
			cout<<"Si esta"<<endl;
		}
		else
		{
			cout<<"No esta"<<endl;
		}
	}
	//eliminar
	//NOTA* no funciona con el menor
	void eliminar()
	{
		
		int cons=0;
		cout<<"dijite el numero"<<endl;
		cin>>cons;
		nodo *aux;
		aux=ini;
		while (aux != NULL)
		{
			if(aux->getN() == cons && aux->getAnt() == NULL)
			{
				//cout<<"es el primero"<<endl;
				 ini = aux->getSig();
			}
			else if(aux->getN() == cons && aux->getSig() == NULL)
			{
				//cout<<"es el ultimo"<<endl;
				//Combinacion 211 si funciona
				aux->getAnt()->setSig(aux->getSig());
			}
			else if (aux->getN() == cons)
			{
				aux->getSig()->setAnt(aux->getAnt());
				aux->getAnt()->setSig(aux->getSig());
			}
			aux = aux->getSig();
		}
	}
};
lista *lis;
int main (int argc, char *argv[]) {
	
	int opc;

	{
		do
		{
			system("CLS");
			cout<<"1-Insertar"<<endl;
			cout<<"2-Mostar"<<endl;
			cout<<"3-Suma"<<endl;
			cout<<"4-Promedio"<<endl;
			cout<<"5-Buscar"<<endl;
			cout<<"6-eliminar"<<endl;
			cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
			cin>>opc;
			
			switch(opc)
			{
			case 1:
				lis=new class lista();
				lis->insertar(1);
				lis->insertar(12);
				lis->insertar(13);
				lis->insertar(14);
				lis->insertar(15);
				lis->insertar(16);
				lis->insertar(17);
				lis->insertar(18);
				lis->insertar(28);
				lis->insertar(10);
				break;
			case 2:
				lis->mostrar();
				break;
			case 3:
				lis->sumar();
				break;
			case 4:
				lis->promedio();
				break;
			case 5:
				lis->buscar();
				break;
			case 6:
				lis->eliminar();
				break;
			case 7:
				break;
			}
			system("PAUSE"); 
		} while(opc!=7);
		
	}
	return 0;
	
	//22-09-21
	//Menu
	//Obtener la sumatoria de la lista
	//Obtener el promedio de la lista
	//Buscar en la lista (devolver true o false) si está o no
	//Elminar un valor de la lista.
}

