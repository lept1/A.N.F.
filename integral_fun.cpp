#include "header.h"

int main(void) {
      double a, b, Ig, eps; 
      int ord, N;
      cout << "Enter begining of interval: "; 
      cin >> a; 
      cout << "Enter end of interval: "; 
      cin >> b;
      cout << "Enter number of iterations: "; 
      cin >> N;
      cout << "Enter number of Quadrature order: "; 
      cin >> ord;
      cout << "Enter tolerance for zeros search: "; 
      cin >> eps;
      
      Ig=GaussLegendre(Sic,a,b,N,ord,eps);
      cout << "Integral quad is equal to: " << setprecision(12)<<Ig << endl;
      return 0;
}
    
