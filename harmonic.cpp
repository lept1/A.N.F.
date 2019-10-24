#include "header.h"
static double OMEGA;

void ydot(double t, double *Y, double *rhs){
	rhs[0]=Y[1];
	rhs[1]=-OMEGA*OMEGA*(Y[0]);
	
}

void Acceleration(double *x, double *v, double *a){
	a[0]=-OMEGA*OMEGA*(x[0]);
}





int main(){ 
    // Initial Values 
    int neq=2;
    int tp =0;
    int Npv=1;
    double x0 = 0; 
    double y0[neq], x[1],v[1]; 
    double h ;
    double k, m, Erk, Epv, vtemp;
    k=1;
    m=1;
    OMEGA=sqrt(k/m);
	x0=0;
	y0[0]=1.0;
	y0[1]=0.0;
	x[0]=1.0;
	v[0]=0.0;
	h=0.2;
	while(tp<=20){
		vtemp=v[0];
		RK2(x0,y0,ydot, h,neq);
		Erk=y0[1]*y0[1]*0.5+0.5*k*y0[0]*y0[0];
		PV(x,v,Acceleration,h,Npv);
		Epv=v[0]*v[0]*0.5+0.5*k*x[0]*x[0];
		cout<<setprecision(4)<<" "<<x0<<" "<<y0[0]<<" "<<y0[1]<<" "<<x[0]<<" "<<v[0]<<" "<<Erk<<" "<<Epv<<endl;
		x0+=h;
		if (vtemp*v[0]<0){
			tp+=1;
		}
	}
	
	
	return 0;
}
