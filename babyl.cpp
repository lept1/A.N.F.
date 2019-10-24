#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

int main() {								
	double hp,x,temp,eps;
	cout << " input positive number to squareroot:"<<endl;
	cin >> x;
	cout << " input your hypothesis:"<<endl;
	cin >> hp;
	cout << " input desired accuracy:"<<endl;
	cin >> eps;
	temp=abs(hp*hp-x);
	while(temp>eps){
		hp=(hp+ (x / hp))/2;
		temp=abs(hp*hp-x);
	}	
	cout << "solution  " << hp <<endl;
 	return 0;
}


