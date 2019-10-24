#include "header.h"

void GaussElimination(double **a,int n){
	PartialPivot(a,n);
	for (int i=0;i<n-1;i++){
		for (int k=i+1;k<n;k++){
			double t=a[k][i]/a[i][i];
			for (int j=0;j<=n;j++){
				a[k][j]=a[k][j]-t*a[i][j];    
            }
		}
	}
}

void SwapRow(double **a, int i, int j, int n) { 
    for (int k=0; k<n; k++) { 
        double temp = a[i][k]; 
        a[i][k] = a[j][k]; 
        a[j][k] = temp; 
    }
}

void PartialPivot(double **a, int n){
	double amax, tmp;
	int imax;
	for (int k=0; k<n-1; k++){
		amax=a[k][k];
		imax=k;
		for(int i=k+1; i<n;i++){
			tmp=fabs(a[i][k]);
			if (tmp>amax){
				imax=i;
				amax=tmp;
			}
		}
		SwapRow(a,k,imax,n);
	}
}

void TridiagonalSolver(double* a, double* b, double* c, double* d, int n) {
    
    n--;
    c[0] /= b[0];
    d[0] /= b[0];

    for (int i = 1; i < n; i++) {
        c[i] /= b[i] - a[i]*c[i-1];
        d[i] = (d[i] - a[i]*d[i-1]) / (b[i] - a[i]*c[i-1]);
    }

    d[n] = (d[n] - a[n]*d[n-1]) / (b[n] - a[n]*c[n-1]);

    for (int i = n; i-- > 0;) {
        d[i] -= c[i]*d[i+1];
    }
}

void PrintMat(double **a,int n){
	for	(int i=0;i<n;i++){					
		for	(int j=0;j<n;j++){							
		cout <<setw(10)<<right<<a[i][j]	<<	"  ";					
		}					
		cout<<endl;			
	}
}
