#include <iostream>
using namespace std;

int main() {
    
    int num;
    

    cout<<"Enter integer value: "<<endl;
    cin>>num;
    
    
    try {
	cin>>num;

    }
    
    catch (char x){
        cout<<"Number is not integer.";
    }
    
    return 0;
}
