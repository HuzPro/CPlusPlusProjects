#include <iostream>
#include <string>
using namespace std;

struct Person {
	string name;
	int age;
	double salary;
};

int main(){
	
	int x;


	Person Prsn[100];

	x = 0;

	do {
		cout<<"Input name: ";
		cin>>Prsn[x].name;
		cout<<"Input age: ";
		cin>>Prsn[x].age;
		cout<<"Input salary: ";
		cin>>Prsn[x].salary;
		
	x++;
	} while (x <= 100);
return 0;
}
