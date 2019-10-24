#include "header.h"



double Source(double x, double y){
	
		return 0.0;
	
}

double Bound(double x, double y){
	double bc;
	if(x==0){
		bc=;
	}
	if(x==2){
		bc=;
	}
	return bc;
}




int main(){
	cout<<fixed<<setprecision(4);
	int Nx=129,Ny=65;
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
	double h=1.0/(Ny-1);
	
	x[0]=0;
	for(int j=1;j<=Nx;++j){
			x[j]=x[j-1]+h;
	}
	y[0]=0;
	for(int j=1;j<=Ny;++j){
			y[j]=y[j-1]+h;
	}
	
	//JACOBI METHOD
	for(int i=0;i<Nx;++i){
		for(int j=0;j<Ny;++j){
			phi_old[j][i]=0;
			phi_new[j][i]=0;
		}
	}
	//B.C.
	for(int i=0;i<Nx;++i){
		phi_old[0][i]=0;
	}
	
	for(int i=0;i<Nx;++i){
		phi_old[Ny-1][i]=2-x[i];
	}
	
	for(int i=0;i<Ny;++i){
		phi_old[i][0]=Bound(x[0],y[i]);
	}
	
	for(int i=0;i<Ny;++i){
		phi_old[i][Nx-1]=Bound(x[Nx-1],y[i]);
	}
	
	//PrintMat(phi_old, Nx);
	int k=0;
	double tol=1.e-7, res=1.e10, err=0;
	while(k<1500){
		for	(int i=1;i<Nx-1;i++){					
			for	(int j=1;j<Ny-1;j++){
				S=Source(x[i],y[j]);							
				phi_new[j][i]=0.25*(phi_old[j][i-1]+phi_old[j][i+1]+phi_old[j-1][i]+phi_old[j+1][i]-h*h*S);
				err=abs(phi_new[j][i]-Bound(x[i],y[j]));
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
			phi_old[j][i]=0;
			phi_new[j][i]=0;
		}
	}
	for(int j=0;j<Ny;j++){
		for(int i=0;i<Nx;i++){
			phi_old[j][i]=Bound(x[i],y[j]);
		}
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
				err=abs(phi_new[j][i]-Bound(x[i],y[j]));
				
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
			phi_old[j][i]=0;
			phi_new[j][i]=0;
		}
	}
	for(int j=0;j<Ny;j++){
		for(int i=0;i<Nx;i++){
			phi_old[j][i]=Bound(x[i],y[j]);
		}
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
				err+=abs(phi_new[j][i]-Bound(x[i],y[j]));
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

