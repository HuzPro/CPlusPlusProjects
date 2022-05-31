#include <iostream>
using namespace std;

class TPortal {
    
    protected:
        int size = 5;
        string     MTSA_Name[size], MTSB_Name[size], BEEPA_Name[size], BEBMEA_Name[size];
        int     MTSA_Roll[size], MTSB_Roll[size], BEEPA_Roll[size], BEBMEA_Roll[size];
        float     MTSALP[size], MTSBLP[size], BEEPALP[size], BEBMEALP[size], MTSALR[size], MTSBLR[size], BEEPALR[size], BEBMEALR[size], 
                MTSAM_Marks[size], MTSBM_Marks[size], BEEPAM_Marks[size], BEBMEAM_Marks[size], MTSAF_Marks[size], MTSBF_Marks[size], BEEPAF_Marks[size], BEBMEAF_Marks[size], 
                MTSA_Cea[size], MTSB_Cea[size], BEEPA_Cea[size], BEBMEA_Cea[size]; 
        
    public:
        void Menu:
            
            int option;
            
            cout<<"1. Add classes."<<endl;
            cout<<"2. Enter classes data."<<endl;
            
            if (option == 1){
                cout<<"Enter class name: "
            }
    
};

int main() {
    
    
    
    return 0;
}


/*
Classes: CE-112L MTS II-B, CE-112L MTS II-A, CE-112L BEEP II-A, and CE-115L BEBME II-A
Marks: Lab Performance (LP), Lab Reports (LR), Mid Marks(Mmarks), Final Marks (Fmarks), CEA

Functions:
    Ask user to enter classses
    Choose 1 class:
        Enter name, roll, marks:
            Options to choose which marks to enter 
            Use file handling to enter marks from CSV
    
    Assign weights to each marks type.
    Generate total marks.
    Generate grades.
    Write data on CSV file.
/*
