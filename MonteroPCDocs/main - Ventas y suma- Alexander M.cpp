#include<iostream>
//Alexander Montero
using namespace std;
struct ventas
{
	int anno;
	int monto;
	ventas *sig;
	
};
struct cantones
{
	string nombreCan;
	cantones *sig;
	cantones *ant;
	ventas *venta;
};
struct provincias
{
	string nombreProv;
	provincias *sig;
	provincias *ant;
	cantones *canton;
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
	while (v!=NULL)
	{
		cout<<v->monto<<"("<<v->anno<<")"<<" -> ";
		v=v->sig;
	}
	cout<<"NULL"<<endl;
}
void mostrarVentasR(ventas *v)
{
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

void insertarProvincia(provincias *&p, string n)
{
	if(p==NULL)
	{
		p=new provincias;
		p->nombreProv=n;
		p->sig=NULL;
		p->canton=NULL;
	}
	else
	{
		insertarProvincia(p->sig,n);
	}
}
void insertarCanton(cantones *&c, string n)
{
	if(c ==NULL)
	{
		c=new cantones;
		c->nombreCan=n;
		c->sig=NULL;
		c->venta=NULL;
	}
	else
	{
		insertarCanton(c->sig,n);
	}
}
void insertarCantonProvincia(string nonProv, string nonCant)
{
	bool band=false;
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombreProv==nonProv)
		{
			insertarCanton(aux->canton, nonCant);
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
		cout<<"Insertar: El canton no esta disponible"<<endl;
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
	}
	aux=aux->sig;
	if(band==false)
	{
		cout<<"Insertar: La provincia no esta disponible"<<endl;
	}
}
//Mostrar ventas por Canton
void mostrarVentaCanton(cantones *c)
{
	bool band=false;
	auxc=c;	
	while (auxc!=NULL)
	{
		mostrarVentasR(auxc->venta);
		band=true;
	}
	auxc=auxc->sig;
	if(band==false)
	{
		cout<<"mostrar venta: La provincia el canton no estan disponibles"<<endl;
	}
	
}
//Mostrar ventas por Provincia
void mostrarVentaProvincia(string nombProv)
{
	bool band=false;
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombreProv==nombProv)
		{
			mostrarVentaCanton(aux->canton);
			band=true;	
		}
	}
	aux=aux->sig;
	if(band==false)
	{
		cout<<"mostrarventa: error"<<endl;
	}
}

//Suma universal (para invocar)
int sumar(ventas *v)
{
	int sum=0;
	auxv=v;
	while (auxv!=NULL)
	{
		sum=sum+auxv->monto;
		auxv=auxv->sig;
	}
	return sum;
}
//Suma de un Canton
void sumarVentasCanton(string nombCan)
{
	bool bandCan=false;
	auxc=iniCan;
	aux=ini;
	while (aux!=NULL)
	{	
			while (auxc!=NULL)
			{	
			if(auxc->nombreCan==nombCan)
			{
				cout<<sumar(auxc->venta)<<endl;
				bandCan=true;
			}
			auxc=auxc->sig;
			}
		aux=aux->sig;
	}
	if(bandCan==false)
	{
		cout<<"El canton no esta disponible"<<endl;
	}
}
//Suma de toda la provincia
void sumarVentasProvincia(string nombProv)
{
	bool bandProv=false;
	auxc=iniCan;
	aux=ini;
	int sumaTot=0;
	while (aux!=NULL)
	{	
		if(aux->nombreProv==nombProv)
		{
			while (auxc!=NULL)
			{	
				sumaTot=sumaTot+sumar(auxc->venta);
				auxc=auxc->sig;
				bandProv=true;
			}
		}
		aux=aux->sig;
	}
	if(bandProv==false)
	{
		cout<<"La provincia no esta disponible"<<endl;
	}
	cout<<"La ganacia de la provincia es de"<<sumaTot<<endl;
}

//MAIN
int main (int argc, char *argv[]) {
	
	
	insertarProvincia(ini,"Puntarenas");
	insertarProvincia(ini,"Cartago");
	mostrarProvincias(ini);
	system("PAUSE"); 
	insertarCantonProvincia("Puntarenas","Quepos");
	insertarCantonProvincia("Puntarenas","Parrita");
	insertarCantonProvincia("Cartago","Guarco");
	insertarCantonProvincia("Cartago","Cachi");
	mostrarDatosProvincia(ini);
	system("PAUSE"); 
	cout<<"insertando"<<endl;
	
	//insertar
	insertarVentaProvincia("Puntarenas","Quepos", 1500, 2019);
	insertarVentaProvincia("Puntarenas","Quepos", 2000, 2018);
	insertarVentaProvincia("Puntarenas","Parrita", 2700, 2019);
	insertarVentaProvincia("Puntarenas","Parrita", 8000, 2017);
	mostrarVentaProvincia("Puntarenas");
	
	
	
	
	
	/*
	int opc;
	string nomb="";
	int mont=0;
	
	{
		do
		{
			system("CLS");
			cout<<"1-Insertar Empleado"<<endl;
			cout<<"2-Insertar una venta de un empleados"<<endl;
			cout<<"3-Mostrar todo"<<endl;
			cout<<"4-Mostrar ventas de un empleado"<<endl;
			cout<<"5-Mostrar empleados"<<endl;
			cout<<"6-Agregar informaci�n predeterminada"<<endl;
			cout<<"7-Suma de ventas de un empleado"<<endl;
			cout<<"8-Suma de ventas de toda la empresa"<<endl;
			cout<<"9-Salir"<<endl;
			cout<<"- - - - - - - - - - - - - - - - - - - - -"<<endl;
			cin>>opc;
			
			switch(opc)
			{
			case 1:
				//Insertar empleado
				cout<<"dijite el  nombre"<<endl;
				cin>>nomb;
				insertarEmpleados(ini, nomb);
				//mostrarDatosCompletos(ini);
				break;
			case 2:
				cout<<"dijite el  nombre"<<endl;
				cin>>nomb;
				cout<<"dijite el  monto de la venta"<<endl;
				cin>>mont;
				insertarVentaNomb(ini, nomb, mont);
				cout<<endl;
				//mostrarDatosCompletos(ini);
				break;
			case 3:
				mostrarDatosCompletos(ini);
				break;
			case 4:
				cout<<"dijite el  nombre"<<endl;
				cin>>nomb;
				mostrarVentaEmp(ini, nomb);
				cout<<endl;
				break;
			case 5:
				mostrarEmpleadosR(ini);
				break;
			case 6:
				insertarEmpleados(ini, "Marcos");
				insertarVentaNomb(ini, "Marcos", 1500);
				insertarVentaNomb(ini, "Marcos", 2500);
				insertarVentaNomb(ini, "Marcos", 1800);
				insertarEmpleados(ini, "Alondra");
				insertarVentaNomb(ini, "Alondra", 2100);
				insertarVentaNomb(ini, "Alondra", 5000);
				insertarEmpleados(ini, "Pedro");
				insertarVentaNomb(ini, "Pedro", 500);
				insertarEmpleados(ini, "Maria");
				insertarVentaNomb(ini, "Maria", 2000);
				insertarVentaNomb(ini, "Maria", 800);
				break;
			case 7:
				cout<<"dijite el  nombre"<<endl;
				cin>>nomb;
				sumarVentasEmpleado(ini, nomb);
				cout<<endl;
				break;
			case 8:
				sumarVentasEmpresa(ini);
				break;
			case 9:
				break;
			}
			system("PAUSE"); 
		} while(opc!=9);
		
	} */
	
	return 0;
}

