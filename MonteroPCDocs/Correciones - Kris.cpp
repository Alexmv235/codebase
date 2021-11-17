//1
//Lo primero es donde están estas lineas
//Esto lo puede pegar a como esta si no ha hecho cambios

cants *inicant=NULL, *auxcant=NULL, *CantFinal=NULL;;
years *iniyears=NULL,*auxyears=NULL, *yearFinal=NULL;

//2
//Este tambien lo puede pegar así
void insertaryear(years *&a, int m, int an)
{
	if(a ==NULL)
	{
		a=new years;
		a->venta=m;
		a->year=an;
		a->sig=NULL;
		a->ant=yearFinal;
	}
	else
	{
		yearFinal=a;
		insertarAnno(a->sig,m,an);
		yearFinal=NULL;
	}
}
//3
//Este tambien
void insertarcant(cants *&c, string n, float gc)
{
	if(c ==NULL)
	{
		c=new cants;
		c->nombrecant=n;
		c->ventacant=gc;
		c->sig=NULL;
		c->year=NULL;
		c->ant=yearFinal;
	}
	else
	{
		yearFinal=c;
		insertarcant(c->sig,n, gc);
		yearFinal=NULL;
	}
}
//  Ahora viene los de eliminar
// Poner atencion a estos

//Eliminar annos
void eliminarAnnos(string nomProv, string nombCan, int an)
{
	//Cambier auxvdel por auxyearsDelete
    annos *auxvdel = NULL;

    aux = ini;
    //Cambiar todos los auxv por auxyears (o por el auxiliar para ventas)
    //Cambiar "datos" por iniyears (o por el ini de los annos)
	auxv = datos;
    //Cambiar todos los auxc por auxcant (o por el auxiliar para cantones)
    //Cambiar "inican" por inicant (o por el ini de los cantones)
	auxc = iniCan;
    //Cambiar todos los auxvdel por auxyearsDelete (o por el nombre que le ponga al puntero)
    //Cambiar "datos" por iniyears (o por el ini de los annos)
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
								auxvdel = auxv->sigv;
								aux->canton->venta = auxvdel;
							}
							else if (auxv->sigv == NULL)
							{
								auxvdel = auxv;
								auxvdel = auxv->antv;
								auxvdel->sigv = auxv->sigv;
							}
							else
							{
								auxvdel = auxv;
								auxvdel = auxv->sigv;
								auxvdel->antv = auxv->antv;
								auxvdel = auxv;
								auxvdel = auxv->antv;
								auxvdel->sigv = auxv->sigv;
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
	//Cambier auxvdel por auxCantDelete
    
    cantones *auxcdel = NULL;
	aux = ini;
    //Cambiar todos los auxv por auxyears (o por el auxiliar para ventas)
    //Cambiar "datos" por iniyears (o por el ini de los annos)
	auxv = datos;
    //Cambiar todos los auxc por auxcant (o por el auxiliar para cantones)
    //Cambiar "inican" por inicant (o por el ini de los cantones)
	auxc = iniCan;
    //Cambiar todos los auxcdel por auxCantDelete (o por el nombre que le ponga al puntero)
    //Cambiar "iniCan" por iniyears (o por el ini de los cantones)
	auxcdel = iniCan;

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
		}
		aux = aux->sig;
	}
	
}
//Eliminar provincia
void eliminarProvincia(string nomProv)
{
	//Cambiar estos igual que los anteriores
	//Cambiar el *auxpdel (invertarse un nombre)
	ventas *auxvdel = NULL;
	cantones *auxcdel = NULL;
	provincias *auxpdel = NULL;
	aux = ini;
    //Cambiar todos los auxv por auxyears (o por el auxiliar para ventas)
    //Cambiar "datos" por iniyears (o por el ini de los annos)
	auxv = datos;
    //Cambiar todos los auxc por auxcant (o por el auxiliar para cantones)
    //Cambiar "inican" por inicant (o por el ini de los cantones)
	auxc = iniCan;
    //Cambiar todos los auxcdel por auxCantDelete (o por el nombre que le ponga al puntero)
    //Cambiar "iniCan" por iniyears (o por el ini de los cantones)
	auxcdel = iniCan;
    //Cambiar todos los auxvdel por auxyearsDelete (o por el nombre que le ponga al puntero)
    //Cambiar "datos" por iniyears (o por el ini de los annos)
	auxvdel = datos;


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
						auxvdel = auxv;
						auxvdel = auxv->sigv;
						aux->canton->venta = auxvdel;
					}
					else if (auxv->sigv == NULL)
					{
						auxvdel = auxv;
						auxvdel = auxv->antv;
						auxvdel->sigv = auxv->sigv;
					}
					else
					{
						auxvdel = auxv;
						auxvdel = auxv->sigv;
						auxvdel->antv = auxv->antv;
						auxvdel = auxv;
						auxvdel = auxv->antv;
						auxvdel->sigv = auxv->sigv;
					}
				auxv = auxv->sigv;
				}
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
				auxc = auxc->sigc;
			}
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