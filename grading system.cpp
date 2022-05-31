#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int indexmax;

struct studentType {
    
    int index;
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
    
};

void readData (studentType array [20]);
void grade (studentType array [20]);
void highestScore (studentType array [20]);
void print (studentType array [20]);

int main() {
	studentType array [20];
    ifstream infile("StudentsData.txt");
    infile.open("StudentsData.txt");
    
    readData(array);
    
    
    return 0;
}

void readData (studentType array [20]){
    
    ifstream infile;
    if (infile.is_open())
    {
	while(! infile.eof()){
	
    for (int i = 0; i < 20; i++){
        
        infile >> array[i].index;
        infile >> array[i].studentFName;
        infile >> array[i].studentLName;
        infile >> array[i].testScore;
        infile >> array[i].grade;
	}
	}    
	}
    
    cout<<array[0].index<<" "<<array[0].studentFName<<" "<<array[0].studentLName<<" "<<array[0].testScore<<" "<<array[0].grade;

}

void grade (studentType array [20]){ 
    
    for (int i = 0; i < 20; i++){
    
    if (array[i].testScore >= 80){
        array[i].grade = 'A';
    }
    
    else if (array[i].testScore >= 70){
        array[i].grade = 'B';
    }
    
    else if (array[i].testScore >= 60){
        array[i].grade = 'C';
    }
        
    else if (array[i].testScore >= 50){
        array[i].grade = 'D';
    }
    
    else if (array[i].testScore <= 40){
        array[i].grade = 'F';
    }
    
}
    
}

void highestScore (studentType array [20]){
    indexmax = 0;
    
    for (int i = 1; i < 20; i++){
        if (array[i].testScore >= array[indexmax].testScore){
            indexmax = i;
        }
    }
    
}

void print (studentType array [20]){
    
}
