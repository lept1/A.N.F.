#include "header.h"

vector<double> Euler(double(*ydot)(double,double),double x0, double y0, double h, double xf) {
    vector<double> yy;
    yy.push_back(y0);
    while (x0 < xf) { 
        y0 = y0 + h * ydot(x0, y0);
        yy.push_back(y0);
        x0 = x0 + h; 
    } 
    return yy;
} 

void EulerStep(double x, double *Y, void (*ydot)(double, double *, double *), double h, int neq){
	int n;
	double rhs[neq];
	ydot(x,Y,rhs);
	for (n=0; n<neq;n++){
		Y[n]+=h*rhs[n];
	}
}

void RK2(double x, double *Y, void(*ydot)(double, double *, double *), double  h, int neq){
	double k1[neq], k2[neq], Y1[neq];
	ydot(x,Y,k1);
	for(int i=0; i<=neq;i++){
		Y1[i]=Y[i]+h*k1[i];
	}
	ydot(x+h,Y1,k2);
	for (int n=0; n<neq;n++){
		Y[n]+=h*0.5*(k1[n]+k2[n]);
	}
}

void RK4(double x, double *Y, void(*ydot)(double, double *, double *), double  h, int neq){
	double k1[neq], k2[neq], k3[neq], k4[neq], Y1[neq], Y2[neq], Y3[neq];
	ydot(x,Y,k1);
	for(int n=0; n<=neq;n++){
		Y1[n]=Y[n]+0.5*h*k1[n];
	}
	ydot(x+0.5*h,Y1,k2);
	for (int n=0; n<neq;n++){
		Y2[n]=Y[n]+0.5*h*k2[n];
	}
	ydot(x+0.5*h,Y2,k3);
	for (int n=0; n<neq;n++){
		Y3[n]=Y[n]+h*k3[n];
	}
	ydot(x+h,Y3,k4);
	for (int n=0; n<neq;n++){
		Y[n]+=h/6.0*(k1[n]+2*k2[n]+2*k3[n]+k4[n]);
	}
}

void PV(double *x, double *v, void(*acc)(double *, double *, double *),double  h, int N){
	double x1_2[N],a[N];
	for (int i=0; i<N;i++){
		x1_2[i]=x[i]+0.5*h*v[i];
	}
	acc(x1_2,v,a);
	for(int i=0; i<N;i++){
		v[i]=v[i]+0.5*h*a[i];
	}
	for (int i=0; i<N;i++){
		x[i]=x1_2[i]+0.5*h*v[i];
	}
}
