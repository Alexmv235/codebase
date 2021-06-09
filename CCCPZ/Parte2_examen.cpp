//Colegio Científico, PZ
//Desarrollado por:
//AlexanderMonteroVargas
//OscarMarioEspinozaCamacho
//GeiselThaisHernandezQuesada
//2021

#include <iostream>
#include <sstream>
#include <time.h>

using namespace std;

const int tam = 7;

class ContenedorMatriz
{
private:
	int ventaProd[tam][tam];

public:
	ContenedorMatriz()
	{
		for (int i = 0; i < tam; i++)
		{
			for (int j = 0; j < tam; j++)
			{
				ventaProd[i][j] = 0;
			}
		}
	}
	// Destructor
	~ContenedorMatriz()
	{

		//Set&get
	}
	void setPos(int i, int j, int valor)
	{
		ventaProd[i][j] = valor;
	}
	int getPos(int i, int j)
	{
		return ventaProd[i][j];
	}

	//Llenar matriz
	void llenarMatriz()
	{
		int num;
		srand(time(NULL));
		for (int i = 0; i < tam; i++)
			for (int j = 0; j < tam; j++)
			{
				num = 1 + rand() % (100 - 1);
				ventaProd[i][j] = num;
			}
	}

	// Obtener suma del producto toda la semana
	int getProductoSemana(int producto)
	{
		int sumaProducto = 0;
		for (int j = 0; j < 7; j++)
		{
			sumaProducto += ventaProd[producto][j];
		}
		return sumaProducto;
	}
	// Metodo para seber si se vendió toda la semana
	int seVendioProductoSemana(int producto)
	{
		for (int j = 0; j < 7; j++)
		{
			if (ventaProd[producto][j] == 0)
			{
				return false;
			}
		}
		return true;
	}
	// Para saber el dia con mas ventas
	int diaMayorVentasSemana(int producto)
	{
		int mayorVentaDia = 0;
		int mayorVentaValor = ventaProd[producto][0];
		for (int j = 1; j < 7; j++)
		{
			if (ventaProd[producto][j] > mayorVentaValor)
			{
				mayorVentaValor = ventaProd[producto][j];
				mayorVentaDia = j;
			}
		}
		return mayorVentaDia;
	}
	//Para	saber el producto menos vendido en el dia
	int productoMenosVentasDia(int dia)
	{
		int menorVentaProducto = 0;
		int menorVentaValor = ventaProd[0][dia];
		for (int i = 1; i < 7; i++)
		{
			if (ventaProd[i][dia] < menorVentaValor)
			{
				menorVentaValor = ventaProd[i][dia];
				menorVentaProducto = i;
			}
		}
		return menorVentaProducto;
	}
	//string to string
	string toString()
	{
		stringstream s;
		for (int i = 0; i < tam; i++)
		{
			for (int j = 0; j < tam; j++)
				s << ventaProd[i][j] << "\t";
			s << endl;
		}
		s << endl;
		return s.str();
	}
};

int main(int argc, char *argv[])
{

	//Para mostrar los productos y los dias en el resultado.
	string productos[] = {"Arroz", "Frijoles", "Azucar", "Leche", "Harina", "Huevos", "Agua"};
	string dias[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

	//Mostrar lista de productos y dias
	cout << "Lista de Productos:" << endl;
	cout << "Arroz - 0" << endl;
	cout << "Frijoles - 1" << endl;
	cout << "Azucar - 2" << endl;
	cout << "Leche - 3" << endl;
	cout << "Harina - 4" << endl;
	cout << "Huevos - 5" << endl;
	cout << "Agua - 6" << endl;
	cout << endl
		 << endl;
	cout << "Lista de Dias:" << endl;
	cout << "Lunes - 0" << endl;
	cout << "Martes - 1" << endl;
	cout << "Miercoles - 2" << endl;
	cout << "Jueves - 3" << endl;
	cout << "Viernes - 4" << endl;
	cout << "Sabado - 5" << endl;
	cout << "Domingo - 6" << endl;
	cout << endl
		 << endl;

	// Llenar e imprimir, deja un espacio con valor 0 para probar el metodo de "seVendioProductoSemana"
	ContenedorMatriz contenedor1;
	contenedor1.llenarMatriz();
	contenedor1.setPos(3, 4, 0);
	cout << contenedor1.toString();
	cout << endl
		 << endl;

	//Solicitar producto y dia para definir cantidad.
	int producto, dia;
	cout << "Digite el numero del producto mostrado en la lista: ";
	cin >> producto;
	cout << endl
		 << "Digite el numero del dia mostrado en la lista: ";
	cin >> dia;
	cout << endl
		 << "El dia " << dias[dia] << " se vendio la cantidad de " << contenedor1.getPos(producto, dia) << " del producto " << productos[producto];
	cout << endl;

	// Digita el producto para saber la cantidad de veces que se vendio en la semana
	cout << endl;
	cout << "Digite el numero del producto para saber cuantas veces se vendio en la semana: ";
	cin >> producto;
	cout << endl
		 << "Durante la semana se vendio la cantidad de " << contenedor1.getProductoSemana(producto) << " del producto " << productos[producto];
	cout << endl;

	// Digita el producto para saber si se vendio toda la semana o no
	cout << endl;
	cout << "Digite el numero del producto para saber si se vendio todos los dias de la semana: ";
	cin >> producto;
	if (contenedor1.seVendioProductoSemana(producto))
	{
		cout << "El producto " << productos[producto] << " se vendio durante toda la semana";
	}
	else
	{
		cout << "El producto " << productos[producto] << " no se vendio algun dia durante toda la semana";
	}
	cout << endl
		 << endl;

	//Digita el prodcuto para saber cual fue el día de mayor venta
	cout << endl;
	cout << "Digite el numero del producto para saber cual fue el dia de mayor venta: ";
	cin >> producto;
	cout << endl
		 << "El dia " << dias[contenedor1.diaMayorVentasSemana(producto)] << " se hicieron mas ventas del producto " << productos[producto];
	cout << endl
		 << endl;

	//Digita el dia para saber cual fue el producto menos vendido
	cout << endl;
	cout << "Digite el numero del dia para saber cual fue el producto menos vendido: ";
	cin >> dia;
	cout << endl
		 << "El dia " << dias[dia] << " se hicieron menos ventas del producto " << productos[contenedor1.productoMenosVentasDia(dia)];
	cout << endl;

	return 0;
}
