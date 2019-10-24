#include <iostream>

using namespace std;
  
    int main(){
		cout <<std::endl;
        for (int num=0;num<11; num+=1){
			cout << "Numero con for:"<< num <<endl;  
        }
        
        int aritm=0;
        while(aritm<11){
			cout << "Numero con while:"<< aritm<<endl;
			aritm+=1; 
        }
        
		return 0;
}
