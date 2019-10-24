#include "header.h"

static int g_N;	

double Trapezoidal(double (*fun)(double), double a, double b, int N) {
	double h, integral;
		h = (b - a) / N;
		integral = 0.5 * (fun(a) + fun(b));	
		for (int i = 0; i < N; ++i) {
			integral += fun(a + h * i);
		}
	integral *= h;
	return integral;
}



double Rectangular(double (*fun)(double), double a, double b, int N) {
	double h, integral;
		h = (b - a) / N;
		integral =0;	
		for (int i = 0; i < N; i+=1) {
			integral += fun(a + h * i);
		}
	integral *= h;
	return integral;
}



double Simpson(double (*fun)(double), double a, double b, int N) {
	double integral,h;
	int i;
	integral=0;
	h=(b-a)/N;
	for (i=0;i<=N;i+=1){
		if (i==0 or i==N){
			integral+=fun(a + h * i)*h/3;
		}
		else if (i%2==0){
			integral+=fun(a + h * i)*2*h/3;
		}
		else if (i%2!=0){
			integral+=fun(a + h * i)*4*h/3;
		}
			
	}
	return integral;
}



double GaussLegendre(double (*fun)(double), double a, double b, int N, int ord, double eps) {
	double integral,c,int_sub,h,ww;
	int i;
	g_N=ord;
	h=(b-a)/N;
	vector<double> xg;
	vector<double> w; 
    xg=BracketBisection(PL,-1,1,eps,2*ord);
    for (unsigned int j=0;j<xg.size();j+=1){
		ww=2.0/((1.0-xg[j]*xg[j])*(DLegendrePol(xg[j],ord)*DLegendrePol(xg[j],ord)));
		w.push_back(ww);
	}
	integral=0;	 
	for (i=0;i<N;i+=1){
		c=a+(i+0.5)*h;
		int_sub=0;
		for(unsigned int k=0; k<xg.size(); k+=1){
			int_sub += w[k]*fun(h*0.5*xg[k]+c);
		}
		int_sub *= h*0.5;
		integral += int_sub;		
	}
	return integral;
}
double PL(double x)  {					 
	return (*LegendrePol)(x,g_N);
}
