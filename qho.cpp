#include "header.h"

static double g_E;

void ydot(double t, double *Y, double *rhs){
	rhs[0]=Y[1];
	rhs[1]=-2*(g_E-0.5*t*t)*Y[0];
}

double Psi(double x){
	return exp(-0.5*x*x);
}

double dPsi(double x){
	return -x*exp(-0.5*x*x);
}

double Residual(double E){
	int neq=2;
	int N=1000;
    double x0f,x0b,xf,xb,xm; 
    double y0f[neq],y0b[neq]; 
    double hf,hb,res,D;
    g_E=E;
	xm=0.1;
	x0f=-10;
	x0b=10;
	y0f[0]=Psi(x0f);
	y0f[1]=dPsi(x0f);
	y0b[0]=Psi(x0b);
	y0b[1]=dPsi(x0b);
	hf=abs(x0f-xm)/N;
	hb=abs(x0b-xm)/N;
	xf=x0f;
	xb=x0b;
	for(int i=1; i<=N;i++){

		RK4(xf,y0f,ydot,hf,neq);
		xf=x0f+i*hf;
		
	}
	for(int i=1; i<=N;i++){
		RK4(xb,y0b,ydot,hb,neq);
		xb=x0b-i*hb;
	}
	D=sqrt(y0f[1]*y0b[0]*y0f[1]*y0b[0]+y0b[1]*y0f[0]*y0b[1]*y0f[0]);
	res=(y0f[1]*y0b[0]-y0b[1]*y0f[0])/D;
	cout<<fixed<<setprecision(4);
	cout <<E<<"  "<<res<<" "<<y0b[0]<<" "<<y0f[0]<<" "<<xb<<" "<<xf<<endl;
	return res;
}

int main(){
	vector<double> zeros;
	zeros=BracketBisection(Residual,0, 5,1.e-5, 40);
		for (unsigned int i = 0; i < zeros.size(); i++) {
			cout << setprecision(7)<<" "<<zeros[i] << endl;
		}
	
	return 0;
}

