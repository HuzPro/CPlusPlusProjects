#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
        private:
                string name;
                int age;
                double balance;
       
        public:
        void open()   //setter
        {
                cout<<"Enter your name: ";
                cin>>name;
                cout<<"Enter your age: ";
                cin>>age;
                cout<<"Enter your balance: ";
                cin>>balance;
        }
       
        string getname()  //getter
        {
                return name;
        }
       
        int getage()   //getter
        {
                return age;
        }
       
        int getbalance()  //getter
        {
                return balance;
        }
       
};


double deposit(double bal);
double withdraw(double bal);
double display(string name, int age, double bal);


int main()
{
        BankAccount b1,b2;
        double bal1,bal2, tempbal;
        string name1, name2;
        int age1, age2;
        
        //Testing for first object
        b1.open();
        
        bal1 = b1.getbalance();
        name1 = b1.getname();
        age1 = b1.getage();
        
        tempbal = deposit(bal1);
        bal1 = tempbal;
        tempbal = withdraw(bal1);
        bal1 = tempbal;
        display(name1, age1, bal1);
       
        //Testing for second object
        b2.open();
        
        bal2 = b2.getbalance();
        name2 = b2.getname();
        age2 = b2.getage();
        
        tempbal = deposit(bal2);
        bal2 = tempbal;
        tempbal = withdraw(bal2);
        bal2 = tempbal;
        display(name2, age2, bal2);
        
        return 0;
}

    double deposit(double bal)
    {
            double deposit;
            cout<<"Enter amount to deposit: ";
            cin>>deposit;
            if(deposit<=0)
                cout<<"Invalid amount";
            else
                bal = bal + deposit;
            return bal;
    }
       
    double withdraw(double bal)
        {
                double withdraw;
                cout<<"Enter amount to withdraw: ";
                cin>>withdraw;
                if(withdraw>bal)
                        cout<<"Insufficient balance";
                else
                        bal = bal - withdraw;
            	return bal;
        }
    
       
    double display(string name, int age, double bal)
    {
        cout<<"Your name: "<<name<<endl;
        cout<<"Your age: "<<age<<endl;
        cout<<"Your balance: "<<bal<<endl;
        cout<<"Thank you for banking with TBL"<<endl;
    }
