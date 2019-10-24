#include "header.h"

double Source(double x, double y){
	return 2;
}

double Poiss(double x, double y){
	double pp, S;
	S=Source(x,y);
	pp=exp(-M_PI*x)*sin(-M_PI*y)+S/4*(x*x+y*y);
	return pp;
}




int main(){
	int Nx=32,Ny=32;
	double S;
	
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
	double h=1.0/(Nx-1);
	
	x[0]=0;
	for(int j=1;j<Nx;++j){
			x[j]=x[j-1]+h;
	}
	
	y[0]=0;
	for(int j=1;j<Ny;++j){
			y[j]=y[j-1]+h;
	}
	
	//JACOBI METHOD
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
			phi_old[i][j]=0;
			phi_new[i][j]=0;
		}
	}
	
	for(int i=0;i<Nx;++i){
		phi_old[0][i]=Poiss(x[i],y[0]);
	}
	
	for(int i=0;i<Nx;++i){
		phi_old[Ny-1][i]=Poiss(x[i],y[Ny-1]);
	}
	
	for(int i=0;i<Ny;++i){
		phi_old[i][0]=Poiss(x[0],y[i]);
	}
	
	for(int i=0;i<Ny;++i){
		phi_old[i][Nx-1]=Poiss(x[Nx-1],y[i]);
	}
	//PrintMat(phi_old, Nx);
	int k=0;
	double tol=1.e-7, res=1.e10, err=0;
	while(k<3000){
		for	(int i=1;i<Nx-1;i++){					
			for	(int j=1;j<Ny-1;j++){
				S=Source(x[i],y[j]);							
				phi_new[j][i]=0.25*(phi_old[j][i-1]+phi_old[j][i+1]+phi_old[j-1][i]+phi_old[j+1][i]-h*h*S);
				err=abs(phi_new[j][i]-Poiss(x[i],y[j]));
				//cout <<x[i]<<" "<<y[j]<<" "<<phi_new[j][i]<<" "<<err<<endl;
				
			}								
		}
		phi_old=phi_new;
		k++;
		res=err;
	}
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
		cout <<x[i]<<" "<<y[j]<<" "<<phi_new[j][i]<<" "<<err<<endl;
		}
	}
	cout<<endl<<endl;
	
	//GAUSS METHOD
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
			phi_old[i][j]=0;
			phi_new[i][j]=0;
		}
	}
	
	for(int i=0;i<Nx;++i){
		phi_old[0][i]=Poiss(x[i],y[0]);
	}
	
	for(int i=0;i<Nx;++i){
		phi_old[Ny-1][i]=Poiss(x[i],y[Ny-1]);
	}
	
	for(int i=0;i<Ny;++i){
		phi_old[i][0]=Poiss(x[0],y[i]);
	}
	
	for(int i=0;i<Ny;++i){
		phi_old[i][Nx-1]=Poiss(x[Nx-1],y[i]);
	}
	//PrintMat(phi_old, Nx);
	k=0;
	tol=1.e-7;
	res=1.e10;
	err=0;
	while(k<1500){
		for	(int i=1;i<Nx-1;i++){					
			for	(int j=1;j<Ny-1;j++){
				S=Source(x[i],y[j]);							
				phi_new[j][i]=0.25*(phi_new[j][i-1]+phi_old[j][i+1]+phi_new[j-1][i]+phi_old[j+1][i]-h*h*S);
				err=abs(phi_new[j][i]-Poiss(x[i],y[j]));
				//cout <<x[i]<<" "<<y[j]<<" "<<phi_new[j][i]<<" "<<err<<endl;
				
			}								
		}
		phi_old=phi_new;
		k++;
		res=err;
	}
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
		cout <<x[i]<<" "<<y[j]<<" "<<phi_new[j][i]<<" "<<err<<endl;
		}
	}
	cout<<endl<<endl;
	//SOR METHOD
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
			phi_old[i][j]=0;
			phi_new[i][j]=0;
		}
	}
	
	for(int i=0;i<Nx;++i){
		phi_old[0][i]=Poiss(x[i],y[0]);
	}
	
	for(int i=0;i<Nx;++i){
		phi_old[Ny-1][i]=Poiss(x[i],y[Ny-1]);
	}
	
	for(int i=0;i<Ny;++i){
		phi_old[i][0]=Poiss(x[0],y[i]);
	}
	
	for(int i=0;i<Ny;++i){
		phi_old[i][Nx-1]=Poiss(x[Nx-1],y[i]);
	}
	//PrintMat(phi_old, Nx);
	
	k=0;
	tol=1.e-7;
	res=1.e10;
	err=0;
	double w;
	w=1.5;
	while(k<1500){
		for	(int i=1;i<Nx-1;i++){					
			for	(int j=1;j<Ny-1;j++){
				S=Source(x[i],y[j]);							
				phi_new[j][i]=(1-w)*phi_old[j][i]+0.25*w*(phi_new[j][i-1]+phi_old[j][i+1]+phi_new[j-1][i]+phi_old[j+1][i]-h*h*S);
				err=abs(phi_new[j][i]-Poiss(x[i],y[j]));
				//cout <<x[i]<<" "<<y[j]<<" "<<phi_new[j][i]<<" "<<err<<endl;
				
			}								
		}
		phi_old=phi_new;
		k++;
		res=err;
	}
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
		cout <<x[i]<<" "<<y[j]<<" "<<phi_new[j][i]<<" "<<err<<endl;
		}
	}	
	
	return 0;
	
	
}	
	
