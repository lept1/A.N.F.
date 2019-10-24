#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
int main(){
	int seed,i,N;
	double x, med, dev;//, mom3, mom4, mom5;
	seed=time(NULL);
	srand(seed);
	for (N=4; N<1000000;N*=2){
		med=0;
		dev=0;
		//mom3=0;
		//mom4=0;
		//mom5=0;		
		for	(i=0;	i<N; i+=1){	
			x=drand48();
			med+=x;
			dev+=x*x;
			//mom3+=x*x*x;
			//mom4+=x*x*x*x;
			//mom5+=x*x*x*x*x;
		}
		med=med/N;
		dev=dev/N;
		//mom3=mom3/N;
		//mom4=mom4/N;
		//mom5=mom5/N;
		cout<<N<<" "<<fabs(med-(0.5+sqrt(1/N)))<<" "<<fabs(dev-(0.3333+sqrt(1/N)))<<endl;//" "<<mom3<<" "<<mom4<<" "<<mom5<<endl;
	}
}

