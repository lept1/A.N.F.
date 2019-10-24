#include "header.h"

static double D=3;
static double V=5;
static double P=1;

void ydot(double t, double *Y, double *rhs){
  double ph,pd,pb,pr;
  ph=Y[0];
  pd=Y[1];
  pb=Y[2];
  pr=Y[3];
  rhs[0]=1.0/2*(D-V)*pow(ph,3)+1.0/2*(2*P-V)*ph*pow(pr,2)
  -1.0/2*(2*V*pb+2*V*pd+D-V)*pow(ph,2)-1.0/2*(V*pow(pb,2)
  -(2*P-V)*pow(pd,2)-2*V*pb+2*(V*pb-V)*pd)*ph+1.0/2*(2*(D-V)*pow(ph,2)
  -(2*V*pb-2*(2*P-V)*pd+D-V)*ph)*pr;

  rhs[1]=-1.0/2*V*pb*pb*pd+1.0/2*(2*P-V)*pd*pd*pd+1.0/2*(D-V)*pd*ph*ph 
  +1.0/2*(2*P-V)*pd*pr*pr-1.0/2*(2*V*pb+2*P-V)*pd*pd-(V*pb*pd + V*pd*pd)
  *ph+1.0/2*(2*(2*P-V)*pd*pd+2*(D-V)*pd*ph-(2*V*pb+2*P-V)*pd)*pr;
  
  rhs[2]=-1/2*V*pb*pb*pb+1.0/2*(2*P-V)*pb*pd*pd+1.0/2*(D-V)*pb*ph*ph
  +1.0/2*(2*P-V)*pb*pr*pr+1.0/2*V*pb*pb-(V*pb*pb-V*pb)*pd
  -(V*pb*pb+V*pb*pd)*ph-(V*pb*pb-(2*P-V)*pb*pd-(D-V)*pb*ph)*pr;

  rhs[3]=1.0/2*(2*P-V)*pr*pr*pr-1.0/2*(2*V*pb-2*(2*P-V)*pd
  -2*(D-V)*ph+2*P-V)*pr*pr-1.0/2*(V*pb*pb-(2*P-V)*pd*pd-(D-V)*ph*ph
  -2*V*pb+(2*V*pb+2*P-V)*pd+(2*V*pb+2*V*pd+D-V)*ph)*pr;

}



int main(){ 
    
    int neq=4;
    double t0 = 0 ,tf=5000; 
    double y0[neq],y02[neq],y03[neq]; 
    double h ;
    int N;
    double err1e, err2e;
    double err1r, err2r;

	
	
	for(int N=4000;N<1000000;N*=2){	
		// Initial Values 
		y0[0]=0.25;
		y0[1]=0.25;
		y0[2]=0.25;
		y0[3]=0.25;
		y02[0]=0.25;
		y02[1]=0.25;
		y02[2]=0.25;
		y02[3]=0.25;
		y03[0]=0.25;
		y03[1]=0.25;
		y03[2]=0.25;
		y03[3]=0.25;
		t0=0;
		h=tf/N;
		err1e=1.e-6;
		err1r=1.e-6;
		for (int i=1; i<=N;i++){
			RK4(t0,y0,ydot, h,neq);
			EulerStep(t0,y02,ydot, h,neq);
			RK2(t0,y03,ydot,h,neq);
			err2e=fabs(y0[0]-y02[0]);
			err2r=fabs(y0[1]-y03[1]);
			if (err2e>err1e){
				err1e=err2e;
			}
			if (err2r>err1r){
				err1r=err2r;
			}
			
			t0=i*h;
		}
		cout<<endl<<endl;
		cout<<h<<" "<<err1e<<" "<<err1r<<endl;
	}
	return 0;
}
