#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main(){
	int number, guess, tentativi, seed, i;
	seed=time(NULL);
	srand(seed);
	tentativi=0;														//	Initialize	the	sequence	
	for	(i=0;	i<1;	i++){	
		number	=	rand()%100+1;		//	Generate	a	random	number	in	[1,100]	
	}
	cout<<	"Indovina il numero da 1 a 100"	<<	endl;
	cout<< "Inserisci la tua ipotesi:";
	cin>> guess;
	while (guess!=number){
		cout<< "Inserisci la tua ipotesi:";
		cin >> 	guess;
		tentativi+=1;
	}
	cout	<< "Il numero esatto: "<< number << endl;
	cout	<< "Con "<< tentativi<< " tentativi"<< endl;	
}
