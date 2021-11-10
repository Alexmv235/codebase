#include <iostream>
//Alexander Montero
using namespace std;
struct ventas
{
	int anno;
	float monto;
	ventas *sig;
	ventas *ant;

	ventas()
	{
		sig = NULL;
		ant = NULL;
	}
	void setSigVen(ventas *s) { sig = s; }
	void setAntVen(ventas *a) { ant = a; }
	ventas *getSigVen() { return sig; }
	ventas *getAntVen() { return ant; }
};
struct cantones
{
	float ganCant;
	string nombreCan;
	cantones *sig;
	cantones *ant;
	ventas *venta;

	cantones()
	{
		sig = NULL;
		ant = NULL;
	}
	void setSigCan(cantones *s) { sig = s; }
	void setAntCan(cantones *a) { ant = a; }
	cantones *getSigCan() { return sig; }
	cantones *getAntCan() { return ant; }
};
struct provincias
{
	float ganProv;
	string nombreProv;
	provincias *sig;
	provincias *ant;
	cantones *canton;

	provincias()
	{
		sig = NULL;
		ant = NULL;
	}
	void setSigProv(provincias *s) { sig = s; }
	void setAntProv(provincias *a) { ant = a; }
	provincias *getSigProv() { return sig; }
	provincias *getAntProv() { return ant; }
};
provincias *ini = NULL, *aux = NULL;
cantones *iniCan = NULL, *auxc = NULL;
ventas *datos = NULL, *auxv = NULL;

//Insertar Ventas
void insertarVenta(ventas *&v, int m, int an)
{
	if (v == NULL)
	{
		v = new ventas;
		v->monto = m;
		v->anno = an;
		v->sig = NULL;
	}
	else
	{
		insertarVenta(v->sig, m, an);
	}
}
//Mostrar ventas
void mostrarVentas(ventas *v)
{
	cout << "		";
	while (v != NULL)
	{
		cout << v->monto << "(" << v->anno << ")"
			 << " -> ";
		v = v->sig;
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
		p->canton = NULL;
	}
	else
	{
		insertarProvincia(p->sig, n, gp);
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
		c->sig = NULL;
		c->venta = NULL;
	}
	else
	{
		insertarCanton(c->sig, n, gc);
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
	while (auxc != NULL)
	{
		if (auxc->nombreCan == nombCan)
		{
			insertarVenta(auxc->venta, mont, an);
			band = true;
		}
		auxc = auxc->sig;
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
		auxc = auxc->sig;
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
		while (auxc != NULL)
		{
			cout << aux->nombreProv << "(" << aux->ganProv << ")" << endl;
			mostrarVentaCanton(auxc);
			band = true;
		}
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
		auxv = auxv->sig;
	}
	return sum;
}
//Suma de un Canton
void sumarVentasCanton()
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
			auxc = auxc->sig;
		}
		aux = aux->sig;
	}
}
//Suma de toda la provincia
void sumarVentasProvincia()
{
	aux = ini;
	while (aux != NULL)
	{
		auxc = aux->canton;
		float sumaTotProv = 0;
		while (auxc != NULL)
		{
			sumaTotProv = sumaTotProv + auxc->ganCant;
			auxc = auxc->sig;
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
	aux = ini;
	auxc = iniCan;
	while (aux != NULL)
	{
		if (aux->nombreProv == nomProv)
		{
			while (aux->canton != NULL)
			{
				if (aux->canton->nombreCan == nombCan)
				{
					while (aux->canton->venta != NULL)
					{
						if (aux->canton->venta->anno == an && aux->canton->venta->getAntVen() == NULL)
						{
							//cout<<"es el primero"<<endl;
							datos = aux->canton->venta->getSigVen();
						}
						else if (aux->canton->venta->anno == an && aux->canton->venta->getSigVen() == NULL)
						{
							//cout<<"es el ultimo"<<endl;
							//Combinacion 211 si funciona
							aux->canton->venta->getAntVen()->setSigVen(aux->canton->venta->getSigVen());
						}
						else if (aux->canton->venta->anno == an)
						{
							aux->canton->venta->getSigVen()->setAntVen(aux->canton->venta->getAntVen());
							aux->canton->venta->getAntVen()->setSigVen(aux->canton->venta->getSigVen());
						}
						aux->canton->venta = aux->canton->venta->sig;
					}
				}
				aux->canton = aux->canton->sig;
			}
		}
		aux = aux->sig;
	}
}
//Eliminar canton
void eliminarCanton(string nomProv, string nombCan)
{
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
						if (auxv->getAntVen() == NULL)
						{
							//cout<<"es el primero"<<endl;
							datos = auxv->getSigVen();
						}
						else if (auxv->getSigVen() == NULL)
						{
							//cout<<"es el ultimo"<<endl;
							//Combinacion 211 si funciona
							auxv->getAntVen()->setSigVen(auxv->getSigVen());
						}
						else
						{
							auxv->getSigVen()->setAntVen(auxv->getAntVen());
							auxv->getAntVen()->setSigVen(auxv->getSigVen());
						}
						auxv = auxv->sig;
						//Canton
						if (auxc->nombreCan == nombCan && auxc->getAntCan() == NULL)
						{
							cout << "es el primero" << endl;
							iniCan = auxc->getSigCan();
						}
						else if (auxc->nombreCan == nombCan && auxc->getSigCan() == NULL)
						{
							//cout<<"es el ultimo"<<endl;
							//Combinacion 211 si funciona
							auxc->getAntCan()->setSigCan(auxc->getSigCan());
						}
						else if (auxc->nombreCan == nombCan)
						{
							auxc->getSigCan()->setAntCan(auxc->getAntCan());
							auxc->getAntCan()->setSigCan(auxc->getSigCan());
						}
					}
				}
				auxc = auxc->sig;
			}
		}
		aux = aux->sig;
	}
}
//Eliminar provincia
void eliminarProvincia(string nomProv)
{
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
					if (auxv->getAntVen() == NULL)
					{
						//cout<<"es el primero"<<endl;
						datos = auxv->getSigVen();
					}
					else if (auxv->getSigVen() == NULL)
					{
						//cout<<"es el ultimo"<<endl;
						//Combinacion 211 si funciona
						auxv->getAntVen()->setSigVen(auxv->getSigVen());
					}
					else
					{
						auxv->getSigVen()->setAntVen(auxv->getAntVen());
						auxv->getAntVen()->setSigVen(auxv->getSigVen());
					}
					auxv = auxv->sig;
				}
				//Canton
				if (auxc->getAntCan() == NULL)
				{
					iniCan = auxc->getSigCan();
				}
				else if (auxc->getSigCan() == NULL)
				{
					//cout<<"es el ultimo"<<endl;
					//Combinacion 211 si funciona
					auxc->getAntCan()->setSigCan(auxc->getSigCan());
				}
				else
				{
					auxc->getSigCan()->setAntCan(auxc->getAntCan());
					auxc->getAntCan()->setSigCan(auxc->getSigCan());
				}
				auxc = auxc->sig;
			}
			//Provincia
			if (aux->nombreProv == nomProv && aux->getAntProv() == NULL)
			{
				ini = aux->getSigProv();
			}
			else if (aux->nombreProv == nomProv && aux->getSigProv() == NULL)
			{
				//cout<<"es el ultimo"<<endl;
				//Combinacion 211 si funciona
				aux->getAntProv()->setSigProv(aux->getSigProv());
			}
			else if (aux->nombreProv == nomProv)
			{
				aux->getSigProv()->setAntProv(aux->getAntProv());
				aux->getAntProv()->setSigProv(aux->getSigProv());
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

	{
		do
		{
			system("CLS");
			cout << "1-Insertar datos predeterminados(diagrama)" << endl;
			cout << "2-Mostrar todos los datos" << endl;
			cout << "3-Revisar datos y corregir si es necesario" << endl;
			cout << "4-Eliminar annos-" << endl;
			cout << "5-Eliminar canton" << endl;
			cout << "6-Salir" << endl;
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
				insertarVentaProvincia("Cartago", "Turrialba", 200, 2019);
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
				sumarVentasCanton();
				sumarVentasProvincia();
				break;
			case 4:
				cout << "escriba el nombre de la provincia" << endl;
				cin >> np;
				cout << "escriba el nombre del canton" << endl;
				cin >> nc;
				cout << "dijite el anno a eliminar" << endl;
				cin >> an;
				eliminarAnnos(np, nc, an);
				sumarVentasCanton();
				sumarVentasProvincia();
				break;

			case 5:
				cout << "escriba el nombre de la provincia" << endl;
				cin >> np;
				cout << "escriba el nombre del canton" << endl;
				cin >> nc;
				eliminarCanton(np, nc);
				sumarVentasProvincia();
				break;
			case 6:
				cout << "escriba el nombre de la provincia" << endl;
				cin >> np;
				eliminarProvincia(np);
				break;
			}
			system("PAUSE");
		} while (opc != 7);
	}

	return 0;
}
