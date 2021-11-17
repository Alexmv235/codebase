#include <iostream>
#include <windows.h>
//Alexander Montero
using namespace std;
struct ventas
{
	int anno;
	float monto;
	ventas *sigv;
	ventas *antv;
};
struct cantones
{
	float ganCant;
	string nombreCan;
	cantones *sigc;
	cantones *antc;
	ventas *venta;
};
struct provincias
{
	float ganProv;
	string nombreProv;
	provincias *sig;
	provincias *ant;
	cantones *canton;
};
provincias *ini = NULL, *aux = NULL, *PF = NULL;
cantones *iniCan = NULL, *auxc = NULL, *CF = NULL;
ventas *datos = NULL, *auxv = NULL, *VF = NULL;

//Insertar Ventas
void insertarVenta(ventas *&v, int m, int an)
{

	if (v == NULL)
	{
		v = new ventas;
		v->monto = m;
		v->anno = an;
		v->sigv = NULL;
		v->antv = VF;
	}
	else
	{
		VF = v;
		insertarVenta(v->sigv, m, an);
		VF = NULL;
	}
}
//Mostrar ventas
void mostrarVentas(ventas *v)
{
	cout << "		";
	while (v != NULL)
	{
		cout << v->anno << "(" << v->monto << ")"
			 << " -> ";
		v = v->sigv;
	}
	cout << "NULL" << endl;
}
//Insertar una provincia
void insertarProvincia(provincias *&p, string n, float gp)
{
	if (p == NULL)
	{
		p = new provincias;
		p->nombreProv = n;
		p->ganProv = gp;
		p->sig = NULL;
		p->ant = PF;
		p->canton = NULL;
	}
	else
	{
		PF = p;
		insertarProvincia(p->sig, n, gp);
		PF = NULL;
	}
}
//Insertar un canton
void insertarCanton(cantones *&c, string n, float gc)
{
	if (c == NULL)
	{
		c = new cantones;
		c->nombreCan = n;
		c->ganCant = gc;
		c->sigc = NULL;
		c->antc = CF;
		c->venta = NULL;
	}
	else
	{
		CF = c;
		insertarCanton(c->sigc, n, gc);
		CF = NULL;
	}
}
//Insertar canton en una provincia
void insertarCantonProvincia(string nonProv, string nonCant, float gc)
{
	bool band = false;
	aux = ini;
	while (aux != NULL)
	{
		if (aux->nombreProv == nonProv)
		{
			insertarCanton(aux->canton, nonCant, gc);
			band = true;
		}
		aux = aux->sig;
	}
	//CF=NULL;
	if (band == false)
	{
		cout << "La provincia no existe" << endl;
	}
}
//Insertar Ventas por Canton
void insertarVentaCanton(cantones *c, string nombCan, int mont, int an)
{
	bool band = false;
	auxc = c;
	VF = NULL;
	while (auxc != NULL)
	{
		if (auxc->nombreCan == nombCan)
		{
			insertarVenta(auxc->venta, mont, an);
			band = true;
		}
		auxc = auxc->sigc;
	}
	if (band == false)
	{
		cout << endl
			 << "Insertar: El canton no esta disponible" << endl;
	}
}
//Insertar Ventas por Provincia
void insertarVentaProvincia(string nomProv, string nombCan, int mont, int an)
{
	bool band = false;
	aux = ini;
	while (aux != NULL)
	{
		if (aux->nombreProv == nomProv)
		{
			insertarVentaCanton(aux->canton, nombCan, mont, an);
			band = true;
		}
		aux = aux->sig;
	}
	if (band == false)
	{
		cout << endl
			 << "Insertar: La provincia no esta disponible" << endl;
	}
}
//Mostrar ventas por Canton
void mostrarVentaCanton(cantones *c)
{
	auxc = c;
	while (auxc != NULL)
	{
		cout << "	" << auxc->nombreCan << "(" << auxc->ganCant << ")" << endl;
		mostrarVentas(auxc->venta);
		auxc = auxc->sigc;
	}
}
//Mostrar ventas por Provincia ()
void mostrarVentaProvincia()
{
	bool band = false;
	aux = ini;
	while (aux != NULL)
	{
		auxc = aux->canton;
		cout << aux->nombreProv << "(" << aux->ganProv << ")" << endl;
		mostrarVentaCanton(auxc);
		band = true;
		aux = aux->sig;
	}
	if (band == false)
	{
		cout << endl
			 << "mostrarventa: La provincia no esta disponible" << endl;
	}
}
//Suma universal (para invocar)
int sumar(ventas *v)
{
	float sum = 0;
	auxv = v;
	while (auxv != NULL)
	{
		sum = sum + auxv->monto;
		auxv = auxv->sigv;
	}
	return sum;
}
//Suma de un Canton
void sumarAnnosCanton()
{
	aux = ini;
	while (aux != NULL)
	{
		auxc = aux->canton;
		while (auxc != NULL)
		{
			if (auxc->ganCant != sumar(auxc->venta))
			{
				cout << "se detecto un error en el canton " << auxc->nombreCan << " de la provincia " << aux->nombreProv << endl;
				auxc->ganCant = sumar(auxc->venta);
				cout << "el error se ha corregido" << endl;
			}
			auxc = auxc->sigc;
		}
		aux = aux->sig;
	}
}
//Suma de toda la provincia
void sumarAnnosProvincia()
{
	aux = ini;
	while (aux != NULL)
	{
		auxc = aux->canton;
		float sumaTotProv = 0;
		while (auxc != NULL)
		{
			sumaTotProv = sumaTotProv + auxc->ganCant;
			auxc = auxc->sigc;
		}
		if (aux->ganProv != sumaTotProv)
		{
			cout << "se detecto un error en la provincia " << aux->nombreProv << endl;
			aux->ganProv = sumaTotProv;
			cout << "el error se ha corregido" << endl;
		}
		aux = aux->sig;
	}
}
//Eliminar annos
void eliminarAnnos(string nomProv, string nombCan, int an)
{
	ventas *auxvdel = NULL;

	aux = ini;
	auxv = datos;
	auxc = iniCan;
	auxvdel = datos;
	while (aux != NULL)
	{
		if (aux->nombreProv == nomProv)
		{
			auxc = aux->canton;
			while (auxc != NULL)
			{
				if (auxc->nombreCan == nombCan)
				{
					auxv = auxc->venta;

					while (auxv != NULL)
					{
						if (auxv->anno == an)
						{
							if (auxv->antv == NULL)
							{
								auxvdel = auxv;
								//cout << "es el primero" << endl;
								if(auxv->sigv!=NULL)
								{
									auxvdel = auxv->sigv;
									aux->canton->venta = auxvdel;
								}
								else
								{
									aux->canton->venta=NULL;
								}
							}
							else if (auxv->sigv == NULL)
							{
								auxvdel = auxv;
								//cout << "es el ultimo" << endl;
								//Combinacion 211 si funciona
								auxvdel = auxv->antv;
								auxvdel->sigv = auxv->sigv;
							}
							else
							{
								auxvdel = auxv;

								//<< "esta en la posision" << endl;
								//cout << aux->nombreProv << auxc->nombreCan << auxvdel->anno << endl;
								auxvdel = auxv->sigv;
								auxvdel->antv = auxv->antv;
								//auxv->getSigVen()->setAntVen(auxv->getAntVen());
								auxvdel = auxv;
								auxvdel = auxv->antv;
								auxvdel->sigv = auxv->sigv;
								//auxv->getAntVen()->setSigVen(auxv->getSigVen());
							}
						}
						auxv = auxv->sigv;
					}
				}
				auxc = auxc->sigc;
			}
		}
		aux = aux->sig;
	}
}
//Eliminar canton
void eliminarCanton(string nomProv, string nombCan)
{
	cantones *auxcdel = NULL;
	aux = ini;
	while (aux != NULL)
	{
		if (aux->nombreProv == nomProv)
		{
			auxc = aux->canton;
			while (auxc != NULL)
			{
				if (auxc->nombreCan == nombCan)
				{
					auxv = auxc->venta;
					while (auxv != NULL)
					{
						if (auxv->antv == NULL)
						{
							aux->canton->venta = auxv->sigv;
						}
						auxv = auxv->sigv;
					}
					//cout<<"annos eliminados"<<endl;
					//Canton
					if (auxc->antc == NULL)
					{
						auxcdel = auxc;
						auxcdel = auxc->sigc;
						aux->canton = auxcdel;
					}
					else if (auxc->sigc == NULL)
					{
						auxcdel = auxc;
						auxcdel = auxc->antc;
						auxcdel->sigc = auxc->sigc;
					}
					else
					{
						auxcdel = auxc;
						auxcdel = auxc->sigc;
						auxcdel->antc = auxc->antc;
						auxcdel = auxc;
						auxcdel = auxc->antc;
						auxcdel->sigc = auxc->sigc;
					}
				}
			auxc = auxc->sigc;
			}
			//cout<<"canton eliminado"<<endl;
		}
		aux = aux->sig;
	}
	
}
//Eliminar provincia
void eliminarProvincia(string nomProv)
{
	provincias *auxpdel = NULL;
	aux = ini;
	while (aux != NULL)
	{
		if (aux->nombreProv == nomProv)
		{
			auxc = aux->canton;
			while (auxc != NULL)
			{
				auxv = auxc->venta;
				while (auxv != NULL)
					{
						if (auxv->antv == NULL)
						{
							aux->canton->venta = auxv->sigv;
						}
						auxv = auxv->sigv;
					}
				//Canton
				if (auxc->antc == NULL)
				{
					aux->canton = auxc->sigc;
				}
				auxc = auxc->sigc;
			}
			//Provincia
			if (aux->ant == NULL)
			{
				auxpdel = aux;
				auxpdel = aux->sig;
				ini = auxpdel;
			}
			else if (aux->sig == NULL)
			{
				auxpdel = aux;
				auxpdel = aux->ant;
				auxpdel->sig = aux->sig;
			}
			else if (aux->nombreProv == nomProv)
			{
				auxpdel = aux;
				auxpdel = aux->sig;
				auxpdel->ant = aux->ant;
				auxpdel = aux;
				auxpdel = aux->ant;
				auxpdel->sig = aux->sig;
			}
		}
		aux = aux->sig;
	}
}

//MAIN
int main(int argc, char *argv[])
{
	int opc;

	//Elminar
	string np, nc = "";
	int an = 0;
	float mont=0;

	//Bienvenida
	cout<<"Programa de Administracion de flota de Buses"<<endl; 
	cout<<"Coorporacion Umbrela Costa Rica"<<endl; 
	cout<<"V 1.1"<<endl;
	for(int i=0; i<6;i++){ 
		cout<<" - "; 
		Sleep(400);
	}

	{
		do
		{
			system("CLS");
			cout << "1-Insertar datos predeterminados(diagrama)" << endl;
			cout << "2-Mostrar todos los datos" << endl;
			cout << "3-Revisar datos y corregir si es necesario" << endl;
			cout << "4-Eliminar annos-" << endl;
			cout << "5-Eliminar canton" << endl;
			cout << "6-Eliminar Provincia" << endl;
			cout << "7-Agregar una nueva Provincia" << endl;
			cout << "8-Agregar un nuevo Canton en una Provincia" << endl;
			cout << "9-Agregar una nueva venta (monto y anno)" << endl;
			cout << "10-Salir" << endl;
			cout << "- - - - - - - - - - - - - - - - - - - - -" << endl;
			cin >> opc;

			switch (opc)
			{
			case 1:
				//Insertar Provincias
				insertarProvincia(ini, "Puntarenas", 35000);
				insertarProvincia(ini, "Alajuela", 45000);
				insertarProvincia(ini, "Limon", 25500);
				insertarProvincia(ini, "Cartago", 35000);
				insertarProvincia(ini, "San_Jose", 80000);
				insertarCantonProvincia("Puntarenas", "Buenos_Aires", 10000);
				insertarCantonProvincia("Puntarenas", "Esparza", 7000);
				insertarCantonProvincia("Puntarenas", "Golfito", 18000);
				insertarCantonProvincia("Alajuela", "Grecia", 10000);
				insertarCantonProvincia("Alajuela", "Atenas", 7000);
				insertarCantonProvincia("Alajuela", "Zarcero", 18000);
				insertarCantonProvincia("Limon", "Limon", 10500);
				insertarCantonProvincia("Limon", "Siquirres", 15000);
				insertarCantonProvincia("Cartago", "Turrialba", 30000);
				insertarCantonProvincia("San_Jose", "San_Jose", 10000);
				insertarCantonProvincia("San_Jose", "Perez_Zeledon", 15000);
				insertarCantonProvincia("San_Jose", "Escazu", 18000);
				insertarCantonProvincia("San_Jose", "Santa_Ana", 7000);
				insertarVentaProvincia("Puntarenas", "Buenos_Aires", 9000, 2021);
				insertarVentaProvincia("Puntarenas", "Esparza", 6000, 2021);
				insertarVentaProvincia("Puntarenas", "Esparza", 4000, 2020);
				insertarVentaProvincia("Puntarenas", "Golfito", 18000, 2021);
				insertarVentaProvincia("Alajuela", "Grecia", 7000, 2021);
				insertarVentaProvincia("Alajuela", "Atenas", 12000, 2021);
				insertarVentaProvincia("Alajuela", "Atenas", 3000, 2020);
				insertarVentaProvincia("Alajuela", "Zarcero", 10000, 2021);
				insertarVentaProvincia("Alajuela", "Zarcero", 3000, 2020);
				insertarVentaProvincia("Limon", "Limon", 3000, 2021);
				insertarVentaProvincia("Limon", "Limon", 3500, 2020);
				insertarVentaProvincia("Limon", "Limon", 4000, 2019);
				insertarVentaProvincia("Limon", "Siquirres", 5000, 2021);
				insertarVentaProvincia("Limon", "Siquirres", 10000, 2020);

				insertarVentaProvincia("Cartago", "Turrialba", 5000, 2021);
				insertarVentaProvincia("Cartago", "Turrialba", 3000, 2020);
				insertarVentaProvincia("Cartago", "Turrialba", 2000, 2019);
				insertarVentaProvincia("Cartago", "Turrialba", 1000, 2018);
				insertarVentaProvincia("Cartago", "Turrialba", 8000, 2017);
				insertarVentaProvincia("San_Jose", "San_Jose", 5000, 2021);
				insertarVentaProvincia("San_Jose", "San_Jose", 5000, 2020);
				insertarVentaProvincia("San_Jose", "Perez_Zeledon", 3000, 2021);
				insertarVentaProvincia("San_Jose", "Perez_Zeledon", 1000, 2020);
				insertarVentaProvincia("San_Jose", "Perez_Zeledon", 5000, 2019);
				insertarVentaProvincia("San_Jose", "Perez_Zeledon", 6000, 2018);
				insertarVentaProvincia("San_Jose", "Escazu", 15000, 2021);
				insertarVentaProvincia("San_Jose", "Escazu", 3000, 2020);
				insertarVentaProvincia("San_Jose", "Santa_Ana", 7000, 2021);
				break;
			case 2:
				mostrarVentaProvincia();
				break;
			case 3:
				sumarAnnosCanton();
				sumarAnnosProvincia();
				break;
			case 4:
				cout << "escriba el nombre de la provincia" << endl;
				cin >> np;
				cout << "escriba el nombre del canton" << endl;
				cin >> nc;
				cout << "dijite el anno a eliminar" << endl;
				cin >> an;
				eliminarAnnos(np, nc, an);
				sumarAnnosCanton();
				sumarAnnosProvincia();
				break;

			case 5:
				cout << "escriba el nombre de la provincia" << endl;
				cin >> np;
				cout << "escriba el nombre del canton" << endl;
				cin >> nc;
				eliminarCanton(np, nc);
				sumarAnnosProvincia();
				break;
			case 6:
				cout << "escriba el nombre de la provincia" << endl;
				cin >> np;
				eliminarProvincia(np);
				break;
			case 7:
				cout << "escriba el nombre de la provincia a agregar" << endl;
				cin >> np;
				insertarProvincia(ini, np, 0);
				break;

			case 8:
				cout << "escriba el nombre de la provincia" << endl;
				cin >> np;
				cout << "escriba el nombre del canton a agregar" << endl;
				cin >> nc;
				insertarCantonProvincia(np,nc,0);
				break;
			case 9:
				cout << "escriba el nombre de la provincia" << endl;
				cin >> np;
				cout << "escriba el nombre del canton" << endl;
				cin >> nc;
				cout << "dijite el anno a agregar" << endl;
				cin >> an;
				cout << "dijite el monto"<< endl;
				cin >> mont;
				insertarVentaProvincia(np, nc, mont, an);
				break;
			}
			system("PAUSE");
		} while (opc != 10);
	}

	return 0;
}
