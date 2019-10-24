#include "header.h"

double ForwardD(double(*fun)(double),double x, double h){
	double dfun;
	dfun=(fun(x+h)-fun(x))/h;
	return dfun;
}
	
double BackwardD(double(*fun)(double),double x,double h){
	double dfun;
	dfun=(fun(x)-fun(x-h))/h;
	return dfun;
}

double CentralD(double(*fun)(double),double x, double h){
	double dfun;
	dfun=(fun(x+h)-fun(x-h))/(2*h);
	return dfun;
}

double HighD(double(*fun)(double),double x,double h){
	double dfun;
	dfun=(fun(x+2*h)-fun(x-2*h)+8*fun(x+h)-8*fun(x-h))/(12*h);
	return dfun;
}


double CentralD2(double(*fun)(double),double x,double h){
	double ddfun;
	ddfun=(fun(x+h)+fun(x-h)-2*fun(x))/(h*h);
	return ddfun;
}

