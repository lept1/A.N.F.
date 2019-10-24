#include "header.h"

void ydot(double t, double *Y, double *rhs){
	rhs[0]=Y[1];
	rhs[1]=-Y[0];
}
  

int main(){ 
    // Initial Values 
    int neq=2;
    double x0 = 0; 
    double y0[neq]; 
    double h = 0.1;
    double x;
    double xf = 2*M_PI;
	int Nend=2048;
	for (int N=4;N<=Nend;N*=2){
		x0=0;
		
		x=x0;
		y0[0]=1;
		y0[1]=0;
		h=xf/N;
		//cout<<N<<" "<<h<<endl;
		for (int i=0; i<=N; i++){
			EulerStep(x,y0,ydot, h,neq);
			//cout<<h<<" "<<x<<" "<<y0[0]<<" "<<y0[1]<<" "<<abs(y0[0]-cos(x0))<<endl;
			cout<<h<<" "<<abs(y0[0]-cos(x0))<<endl;
			x=x0+i*h;
		}
		
	}
	cout<<endl;
		cout<<endl;
	
	for (int N=4;N<=Nend;N*=2){
		x0=0;
		x=x0;
		y0[0]=1;
		y0[1]=0;
		h=xf/N;
		for (int i=0; i<=N; i++){
			RK2(x,y0,ydot, h,neq);
		//	cout<<h<<" "<<x<<" "<<y0[0]<<" "<<y0[1]<<" "<<abs(y0[0]-cos(x0))<<endl;
			cout<<h<<" "<<abs(y0[0]-cos(x0))<<endl;
			x=x0+i*h;
		}
	}
	cout<<endl;
		cout<<endl;
	
	for (int N=4;N<=Nend;N*=2){
		x0=0;
		x=x0;
		y0[0]=1;
		y0[1]=0;
		h=xf/N;
		for (int i=0; i<=N; i++){
			RK4(x0,y0,ydot, h,neq);
			//cout<<h<<" "<<x<<" "<<y0[0]<<" "<<y0[1]<<" "<<abs(y0[0]-cos(x0))<<endl;
			cout<<h<<" "<<abs(y0[0]-cos(x0))<<endl;
			x=x0+i*h;
		}
	}
    cout<<endl;
		cout<<endl;
		return 0; 
}
