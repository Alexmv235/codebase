#include<iostream>
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
empleados *ini=NULL, *aux=NULL;
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
		cout<<v->monto<<" ->";
		v=v->sig;
	}
	cout<<"NULL"<<endl;
}
void mostrarVentasR(ventas *v)
{
	if(v!=NULL)
	{	
		cout<<v->monto<<" ->";
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
		e->venta=NULL;
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
		cout<<e->nombre<<" ->";
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
void insertarVentaNomb(empleados *&e, string n, int m)
{
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombre==n)
		{
			insertarVenta(aux->venta, m);
		}
		aux=aux->sig;
	}
}
void mostrarVentaEmp(empleados *&e, string n)
{
	aux=ini;
	while (aux!=NULL)
	{	
		if(aux->nombre==n)
		{
			mostrarVentasR(aux->venta);
		}
		aux=aux->sig;
	}
}
int sumas(ventas *&v)
{
	int suma=0;
	auxv=v;
	while (auxv!=NULL)
	{
		suma=suma+auxv->monto;
		auxv=auxv->sig;
	}
	return suma;
}
void sumaVentasEmpleados(empleados *&e, string nomb)
{
	aux=ini;
	bool band=false;
	while (aux!=NULL)
	{	
		if(aux->nombre==nomb)
		{
			cout<<sumas(aux->venta)<<endl;
			band=true;
		}
		aux=aux->sig;
	}
	if(band==false)
	{
		cout<<"El empleado no está registrado"<<endl;
	}
}
void sumaVentasEmpresa(empleados *&e)
{
	aux=ini;
	int sumaTot=0;
	while (aux!=NULL)
	{	
		sumaTot=sumaTot+sumas(aux->venta);
		aux=aux->sig;
	}
	cout<<sumaTot<<endl;
}
int main (int argc, char *argv[]) {
	int opc;
	string n="";
	int m=0;
	
	{
		do
		{
			system("CLS");
			cout<<"1-Insertar el nombre de un empleado"<<endl;
			cout<<"2-Insertar una venta para un empleado"<<endl;
			cout<<"3-Mostrar toda la lista"<<endl;
			cout<<"4-Mostrar ventas de un empleado"<<endl;
			cout<<"5-Mostrar todos los empleados"<<endl;
			cout<<"6-Agrgar información de forma predeterminada"<<endl;
			cout<<"7-Suma de ventas de un empleado"<<endl;
			cout<<"8-Suma de ventas de toda la empresa"<<endl;
			cout<<"9-Salir"<<endl;
			cin>>opc;
			
			switch(opc)
			{
			case 1:
				cout<<"dijite el  nombre del emepleado"<<endl;
				cin>>n;
				insertarEmpleados(ini, n);
				break;
			case 2:
				cout<<"dijite el  nombre"<<endl;
				cin>>n;
				cout<<"dijite el  monto de la venta"<<endl;
				cin>>m;
				insertarVentaNomb(ini, n, m);
				cout<<endl;
				//mostrarDatosCompletos(ini);
				break;
			case 3:
				mostrarDatosCompletos(ini);
				break;
			case 4:
				cout<<"dijite el  nombre"<<endl;
				cin>>n;
				mostrarVentaEmp(ini, n);
				cout<<endl;
				break;
			case 5:
				mostrarEmpleadosR(ini);
				break;
			case 6:
				//Empleados
				insertarEmpleados(ini, "l");
				insertarEmpleados(ini, "a");
				insertarEmpleados(ini, "d");
				insertarEmpleados(ini, "s");
				//Ventas
				insertarVentaNomb(ini, "l", 1);
				insertarVentaNomb(ini, "l", 2);
				insertarVentaNomb(ini, "a", 3);
				insertarVentaNomb(ini, "a", 4);
				insertarVentaNomb(ini, "a", 5);
				insertarVentaNomb(ini, "s", 6);
				insertarVentaNomb(ini, "s", 7);
				insertarVentaNomb(ini, "d", 8);
				break;
			case 7:
				cout<<"dijite el  nombre"<<endl;
				cin>>n;
				sumaVentasEmpleados(ini,n);
				cout<<endl;
				break;
			case 8:
				sumaVentasEmpresa(ini);
				break;
			case 9:
				break;
			}
			system("PAUSE"); 
		} while(opc!=9);
		
	}
	
	return 0;
}

