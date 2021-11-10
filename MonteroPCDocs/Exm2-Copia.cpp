#include<iostream>
using namespace std;
struct annos
{
	int anno;
	float venta;
	annos *sig;
	annos *ant;
	
	annos()
	{
		sig=NULL; ant=NULL;
	}
	void setSigAnno(annos *s)
	{
		sig=s;
	}
	void setAntAnno(annos *a)
	{
		ant=a;
	}
	annos* getSigAnno()
	{
		return sig;
	}
	annos* getAntAnno()
	{
		return ant;
	}
};
struct cantones
{
	float ventaCanton;
	string nombreCanton;
	cantones *sig;
	cantones *ant;
	annos *anno;

	cantones()
	{
	sig=NULL; ant=NULL;
	}
	void setSigCan(cantones *s)
	{
		sig=s;
	}
	void setAntCan(cantones *a)
	{
		ant=a;
	}
	cantones* getSigCan()
	{
		return sig;
	}
	cantones* getAntCan()
	{
		return ant;
	}
};
struct provincias
{
	float ventaProv;
	string nombreProvincia;
	provincias *sig;
	provincias *ant;
	cantones *canton;

	provincias()
	{
		sig=NULL; ant=NULL;
	}
	void setSigProvincia(provincias *s)
	{
		sig=s;
	}
	void setAntProvincia(provincias *a)
	{
		ant=a;
	}
	provincias* getSigProvincia()
	{
		return sig;
	}
	provincias* getAntProvincia()
	{
		return ant;
	}
};
provincias *ini=NULL, *aux=NULL;
cantones *iniCanton=NULL, *auxcanton=NULL;
annos *iniAnnos=NULL,*auxAnnos=NULL;

void insertarAnno(annos *&a, int m, int an)
{
	if(a ==NULL)
	{
		a=new annos;
		a->venta=m;
		a->anno=an;
		a->sig=NULL;
	}
	else
	{
		insertarAnno(a->sig,m,an);
	}
}
void mostrarAnno(annos *a)
{
	cout<<"		";
	while (a!=NULL)
	{
		cout<<a->venta<<" -> ";
		cout<<a->anno<<" -> ";
		a=a->sig;
	}
	cout<<"NULL"<<endl;
}
void mostrarVentasR(annos *a)
{
	cout<<"		";
	if(a!=NULL)
	{	
		cout<<a->venta<<" -> ";
		mostrarVentasR(a->sig);
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
		p->nombreProvincia=n;
		p->ventaProv=gp;
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
		c->nombreCanton=n;
		c->ventaCanton=gc;
		c->sig=NULL;
		c->anno=NULL;
	}
	else
	{
		insertarCanton(c->sig,n, gc);
	}
}
void insertarCantonEnProvincia(string np, string nc, float gc)
{
	bool band=false;
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombreProvincia==np)
		{
			insertarCanton(aux->canton, nc, gc);
			band=true;
		}
		aux=aux->sig;
	}
	if(band==false)
	{
		cout<<"No hay provincia"<<endl;
	}
}
void mostrarListaProvincias(provincias *p)
{
	if(p!=NULL)
	{	
		cout<<p->nombreProvincia<<" -> ";
		mostrarListaProvincias(p->sig);
	}
	else
	{
		cout<<"NULL"<<endl;
	}
}
void mostrarListaCantones(cantones *c)
{
	if(c!=NULL)
	{	
		cout<<c->nombreCanton<<" -> ";
		mostrarListaCantones(c->sig);
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
		cout<<c->nombreCanton<<endl;
		cout<<"\t";
		mostrarVentasR(c->anno);
		mostrarDatosCantones(c->sig);
	}
}
void mostrarDatosProvincia(provincias *p)
{
	if (p!=NULL)
	{
		cout<<p->nombreProvincia<<endl;
		cout<<"\t";
		mostrarListaCantones(p->canton);
		mostrarDatosProvincia(p->sig);
	}
}
void insertarVentaCanton(cantones *c, string nc, int g, int an)
{
	bool band=false;
	auxcanton=c;
	while (auxcanton!=NULL)
	{	
		if(auxcanton->nombreCanton==nc)
		{
			insertarAnno(auxcanton->anno, g, an);
			band=true;
		}
		auxcanton=auxcanton->sig;
	}
	if(band==false)
	{
		cout<<endl<<"El canton no existe"<<endl;
	}
}
void insertarVentaProvincia(string np, string nc, int g, int an)
{
	bool band=false;
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombreProvincia==np)
		{
			insertarVentaCanton(aux->canton, nc, g, an);
			band=true;
		}
		aux=aux->sig;
	}
	if(band==false)
	{
		cout<<endl<<"La provincia no existe"<<endl;
	}
}
void mostrarVentaCanton(cantones *c)
{
	auxcanton=c;	
	while (auxcanton!=NULL)
	{
		cout<<"	"<<auxcanton->nombreCanton<<endl;
		mostrarAnno(auxcanton->anno);
		cout<<"	Monto canton:"<<auxcanton->ventaCanton<<endl;
		auxcanton=auxcanton->sig;
	}
}
void mostrarVentaProvincia(string np)
{
	bool band=false;
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombreProvincia==np)
		{
			cout<<aux->nombreProvincia<<endl;
			mostrarVentaCanton(aux->canton);
			cout<<"Monto Provincia:"<<aux->ventaProv<<endl;
			band=true;	
		}
		aux=aux->sig;
	}
	if(band==false)
	{
		cout<<endl<<"La provincia no existe"<<endl;
	}
}
float sumarDatos(annos *a)
{
	float sum=0;
	auxAnnos=a;
	while (auxAnnos!=NULL)
	{
		sum=sum+auxAnnos->venta;
		auxAnnos=auxAnnos->sig;
	}
	return sum;
}
void sumarVentasCanton()
{
	aux=ini;
	while(aux!=NULL)
	{	
		auxcanton=aux->canton;
		while (auxcanton!=NULL)
		{
			if(auxcanton->ventaCanton!=sumarDatos(auxcanton->anno))
			{
				cout<<"se detecto un error" <<endl;
				auxcanton->ventaCanton=sumarDatos(auxcanton->anno);
				cout<<"error corregido"<<endl;
			}
			auxcanton=auxcanton->sig;
		}
		aux=aux->sig;
	}
}
void sumarVentasProvincia()
{
	aux=ini;
	while (aux!=NULL)
	{	
		auxcanton=aux->canton;
		float sumaTotalProv=0;
		while (auxcanton!=NULL)
		{
			sumaTotalProv=sumaTotalProv+auxcanton->ventaCanton;
			auxcanton=auxcanton->sig;
		}
		if (aux->ventaProv!=sumaTotalProv)
		{
			cout<<"se detecto un error"<<endl;
			aux->ventaProv=sumaTotalProv;
			cout<<"corregido"<<endl;
		}
		aux=aux->sig;
	}
}
void eliminarAnnos(string np, string nc, int an)
{	
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombreProvincia==np)
		{
			auxcanton=aux->canton;
			while (auxcanton!=NULL)
			{
				if(auxcanton->nombreCanton==nc)
				auxAnnos=auxcanton->anno;
				while (auxAnnos!=NULL)
				{
				//COnSERVAR ESTRECTURA
				if(auxAnnos->anno == an && auxAnnos->getAntAnno() == NULL)
				{
					auxcanton->anno = auxAnnos->getSigAnno();
				}
				else if(auxAnnos->anno == an && auxAnnos->getSigAnno() == NULL)
				{
					auxAnnos->getAntAnno()->setSigAnno(auxAnnos->getSigAnno());
				}
				else if (auxAnnos->anno == an)
				{
					auxAnnos->getSigAnno()->setAntAnno(auxAnnos->getAntAnno());
					auxAnnos->getAntAnno()->setSigAnno(auxAnnos->getSigAnno());
				}
				auxAnnos=auxAnnos->sig;
				}	
				auxcanton=auxcanton->sig;
			}
		}
		aux=aux->sig;
	}
}
int main (int argc, char *argv[]) {
	
	int opc;
	string nomb="";
	
	{
		do
		{
			system("CLS");
			cout<<"1-datos estandar"<<endl;
			cout<<"2-Mostrar datos"<<endl;
			cout<<"3-Revisar datos"<<endl;
			cout<<"4-Eliminar datos"<<endl;
			cout<<"5-Salir"<<endl;
			cout<<"- - - - - - - - - - - - - - - - - - - - -"<<endl;
			cin>>opc;
			
			switch(opc)
			{
			case 1:
				insertarProvincia(ini,"Puntarenas", 0);
				insertarProvincia(ini,"Alajuela", 00);
				insertarProvincia(ini,"Limon", 0);
				insertarProvincia(ini,"Cartago", 00);
				insertarProvincia(ini,"San_Jose", 0);
				insertarCantonEnProvincia("Puntarenas","Buenos_Aires", 3500);
				insertarCantonEnProvincia("Puntarenas","Esparza", 00);
				insertarCantonEnProvincia("Puntarenas","Golfito", 00);
				insertarCantonEnProvincia("Alajuela","Grecia", 00);
				insertarCantonEnProvincia("Alajuela","Atenas", 3500);
				insertarCantonEnProvincia("Alajuela","Zarcero", 00);
				insertarCantonEnProvincia("Limon","Limon", 00);
				insertarCantonEnProvincia("Limon","Siquirres", 00);
				insertarCantonEnProvincia("Cartago","Turrialba", 3500);
				insertarCantonEnProvincia("San_Jose","San_Jose", 00);
				insertarCantonEnProvincia("San_Jose","Perez_Zeledon", 00);
				insertarCantonEnProvincia("San_Jose","Escazu", 00);
				insertarCantonEnProvincia("San_Jose","Santa_Ana", 00);
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

