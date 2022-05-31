#include <iostream>
#include <string>
using namespace std;

int main() {
	
	string check1, check2 = "Y";
	
	do{
		int markst = 0, marks, avg, i;
	
		for(i = 1; i <= 3; i++){
			cout<<"Please enter test marks daddy OwO\n";
			cin>>marks;
			markst = markst + marks;
		}
		avg = markst / 3;
		cout<<"\nYour avg marks are: "<<avg;
		
		cout<<"\nPlease enter Y if you wish to continue abusing me UwU\n";
		
		cin>>check1; cout<<"";
		if(cin.get() == '\n'){
			check2 == "N";
		}
		
	
	}while (check1 == "y" && check2 != "N");
	
	
	return 0;
}
