#include <iostream>
#include <fstream>
using namespace std;

int main() {
    
    string x;
    int rollno[5];

    
    ifstream fin1("Read.txt");
    getline(fin1, x);
    for (int i = 0; i < 5; i++){
        fin1>>rollno[i];
    }
    
    cout<<x<<endl;
    for (int i = 0; i < 5; i++){
        cout<<rollno[i]<<endl;
    }
    
    return 0;
}
