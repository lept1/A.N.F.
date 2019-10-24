#include "header.h"


static double g_alpha;

double Particle(double x, double alpha){
	return alpha*x*x-x*x*x*(1-exp(-alpha*alpha/x));
}

double ParticleT(double x){
	return Particle(x, g_alpha);
}

int main(void) {
	double x, h, alpha;
	//int step;
	//step=1;
	//x=1.0;
	//h=1.e-1;
	//while(step<10){
		//cout <<setprecision(12)<< h <<" "<< abs(cos(x)-ForwardD(sin,x,h))<<" "<<  abs(cos(x)-BackwardD(sin,x,h))<<" "<< abs(cos(x)- CentralD(sin,x,h))<<" "<< abs(cos(x)- HighD(sin,x,h))<<endl;
		//h=h/10.0;
		//step+=1;
	//}
	h=1.e-3;
	alpha=10;
	while(alpha<=100.0){
		x=0.0;
		g_alpha=alpha;
		while(x<=alpha){
			cout <<setprecision(5)<< x <<" "<< ParticleT(x)<<" "<< HighD(ParticleT,x,h)<<" "<< CentralD2(ParticleT,x,h)<<endl;
			x+=h;
		}
		cout <<endl;
		cout <<endl;
		alpha+=10;
	}
		
		
	
	return 0;
	
}
