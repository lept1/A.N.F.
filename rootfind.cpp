#include "header.h"

static int g_N;

double Fun(double x){
	return sin(x)-(1.0/3.0+x*(1.0/5.0+x/100.0));
}



double DFun(double x){
	return -cos(x)-(1.0/5.0+x/50.0);
}

double Par(double x){
	return x*x-1;
}



double DPar(double x){
	return 2.0*x;
}



double Pol(double x){
	int a[] {1,-3,1,5};
	double p;
	p=a[4];		
	for (int j=4-1;	j>=0;j=-1){	
		p=p*x+a[j];	
	}
	return p;
}
double DPol(double x){
	int a[] {1,-3,1,5};
	double p,dpdx;
	p=a[4];	
	dpdx=0;		
	for (int j=4-1;	j>=0;j=-1){	
		dpdx=dpdx*x+p;	
	}
	return dpdx;
}
	
double PL(double x)  {					 
	return (*LegendrePol)(x,g_N);
}

int main(void) {
    double a, b, eps,ww;
    int ord;
    
    cout << "Enter begining of interval: "; 
    cin >> a; 
    cout << "Enter end of interval: "; 
    cin >> b;
    cout << "Desired tolerance: "; 
    cin >> eps;
	//cout << "Number of interval: "; 
    //cin >> N;
    cout << "Order of Legendre: "; 
    cin >> ord;
   
   //vector<double> zeros;
    //zeros=BracketBisection(Fun,a,b,eps,N);
    //for (unsigned int i = 0; i < zeros.size(); i++) {
		//std::cout << setprecision(12) << zeros.at(i) << endl;
	//}
    
    vector<double> xg;
    vector<double> w; 
    g_N=ord; 
    xg=BracketBisection(PL,-1,1,eps,2*ord);
    for (unsigned int j=0;j<xg.size();j+=1){
		ww=2.0/((1.0-xg[j]*xg[j])*(DLegendrePol(xg[j],ord)*DLegendrePol(xg[j],ord)));
		w.push_back(ww);
		cout<<w[j]<<" "<<xg[j]<<endl;
	}
    return 0;
}
    

