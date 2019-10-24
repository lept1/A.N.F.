#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

int main() {	
	double a,b,c,x1,x2;    // search the solutions of equation a*x^2+b*x+c=0
	cout << "Inserire coefficiente x^2 " <<endl;  //input the values of a,b,c
	cin >> a;
	cout << "Inserire coefficiente x " <<endl;
	cin >> b;
	cout << "Inserire termine noto " <<endl;
	cin >> c;
	if (b*b-4*a*c>=0){
		if (b>=0){
			x1=(-b-sqrt(b*b-4*a*c))/(2*a);
			x2=(2*c)/(-b-sqrt(b*b-4*a*c));
			cout << "x1=" <<x1<<endl;
			cout << "x2=" <<x2<<endl;
		}
		else {
			x1=(2*c)/(-b+sqrt(b*b-4*a*c));
			x2=(-b+sqrt(b*b-4*a*c))/(2*a);
			cout << "x1=" <<x1<<endl;
			cout << "x2=" <<x2<<endl;
		}
	}
	else {
		cout << "Nessuna soluzione reale. Delta negativo"<<endl;
	}
	return 0;
}

