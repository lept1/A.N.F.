#include "header.h"

#define COL 5
#define ROW 5


int main(){
	cout<<fixed<<setprecision(4);
	double **A= new double *[ROW];
	double *r= new double [ROW]; 	
    A[0]=new double	[ROW*COL];	
	
	for (int j=1;j<ROW;j++){	
		A[j]=A[j-1]	+COL;	
	}
	
	A[0][0]=2;	A[0][1]=1;	A[0][2]=0;	A[0][3]=0;	A[0][4]=0;	r[0]=1;
	A[1][0]=1;	A[1][1]=2;	A[1][2]=1;	A[1][3]=0;	A[1][4]=0;	r[1]=0;
	A[2][0]=0;	A[2][1]=1;	A[2][2]=2;	A[2][3]=1;	A[2][4]=0;	r[2]=3;
	A[3][0]=0;	A[3][1]=0;	A[3][2]=1;	A[3][3]=2;	A[3][4]=1;	r[3]=1;
	A[4][0]=0;	A[4][1]=0;	A[4][2]=0;	A[4][3]=1;	A[4][4]=2;	r[4]=0;
	
	for	(int i=0;i<ROW;i++){					
		for	(int j=0;j<COL;j++){							
		cout <<setw(10)<<right<<A[i][j]	<<	"		";					
		}					
		cout<<endl;			
	}
	double *a= new double [ROW-1];
	a[1]=1;a[2]=1;a[3]=1;a[4]=1;
	double *b= new double [ROW];
	b[0]=2;b[1]=2;b[2]=2;b[3]=2;b[4]=2;
	double *c= new double [ROW-1];
	c[0]=1;c[1]=1;c[2]=1;c[3]=1;
	double *x= new double [ROW];
	TridiagonalSolver(a,b,c,r,ROW);
	for (unsigned int i = 0; i < ROW; i++) {
			cout << setprecision(4)<<"  "<<r[i] <<"  ";
		}
	cout<<endl;
}
