#include <iostream>
using namespace std;

int main() {
    
    int matrix1[3][3], matrix2[3][3], i, j, k;
    int temp1, total[3][3];
    
    cout<<"Enter 9 numbers in a 3x3 matrix: "<<endl;
    
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
        	cin>>matrix1[i][j];
        }
    }
     
    cout<<"\nEnter 9 numbers in another 3x3 matrix: "<<endl;
    
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
        	cin>>matrix2[i][j];
        }
    }
     
    cout<<"\nMatrix 1: "<<endl;
    
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
        	cout<<matrix1[i][j]<<" ";
        }
    cout<<endl;
    }
     
    cout<<"\nMatrix2: "<<endl;
    
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
        cout<<matrix2[i][j]<<" ";
        }
    cout<<endl;
    }
     
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2 ; j++) {
			temp1 = 0;
         	for (k = 0; k <= 2; k++){
		 		temp1 = temp1 + matrix1[i][k]*matrix2[k][j];
			}
			total[i][j] = temp1;
		}
		
    }
    
    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
        	cout<<"\t";
        	cout<<" "<<total[i][j];
        }
        cout<<"\n";
    }
    
     
     
     
     
     
    
    
    
    return 0;
}
