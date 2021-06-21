#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	float exm, quiz, foro, inv, total =0;
	
	exm= (92*0.2)+20+20;
	quiz= (90*0.05)+(88*0.05);
	foro= 15;
	inv= 15;
	total= exm+quiz+foro+inv;
	
	cout<<total<<endl;
	return 0;
}

