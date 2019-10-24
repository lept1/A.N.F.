#include "header.h"	

void Gauss(double a){
	for (i=0;i<a.size();i++){
		for (k=i+1;k<n;k++){
			double t=a[k][i]/a[i][i];
			for (j=0;j<=n;j++){
				a[k][j]=a[k][j]-t*a[i][j];    //make the elements below the pivot elements equal to zero or elimnate the variables
            }
