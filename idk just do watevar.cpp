#include <iostream>
using namespace std;

class Time {
	
	private:
		int Minutes, Hours;
		
	public:
		Time ();
		Time (int, int); 
		void setTime (int, int); 
		void getTime ();
		void printTime();
		void incrementHours (); 
		void incrementMinutes ();
	
};

class Date {
	
	private:
		int month, day, year;
		
	public:
		Date ();
		Date (int, int, int); 
		void setDate (int, int, int); 
		void getDate();
		void printDate();
	
};

class Event {
	
	private:
		string eventName;
		Time eventTime;
		Date eventDate;
		
	public:
		Event ();
		void setEventData(int hours, int minutes, int m, int d, int y, string name);
		void printEventData();
	
};

int main() {
	Event E1, E2;
	
	E1.setEventData(4,41,9,23,2013, "Anniversary");
	E1.printEventData();
	
	E2.setEventData(25,68,1,70,2053,"Birthday");
	E2.printEventData();
	
	return 0;
}

Time :: Time (){
	Hours = 0;
	Minutes = 0;
}

Time :: Time (int h, int m){
	Hours = h;
	Minutes = m;
	Time temp;
	
	if (Hours >= 24){
		while (Hours >= 24){
		temp.Hours = Hours - 24;
		}
		
		Hours = temp.Hours;
	}
	
	if (Minutes >= 60){
		while (Minutes >= 60){
		temp.Minutes = Minutes - 60;
		Hours++;
		}
		
		Minutes = temp.Minutes;
	}
	
} 

void Time :: setTime (int h, int m){
	Hours = h;
	Minutes = m;
	Time temp;
	
	if (Hours >= 24){
		while (Hours >= 24){
			Hours = Hours - 24;
			temp.Hours = Hours;
		}
		Hours = temp.Hours;
	}
	
	if (Minutes >= 60){
		while (Minutes >= 60){
			Minutes = Minutes - 60;
			temp.Minutes = Minutes;
			Hours++;
		}
		
		Minutes = temp.Minutes;
	}
}

void Time :: getTime (){
	cout<<"Enter number of hours: ";
	cin>>Hours;
	
	cout<<"Enter number of minutes: ";
	cin>>Minutes;
	
}

void Time :: printTime(){
	cout<<"Time: "<<Hours<<" hours, "<<Minutes<<" minutes"<<endl;
}

void Time :: incrementHours (){
	Hours++;
	
	Time temp;
	
	if (Hours >= 24){
		while (Hours >= 24){
		temp.Hours = Hours - 24;
		}
		
		Hours = temp.Hours;
	}
	
	if (Minutes >= 60){
		while (Minutes >= 60){
		temp.Minutes = Minutes - 60;
		Hours++;
		}
		
		Minutes = temp.Minutes;
	}
	
} 

void Time :: incrementMinutes (){
	Minutes++;
	
	Time temp;
	
	if (Hours >= 24){
		while (Hours >= 24){
		temp.Hours = Hours - 24;
		}
		
		Hours = temp.Hours;
	}
	
	if (Minutes >= 60){
		while (Minutes >= 60){
		temp.Minutes = Minutes - 60;
		Hours++;
		}
		
		Minutes = temp.Minutes;
	}
	
}


Date :: Date (){
	day = 0;
	month = 0;
	year = 0;
}

Date :: Date (int d, int m, int y){
	day = d;
	month = m;
	year = y;
	
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		if(day < 1 || day > 31){
			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
			exit(0);
		}
	} else 
	if (month == 4 || month == 6 || month == 9 || month == 11){
		if(day < 1 || day > 30){
			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
			exit(0);
		}
	} else
	if (month == 2){
		if (year % 400 == 0) {
      		if(day < 1 || day > 29){
      			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
				exit(0);
			}
   		}
   		else if (year % 100 == 0) {
      		if(day > 0 || day <= 28){
      			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
				exit(0);
			}
   		}
   
   		else if (year % 4 == 0) {
    		if(day > 0 || day <= 29){
    			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
      			exit(0);
			}
   		}
   
   		else {
      		if(day > 0 || day <= 28){
      			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
      			exit(0);
			}
   		}
	}
	
	if (month < 1 || month > 12){
		cout<<"INVALID MONTH"<<endl;
		exit(0);
	}
	
	if (year < 0){
		cout<<"INVALID YEAR"<<endl;
		exit(0);
	}
	
}

void Date :: setDate (int d, int m, int y){
	
	day = d;
	month = m;
	year = y;
	
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		if(day < 1 || day > 31){
			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
			exit(0);
		}
	} else 
	if (month == 4 || month == 6 || month == 9 || month == 11){
		if(day < 1 || day > 30){
			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
			exit(0);
		}
	} else
	if (month == 2){
		if (year % 400 == 0) {
      		if(day < 1 || day > 29){
      			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
				exit(0);
			}
   		}
   		else if (year % 100 == 0) {
      		if(day > 0 || day <= 28){
      			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
				exit(0);
			}
   		}
   
   		else if (year % 4 == 0) {
    		if(day > 0 || day <= 29){
    			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
      			exit(0);
			}
   		}
   
   		else {
      		if(day > 0 || day <= 28){
      			cout<<"INVALID DATE ACCORDING TO THE MONTH"<<endl;
      			exit(0);
			}
   		}
	}
	
	if (month < 1 || month > 12){
		cout<<"INVALID MONTH"<<endl;
		exit(0);
	}
	
	if (year < 0){
		cout<<"INVALID YEAR"<<endl;
		exit(0);
	}
	
}

void Date :: getDate(){
	cout<<"Enter day number: ";
	cin>>day;
	
	cout<<"Enter month number: ";
	cin>>month;
	
	cout<<"Enter year number: ";
	cin>>year;
}

void Date :: printDate(){
	cout<<"Date: "<<day<<"-"<<month<<"-"<<year<<endl;
	
}


Event :: Event (){
}

void Event :: setEventData(int hours, int minutes, int m, int d, int y, string name){

	eventTime.setTime(hours, minutes);
	
	eventDate.setDate(d, m, y);
	
	eventName = name;
}

void Event :: printEventData(){
	cout<<"Event Name: "<<eventName<<endl;
	cout<<"Event Time: ";
	eventTime.printTime();
	cout<<"Event Date: ";
	eventDate.printDate();
	cout<<endl;
}
