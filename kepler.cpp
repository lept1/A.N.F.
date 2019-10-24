#include "header.h"

void ydot(double t, double *Y, double *rhs){
	double r;
	r=sqrt(Y[0]*Y[0]+Y[1]*Y[1]);
	rhs[0]=Y[2];
	rhs[1]=Y[3];
	rhs[2]=-Y[0]/(r*r*r);
	rhs[3]=-Y[1]/(r*r*r);
	
}


int main(){ 
    // Initial Values 
    int neq=4;
    double x0 = 0; 
    double y0[neq]; 
    double h = 0.1;
    int N, tp;
    double ytemp, r, E, v, L;
	x0=0;
	y0[0]=4.0;
	y0[1]=0.0;
	y0[2]=0.0;
	y0[3]=0.4;

	tp=0;	
	while(tp<200){
		ytemp=y0[3];
		RK4(x0,y0,ydot, h,neq);
		v=sqrt(y0[2]*y0[2]+y0[3]*y0[3]);
		r=sqrt(y0[0]*y0[0]+y0[1]*y0[1]);
		L=r*v;
		E=0.5*v*v-1.0/r;
		std::cout.precision (10);
		std::cout<<tp<<" "<<x0<<" "<<y0[0]<<" "<<y0[1]<<" "<<y0[2]<<" "<<y0[3]<<" "<<E<<" "<<L<<endl;
		x0+=h;
		if (ytemp*y0[3]<0){
			tp+=1;
		}
		
	}
	
	return 0;
}
