//Esto en el metodo
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
			cout<<sumar(aux->venta)<<endl;
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
		sumaTot=sumaTot+sumar(aux->venta);
		aux=aux->sig;
	}
	cout<<sumaTot<<endl;
}

//En el main
cout<<"7-Suma de ventas de un empleado"<<endl;
cout<<"8-Suma de ventas de toda la empresa"<<endl;
cout<<"9-Salir"<<endl;


case 7:
	cout<<"dijite el  nombre"<<endl;
	cin>>nomb;
	sumarVentasEmpleado(ini,nomb);
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
