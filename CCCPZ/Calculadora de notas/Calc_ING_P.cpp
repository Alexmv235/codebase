#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float tc, te,exm, quiz, op, total=0;
	tc=5;
	te=10;
	exm= (100*0.125)+(91*0.125) + (76*0.125) + (83*0.125);
	quiz= (71*0.1)+(94*0.1);
	op= 9.2;
	total= tc+te+exm+quiz+op;
	
	cout<<total<<endl;
	
	return 0;
}

