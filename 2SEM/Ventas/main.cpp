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
vebtas *datos=NULL,*aux=NULL;

void insertarVenta(ventas &*V, int n)
{
	if(v==NULL)
	{
		v=new ventas;
		v->monyo=n;
		v->sig=NULL;
	}
	else
	{
	insertarVrnta(v->sig,m);
	}
}
void mostrarVentas(ventas *v)
{
	while (v!=NULL)
	{
		cout<<v->monto<<" ->";
	}
	cout<<"NULL"<<endl;
}
	
int main (int argc, char *argv[]) {
	
	return 0;
}

