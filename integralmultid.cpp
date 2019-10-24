#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

static float xsav;
static float (*nrfunc)(float,float);



float Gauss2D(float (*func)(float, float), float x1, float x2, int N, int ord){
	float Gauss1D(float (*func)(float), float a, float b, int N, int ord); 
	float G_int(float x);
	nrfunc=func;
	return Gauss1D(G_int,x1,x2,N, ord); 
}



float G_int(float x){								//G e' la nostra funzione integrata sulle sole y
	float Gauss1D(float (*func)(float), float a, float b, int N, int ord); 
	float F2(float y);												
	float yy1(float),yy2(float);											//le funzioni di condizione su y in termini di x (possono anche essere costanti)
	int N, ord;																//e definizione dell'ordine della quadratura
	N=100;																	//e del numero di punti
	ord=3;																	//
    xsav=x;
    return Gauss1D(F2,yy1(x),yy2(x),N,ord); 
}



float F2(float y)  {					//funzione delle y 
	return (*nrfunc)(xsav,y);			//punta alla nostra funzione non variando le x (xsav=x save) e variando le y
}




float Gauss1D(float (*Funcp)(float), float a, float b, int N, int ord){			//il classico gauss legendre per una dimensione
	double integral, h, c, int_sub;
	int i;
	integral=0;
	h=(b-a)/N;
	vector<float> x(ord-1,0);
	vector<float> w(ord-1,0);
	
	if (ord==1){
		x[0]=0;		w[0]=2;
	}
	if (ord==2){
		x[0]=-sqrt(1.0/3.0);	w[0]=1;
		x[1]=-x[0];				w[1]=1;
	}
	if (ord==3){
		x[0]=0.0;				w[0]=8.0/9.0;
		x[1]=-sqrt(3.0/5.0);	w[1]=5.0/9.0;
		x[2]=-x[1];				w[2]=5.0/9.0;
	}
	if (ord==4){
		x[0]=-sqrt(3.0/7-2.0/7*sqrt(6.0/5));			w[0]=(18.0+sqrt(30.0))/36.0;
		x[1]=+sqrt(3.0/7-2.0/7*sqrt(6.0/5));			w[1]=(18.0+sqrt(30.0))/36.0;
		x[2]=-sqrt(3.0/7+2.0/7*sqrt(6.0/5));			w[2]=(18.0-sqrt(30.0))/36.0;
		x[3]=+sqrt(3.0/7+2.0/7*sqrt(6.0/5));			w[3]=(18.0-sqrt(30.0))/36.0;
	}
	if (ord==5){
		x[0]=0;										w[0]=128/225;
		x[1]=-1.0/3 * sqrt(5.0-2*sqrt(10.0/7));		w[1]=(322+13*sqrt(70))/900.0;
		x[2]=-x[1];									w[2]=w[1];
		x[3]=-1.0/3 * sqrt(5.0+2*sqrt(10.0/7));		w[3]=(322-13*sqrt(70))/900.0;
		x[4]=-x[3];									w[4]=w[3];
	}
		 
	for (i=0;i<N;i+=1){
		c=a+(i+0.5)*h;
		int_sub=0;
		for(int k=0; k<ord; k+=1){
			int_sub += w[k]*Funcp(h*0.5*x[k]+c);
		}
		int_sub *= h*0.5;
		integral += int_sub;
			
	}
	return integral;
}



float f(float x, float y){ 							//la funzione da integrare
    float a = x*x*x*x*y*y+2*y*y*x*x-y*x*x+2;		//
    return a;
}

float yy1(float x)						//limite inferiore di y rispetto a x
{
    float y = -1;
    return y;   
}

float yy2(float x)						////limite superiore di y rispetto a x
{
    float y = 1;
    return y;
}


int main ()
{
    float z;
    float xa, xb, N, ord;			//le condizioni su x
    xa=-1.0;						//e la scelta del numero di punti
    xb=1.0;							//e dell'ordine della quadratura
    N=100;							//
    ord=3;							//
    z = Gauss2D(f, xa, xb, N, ord);  
    cout << z << endl;
}
