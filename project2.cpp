#include "header.h"


#define BRUTE 0
#define LIGHT 1
#define VALIDATION 0
#define VERIFICATION 0

static int D;
static int V;
static int P;


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
    double t0 = 0 ,tf=100; 
    double y0[neq], y0temp; 
    double h ;
    int N=10000;
    string fLight = "light.dat";
    string fBrute = "brute.dat";
    string fValidation = "validation.dat";
    string fVerification = "verification.dat";
    
    #if LIGHT==1
    ofstream fdata;
    fdata.open(fLight);
    
    //V>D>P homogeneous popolation
    P=3;
    D=4;
    V=10;
    y0[0]=1.0/4;
    y0[1]=1.0/4;
    y0[2]=1.0/4;
    y0[3]=1.0/4;
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdata<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<endl;
        t0=i*h;
    }
    fdata<<endl<<endl;
    
    
    //P<<D<V, homogeneous popolation
    P=0.1;
    D=5;
    V=9;
    y0[0]=1.0/4;
    y0[1]=1.0/4;
    y0[2]=1.0/4;
    y0[3]=1.0/4;
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdata<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<endl;
        t0=i*h;
    }
    fdata<<endl<<endl;
    
    
    //D>V>P, homogeneous popolation
    P=3;
    D=7;
    V=5;
    y0[0]=1.0/4;
    y0[1]=1.0/4;
    y0[2]=1.0/4;
    y0[3]=1.0/4; 
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdata<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<endl;
        t0=i*h;
    }
    fdata<<endl<<endl;
    
    
    //P<D<V, most Hawks
    P=3;
    D=4;
    V=10;
    y0[0]=7.0/10;
    y0[1]=1.0/10;
    y0[2]=1.0/10;
    y0[3]=1.0/10;
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdata<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<endl;
        t0=i*h;
    }
    fdata<<endl<<endl;   
    
    //most Doves
    P=3;
    D=4;
    V=10;
    y0[0]=1.0/30;
    y0[1]=9.0/10;
    y0[2]=1.0/30;
    y0[3]=1.0/30;
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdata<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<endl;
        t0=i*h;
    }
    fdata<<endl<<endl;   
    
    
    //most Bullies
    P=3;
    D=4;
    V=10;
    y0[0]=1.0/10;
    y0[1]=1.0/10;
    y0[2]=7.0/10;
    y0[3]=1.0/10;
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdata<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<endl;
        t0=i*h;
    }
    fdata<<endl<<endl;   
    
    
    //most Retaliators
    P=3;
    D=10;
    V=4;
    y0[0]=1.0/30;
    y0[1]=1.0/30;
    y0[2]=1.0/30;
    y0[3]=9.0/10;
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdata<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<endl;
        t0=i*h;
    }
    fdata.close();
    #endif
    
   
    
    #if VALIDATION==1
    ofstream fdatab;
    fdatab.open(fValidation);
    
    //Verify Equilibrium H in simple game H-D with D<V
    P=3;
    D=5;
    V=10;
    y0[0]=1.0/2;
    y0[1]=1.0/2;
    y0[2]=0;
    y0[3]=0;
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdatab<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<endl;
        t0=i*h;
    }
    fdatab<<endl<<endl;
    
    
    //Verify Equilibrium ph=(2P+V)/(2P+D) & pd=1-(2P+V)/(2P+D) 
    //in simple game H-D with V<d
    P=3;
    D=10;
    V=5;
    y0[0]=1.0/2;
    y0[1]=1.0/2;
    y0[2]=0;
    y0[3]=0;
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdatab<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<
        " "<<(2*P+V)/(2*P+D)<<" "<<1-(2*P+V)/(2*P+D)<<endl;
        t0=i*h;
    }
    fdatab<<endl<<endl;
    
    
	//Verify no difference between D and R in absence of H and B
    P=3;
    D=5;
    V=10;
    y0[0]=0;
    y0[1]=1.0/2;
    y0[2]=0;
    y0[3]=1.0/2;
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdatab<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<endl;
        t0=i*h;
    }
    fdatab<<endl<<endl;
    
    
    //Verify R kill all B
    P=3;
    D=5;
    V=10;
    y0[0]=0;
    y0[1]=0;
    y0[2]=1.0/2;
    y0[3]=1.0/2; 
    t0=0;
    h=tf/N;
    for (int i=1; i<=N;i++){
        RK4(t0,y0,ydot, h,neq);
        fdatab<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
        <<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]<<endl;
        t0=i*h;
    }
    fdatab<<endl<<endl;
    fdatab.close();
    #endif
   
    
    #if BRUTE==1
    ofstream fdatac;
    fdatac.open(fBrute);
    int t=3;
    for (D=0;D<=t;D++){
	for (V=0;V<=t;V++){
	for (P=0;P<=t;P++){
		y0[0]=1.0/4;
		y0[1]=1.0/4;
		y0[2]=1.0/4;
		y0[3]=1.0/4; 
		t0=0;
		h=tf/N;
		for (int i=1; i<=N;i++){
			RK4(t0,y0,ydot, h,neq);
			fdatac<<t0<<" "<<y0[0]<<" "<<y0[1]<<" "
			<<y0[2]<<" "<<y0[3]<<" "<<y0[0]+y0[1]+y0[2]+y0[3]
			<<' '<<P<<' '<<D<<' '<<V<<endl;
			t0=i*h;
		}
		fdatac<<endl<<endl;
	}
	}
	}
    fdatac.close();
    #endif
    
   
    #if VERIFICATION==1
    double y02[neq],y03[neq]; 
    double err1e, err2e;
    double err1r, err2r;
	ofstream fdatad;
    fdatad.open(fVerification);
    
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
		fdatad<<endl<<endl;
		fdatad<<h<<" "<<err1e<<" "<<err1r<<endl;
	}
	fdatad.close();
    #endif
    return 0;
}
