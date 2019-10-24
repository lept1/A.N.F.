#include <iostream>
#include <cmath>

int main() {
	using namespace std;
	double a,eps,b;
	int i=1;
	b=1;
	a=1;
	eps=1.0e-20;
	while (b==a){
		b=b+i*eps;
		i+=1;
		cout << i<<endl;;
	}
	cout << "machine precision tra  " <<(i-1)*eps<<"  e tra  "<<i*eps;
	return 0;
}
