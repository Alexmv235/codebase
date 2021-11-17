//1
//Lo primero es donde están estas lineas
//Esto lo puede pegar a como esta si no ha hecho cambios

cantones *iniCanton=NULL, *auxcanton=NULL, *cantonFinal=NULL;
annos *iniAnnos=NULL,*auxAnnos=NULL, *annoFinal=NULL;

//2
//Este tambien lo puede pegar así
void insertarAnno(annos *&a, int m, int an)
{
	if(a ==NULL)
	{
		a=new annos;
		a->venta=m;
		a->anno=an;
		a->sig=NULL;
		a->ant=annoFinal;
	}
	else
	{
		annoFinal=a;
		insertarAnno(a->sig,m,an);
		annoFinal=NULL;
	}
}
//3
//Este tambien
void insertarCanton(cantones *&c, string n, float gc)
{
	if(c ==NULL)
	{
		c=new cantones;
		c->nombreCanton=n;
		c->ventaCanton=gc;
		c->sig=NULL;
        c->ant=cantonFinal;
		c->anno=NULL;
	}
	else
	{
        cantonFinal=c;
		insertarCanton(c->sig,n, gc);
        cantonFinal=c;
	}
}
//  Ahora viene los de eliminar
// Poner atencion a estos

//Eliminar annos
void eliminarAnnos(string nomProv, string nombCan, int an)
{
	//Cambier auxvdel por auxAnnosEliminar
    annos *auxvdel = NULL;

    aux = ini;
    //Cambiar todos los auxv por auxAnnos (o por el auxiliar para ventas)
    //Cambiar "datos" por iniAnnos (o por el ini de los annos)
	auxv = datos;
    //Cambiar todos los auxc por auxcanton (o por el auxiliar para cantones)
    //Cambiar "inican" por iniCanton (o por el ini de los cantones)
	auxc = iniCan;
    //Cambiar todos los auxvdel por auxAnnosEliminar (o por el nombre que le ponga al puntero)
    //Cambiar "datos" por iniAnnos (o por el ini de los annos)
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
	//Cambier auxvdel por auxCantonesEliminar
    
    cantones *auxcdel = NULL;
	aux = ini;
    //Cambiar todos los auxv por auxAnnos (o por el auxiliar para ventas)
    //Cambiar "datos" por iniAnnos (o por el ini de los annos)
	auxv = datos;
    //Cambiar todos los auxc por auxcanton (o por el auxiliar para cantones)
    //Cambiar "inican" por iniCanton (o por el ini de los cantones)
	auxc = iniCan;
    //Cambiar todos los auxcdel por auxCantonesEliminar (o por el nombre que le ponga al puntero)
    //Cambiar "iniCan" por iniCanton (o por el ini de los cantones)
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
	ventas *auxvdel = NULL;
	cantones *auxcdel = NULL;
	provincias *auxpdel = NULL;
	aux = ini;
    //Cambiar todos los auxv por auxAnnos (o por el auxiliar para ventas)
    //Cambiar "datos" por iniAnnos (o por el ini de los annos)
	auxv = datos;
    //Cambiar todos los auxc por auxcanton (o por el auxiliar para cantones)
    //Cambiar "inican" por iniCanton (o por el ini de los cantones)
	auxc = iniCan;
    //Cambiar todos los auxcdel por auxCantonesEliminar (o por el nombre que le ponga al puntero)
    //Cambiar "iniCan" por iniCanton (o por el ini de los cantones)
	auxcdel = iniCan;
    //Cambiar todos los auxvdel por auxAnnosEliminar (o por el nombre que le ponga al puntero)
    //Cambiar "datos" por iniAnnos (o por el ini de los annos)
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
