#include <iostream>
using namespace std;

class RationalNumber{
	private:
		int numerator, denominator;
		
	public:
	//Constructors
		RationalNumber() {
			numerator = 28;
			denominator = 16;
			
			//Simplifying the fraction
			for (int i = denominator * numerator; i > 1; i--) {  
                if ((denominator % i == 0) && (numerator % i == 0)) {  
            		denominator /= i;  
                	numerator /= i;  
				}
			}
		}
		
		RationalNumber(int n,int d) {
			numerator = n;
			denominator = d;
			int temp1, temp2, gcd;
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
		
		void display() {
			cout<<"\nThe fraction is: "<<numerator<<"/"<<denominator<<endl;
		}
		
		RationalNumber operator ++ () {
			RationalNumber temp;
			++numerator;
			++denominator;
			temp.numerator = numerator;
			temp.denominator = denominator;
			
			return temp;
		}
		
		RationalNumber operator ++ (int) {
			RationalNumber temp;
			numerator++;
			denominator++;
			temp.numerator = numerator;
			temp.denominator = denominator;
			
			return temp;
		}
		
		RationalNumber operator - (const RationalNumber& obj) {
			RationalNumber temp;
			temp.numerator = (numerator*obj.denominator)-(denominator*obj.numerator);
			temp.denominator = denominator*obj.denominator;
			
			return temp;
		}
		
		RationalNumber operator / (const RationalNumber& obj) {
			RationalNumber temp;
			temp.numerator = numerator*obj.denominator;
			temp.denominator = denominator*obj.numerator;
			
			return temp;
		}
		
		bool operator >= (const RationalNumber& obj) {
			int temp1, temp2;
			temp1 = numerator/denominator;
			temp2 = obj.numerator/obj.denominator;
			if (temp1>temp2){
				return true;
			} else {
				return false;
			}
		}
		
		bool operator == (const RationalNumber& obj) {
			int temp1, temp2;
			temp1 = numerator/denominator;
			temp2 = obj.numerator/obj.denominator;
			if (temp1==temp2){
				return true;
			} else {
				return false;
			}
		}
		
};



int main() {
	
	int n, d;
	
	cout<<"Enter Numerator value: ";
	cin>>n;
	cout<<"Enter Denominator value: ";
	cin>>d;
	
	RationalNumber fraction1, fraction2(n, d), result;
	
	fraction1.display();
	fraction2.display();
	
	fraction1++;
	fraction1.display();
	
	++fraction2;
	fraction2.display();
	
	result = fraction1 - fraction2;
	result.display();
	
	result = fraction1 / fraction2;
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
