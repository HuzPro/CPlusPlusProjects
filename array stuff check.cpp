#include <iostream>
using namespace std;

int main() {
    
    int array[10];
    int evenn=0, oddn=0, positive=0, negative=0, zero=0, prime=0, composite=0, pcheck = 1;
    
    for (int i = 0; i < 10; i++) {
        cout<<"Enter number "<<i+1<<": ";
        cin>>array[i];
    }
    
    cout<<endl;
    
	for (int i = 0; i < 10; i++) {
        
        
        if (array[i]%2 == 0) {
            evenn++;
        } else {
            oddn++;
        }
    
        if (array[i] > 0) {
            positive++;
        }
        if (array[i] < 0){
            negative ++;
        }
    
        if (array[i] == 0) {
            zero++;
        }
        
        
        if(array[i] != 0 && array[i] != 1){
		if(array[i] < 0){
           	pcheck = 0;
		}
        int j = 2;
        j = 2;
        int halfofarray = array[i]/2;
            for(j = 2;j <= halfofarray; j++){
            	
                if (array[i] % j == 0) {
                    pcheck = 0;
                }
            }
            
			if(pcheck == 0){
			composite++;
			} else if(pcheck == 1){
            prime++;
			}
			
			
			pcheck = 1;
        }
        
    }    
    cout<<"There are "<<evenn<<" even numbers \n";
    cout<<"There are "<<oddn<<" odd numbers \n";
    cout<<"There are "<<prime<<" prime numbers \n";
    cout<<"There are "<<composite<<" composite numbers \n";
    cout<<"There are "<<zero<<" zeros \n";
    cout<<"There are "<<positive<<" positive numbers \n";
    cout<<"There are "<<negative<<" negative numbers \n";
    
    
    return 0;
}
