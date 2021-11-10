#include<iostream>
//Alexander Montero
using namespace std;
struct ventas
{
	int anno;
	float monto;
	ventas *sig;
	ventas *ant;
	
	ventas(){sig=NULL; ant=NULL;}
	void setSigVen(ventas *s){sig=s;}
	void setAntVen(ventas *a){ant=a;}
	ventas* getSigVen(){return sig;}
	ventas* getAntVen(){return ant;}
};
struct cantones
{
	float ganCant;
	string nombreCan;
	cantones *sig;
	cantones *ant;
	ventas *venta;

	cantones(){sig=NULL; ant=NULL;}
	void setSigCan(cantones *s){sig=s;}
	void setAntCan(cantones *a){ant=a;}
	cantones* getSigCan(){return sig;}
	cantones* getAntCan(){return ant;}
};
struct provincias
{
	float ganProv;
	string nombreProv;
	provincias *sig;
	provincias *ant;
	cantones *canton;

	provincias(){sig=NULL; ant=NULL;}
	void setSigProv(provincias *s){sig=s;}
	void setAntProv(provincias *a){ant=a;}
	provincias* getSigProv(){return sig;}
	provincias* getAntProv(){return ant;}
};
provincias *ini=NULL, *aux=NULL;
cantones *iniCan=NULL, *auxc=NULL;
ventas *datos=NULL,*auxv=NULL;

void insertarVenta(ventas *&v, int m, int an)
{
	if(v ==NULL)
	{
		v=new ventas;
		v->monto=m;
		v->anno=an;
		v->sig=NULL;
	}
	else
	{
		insertarVenta(v->sig,m,an);
	}
}
void mostrarVentas(ventas *v)
{
	cout<<"		";
	while (v!=NULL)
	{
		cout<<v->monto<<"("<<v->anno<<")"<<" -> ";
		v=v->sig;
	}
	cout<<"NULL"<<endl;
}
void mostrarVentasR(ventas *v)
{
	cout<<"		";
	if(v!=NULL)
	{	
		cout<<v->monto<<"("<<v->anno<<")"<<" -> ";
		mostrarVentasR(v->sig);
	}
	else
	{
		cout<<"NULL"<<endl;
	}
}

void insertarProvincia(provincias *&p, string n, float gp)
{
	if(p==NULL)
	{
		p=new provincias;
		p->nombreProv=n;
		p->ganProv=gp;
		p->sig=NULL;
		p->canton=NULL;
	}
	else
	{
		insertarProvincia(p->sig,n,gp);
	}
}
void insertarCanton(cantones *&c, string n, float gc)
{
	if(c ==NULL)
	{
		c=new cantones;
		c->nombreCan=n;
		c->ganCant=gc;
		c->sig=NULL;
		c->venta=NULL;
	}
	else
	{
		insertarCanton(c->sig,n, gc);
	}
}
void insertarCantonProvincia(string nonProv, string nonCant, float gc)
{
	bool band=false;
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombreProv==nonProv)
		{
			insertarCanton(aux->canton, nonCant, gc);
			band=true;
		}
		aux=aux->sig;
	}
	if(band==false)
	{
		cout<<"El empleado no esta registrado"<<endl;
	}
}
void mostrarProvincias(provincias *p)
{
	if(p!=NULL)
	{	
		cout<<p->nombreProv<<" -> ";
		mostrarProvincias(p->sig);
	}
	else
	{
		cout<<"NULL"<<endl;
	}
}
void mostrarCantones(cantones *c)
{
	if(c!=NULL)
	{	
		cout<<c->nombreCan<<" -> ";
		mostrarCantones(c->sig);
	}
	else
	{
		cout<<"NULL"<<endl;
	}
}
void mostrarDatosCantones(cantones *c)
{
	if(c!=NULL)
	{	
		cout<<c->nombreCan<<endl;
		cout<<"\t";
		mostrarVentasR(c->venta);
		mostrarDatosCantones(c->sig);
	}
}
void mostrarDatosProvincia(provincias *p)
{
	if (p!=NULL)
	{
		cout<<p->nombreProv<<endl;
		cout<<"\t";
		mostrarCantones(p->canton);
		mostrarDatosProvincia(p->sig);
	}
}
//Insertar Ventas por Canton
void insertarVentaCanton(cantones *c, string nombCan, int mont, int an)
{
	bool band=false;
	auxc=c;
	while (auxc!=NULL)
	{	
		if(auxc->nombreCan==nombCan)
		{
			insertarVenta(auxc->venta, mont, an);
			band=true;
		}
		auxc=auxc->sig;
	}
	if(band==false)
	{
		cout<<endl<<"Insertar: El canton no esta disponible"<<endl;
	}
}
//Insertar Ventas por Provincia
void insertarVentaProvincia(string nomProv, string nombCan, int mont, int an)
{
	bool band=false;
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombreProv==nomProv)
		{
			insertarVentaCanton(aux->canton, nombCan, mont, an);
			band=true;
		}
		aux=aux->sig;
	}
	if(band==false)
	{
		cout<<endl<<"Insertar: La provincia no esta disponible"<<endl;
	}
}
//Mostrar ventas por Canton
void mostrarVentaCanton(cantones *c)
{
	auxc=c;	
	while (auxc!=NULL)
	{
		cout<<"	"<<auxc->nombreCan<<"("<<auxc->ganCant<<")"<<endl;
		mostrarVentas(auxc->venta);
		auxc=auxc->sig;
	}
	
}
//Mostrar ventas por Provincia (corregir)
void mostrarVentaProvincia(string nombProv)
{
	bool band=false;
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombreProv==nombProv)
		{
			cout<<aux->nombreProv<<"("<<aux->ganProv<<")"<<endl;
			mostrarVentaCanton(aux->canton);
			band=true;	
		}
		aux=aux->sig;
	}
	if(band==false)
	{
		cout<<endl<<"mostrarventa: La provincia no esta disponible"<<endl;
	}
}

//Suma universal (para invocar)
int sumar(ventas *v)
{
	float sum=0;
	auxv=v;
	while (auxv!=NULL)
	{
		sum=sum+auxv->monto;
		auxv=auxv->sig;
	}
	return sum;
}
//Suma de un Canton
void sumarVentasCanton()
{
	
	aux=ini;
	while(aux!=NULL)
	{	
		auxc=aux->canton;
		while (auxc!=NULL)
		{
			if(auxc->ganCant!=sumar(auxc->venta))
			{
				cout<<"se detecto un error en el canton "<<auxc->nombreCan<<" de la provincia "<<aux->nombreProv<<endl;
				auxc->ganCant=sumar(auxc->venta);
				cout<<"el error se ha corregido"<<endl;
			}
			auxc=auxc->sig;
		}
		aux=aux->sig;
	}
}
//Suma de toda la provincia
void sumarVentasProvincia()
{
	aux=ini;
	
	while (aux!=NULL)
	{	
		auxc=aux->canton;
		float sumaTotProv=0;
		while (auxc!=NULL)
		{
			sumaTotProv=sumaTotProv+auxc->ganCant;
			auxc=auxc->sig;
		}
		if (aux->ganProv!=sumaTotProv)
		{
			cout<<"se detecto un error en la provincia "<<aux->nombreProv<<endl;
			aux->ganProv=sumaTotProv;
			cout<<"el error se ha corregido"<<endl;
		}
		aux=aux->sig;
	}
}
void eliminarAnnos(string nomProv, string nombCan, int an)
{	
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombreProv==nomProv)
		{
			auxc=aux->canton;
			while (auxc!=NULL)
			{
				if(auxc->nombreCan==nombCan)
				auxv=auxc->venta;
				while (auxv!=NULL)
				{
				if(auxv->anno == an && auxv->getAntVen() == NULL)
				{
					//cout<<"es el primero"<<endl;
					auxc->venta = auxv->getSigVen();
				}
				else if(auxv->anno == an && auxv->getSigVen() == NULL)
				{
					//cout<<"es el ultimo"<<endl;
					//Combinacion 211 si funciona
					auxv->getAntVen()->setSigVen(auxv->getSigVen());
				}
				else if (auxv->anno == an)
				{
					auxv->getSigVen()->setAntVen(auxv->getAntVen());
					auxv->getAntVen()->setSigVen(auxv->getSigVen());
				}
				auxv=auxv->sig;
				}	
				auxc=auxc->sig;
			}
		}
		aux=aux->sig;
	}
}

//MAIN
int main (int argc, char *argv[]) {
	
	int opc;
	string nomb="";
	
	{
		do
		{
			system("CLS");
			cout<<"1-Insertar datos predeterminados(diagrama)"<<endl;
			cout<<"2-Mostrar todos los datos"<<endl;
			cout<<"3-Revisar datos y corregir si es necesario"<<endl;
			cout<<"4-Eliminar datos-"<<endl;
			cout<<"5-Salir"<<endl;
			cout<<"- - - - - - - - - - - - - - - - - - - - -"<<endl;
			cin>>opc;
			
			switch(opc)
			{
			case 1:
				//Insertar Provincias
				insertarProvincia(ini,"Puntarenas", 0);
				insertarProvincia(ini,"Alajuela", 00);
				insertarProvincia(ini,"Limon", 0);
				insertarProvincia(ini,"Cartago", 00);
				insertarProvincia(ini,"San_Jose", 0);
				insertarCantonProvincia("Puntarenas","Buenos_Aires", 3500);
				insertarCantonProvincia("Puntarenas","Esparza", 00);
				insertarCantonProvincia("Puntarenas","Golfito", 00);
				insertarCantonProvincia("Alajuela","Grecia", 00);
				insertarCantonProvincia("Alajuela","Atenas", 3500);
				insertarCantonProvincia("Alajuela","Zarcero", 00);
				insertarCantonProvincia("Limon","Limon", 00);
				insertarCantonProvincia("Limon","Siquirres", 00);
				insertarCantonProvincia("Cartago","Turrialba", 3500);
				insertarCantonProvincia("San_Jose","San_Jose", 00);
				insertarCantonProvincia("San_Jose","Perez_Zeledon", 00);
				insertarCantonProvincia("San_Jose","Escazu", 00);
				insertarCantonProvincia("San_Jose","Santa_Ana", 00);
				insertarVentaProvincia("Puntarenas","Buenos_Aires", 9000, 2021);
				insertarVentaProvincia("Puntarenas","Esparza", 0,0);
				insertarVentaProvincia("Puntarenas","Esparza", 0,0);
				insertarVentaProvincia("Puntarenas","Golfito", 00,2017);
				insertarVentaProvincia("Alajuela","Grecia", 00,0);
				insertarVentaProvincia("Alajuela","Atenas", 3500,0);
				insertarVentaProvincia("Alajuela","Zarcero", 00,0);
				insertarVentaProvincia("Alajuela","Zarcero", 00,0);
				insertarVentaProvincia("Limon","Limon", 00,0);
				insertarVentaProvincia("Limon","Limon", 00,0);
				insertarVentaProvincia("Limon","Limon", 00,0);
				insertarVentaProvincia("Limon","Siquirres", 00,0);
				insertarVentaProvincia("Limon","Siquirres", 00,0);
				
				insertarVentaProvincia("Cartago","Turrialba", 3500,0);
				insertarVentaProvincia("Cartago","Turrialba", 3500,0);
				insertarVentaProvincia("Cartago","Turrialba", 3500,0);
				insertarVentaProvincia("Cartago","Turrialba", 3500,0);
				insertarVentaProvincia("Cartago","Turrialba", 3500,0);

				insertarVentaProvincia("San_Jose","San_Jose", 00,0);
				insertarVentaProvincia("San_Jose","San_Jose", 00,0);
				insertarVentaProvincia("San_Jose","Perez_Zeledon", 00,0);
				insertarVentaProvincia("San_Jose","Perez_Zeledon", 00,0);
				insertarVentaProvincia("San_Jose","Perez_Zeledon", 00,0);
				insertarVentaProvincia("San_Jose","Perez_Zeledon", 00,0);
				insertarVentaProvincia("San_Jose","Escazu", 00,0);
				insertarVentaProvincia("San_Jose","Escazu", 00,0);
				insertarVentaProvincia("San_Jose","Santa_Ana", 00,0);
				

				break;
			case 2:
				mostrarVentaProvincia("Puntarenas");
				mostrarVentaProvincia("Alajuela");
				mostrarVentaProvincia("Limon");
				mostrarVentaProvincia("Cartago");
				mostrarVentaProvincia("San_Jose");
				break;
			case 3:
				sumarVentasCanton();
				sumarVentasProvincia();
				break;
			case 4:
				eliminarAnnos("Puntarenas","Golfito",2017); 
				sumarVentasCanton();
				sumarVentasProvincia();
				break;
			case 5:
				break;
			}
			system("PAUSE"); 
		} while(opc!=5);
		
	} 
	
	return 0;
}

