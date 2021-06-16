#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	float suma, quiz, exm, tarea, puntos = 0;
		
	quiz=(50*0.075) + (70*0.075) + (83.33*0.075) + (91.67*0.075) ;
	exm= (45*0.3) + (88*0.3);
	tarea= (100*0.05) + (65*0.05);
	suma= quiz+exm+tarea;
	puntos= (100 - 7.875 - 20.1 - 1.75);
	
	cout<<"promedio mate"<<endl;
	cout<<"Quices:"<<quiz<<"  / 30"<<endl;
	cout<<"Exámenes:"<<exm<<"  / 60"<<endl;
	cout<<"tareas y puntos extra:"<<tarea<<"  / 10"<<endl;
	cout<<"Pormedio final:"<<endl<<endl;
	cout<<suma<<"  /100"<<endl;
	cout<<endl;
	cout<<puntos<<endl;
	
	
	
	return 0;
}

