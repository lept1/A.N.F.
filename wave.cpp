#include "header.h"

static double g_K;
static double g_s;

void ydot(double t, double *Y, double *rhs){
	rhs[0]=Y[1];
	rhs[1]=-g_K*g_K*Y[0];
}

double Residual(double k){
	
	int neq=2;
    int N;
    double x0,x,yb; 
    double y0[neq]; 
    double h, b, res;
	b=1;
	yb=0;
	x0=0;
	N=10000;
	h=abs(x0-b)/N;
	x=x0;
	y0[0]=0;
	y0[1]=g_s;
	g_K=k;
	x=x0;
	for(int i=0; i<N;i++){
		RK4(x,y0,ydot, h,neq);
		x=x0+i*h;
	}
	res=y0[0]-yb;
	//cout <<"s"<<"  "<<s<<endl;
	//cout <<"res"<<"  "<<res<<endl;
	return res;
}

int main(){
	double s;
	vector<double> zeros;
	s=0;
	while (s<100){
		g_s=s;
		zeros=BracketBisection(Residual,0, 20,1.e-4, 80);
		for (unsigned int i = 0; i < zeros.size(); i++) {
			cout << setprecision(7)<<s<<" "<<zeros[i] << endl;
		}
		s+=0.1;
	}
		
	return 0;
}

