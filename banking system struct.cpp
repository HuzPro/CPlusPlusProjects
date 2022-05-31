#include <iostream>
#include <string>

using namespace std;

struct BankAccount
{
	string name;
	int age;
	double balance;
};

BankAccount open(BankAccount);
BankAccount deposit(BankAccount);
BankAccount withdraw(BankAccount);
BankAccount display(BankAccount);



int main()
{
    BankAccount b1, b2, temp;
    //Testing for first object
    temp = open(b1);
    b1 = temp;
    temp = deposit(b1);
    b1 = temp;
	temp = withdraw(b1);
	b1 = temp;
    display(b1);
        
	//Testing for second object
    temp = open(b2);
    b2 = temp;
    temp = deposit(b2);
    b2 = temp;
	temp = withdraw(b2);
	b2 = temp;
    display(b2);
	
	return 0;
}

	BankAccount open(BankAccount b1)
        {
            cout<<"Enter your name: ";
            cin>>b1.name;
            cout<<"Enter your age: ";
            cin>>b1.age;
            cout<<"Enter your balance: ";
            cin>>b1.balance;
            
            return b1;
        }
    
       
    BankAccount deposit(BankAccount b1)
    {
            double deposit;
            cout<<"Enter amount to deposit: ";
            cin>>deposit;
            if(deposit<0)
                cout<<"Invalid amount";
            else
                b1.balance = b1.balance + deposit;
            return b1;
    }
       
    BankAccount withdraw(BankAccount b1)
        {
                double withdraw;
                cout<<"Enter amount to withdraw: ";
                cin>>withdraw;
                if(withdraw>b1.balance)
                        cout<<"Insufficient balance";
                else
                        b1.balance = b1.balance - withdraw;
            	return b1;
        }
    
       
    BankAccount display(BankAccount b1)
    {
        cout<<"Your name: "<<b1.name<<endl;
        cout<<"Your age: "<<b1.age<<endl;
        cout<<"Your balance: "<<b1.balance<<endl;
        cout<<"Thank you for banking with TBL"<<endl;
        return b1;
    }
