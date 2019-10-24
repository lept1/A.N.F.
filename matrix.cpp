#include "header.h"

#define m 10
#define n 10

int main(){
	cout<<fixed<<setprecision(4);
	int seed;
	seed=time(NULL);
	srand(seed);
	double **A= new double *[m];
		
    A[0]=new double	[n*m];	
	
	for (int j=1;j<m;j++){	
		A[j]=A[j-1]	+n;	
	}
	
	
	for(int i = 0 ; i < m ; ++i){
		for(int j = 0 ; j < n ; ++j){
			A[i][j]=drand48();
		}
	}
	
	for	(int i=0;i<m;i++){					
		for	(int j=0;j<n;j++){							
		cout <<setw(10)<<right<<A[i][j]	<<	"  ";					
		}					
		cout<<endl;			
	}
	cout<<endl;	
	cout<<endl;
	
	SwapRow(A, 1,2,n);
	for	(int i=0;i<m;i++){					
		for	(int j=0;j<n;j++){							
		cout <<setw(10)<<right<<A[i][j]	<<	"  ";					
		}					
		cout<<endl;			
	}
	cout<<endl;	
	cout<<endl;
	
	PartialPivot(A,n);
	for	(int i=0;i<m;i++){					
		for	(int j=0;j<n;j++){							
		cout <<setw(10)<<right<<A[i][j]	<<	"  ";					
		}					
		cout<<endl;			
	}
	
	cout<<endl;	
	cout<<endl;	
	
	GaussElimination(A,n);
	for	(int i=0;i<m;i++){					
		for	(int j=0;j<n;j++){							
		cout <<setw(10)<<right<<A[i][j]	<<	"  ";					
		}					
		cout<<endl;			
	}
	return 0;
}			
