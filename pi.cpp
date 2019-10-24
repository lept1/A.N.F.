#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
int main(){
	int i, N_p, in;
	double Aq, I, seed,x,y,r, eps;
	N_p=2;
	Aq=4.0;
	eps=1.e-4;
	seed=time(NULL);
	srand(seed);
	I=0;
	while (fabs(I-M_PI)>eps){
		in=0;
		for (i=1; i<=N_p; i+=1 ){
			x=(drand48()-0.5)*2;
			y=(drand48()-0.5)*2;
			r=sqrt(x*x+y*y);
			if (r<1.0){
					in+=1;
			}	
		}
		I=Aq*double(in)/N_p;
		cout<<N_p<<" "<<fabs(I-M_PI)<<endl;
		N_p*=2;
		
	}
	return 0;
}
