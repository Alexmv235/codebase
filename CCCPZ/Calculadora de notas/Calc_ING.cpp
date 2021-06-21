#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float tc, te, exam, quiz, escrito, total =0;
	tc=5;
	te= (92*0.1);
	exam= (65*0.25) + (73.91*0.15)+(88*0.15);
	quiz= (89.66*0.1)+(87.5*0.05)+(66.67*0.05);
	escrito=9.2;
	total= tc+te+exam+quiz+escrito;
	
	cout<<total<<endl;
	return 0;
}

