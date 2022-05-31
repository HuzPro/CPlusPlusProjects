#include <iostream>
using namespace std;

void ascending (int array [10]);

int main() {
    
    int array [10];
    
    cout<<"Enter 10 values: "<<endl;
    for (int i = 0; i < 10; i++) {
        cin>>array[i];
    }
    
    ascending (array);
    
    return 0;
}

void ascending (int array [10]) {
	
	int swapping;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j <
		 9; j++){
        	if(array[j] > array[j+1]){
        		swapping = array[j];
				array[j] = array[j+1];
				array[j+1] = swapping;
				
			} 
            
        }
    }
        
    for (int i = 0; i < 10; i++) {
        cout<<array[i]<<" ";
    }
}
