#include <iostream>
#include <math.h>
using namespace std;

class DB;

class DM{
    private:
        double m, cm;
        
    public:
        void setDistance();
        friend void add(DM dm, DB db);
    
};

class DB{
    private:
        int feet, inch;
        
    public:
        void setDistance();
        friend void add(DM dm, DB db);
    
};

int main() {
    
    DM dm;
    DB db;
    
    dm.setDistance();
    cout<<endl;
    db.setDistance();
    
    cout<<endl;
    add(dm, db);
    
    
    return 0;
}

void DM :: setDistance(){
    cout<<"You are required to enter distance in metres and centimetres"<<endl;
    do{
    	cout<<"\nEnter number of metres: ";
    	cin>>m;
    } while (fmod(m,1) !=0);
	cout<<"Enter number of centimetres: ";
    cin>>cm;
    
    double tempm;
    m = tempm;
    while (cm >= 100 || tempm > 0){
    	if(cm >=100){
        	cm = cm - 100;
        	m = m + 1;
		}
		if(tempm > 0){
        	tempm = tempm - 1;
        	if (tempm <= 0){
        		m = m - tempm;
        		cm = tempm*100;
			}
		}
    }
    
    
    cout<<"Distance: "<<m<<" metres and "<<cm<<" centimetres"<<endl;
    
}

void DB :: setDistance(){
    cout<<"You are required to enter distance in feet and inches"<<endl;
    cout<<"\nEnter number of feet: ";
    cin>>feet;
    cout<<"Enter number of inches: ";
    cin>>inch;
    
    while (inch >= 12){
        inch = inch - 12;
        feet = feet + 1;
    }
    cout<<"Distance: "<<feet<<" feet and "<<inch<<" inches"<<endl;
}

void add(DM dm, DB db){
    double distancem, distancecm, distancef, distancein, m, cm, feet, inch;
    
    m = db.feet/3.28;
    cm = db.inch*2.54;
    
    while (cm >= 100){
        cm = cm - 1;
        m = m + 1;
    }
    
    feet = dm.m*3.28;
    inch = dm.cm/2.54;
    
    while (inch >= 12){
        inch = inch - 12;
        feet = feet + 1;
    }
    
    distancem = m + dm.m;
    distancecm = cm + dm.cm;
    distancef = feet + db.feet;
    distancein = inch + db.inch;
    
    cout<<"Total distance in metres and centimetres: "<<distancem<<" metres and "<<cm<<" centimetres"<<endl;
}
