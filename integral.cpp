#include <iostream>
#include <cmath>
#include <vector>
//integration having N measures, unknown the shape of function
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
	double a, b, h;
	int i;
	cout << "Inserire primo numero " <<endl;
	cin >> a;
	cout << "Inserire secondo numero " <<endl;
	cin >> b;
	int N;
	N=1000;
	h=(b-a)/N;
	vector<double> y(N,0);
	 
    
	for(i=0; i<=N;i+=1){
		y[i]=sqrt(1+a+i*h);
	}
	cout <<"Trapezi  "<< Trapezoidal(a,b,y)<<endl;
	cout <<"Rettang  "<< Rectangular(a,b,y)<<endl;
	cout <<"Simpson  "<< Simpson(a,b,y)<<endl;
	return 0;
}

