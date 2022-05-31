#include <iostream>
using namespace std;

class RationalNumber{
    private:
        int numerator, denominator;
        
    public:
    
        RationalNumber();
        RationalNumber(int n,int d);
        
        void display();
        
        RationalNumber operator ++ (); 
        
        RationalNumber operator ++ (int);
        
        RationalNumber operator - (const RationalNumber& obj);
        
        RationalNumber operator / (const RationalNumber& obj);
        
        bool operator >= (const RationalNumber& obj);
        
        bool operator == (const RationalNumber& obj);
        
};



int main() {
    
    int n, d;
    
    cout<<"Enter Numerator value: ";
    cin>>n;
    cout<<"Enter Denominator value: ";
    cin>>d;
    
    RationalNumber fraction1, fraction2(n, d), result;
    
    cout<<"\nThe first fraction = ";
    fraction1.display();
    cout<<"\nThe second fraction = ";
    fraction2.display();
    
    fraction1++;
    cout<<"\nFirst fraction after post increment: ";
    fraction1.display();
    
    ++fraction2;
    cout<<"\nSecond fraction after pre increment: ";
	fraction2.display();
    
    result = fraction1 - fraction2;
    cout<<"\nResult after subtracting fraction 2 from fraction 1";
    result.display();
    
    result = fraction1 / fraction2;
    cout<<"\nResult after dividing fraction 1 by fraction 2";
    result.display();
    
    if(fraction1>=fraction2){
        cout<<"\nThe First fraction is greater than the Second fraction.";
    } else {
        cout<<"\nThe Second fraction is greater than the First fraction.";
    }
    
    if(fraction1==fraction2){
        cout<<"\nThe first fraction is Equal than the second fraction.";
    } else {
        cout<<"\nThe first fraction is NOT Equal than the second fraction.";
    }
    
    return 0;    
}

RationalNumber :: RationalNumber (){
	
    numerator = 28;
    denominator = 16;
            
    //Simplifying the fraction
    for (int i = denominator * numerator; i > 1; i--) {  
    	if ((denominator % i == 0) && (numerator % i == 0)) {  
            denominator /= i; // denominator = denominator / i;
            numerator /= i; // numerator = numerator / i;
        } // a = a + b, a += b
    }
}

RationalNumber :: RationalNumber (int n, int d) {
    numerator = n;
    denominator = d;
        
	//Checking for negative and 0 values for denominator
    while (denominator <= 0){
        cout<<"The value for denominator is either 0 or in negative numbers.\nEnter a value for denominator: ";
        cin>>denominator;
    }
            
    //Simplifying the fraction
    for (int i = denominator * numerator; i > 1; i--) {  
        if ((denominator % i == 0) && (numerator % i == 0)) {  
            denominator /= i;  
            numerator /= i;  
        }
    }
            
}

void RationalNumber :: display (){
    cout<<numerator<<"/"<<denominator<<endl;
}

RationalNumber RationalNumber :: operator ++ (){
    RationalNumber temp;
    ++numerator
    ++denominator
    temp.numerator = numerator;
    temp.denominator = denominator;
            
    return temp;
}      

RationalNumber RationalNumber :: operator ++ (int) {
    RationalNumber temp;
    numerator++;
    denominator++;
    temp.numerator = numerator;
    temp.denominator = denominator;
            
	return temp;
}

RationalNumber RationalNumber :: operator - (const RationalNumber& obj){
    RationalNumber temp;
    temp.numerator = (numerator*obj.denominator)-(denominator*obj.numerator);
    temp.denominator = denominator*obj.denominator;
            
    return temp;
}

RationalNumber RationalNumber :: operator / (const RationalNumber& obj) {
	RationalNumber temp;
    temp.numerator = numerator*obj.denominator;
    temp.denominator = denominator*obj.numerator;
            
    return temp;
}
  
 bool RationalNumber :: operator >= (const RationalNumber& obj) {
    int temp1, temp2;
    temp1 = numerator/denominator;
    temp2 = obj.numerator/obj.denominator;
    if (temp1>=temp2){
        return true;
    } else {
        return false;
    }
}      

bool RationalNumber :: operator == (const RationalNumber& obj) {
    int temp1, temp2;
    temp1 = numerator/denominator;
    temp2 = obj.numerator/obj.denominator;
    if (temp1==temp2){
        return true;
    } else {
        return false;
    }
}
