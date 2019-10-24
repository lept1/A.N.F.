#include "header.h"

#define ROW 32

void solve(double* a, double* b, double* c, double* d, int n) {
    
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

int main(){
	cout<<fixed<<setprecision(4);
	double x1,xN,h,y1,yN;
	x1=0;
	xN=1;
	y1=0;
	yN=0;
	h=abs(x1-xN)/(ROW+2);
	
	double *r= new double [ROW];
	
	double *a= new double [ROW];
	
	double *b= new double [ROW];
	
	double *c= new double [ROW];

	
	for(int i=0; i<ROW;i++){
		
		if (i==0){
			r[i]=h*h-y1;
			b[i]=-2;
			c[i]=1;
		}
		else if (i==ROW-1){
			r[i]=h*h-yN;
			b[i]=-2;
			a[i]=1;
		}
		else {
			r[i]=h*h;
			b[i]=-2;
			a[i]=1;
			c[i]=1;
		}
		//cout<<i<<" 	"<<r[i]<<" "<<a[i]<<" " << b[i]<<" "<<c[i]<<endl;
	}
	solve(a,b,c,r,ROW);
	for (unsigned int i = 0; i <ROW; i++) {
			cout << setprecision(4)<<x1+(i+1)*h<<" 	 "<<r[i] <<endl;
		}
	cout<<endl;
}
