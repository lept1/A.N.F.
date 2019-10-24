#include "header.h"


void ydot(double t, double *Y, double *rhs){
	rhs[0]=Y[1];
	rhs[1]=0;
	
}




int main(){ 
    // Initial Values 
    int neq=2;
    int N;
    double x0,x; 
    double y0[neq], x[1],v[1]; 
    double h, xf,s;
    double vtemp, Erk, Epv;
	xf=20;
	x0=0;
	s=0;
	y0[0]=0;
	y0[1]=s;
	h=0.1;
	N=int(abs(x0-xf)/h);
	x=x0;
	while (s<=1){
		for(int i=0; i<N;i++){
			RK4(x0,y0,ydot, h,neq);
			Erk=0.5*y0[1]*y0[1];
			cout<<setprecision(8)<<x0<<" "<<y0[0]<<" "<<y0[1]<<" "<<Erk<<endl;
			x=x0+ih;
		}
		s+=0.2;
		cout<<endl;
		cout<<endl;
	}
}
