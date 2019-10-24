#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;
int Fact(int);
int main() {															//compute approximation of sin
	double y,x,eps,dis;
	int n;
	x=1;
	eps=1.e-8;
	dis=10*eps;
	n=0;
	y=0;
	while(eps<dis){
		y+=pow(-1,n)*pow(x,2*n+1)/Fact(2*n+1);
		dis=abs(y-sin(x));
		cout << "n " << n << "  sin  " << sin(x) << " approx " << y<<endl;
		n+=1;
		
	}
 	return 0;
}

int Fact (int x){
	if (x == 1){
		return 1;
	}
	else{
		return (x * Fact(x-1));
	}
}


