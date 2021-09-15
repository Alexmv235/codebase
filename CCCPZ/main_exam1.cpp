clsColeccion A1;

A1.definirPlantas();
A1.definirSurcos();
A1.definirPrecios();
A1.limpiarTerreno();

int opc;
{
	do
	{
		system("CLS");
		cout<<"1- "<<endl;
		cout<<"2-"<<endl;
		cout<<"3-"<<endl;
		cout<<"4-"<<endl;
		cout<<"5-"<<endl;
		cout<<"6-"<<endl;
		cout<<"7-"<<endl;
		cout<<"8-"<<endl;
		cout<<"9- "<<endl;
		cout<<"10- "<<endl;
		cout<<"11- "<<endl;
		cout<<"12-Salir"<<endl;
		cin>>opc;
		switch(opc)
		{
		case 1:
			//limpiar terreno
			break;
		case 2:
			//Sembrar terreno
			break;
		case 3:
			//espacio de tiempo (metodo 4)
			break;
		case 4:
			//Plantas cambian de estado
			break;
		case 5:
			//Cosecha por tipo de planta
			break;
		case 6:
			//Cosecha en todo el terreno
			break;
		case 7:
			//Precio por planta
			break;
		case 8:
			//Ganancia por planta
			break;
		case 9:
			//Ganancia por surco
			break;
		case 10:
			// limpiar de surco m a surco n
			break;
			
		case 11:
			A1.mostrarTerreno();
			break;
		case 12:
			
			break;
		}
		system("PAUSE"); 
	} while(opc!=12);
	
}
