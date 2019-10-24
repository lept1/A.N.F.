#include "header.h"	


double LegendrePol(double x, int n){
	double P;
	if (n==0){
		return 1;
	}
	else if (n==1){
		return x;
	}
	else{
	P=(2*n-1)*x*LegendrePol(x,n-1)/n-(n-1)*LegendrePol(x,n-2)/n;
	}
	return P;
}

double DLegendrePol(double x, int n){
	double DP;
	DP=(x*LegendrePol(x,n)-LegendrePol(x,n-1))*n/(x*x-1);
	return DP;
}

double Parabola(double x){
	return x * x;
}

double Sic(double x){
	return sin(x)/x;
}

double Gaussian(double x){
	return exp(-x*x);
}

//double Polynom(double x, int N, double *coeff){}
