#include <iostream>
#include <limits>
using namespace std;

int main() {
    
    int num;
    int ex;

    cout<<"Enter integer value: "<<endl;
    
    
	while (true){
	try {

	    cin>>num;
	
		if (cin.fail() == true){
			cin.clear();
			throw num;
		} else {
			break;
		}
        
		
   	}

   	catch (int ex){
   	    cout<<"Please enter an integar value.\n";
   	}
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
 	}
    
    return 0;
}
