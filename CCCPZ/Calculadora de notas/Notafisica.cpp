#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	float total, fullexam, exam, quiz, port =0;
	
	fullexam= (68.18*0.3333) + (70.45*0.3333) + (75*0.3333);
	exam= (68.18*0.2666) + (70.45*0.2666) + (75*0.2666);
	quiz= 10;
	port= 10;
	total= exam + quiz + port;
	
	cout<< " Si es todo examenes :  "<<fullexam<<endl;
	cout<< "Si no:   " <<total<<endl;
	return 0;
}

