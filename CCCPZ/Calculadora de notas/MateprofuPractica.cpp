#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	float suma, quiz, exm, tarea, puntos = 0;
		
	quiz= (90*0.15);
	exm= (75*0.25) + (72*0.25) + (80*0.25);
	tarea= (83*0.1);
	suma= quiz+exm+tarea;
	puntos= (100 - 7.875 - 20.1 - 1.75);
	
	/*cout<<"promedio mate"<<endl;
	cout<<"Quices:"<<quiz<<"  / 30"<<endl;
	cout<<"Examenes:"<<exm<<"  / 60"<<endl;
	cout<<"tareas y puntos extra:"<<tarea<<"  / 10"<<endl;*/
	cout<<"Pormedio final:"<<endl<<endl;
	cout<<suma<<"  /100"<<endl;
	cout<<endl;
	//cout<<puntos<<endl;
	
	
	
	return 0;
}

