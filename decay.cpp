#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
int main(){
	int i, Natom, step, seed;
	double lambda, dec;
	lambda=0.01;
	seed=time(NULL);
	srand(seed);
	Natom=1000;
	step=0;
	cout<<step<<" "<<Natom<<endl;
	step=1;
	while (Natom>0){
		for (i=1; i<=Natom; i+=1 ){
			dec=drand48();	
			if (dec<lambda){
					Natom-=1;
			}	
		}
		
		cout<<step<<" "<<Natom<<endl;
		step+=1;
		
	}
	return 0;
}

