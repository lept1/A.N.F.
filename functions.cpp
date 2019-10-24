#include <iostream>
#include <cmath>

double Sum(double,double);
double Quotient(int,int);
int main() {
	using namespace std;
	double a, b, c;
	cout << "Inserire primo numero " <<endl;
	cin >> a;
	cout << "Inserire secondo numero " <<endl;
	cin >> b;
	c=Sum(a,b);
	cout << "somma "<< c <<endl;
	return 0;
}
double Sum(double x, double y){
	double z;
	z=x+y;
	return z;
} 
int Quotient(int i, int j){
	q=i/j;
	r=i%j;
	return q,r;
}

	
	

