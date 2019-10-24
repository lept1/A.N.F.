#include "header.h"	

double Bisection(double(*fun)(double),double a, double b,double eps){
	double zero, xm, Fa,Fb,Fx;
	int step;
	xm=(a+b)/2;
	Fa=fun(a);
	Fb=fun(b);
	Fx=fun(xm);
	step=0;
	//if (fabs(Fa)<eps){
		//zero=a;
		//return zero;
	//}
	//if (fabs(Fb)<eps){
		//zero=b;
		//return zero;
	//}
	
	while ((fabs(a-b)>eps)&&(step<250)){
		
		if (Fx*Fa>0){
			a=xm;
			Fa=Fx;
		}
		if (Fx*Fa<0){
			b=xm;
			Fb=Fx;
		}
		xm=(a+b)/2;
		step+=1;
		Fx=fun(xm);
	}
	zero=xm;
	return zero;
}
		
	
	
double Falsi(double(*fun)(double), double a, double b, double eps){	
	double zero, xm;
	int step;
	step=0;
	if (fabs(fun(a))<eps){
		zero=a;
		return zero;
	}
	if (fabs(fun(b))<eps){
		zero=b;
		return zero;
	}
	xm=(a*fun(b)-b*fun(a)) / (fun(b)-fun(a));									
	while ((fun(xm)>eps)&&(step<250)){
		xm=(a*fun(b)-b*fun(a)) / (fun(b)-fun(a));
	
		if (fun(xm)*fun(a)>0){
			a=xm;
		}
		
		if (fun(xm)*fun(a)<0){
			b=xm;
		}
		step+=1;
	}
	zero=xm;
	return zero;
}



double Secant(double (*fun)(double), double a, double b, double eps){
	double zero, dx, Fa,Fb;
	int step;
	step=0;
	dx=b-a;
	Fa=fun(a);
	Fb=fun(b);
	if (fabs(Fa)<eps){
		zero=a;
		return zero;
	}
	if (fabs(Fb)<eps){
		zero=b;
		return zero;
	}
										
	while ((fabs(Fb)>eps)&&(step<250)  ){
		dx=Fb*(b-a)/(Fb-Fa);
		a=b;
		b=b-dx;
		Fa=Fb;
		Fb=fun(b);
		step+=1;
	}	
	zero=b;
	return zero;
}



double Newton(double (*fun)(double),double (*dfun)(double), double a, double eps){
	double zero, dx, Fa, DFa;
	int step;
	step=0;
	Fa=fun(a);
	DFa=dfun(a);
	if (fabs(Fa)<eps){
		zero=a;
		return zero;
	}									
	while ((fabs(Fa)>eps)&&(step<2500)  ){
		dx=Fa/DFa;
		a-=dx;
		Fa=fun(a);
		DFa=dfun(a);
		step+=1;
	}	
	zero=a;
	return zero;
}




vector<double> BracketBisection(double(*fun)(double),double a, double b,double eps, int N) {
    double dx, Fa, Fb;
    int i;
    i=1;
	vector<double> x0;
    dx=fabs(a-b)/N;
    b=a+dx;
    Fa=fun(a);
	Fb=fun(b);
	while (i<N){
		if (Fb*Fa<0){
			x0.push_back(Bisection(fun,a,b,eps));
		}
		i+=1;
		a=b;
		b+=dx;
		Fa=Fb;
		Fb=fun(b);	
	}
    return x0;
}
