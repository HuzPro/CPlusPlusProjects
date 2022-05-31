#include <iostream>

using namespace std;


int main()
{
	int bookId[20][20], test = 54;
	
	for(int i = 0; i <= 20; i++){
		bookId[][i]= test+i;
	}
	
	for(int i = 0; i <= 20; i++){
		cout<<bookId[][i];
	}


return 0;
}
