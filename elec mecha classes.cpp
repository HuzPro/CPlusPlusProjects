#include <iostream>
using namespace std;

class Mechatronics;

class Electrical{
	
	friend class Mechatronics;
	
	private:
		string name;
		double marks;
		
	public:
		Electrical();
		Electrical(string name);
		Electrical(double marks);
		Electrical(string name, double marks);
		void set();
		void average(Electrical e2);	
		friend void average(Electrical e1, Electrical e2, Mechatronics m1, Mechatronics m2);
		~Electrical();
	
};

class Mechatronics {
	
	private:
		string name;
		double marks;
		
	public:
		Mechatronics();
		Mechatronics(string name);
		Mechatronics(double marks);
		Mechatronics(string name, double marks);
		void set();
		void average(Mechatronics m2);	
		void average(Electrical e1, Electrical e2, Mechatronics m2);
		friend void average(Electrical e1, Electrical e2, Mechatronics m1, Mechatronics m2);
		~Mechatronics();
	
};

int main(){
	
	Electrical e1, e2;
	Mechatronics m1, m2;
	
	cout<<"Electrical Department"<<endl;
	cout<<"\nStudent 1: "<<endl;
	e1.set();
	cout<<"\nStudent 2: "<<endl;
	e2.set();
	cout<<endl;
	e1.average(e2);
	cout<<"\n___________________________________________"<<endl;
	
	cout<<"\nMechatronics Department"<<endl;
	cout<<"\nStudent 1: "<<endl;
	m1.set();
	cout<<"\nStudent 2: "<<endl;
	m2.set();
	cout<<endl;
	m1.average(m2);
	cout<<"\n___________________________________________"<<endl;
	
	cout<<endl;
	m1.average(e1, e2, m2);
	
	cout<<endl;
	average(e1, e2, m1, m2);
	cout<<endl;
	
	return 0;
}

Electrical :: Electrical(){
	name = " ";
	marks = 0;
	
}

Electrical :: Electrical(string name){
	
}

Electrical :: Electrical(double marks){
	
}

void Electrical :: set(){
	
	cout<<"\nEnter your name: ";
	cin>>name;
	
	cout<<"Enter your marks: ";
	cin>>marks;
	
}

void Electrical :: average(Electrical e2){
	double average;
	
	average = (marks + e2.marks)/2;
	cout<<"Average for Electrical Department: "<<average;
}	


Mechatronics :: Mechatronics(){
	name = " ";
	marks = 0;
	
}

Mechatronics :: Mechatronics(string name){
	
	
}

Mechatronics :: Mechatronics(double marks){
	
	
}

void Mechatronics :: set(){
	
	cout<<"\nEnter your name: ";
	cin>>name;
	
	cout<<"Enter your marks: ";
	cin>>marks;
}
		
void Mechatronics :: average(Mechatronics m2){
	double average;
	
	average = (marks + m2.marks)/2;
	cout<<"Average marks for Electrical Department: "<<average;
	
}

void Mechatronics :: average(Electrical e1, Electrical e2, Mechatronics m2){
	double average;
	
	average = (e1.marks + e2.marks + marks + m2.marks)/4;
	
	cout<<"Average marks for University (using class Mechatronics): "<<average;
	
}

void average(Electrical e1, Electrical e2, Mechatronics m1, Mechatronics m2){
	double average;
	
	average = (e1.marks + e2.marks +m1.marks + m2.marks)/4;
	
	cout<<"Average marks for University (using friend function): "<<average;
	
}

Electrical :: ~Electrical(){
	
}

Mechatronics :: ~Mechatronics(){
	
}
