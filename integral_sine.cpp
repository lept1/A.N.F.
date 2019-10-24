#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double Rectangular(double,double,vector<double>);
double Trapezoidal(double,double,vector<double>);
double Simpson(double,double,vector<double>);

using namespace std;

//we have got equally spaced abscissae
double Rectangular(double a, double b, vector<double> f){ //a inferior bound, b upper bound, f list of values of funcion 
	double i,h;
	unsigned int j;
	i=0;
	h=(b-a)/f.size();
	for (j=0;j<f.size();j+=1){
		i+=f[j]*h;
	}
	return i;
}

double Trapezoidal(double a, double b, vector<double> f){ //a inferior bound, b upper bound, f list of values of funcion 
	double i,h;
	unsigned int j;
	i=0;
	h=(b-a)/f.size();
	for (j=0;j<f.size();j+=1){
		i+=(f[j]+f[j+1])*h/2;
	}
	return i;
}

double Simpson(double a, double b, vector<double> f){ //a inferior bound, b upper bound, f list of values of funcion 
	double i,h;
	unsigned int j;
	i=0;
	h=(b-a)/f.size();
	
	for (j=0;j<=f.size();j+=1){
		if (j==0 or j==f.size()){
			i+=f[j]*h/3;
		}
		else if (j%2==0){
			i+=f[j]*2*h/3;
		}
		else if (j%2!=0){
			i+=f[j]*4*h/3;
		}
			
	}
	return i;
}

int main() { //driver delle funzioni di integrazioni, qui definiamo funzioni da integrare o il set di punti e il resto
	double a, x, h, eps, lim, dx;
	int i, N;
	dx=0.1;
	N=10;
	a=0;
	lim=25;
	vector<double> y(N,0);
	eps=1.e-3;
    
	
	for (x=0;x<=lim; x=x+dx){
		h=(x-a)/N;			
		for(i=0; i<=N;i+=1){
			if (a+i*h>eps){
				y[i]=sin(a+i*h)/(a+i*h);
			}
			else {
				y[i]=1-(a+i*h)*(a+i*h)/6;
			}
		}
		cout <<x <<" "<< Trapezoidal(a,x,y)<<endl;
	}
	return 0;
}

