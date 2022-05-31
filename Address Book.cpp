#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class addressType {
    
    private:
        string strAddress, city, state;
        double ZIP;
        
    public:
        addressType(){
            strAddress = " ";
            city = " ";
            state = " ";
            ZIP = 0;
        }
        
        void setAddressType(string addr, string cit, string sta, int zip){
		    strAddress = addr;
    		city = cit;
		    state = sta;
    		ZIP = zip;
		}
        
        
        void print(){
        	cout<<"State: "<<state;
        	cout<<"City: "<<city;
        	cout<<"Street Address: "<<strAddress;
        	cout<<"ZIP Code: "<<ZIP;
		}
};

class dateType	{
	
	private:
		int dMonth;
		int dDay;
		int dYear;
	
	
	public:
	
		dateType(int month = 1, int day = 1, int year = 1900){
			dMonth = month;
			dDay = day;
			dYear = year;
		}
		
		void setDate(int month, int day, int year){
			dMonth = month;
			dDay = day;
			dYear = year;
		}
		
		int getDay() const{
			return dDay;
		}
		
		int getMonth() const{
			return dMonth;
		}
		
		int getYear() const{
			return dYear;
		}
		
		void printDate() const{
			cout<<dMonth<<"-"<<dDay<<"-"<<dYear;
		}
		
		
};

class personType {
    
    private:
        string firstName;
        string lastName;
        
    public:
        void setName(string First, string Last){
            
            firstName = First;
            lastName = Last;
        }
        
        void printName() {
            cout << firstName << " " << lastName;
        }
        
        string getFirstName(){
            return firstName;
        }
        
        string getLName(){
            return lastName;
        }
        
        
};


class extPersonType {
    
    private:
    	personType name;
        addressType address;
        dateType birthday;
        string contactGroup;
        string phone;
        
    public:
        extPersonType() {
        	string firstName = "";
        	string lastName = "";
        	
        	phone = "";
        	contactGroup = "Business";
        	birthday.setDate(05, 06, 2000);
    	}
    	
    	void setExtPersonType(string first, string last, int month, int day, int year, string straddr, string city, string state, int zip, string cGroup, string phon){
    		name.setName(first, last);
    		birthday.setDate(month, day, year);
    		address.setAddressType(straddr, city, state, zip);
    		contactGroup = cGroup;
    		phone = phon;
		}
		
		void printNames() {
			name.printName();
		}
		
		string getLastName() {
			return name.getLName();
		}
		
    	string getGroup()const {
        
        	return contactGroup;    
    	}

    	int getBirthday()const {
        
        	return birthday.getMonth();    
    	}
    
    
    	void printExtPersonType(){
    		cout<<"Name: ";
    		name.printName();
    		cout<<"Date of birth: ";
    		birthday.printDate();
    		cout<<"Contact number: "<<phone<<endl;
    		cout<<"Contact group: "<<contactGroup<<endl;
    	}
    
};


class addressBookType : public extPersonType {
	
	private:
		static const int maxEntries=2;
		extPersonType addrBook[maxEntries];
		ifstream inF;
		
	
	public:
		addressBookType(){
		}
		
		void setInfo(string file){
			string firstName, lastName;
			int dDate, dMonth, dYear;
			string strAddress, city, state;
			int zip;
			string contactGroup;
			string phone;
			inF.open(file.c_str());
			for (int i=0; i<maxEntries; i++){
				inF>>firstName>>lastName>>dMonth>>dDate>>dYear>>strAddress>>city>>state>>zip>>contactGroup>>phone;
				addrBook[i].setExtPersonType(firstName, lastName, dMonth, dDate, dYear, strAddress, city, state, zip, contactGroup, phone);
			}
			inF.close();
		}
		
		void nameSort(){
			extPersonType temp;
			for(int i=1; i<maxEntries; i++){
				for(int j=0; j<maxEntries-1; j++){
					if(addrBook[j].getLastName()>addrBook[j+1].getLastName()){
						temp = addrBook[j+1];
						addrBook[j]=addrBook[j+1];
						addrBook[j+1] = temp;
					}
				}
			}
		}
		
		void nameSearch(string choice){
			cout<<"Returning results for "<<choice<<": "<<endl;
			for (int i=0; i<maxEntries;i++){
				if(addrBook[i].getLastName() == choice){
					addrBook[i].printExtPersonType();
				}
			}
		}
		
		void birthdaySearch(int month){
			for(int i=0; i<maxEntries; i++){
				if(addrBook[i].getBirthday()==month){
					addrBook[i].printNames();
					cout<<endl;
				}
			}
		}
		
		void printNameRange(string first, string last){
			for (int i=0; i<maxEntries; i++){
				if(first <= addrBook[i].getLastName() || addrBook[i].getLastName() <= last){
					addrBook[i].printNames();
					cout<<endl;
				}
			}
		}
		
		void printContactGroup(string choice){
			for (int i=0; i<maxEntries; i++){
				if(addrBook[i].getGroup() == choice){
					addrBook[i].printNames();
					cout<<endl;
				}
			}
		}
};


int main() {
	
	const int maxEnteries = 500;
	
	addressBookType addrObject;
	string searchV, first, last;
	int month;
	addrObject.setInfo("AddressBookData.txt");
	addrObject.nameSort();
	
	do 
	{
		cout<<"Please name the parameters you want to search \n(Enter 0 at any point to Terminate the program.): ";
		cin>>searchV;
		if(searchV == "Birthday"){
			cout<<"Please enter your month: ";
			cin>>month;
			addrObject.birthdaySearch(month);
		}
		if(searchV == "Names"){
			cout<<"Please enter the first and the last names: ";
			cin>>first>>last;
			addrObject.printNameRange(first, last);
		}
		if(searchV == "Family" || searchV == "Friend" || searchV == "Associate"){
			addrObject.printContactGroup(searchV);
		} else {
			addrObject.nameSearch(searchV);
		}
	}while(searchV != "0");
    return 0;
}
