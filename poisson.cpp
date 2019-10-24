#include "header.h"



void ydot(double t, double *Y, double *rhs){
	rhs[0]=Y[1];
	rhs[1]=-0.5*t*exp(-t);
	
}

double Residual(double s){
	int neq=2;
    int N;
    double x0,x,yb; 
    double y0[neq]; 
    double h, b, res;
	b=20;
	yb=1;
	x0=0;
	N=1000;
	h=abs(x0-b)/N;
	x=x0;
	y0[0]=0;
	y0[1]=s;
	x=x0;
	for(int i=0; i<=N;i++){
		RK4(x,y0,ydot, h,neq);
		x=x0+i*h;
	}
	res=y0[0]-yb;
	return res;
}

int main(){ 
    //double s;
    double res;
    vector<double> zeros;
	//while (s<=1){
		//res=Residual(s);
		//cout <<s<<" "<<res<<endl;
		//s+=0.05;
	//}
		zeros=BracketBisection(Residual,0, 20,1.e-7, 1000);
		for (unsigned int i = 0; i < zeros.size(); i++) {
			cout << setprecision(7)<<" "<<zeros.at(i) << endl;
		}
	return 0;

	}
