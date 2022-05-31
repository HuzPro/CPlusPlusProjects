#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){ 
   
    int size = 10;
    string name[size];
    int rollnum[size];
    float marks[size];
    char grade[size];
   
    string line;
    ifstream file3("Read.csv");
    int i=0;
    while (getline(file3, line)){ // read whole line into line
        string rand;
        istringstream iss(line); // string stream
        getline(iss, name[i], ',');
        iss >> rollnum[i];
        getline(iss, rand, ',');
        iss >> marks[i];
        getline(iss, rand, ',');
        iss >> grade[i];    
        i++;
    }

    for(int i=0;i<size;i++)
    cout<<name[i]<<setw(10)<<rollnum[i]<<setw(10)<<marks[i]<<setw(10)<<grade[i]<<endl;

    return 0;
}
