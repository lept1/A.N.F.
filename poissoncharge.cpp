#include "header.h"

static double g_rho0;
static double g_a;

double Density(double x, double y){
	double r;
	if (r<=g_a){
		return g_rho0;
	}
	else{
		return 0.0;
	}
}

double Charge(double x, double y){
	double pp, r;
	r=sqrt(x*x+y*y);
	if(r<=g_a){
		pp=-g_rho0*r*r*0.25;
	}
	else{
		//pp=-0.5*g_rho0*g_a*g_a*(log(r/g_a)+0.5);
		pp=0;
	}
	return pp;
}




int main(){
	cout<<fixed<<setprecision(4);
	int Nx=30,Ny=30;
	double S;
	g_rho0=1;
	g_a=0.1;
	double **phi_old= new double *[Nx];
	double **phi_new= new double *[Nx];
	
	phi_old[0]=new double [Nx*Ny];	
	for (int j=1;j<Nx;j++){	
		phi_old[j]=phi_old[j-1]+Ny;	
	}
	
	phi_new[0]=new double [Nx*Ny];	
	for (int j=1;j<Nx;j++){	
		phi_new[j]=phi_new[j-1]+Ny;	
	}
	
	double x[Nx];
	double y[Ny];
	double h=2.0/(Nx-1);
	
	x[0]=-1;
	for(int j=1;j<Nx;++j){
			x[j]=x[j-1]+h;
	}
	y[0]=-1;
	for(int j=1;j<Ny;++j){
			y[j]=y[j-1]+h;
	}
	
	//JACOBI METHOD
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
			phi_old[j][i]=0;
			phi_new[j][i]=0;
		}
	}
	for(int j=0;j<Ny;j++){
		for(int i=0;i<Nx;i++){
			phi_old[j][i]=Charge(x[i],y[j]);
		}
	}
	
	
	int k=0;
	double tol=1.e-7, res=1.e10, err=0;
	while(res>tol){
		err=0;
		for	(int i=1;i<Nx-1;i++){					
			for	(int j=1;j<Ny-1;j++){
				S=Density(x[i],y[j]);							
				phi_new[j][i]=0.25*(phi_old[j][i-1]+phi_old[j][i+1]+
					phi_old[j-1][i]+phi_old[j+1][i]-h*h*S);
				err+=abs(h*h*phi_old[j][i]+h*h*phi_old[j][i]-h*h*S);
				
			}								
		}
		cout<<err<<endl;
		res=err*h*h;
		phi_old=phi_new;
		k++;
		
	}
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
		cout <<x[i]<<" "<<y[j]<<" "<<phi_old[j][i]<<" "<<k<<endl;
		}
	}
	cout<<endl<<endl;
	
	//GAUSS METHOD
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
			phi_old[j][i]=0;
		}
	}
	for(int j=0;j<Ny;j++){
		for(int i=0;i<Nx;i++){
			phi_old[j][i]=Charge(x[i],y[j]);
		}
	}

	k=0;
	tol=1.e-7;
	res=1.e10;
	err=0;
	while(res>tol){
		err=0;
		for	(int i=1;i<Nx-1;i++){					
			for	(int j=1;j<Ny-1;j++){
				S=Density(x[i],y[j]);							
				phi_old[j][i]=0.25*(phi_old[j][i-1]+phi_old[j][i+1]+
					phi_old[j-1][i]+phi_old[j+1][i]-h*h*S);
				err+=abs(h*h*2*phi_old[j][i]-h*h*S);
				
			}								
		}
		res=err;
		cout<<err<<endl;
		k++;
		
	}
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
		cout <<x[i]<<" "<<y[j]<<" "<<phi_old[j][i]<<" "<<k<<endl;
		}
	}	
	cout<<endl<<endl;
	//SOR METHOD
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
			phi_old[j][i]=0;
		}
	}
	for(int j=0;j<Ny;j++){
		for(int i=0;i<Nx;i++){
			phi_old[j][i]=Charge(x[i],y[j]);
		}
	}
	k=0;
	tol=1.e-7;
	res=1.e10;
	err=0;
	double w;
	w=1.5;
	while(res>tol){
		err=0;
		for	(int i=1;i<Nx-1;i++){					
			for	(int j=1;j<Ny-1;j++){
				S=Density(x[i],y[j]);							
				phi_new[j][i]=(1-w)*phi_old[j][i]+
					0.25*w*(phi_new[j][i-1]+phi_old[j][i+1]+
					phi_new[j-1][i]+phi_old[j+1][i]-h*h*S);
				err+=abs(h*h*phi_old[j][i]+h*h*phi_old[j][i]-h*h*S);
			}								
		}
		k++;
		res=err;
	}
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
		cout <<x[i]<<" "<<y[j]<<" "<<phi_old[j][i]<<" "<<k<<endl;
		}
	}	
	
	return 0;
	
	
}	
