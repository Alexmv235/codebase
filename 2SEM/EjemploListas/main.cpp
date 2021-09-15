#include<iostream>
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
			while(aux->getSig()!=NULL)
			{
				aux=aux->getSig();
			}
			dato=new class nodo();
			dato->setN(n);
			dato->setAnt(aux);
			dato->setSig(NULL);
			aux->setSig(dato);
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
};
lista *lis;
int main (int argc, char *argv[]) {
	
	lis=new class lista();
	lis->insertar(1);
	lis->insertar(84);
	lis->insertar(42);
	lis->insertar(47);
	lis->insertar(38);
	lis->insertar(62);
	lis->insertar(76);
	lis->insertar(81);
	lis->insertar(9);
	lis->insertar(41);
	lis->mostrar();
	system("PAUSE");
	return 0;
}

