#include<iostream>
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
void insertarVentaNomb(empleados *&e, string nomb, int mont)
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
		cout<<"El empleado no est� registrado"<<endl;
	}
}
//Mostrar Ventas de Un empleado
void mostrarVentaEmp(empleados *&e, string nomb)
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
void sumarVentasEmpleado(empleados *&e, string nomb)
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
void sumarVentasEmpresa(empleados *&e)
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

//MAIN
int main (int argc, char *argv[]) {
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
			cout<<"6-Agregar informacion predeterminada"<<endl;
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
		
	}
	
	return 0;
}

