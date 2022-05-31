#include <iostream>
using namespace std;

float billing (float hourly_rate, float time, float income);

int main() {
    
    float hourly_rate, time, bill;
    char income;
    
    cout<<"Enter the hourly rate: ";
    cin>>hourly_rate;
    
    cout<<"\nEnter the total consulting time (in minutes): ";
    cin>>time;
    
    cout<<"\nDoes the person have low income? (Enter Y for yes N for no): ";
    cin>>income; 
    
    bill = billing (hourly_rate, time, income);
    
    cout<<"\n\nYour total billing amount is $"<<bill;

    return 0;
}

float billing (float hourly_rate, float time, float income) {
    
    float bill;
    
    if (income == 'Y' || income == 'y') {
        if (time <= 30) {
        bill = 0;
        }
        else {
        bill = hourly_rate*0.40*((time - 30)/60);
        }
    }
    
    if (income == 'N' || income == 'n') {
        if (time <= 20) {
            bill = 0;
        }
        else {
            bill = hourly_rate*0.70*((time - 30)/60);
        }
    }
    
    return bill;
        
    }
