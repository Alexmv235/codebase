#include <iostream>
#include <sstream>

using namespace std;

class Contenedor {
	private:
		char hilera[30];
		int tamano;
		int cantidad;
	public:
		Contenedor(int n) {
			cantidad = 0;
			tamano = n;
			for(int i = 0; i < tamano; i++)
				hilera[i] = ' ';
		}
		int getCantidad() {
			return this->cantidad;
		}
		int getTamano() {
			return this->tamano;
		}
		void setCantidad(int cantidad) {
			this->cantidad = cantidad;
		}
		void setTamano(int tamano) {
			this->tamano = tamano;
		}
		void insertarElemento(char elem) {
			if (cantidad < tamano) {
				hilera[cantidad] = elem;
				cantidad++;
			}
		}
		string toString() {
			stringstream s;
			for (int i = 0; i < cantidad; i++)
				s << hilera[i];
			s << endl;
			return s.str();
		}
		
		void insertarPalabraMinuscula(char letra){
			int numAscii = (int)letra; 
			if(numAscii > 64 && numAscii < 91){ 
				numAscii+=32;    				
			}
			char nuevaLetra = (char)numAscii; 
			insertarElemento(nuevaLetra);
		}
			
		void plural(){
			char ultLetra = hilera[cantidad-1];
			if(ultLetra!='s'){
				if(ultLetra!='a' && ultLetra!='e' && ultLetra!='i' && ultLetra!='o' && ultLetra!='u' && ultLetra!='z'){
					hilera[cantidad]='e';
					hilera[cantidad+1]='s';
					cantidad+=2;
				}else{
					if(ultLetra=='z'){
						hilera[cantidad-1]='c';
						hilera[cantidad]='e';
						hilera[cantidad+1]='s';
						cantidad+=2;
					}else{
						hilera[cantidad]='s';
						cantidad+=1;
					}
				}
			}
		}
			
		void codifica(){
			for(int i=0; i<cantidad; i++){
				switch(hilera[i]){
					case 'a':
						hilera[i]='1';
						break;
					case 'e':
						hilera[i]='2';
						break;
					case 'i':
						hilera[i]='3';
						break;
					case 'o':
						hilera[i]='4';
						break;
					case 'u':
						hilera[i]='5';
						break;
				}
			}
		}
			
		bool is_palindroma(){
			int temp = cantidad-1;
			for(int i=0; i<cantidad; i++){ //i=0  temp=8 - 
				if(hilera[i]!=hilera[temp]){
					return false;
				}
				temp--;
			}
			return true;
		}
};


int main(int argc, char *argv[]) {
	
	Contenedor contenedor(15);
	Contenedor contenedor2(15);
	
	//Prueba 1 Punto
	string palabra;
	cout<<"********** Comprobador de palabras******"<<endl;
	cout<<"Palabra 1: "<<palabra<<endl;;
	
	for(int i=0; i<6; i++){
		contenedor.insertarPalabraMinuscula(palabra[i]);
	}

	cout<<"Palabra en minuscula: ";
	cout<<(contenedor.toString());
	
	if(contenedor.is_palindroma()){
			cout<<"Es palindroma";
	}else{
			cout<<"No es palindroma";
	}
	contenedor.plural();
	cout<<endl<<"Palabra en plural: ";
	cout<<(contenedor.toString());
	
	contenedor.codifica();
	cout<<"Palabra codificada: ";
	cout<<(contenedor.toString());
	
	cout<<endl<<"********************************"<<endl;
	palabra= "ReConoCER";
	cout<<"Palabra 2: "<<palabra<<endl;
	
	for(int i=0; i<9; i++){
		contenedor2.insertarPalabraMinuscula(palabra[i]);
	}
	
	cout<<"Palabra en minuscula: ";
	cout<<(contenedor2.toString());
	
	if(contenedor2.is_palindroma()){
		cout<<"Es palindroma";
	}else{
		cout<<"No es palindroma";
	}
	
	contenedor2.plural();
	cout<<endl<<"Palabra en plural: ";
	cout<<(contenedor2.toString());
	
	contenedor2.codifica();
	cout<<"Palabra codificada: ";
	cout<<(contenedor2.toString());
	cout<<endl;
	return 0;
}








