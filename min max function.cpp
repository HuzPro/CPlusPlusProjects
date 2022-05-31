#include <iostream>
using namespace std;

float minimum (float num1 = 34, float num2 = 65, float num3 = 21);

int main() {
    
    float min, num1, num2, num3;
    
    min = minimum ();
    
    cout<<"The minimum number = "<<min;
    
    cout<<"\nEnter a number: ";
    cin>>num3;
    
    min = minimum (num1, num2, num3);
    
    cout<<"The minimum number = "<<min;
    
    cout<<"\n\nEnter first number: ";
    cin>>num1;
    
    cout<<"\nEnter second number: ";
    cin>>num2;
    
    cout<<"\nEnter third number: ";
    cin>>num3; 
    
    min = minimum (num1, num2, num3);
    
    cout<<"\n\nThe minimum number = "<<min;
    
    return 0;
}

float minimum (float num1, float num2, float num3) {
    
    float min;
    
    min = num1;
    
    if (num2 <= num1) {
        min = num2;
    }
    
    if (num3 <= num2) {
        min = num3;
    }
    
    return min;
}
