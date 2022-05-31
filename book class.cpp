#include <iostream>
#include <string>
using namespace std;

class Country {
    
    private: 
    	string name, capital;
    	float longitude, latitude;
    	int population;
		  
    public:
        void AskInput();
        void DisplayAllInfo();
        void SetName();
        void SetLongitude();
        void SetLatitude();
        void SetPopulation();
        void SetCapital();
        void DisplayName();
        void DisplayLongitude();
        void DisplayLatitude();
        void DisplayPopulation();
        void DisplayCapital();
};

void DisplayMenu();
void SwitchConditions(Country c);

int main() {
    Country c1, c2, c3;
    
	string Name, Capital;
    float Longitude, Latitude;
	int Population, Code, Ans;
	char Ansr;
    
    cout<<"For the First country:"<<endl;
    c1.AskInput();
    c1.DisplayAllInfo();
    cout<<"For the Second country:"<<endl;
    c2.AskInput();
    c2.DisplayAllInfo();
    cout<<"For the Third country:"<<endl;
    c3.AskInput();
    c3.DisplayAllInfo();
		
	do {
		cout<<"Do you want to read or write to current info? (Y/N)\n";
		cin>>Ansr;
		if(Ansr == 'Y'||Ansr == 'y'){
			
			cout<<"Enter the countrys' code: "<<endl;
			c1.DisplayName();
    		cout<<"'s code: 1\n";
    		c2.DisplayName();
    		cout<<"'s code: 2\n";
    		c3.DisplayName();
    		cout<<"'s code: 3\n";
    		cin>>Code;
    
			switch (Code) {
    			case 1:
    				SwitchConditions(c1);
    				c1.DisplayAllInfo();
    			break;
    	
    			case 2:
    				SwitchConditions(c2);
    				c2.DisplayAllInfo();
    			break;
    	
    			case 3:
    				SwitchConditions(c3);
    				c3.DisplayAllInfo();
   		 		break;
			}
		}
	} while (Ansr == 'Y'|| Ansr =='y');
	
    return 0;
}


void SwitchConditions(Country c){
	
	string Name, Capital;
    float Longitude, Latitude;
	int Population, Ans;
	
    DisplayMenu();
   	cin>>Ans;
   	switch (Ans){
   		case 1:
   			c.SetName();
   			c.DisplayName();
  		break;

		case 2:
			c.SetLongitude();
			c.DisplayLongitude();
		break;
				
		case 3:
			c.SetLatitude();
			c.DisplayLatitude();
		break;
				
		case 4:
			c.SetPopulation();
			c.DisplayPopulation();
		break;
				
		case 5:			
			c.SetCapital();
			c.DisplayCapital();
		break;
				
		case 6:
   			c.DisplayName();
    	break;
    			
		case 7:
			c.DisplayLongitude();
		break;
				
		case 8:
			c.DisplayLatitude();
		break;
				
		case 9:
			c.DisplayPopulation();
		break;
				
		case 10:
			c.DisplayCapital();
		break;	
	}		
}

void DisplayMenu(){
	cout<<"\nEnter the number for the coresponding action: "<<endl;
	cout<<"Change country Name: 1\n";
	cout<<"Change country Longitude: 2\n";
	cout<<"Change country Latitude: 3\n";
	cout<<"Change country Population: 4\n";
	cout<<"Change country Capital: 5\n";
	cout<<"Show country Name: 6\n";
	cout<<"Show country Longitude: 7\n";
	cout<<"Show country Latitude: 8\n";
	cout<<"Show country Population: 9\n";
	cout<<"Show country Capital: 10\n\n";
}

void Country :: AskInput(){
    cout<<"Enter the name of the Country: ";
    cin>>name;
    cout<<"Enter the Longitude: ";
    cin>>longitude;
    cout<<"Enter the Latitude: ";
    cin>>latitude;
    cout<<"Enter the Population of the country: ";
    cin>>population;
    cout<<"Enter the Capital of the country: ";
    cin>>capital;
    cout<<endl;
}

void Country :: DisplayAllInfo(){
    cout<<"\nCountry Name: "<<name<<endl;
    cout<<"Country Longitude: "<<longitude<<endl;
	cout<<"Country Latitude: "<<latitude<<endl;
    cout<<"Country Population: "<<population<<endl;
	cout<<"Country Capital: "<<capital<<endl<<endl;
}

void Country :: SetName(){
	cout<<"Enter the name of the Country: ";
    cin>>name;
}

void Country :: SetLongitude(){
	cout<<"Enter the Longitude: ";
    cin>>longitude;
}

void Country :: SetLatitude(){
	cout<<"Enter the Latitude: ";
    cin>>latitude;
}

void Country :: SetPopulation(){
	cout<<"Enter the Population of the country: ";
    cin>>population;
}

void Country :: SetCapital(){
	cout<<"Enter the Capital of the country: ";
    cin>>capital;
}

void Country :: DisplayName(){
	cout<<name;
}

void Country :: DisplayLongitude(){
	cout<<longitude;
}

void Country :: DisplayLatitude(){
	cout<<latitude;
}

void Country :: DisplayPopulation(){
	cout<<population;
}

void Country :: DisplayCapital(){
	cout<<capital;
}
