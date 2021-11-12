#include<iostream>
#include<windows.h>
//Alexander Montero
using namespace std;
struct ventas
{
	int monto;
	ventas *sig;
	
};
struct empleados
{
	string nombre;
	empleados *sig;
	empleados *ant;
	ventas *venta;
};
empleados *ini=NULL, *aux=NULL, *IE, *FE ;
ventas *datos=NULL,*auxv=NULL;

void insertarVenta(ventas *&v, int m)
{
	if(v ==NULL)
	{
		v=new ventas;
		v->monto=m;
		v->sig=NULL;
	
	}
	else
	{
		insertarVenta(v->sig,m);
	}
}
void mostrarVentas(ventas *v)
{
	while (v!=NULL)
	{
		cout<<v->monto<<" -> ";
		v=v->sig;
	}
	cout<<"NULL"<<endl;
}
void mostrarVentasR(ventas *v)
{
	if(v!=NULL)
	{	
		cout<<v->monto<<" -> ";
		mostrarVentasR(v->sig);
	}
	else
	{
		cout<<"NULL"<<endl;
	}
}
void insertarEmpleados(empleados *&e, string n)
{
	if(e ==NULL)
	{
		e=new empleados;
		e->nombre=n;
		e->sig=NULL;
		e->ant=FE;
		e->venta=NULL;
		FE=e;
	}
	else
	{
		insertarEmpleados(e->sig,n);
	}
}
void mostrarEmpleadosR(empleados *e)
{
	if(e!=NULL)
	{	
		cout<<e->nombre<<" -> ";
		mostrarEmpleadosR(e->sig);
	}
	else
	{
		cout<<"NULL"<<endl;
	}
}	
void mostrarDatosCompletos(empleados *e)
{
	if (e!=NULL)
	{
		cout<<e->nombre<<endl;
		cout<<"\t";
		mostrarVentasR(e->venta);
		mostrarDatosCompletos(e->sig);
	}
}
//Insertar Ventas por nombre
void insertarVentaNomb(string nomb, int mont)
{
	bool band=false;
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombre==nomb)
		{
			insertarVenta(aux->venta, mont);
			band=true;
		}
		aux=aux->sig;
	}
	if(band==false)
	{
		cout<<"El empleado no esta registrado"<<endl;
	}
}
//Mostrar Ventas de Un empleado
void mostrarVentaEmp(string nomb)
{
	aux=ini;
	bool band=false;
	while (aux!=NULL)
	{	
		if(aux->nombre==nomb)
		{
			mostrarVentasR(aux->venta);
			band=true;
		}
		aux=aux->sig;
	}
	if(band==false)
	{
		cout<<"El empleado no est� registrado"<<endl;
	}
}
//Suma universal (para invocar)
int sumar(ventas *&v)
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
//Suma de un empleado
void sumarVentasEmpleado(string nomb)
{
	aux=ini;
	bool band=false;
	while (aux!=NULL)
	{	
		if(aux->nombre==nomb)
		{
			cout<<sumar(aux->venta)<<endl;
			band=true;
		}
		aux=aux->sig;
	}
	if(band==false)
	{
		cout<<"El empleado no est� registrado"<<endl;
	}
}
//Suma de toda la empresa
void sumarVentasEmpresa()
{
	aux=ini;
	int sumaTot=0;
	while (aux!=NULL)
	{	
		sumaTot=sumaTot+sumar(aux->venta);
		aux=aux->sig;
	}
	cout<<sumaTot<<endl;
}
//probar ant
void antPrueba(empleados *e)
{
	while (e != NULL)
	{
		cout << e->nombre<< " -> ";
		e = e->sig;
		if(e->sig==NULL)
		{
			cout<<endl;
			while(e!=NULL)
			{
				cout<<e->nombre<<" -> ";
				e=e->ant;
			}
			cout<<endl;
		}
	}
}	

//MAIN
int main (int argc, char *argv[]) {
	int opc;
	string nomb="";
	int mont=0;
	//Bienvenida
	cout<<"BUSINESS MANAGER 2021"<<endl; 
	cout<<"V 1.0"<<endl;
	for(int i=0; i<6;i++){ 
		cout<<" - "; 
		Sleep(400);
	}
	cout<<endl;
	system("CLS");
	//Sesion
	string s="";
	cout<<"Inicio de sesion"<<endl; 
	cout<<"- - - - - - - -"<<endl; 
	cout<<"Ingrese el nombre para iniciar sesion: "<<endl; 
	cin>>s;
	//Iniciando 
	system("CLS");
	cout<<"iniciando sesion"<<endl; 
	for(int i=0; i<6;i++){ 
		cout<<" - "; 
		Sleep(200);
	}
	cout<<endl;
	
	{
		do
		{
			system("CLS");
			cout<<"Sesion actual: "<<s<<endl; 
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
				insertarVentaNomb(nomb, mont);
				cout<<endl;
				//mostrarDatosCompletos(ini);
				break;
			case 3:
				mostrarDatosCompletos(ini);
				break;
			case 4:
				cout<<"dijite el  nombre"<<endl;
				cin>>nomb;
				mostrarVentaEmp(nomb);
				cout<<endl;
				break;
			case 5:
				mostrarEmpleadosR(ini);
				break;
			case 6:
				insertarEmpleados(ini, "Marcos");
				insertarVentaNomb("Marcos", 1500);
				insertarVentaNomb("Marcos", 2500);
				insertarVentaNomb("Marcos", 1800);
				insertarEmpleados(ini, "Alondra");
				insertarVentaNomb("Alondra", 2100);
				insertarVentaNomb("Alondra", 5000);
				insertarEmpleados(ini,"Pedro");
				insertarVentaNomb("Pedro", 500);
				insertarEmpleados(ini,"Maria");
				insertarVentaNomb("Maria", 2000);
				insertarVentaNomb("Maria", 800);
				break;
			case 7:
				cout<<"dijite el  nombre"<<endl;
				cin>>nomb;
				sumarVentasEmpleado(nomb);
				cout<<endl;
				break;
			case 8:
				sumarVentasEmpresa();
				break;
			case 9:
				antPrueba(ini);
				break;
			}
			system("PAUSE"); 
		} while(opc!=10);
		
	}
	
	return 0;
}

