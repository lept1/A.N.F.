#include "header.h"

void ydot(double t, double *Y, double *rhs){
	rhs[0]=Y[1];
	rhs[1]=-sin(Y[0]);
	
}

void Acceleration(double *x, double *v, double *a){
	a[0]=-sin(x[0]);
}





int main(){ 
    // Initial Values 
    int neq=2;
    int tp =0;
    int Npv=1;
    double x0 = 0; 
    double y0[neq]; 
    double h ;
    double vtemp, Erk, Epv;
	x0=0;
	y0[0]=0;
	y0[1]=1;
	h=0.1;
	while(tp<=100){
		vtemp=y0[0];
		RK4(x0,y0,ydot, h,neq);
		Erk=0.5*y0[1]*y0[1];
		cout<<setprecision(8)<<x0<<" "<<y0[0]<<" "<<y0[1]<<" "<<Erk<<endl;
		x0+=h;
		if (vtemp*y0[0]<0){
			tp+=1;
		}
	}
	cout<<endl;
	cout<<endl;
	
	return 0;
}
