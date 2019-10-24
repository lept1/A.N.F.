#include <iostream>

using namespace std;
  
    int main(){
		cout <<std::endl;
        
        int num1=11;
        cout << "Intero1 "<< num1<<endl;
        int num2=123;
        cout << "Intero2 "<< num2<<endl;
        
        cout << "somma "<< num2+num1<<endl;
        
        
        if (num1>=num2){
			cout << "differenza Intero1-Intero2 "<< num1-num2<<endl;
		}
		
		else if (num1<num2){
			cout << "differenza Intero2-Intero1 "<< num2-num1<<endl;
		}
		cout << "prodotto "<< num2*num1<<endl;
		
	    cout << "divisione Intero1/Intero2 "<< double(num1)/double(num2)<<endl;

		
		if (num2%num1==0){
			cout << "divisione Intero1/Intero2 "<< num2/num1<<endl;
		}
        
        
        float numr1= 11.2356;
        cout << "Reale1 "<< numr1<<endl;
        float numr2=1.2657;
        cout << "Reale2 "<< numr2<<endl;
        
        cout << "somma "<< numr2+numr1<<endl;
        
        
		cout << "differenza Reale1-Reale2 "<< numr1-numr2<<endl;
		cout << "differenza Reale2-Reale1 "<< numr2-numr1<<endl;
		
		
		cout << "prodotto "<< numr2*numr1<<endl;
		
		
		if (numr1!=0 and numr2!=0 ){
			cout << "divisione Reale2/Reale1 "<< numr2/numr1<<endl;
			cout << "divisione Reale1/Reale2 "<< numr1/numr2<<endl;
		}
			

        
		return 0;
}
