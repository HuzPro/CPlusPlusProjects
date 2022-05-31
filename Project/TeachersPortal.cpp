#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class TPortal {
    
    protected:
        int static const size = 100;
        string  MTSA_Name[size], MTSB_Name[size], BEEPA_Name[size], BEBME_Name[size], FileHeader;
        int     MTSA_Roll[size], MTSB_Roll[size], BEEPA_Roll[size], BEBME_Roll[size], sizee[4];
        float   MTSA_LP[size][14], MTSB_LP[size][14], BEEPA_LP[size][14], BEBME_LP[size][14], MTSA_LR[size][14], MTSB_LR[size][14], BEEPA_LR[size][14], BEBME_LR[size][14], 
                MTSA_MMarks[size], MTSB_MMarks[size], BEEPA_MMarks[size], BEBME_MMarks[size], MTSA_FMarks[size], MTSB_FMarks[size], BEEPA_FMarks[size], BEBME_FMarks[size], 
                MTSA_Cea[size], MTSB_Cea[size], BEEPA_Cea[size], BEBME_Cea[size], 
                BEBME_totalLP[size], BEBME_totalLR[size], BEBME_totalMid[size], BEBME_totalFinal[size], BEBME_totalCea[size],
                MTSA_totalLP[size], MTSA_totalLR[size], MTSA_totalMid[size], MTSA_totalFinal[size], MTSA_totalCea[size],
                MTSB_totalLP[size], MTSB_totalLR[size], MTSB_totalMid[size], MTSB_totalFinal[size], MTSB_totalCea[size],
                BEEPA_totalLP[size], BEEPA_totalLR[size], BEEPA_totalMid[size], BEEPA_totalFinal[size], BEEPA_totalCea[size],
                BEBME_total[size], MTSA_total[size], MTSB_total[size], BEEPA_total[size];
        char     BEBME_grade[size], MTSA_grade[size], MTSB_grade[size], BEEPA_grade[size]; 
        float weight_LP, weight_LR, weight_Mid, weight_Final, weight_Cea;			
        
    public:
    	
    	void ReadFileBEBME() {
    		
    		ifstream BEBME_OOP;										//Making the file variable and storing the file in it
    		BEBME_OOP.open("BEBME-OOP-GRADES.csv");
    		
    		string line = "";										//line string to store the line of the file
    		getline(BEBME_OOP, line);								//Storing the first line of the file in the line variable
    		FileHeader = line;
    		line = "";												//The first line of this file has headers, this is to ignore that
    		
    		int i=0;
    		while(getline(BEBME_OOP, line)) {						//Reading the whole line of the file and storing it into variable line. Using that as a condition: "If this keeps happening, run the loop".
    		
    			
    			
    			string tempString = "";
    			stringstream inputString(line);						//converting the line variable into a string variable
    			    			
				//Storing the Roll Numbers
    			getline(inputString, tempString, ',');
    			BEBME_Roll[i] = atoi(tempString.c_str());
				//Storing the Names
    			getline(inputString, BEBME_Name[i], ',');
    			//Storing the 14 different Lab Performance marks into a 2D array
    			for (int j=0; j < 14; j++){						//Looping 14 times for 14 Lab Performance marks
    				getline(inputString, tempString, ',');			//Putting it into a temp string variable
    				BEBME_LP[i][j] = atoi(tempString.c_str());		//Converting that temp string variable into a integar type and storing it into the 2D array
				}
				//Storing the 14 different Lab Report marks into a 2D array
				for (int k=0; k < 14; k++){						//Looping 14 times for 14 Lab Report Marks
					getline(inputString, tempString,',');			//Putting it into a temp string variable
					BEBME_LR[i][k] = atoi(tempString.c_str());		//Converting that temp string variable into a integar type and storing it into the 2D array
				}
				//Storing the Mid-term Marks
				getline(inputString, tempString, ',');
    			BEBME_MMarks[i] = atoi(tempString.c_str());
				//Storing the Final-term Marks
    			getline(inputString, tempString, ',');
    			BEBME_FMarks[i] = atoi(tempString.c_str());
				//Storing the CEA 
				getline(inputString, tempString, '\n');
    			BEBME_Cea[i] = atoi(tempString.c_str());
    			line = "";
    			i++;
			}
			sizee[0] = 100-i;			BEBME_OOP.close();
    	}
    	
    	void SaveFileBEBME() {
            ofstream BEBME_OOP;
            BEBME_OOP.open("BEBME-OOP-GRADES.csv");
            BEBME_OOP<<FileHeader<<endl;
            for (int i=0; i<size-sizee[0]; i++) {
                BEBME_OOP << BEBME_Roll[i] << ',' << BEBME_Name[i] << ',';
                for (int j=0; j < 14; j++) {
                    BEBME_OOP << BEBME_LP[i][j] << ',';
                }
                for (int k=0; k < 14; k++) {
                    BEBME_OOP << BEBME_LR[i][k] << ',';
                }
                BEBME_OOP << BEBME_MMarks[i] << ',' << BEBME_FMarks[i] << ',' << BEBME_Cea[i] << BEBME_grade[i]<<endl;
            }
        }
    	
    	void ReadFileBEEPA() {
    		
    		ifstream BEEPA_OOP("POWER-CP.csv");				//Making the file variable and storing the file in it
    		
    		string line = "";										//line string to store the line of the file
    		getline(BEEPA_OOP, line);								//Storing the first line of the file in the line variable
    		line = "";												//The first line of this file has headers, this is to ignore that
    		
    		int i=0;
    		while(getline(BEEPA_OOP, line)) {
    			
    			string tempString = "";
    			stringstream inputString(line);						//converting the line variable into a string variable
    			    			
				//Storing the Roll Numbers
    			getline(inputString, tempString, ',');
    			BEEPA_Roll[i] = atoi(tempString.c_str());
				//Storing the Names
    			getline(inputString, BEEPA_Name[i], ',');
    			//Storing the 14 different Lab Performance marks into a 2D array
    			for (int j=0; j < 14; j++){						//Looping 14 times for 14 Lab Performance marks
    				getline(inputString, tempString, ',');			//Putting it into a temp string variable
    				BEEPA_LP[i][j] = atoi(tempString.c_str());		//Converting that temp string variable into a integar type and storing it into the 2D array
				}
				//Storing the 14 different Lab Report marks into a 2D array
				for (int k=0; k < 14; k++){						//Looping 14 times for 14 Lab Report Marks
					getline(inputString, tempString,',');			//Putting it into a temp string variable
					BEEPA_LR[i][k] = atoi(tempString.c_str());		//Converting that temp string variable into a integar type and storing it into the 2D array
				}
				//Storing the Mid-term Marks
				getline(inputString, tempString, ',');
    			BEEPA_MMarks[i] = atoi(tempString.c_str());
				//Storing the Final-term Marks
    			getline(inputString, tempString, ',');
    			BEEPA_FMarks[i] = atoi(tempString.c_str());
				//Storing the CEA 
				getline(inputString, tempString, '\n');
    			BEEPA_Cea[i] = atoi(tempString.c_str());
    			line = "";
    			i++;
			}
			sizee[1] = 100-i;
			BEEPA_OOP.close();
    	}
    	
    	void SaveFileBEEPA() {
    		ofstream BEEPA_OOP;
    		BEEPA_OOP.open("POWER-CP.csv");
    		BEEPA_OOP << FileHeader<<endl;
    		for (int i=0; i<size-sizee[1]; i++) {
    			BEEPA_OOP << BEEPA_Roll[i] << ',' << BEEPA_Name[i] << ',';
    			for (int j=0; j < 14; j++) {
    				BEEPA_OOP << BEEPA_LP[i][j] << ',';
				}
				for (int k=0; k < 14; k++) {
					BEEPA_OOP << BEEPA_LR[i][k] << ',';
				}
				BEEPA_OOP << BEEPA_MMarks[i] << ',' << BEEPA_FMarks[i] << ',' << BEEPA_Cea[i] << BEEPA_grade[i]<< endl;
			}
		}
    	
    	void ReadFileMTSA() {
    		
    		ifstream MTSA_OOP("MTSA-CP-GRADES.csv");				//Making the file variable and storing the file in it
    		
    		string line = "";										//line string to store the line of the file
    		getline(MTSA_OOP, line);								//Storing the first line of the file in the line variable
    		line = "";												//The first line of this file has headers, this is to ignore that
    		
    		int i=0;
    		while(getline(MTSA_OOP, line)) {
			
			    			
    			string tempString = "";
    			stringstream inputString(line);						//converting the line variable into a string variable
    			    			
				//Storing the Roll Numbers
    			getline(inputString, tempString, ',');
    			MTSA_Roll[i] = atoi(tempString.c_str());
				//Storing the Names
    			getline(inputString, MTSA_Name[i], ',');
    			//Storing the 14 different Lab Performance marks into a 2D array
    			for (int j=0; j < 14; j++){						//Looping 14 times for 14 Lab Performance marks
    				getline(inputString, tempString, ',');			//Putting it into a temp string variable
    				MTSA_LP[i][j] = atoi(tempString.c_str());		//Converting that temp string variable into a integar type and storing it into the 2D array
				}
				//Storing the 14 different Lab Report marks into a 2D array
				for (int k=0; k < 14; k++){						//Looping 14 times for 14 Lab Report Marks
					getline(inputString, tempString,',');			//Putting it into a temp string variable
					MTSA_LR[i][k] = atoi(tempString.c_str());		//Converting that temp string variable into a integar type and storing it into the 2D array
				}
				//Storing the Mid-term Marks
				getline(inputString, tempString, ',');
    			MTSA_MMarks[i] = atoi(tempString.c_str());
				//Storing the Final-term Marks
    			getline(inputString, tempString, ',');
    			MTSA_FMarks[i] = atoi(tempString.c_str());
				//Storing the CEA 
				getline(inputString, tempString, '\n');
    			MTSA_Cea[i] = atoi(tempString.c_str());
    			line = "";
    			i++;
			}
			sizee[2] = 100-i;
			MTSA_OOP.close();
    	}
    	
    	void SaveFileMTSA() {
    		ofstream MTSA_OOP;
    		MTSA_OOP.open("MTSA-CP-GRADES.csv");
    		MTSA_OOP << FileHeader<<endl;
    		for (int i=0; i<size-sizee[2]; i++) {
    			MTSA_OOP << MTSA_Roll[i] << ',' << MTSA_Name[i] << ',';
    			for (int j=0; j < 14; j++) {
    				MTSA_OOP << MTSA_LP[i][j] << ',';
				}
				for (int k=0; k < 14; k++) {
					MTSA_OOP << MTSA_LR[i][k] << ',';
				}
				MTSA_OOP << MTSA_MMarks[i] << ',' << MTSA_FMarks[i] << ',' << MTSA_Cea[i] << MTSA_grade[i] << endl;
			}
		}
    	
    	void ReadFileMTSB() {
    		
    		ifstream MTSB_OOP("MTSB-CP-GRADES.csv");				//Making the file variable and storing the file in it
    		
    		string line = "";										//line string to store the line of the file
    		getline(MTSB_OOP, line);								//Storing the first line of the file in the line variable
    		line = "";												//The first line of this file has headers, this is to ignore that
    		
    		int i=0;
    		while(getline(MTSB_OOP, line)) {
    		
    		
    			
    			string tempString = "";
    			stringstream inputString(line);						//converting the line variable into a string variable
    			    			
				//Storing the Roll Numbers
    			getline(inputString, tempString, ',');
    			MTSB_Roll[i] = atoi(tempString.c_str());
				//Storing the Names
    			getline(inputString, MTSB_Name[i], ',');
    			//Storing the 14 different Lab Performance marks into a 2D array
    			for (int j=0; j < 14; j++){						//Looping 14 times for 14 Lab Performance marks
    				getline(inputString, tempString, ',');			//Putting it into a temp string variable
    				MTSB_LP[i][j] = atoi(tempString.c_str());		//Converting that temp string variable into a integar type and storing it into the 2D array
				}
				//Storing the 14 different Lab Report marks into a 2D array
				for (int k=0; k < 14; k++){						//Looping 14 times for 14 Lab Report Marks
					getline(inputString, tempString,',');			//Putting it into a temp string variable
					MTSB_LR[i][k] = atoi(tempString.c_str());		//Converting that temp string variable into a integar type and storing it into the 2D array
				}
				//Storing the Mid-term Marks
				getline(inputString, tempString, ',');
    			MTSB_MMarks[i] = atoi(tempString.c_str());
				//Storing the Final-term Marks
    			getline(inputString, tempString, ',');
    			MTSB_FMarks[i] = atoi(tempString.c_str());
				//Storing the CEA 
				getline(inputString, tempString, '\n');
    			MTSB_Cea[i] = atoi(tempString.c_str());
    			line = "";
    			i++;
			}
			sizee[3] = 100-i;
			MTSB_OOP.close();
    	}
    	
    	void SaveFileMTSB() {
    		ofstream MTSB_OOP;
    		MTSB_OOP.open("MTSB-CP-GRADES.csv");
    		MTSB_OOP << FileHeader<<endl;
    		for (int i=0; i<size-sizee[3]; i++) {
    			MTSB_OOP << MTSB_Roll[i] << ',' << MTSB_Name[i] << ',';
    			for (int j=0; j < 14; j++) {
    				MTSB_OOP << MTSB_LP[i][j] << ',';
				}
				for (int k=0; k < 14; k++) {
					MTSB_OOP << MTSB_LR[i][k] << ',';
				}
				MTSB_OOP << MTSB_MMarks[i] << ',' << MTSB_FMarks[i] << ',' << MTSB_Cea[i] << MTSB_grade[i] << endl;
			}
		}
    	
    	void DisplayStudentInfo(int roll) {
    		for (int i=0; i < size; i++) {
    			if (roll == BEBME_Roll[i]) {
	    			cout<<"Roll Number: "<<BEBME_Roll[i]<<endl;
	    			cout<<"Name: "<<BEBME_Name[i]<<endl;
	    			cout<<"Lab Performance marks: ";
	    			for (int j=0; j < 14; j++) {
	    				cout<<BEBME_LP[i][j]<<", ";
					}
					cout<<"\nLab Report marks: ";
					for (int k=0; k < 14; k++) {
						cout<<BEBME_LR[i][k]<<", ";
					}
					cout<<"\nMid-Term marks: "<<BEBME_MMarks[i]<<endl;
	    			cout<<"Final-Term marks: "<<BEBME_FMarks[i]<<endl;
	    			cout<<"CEA Marks: "<<BEBME_Cea[i]<<endl;
	    			cout<<"\n-----------------------------------------------------------------------\n";
				}
				if (roll == BEEPA_Roll[i]) {
	    			cout<<"Roll Number: "<<BEEPA_Roll[i]<<endl;
	    			cout<<"Name: "<<BEEPA_Name[i]<<endl;
	    			cout<<"Lab Performance marks: ";
	    			for (int j=0; j < 14; j++) {
	    				cout<<BEEPA_LP[i][j]<<", ";
					}
					cout<<"\nLab Report marks: ";
					for (int k=0; k < 14; k++) {
						cout<<BEEPA_LR[i][k]<<", ";
					}
					cout<<"\nMid-Term marks: "<<BEEPA_MMarks[i]<<endl;
	    			cout<<"Final-Term marks: "<<BEEPA_FMarks[i]<<endl;
	    			cout<<"CEA Marks: "<<BEEPA_Cea[i]<<endl;
	    			cout<<"\n-----------------------------------------------------------------------\n";
				}
				if (roll == MTSA_Roll[i]) {
	    			cout<<"Roll Number: "<<MTSA_Roll[i]<<endl;
	    			cout<<"Name: "<<MTSA_Name[i]<<endl;
	    			cout<<"Lab Performance marks: ";
	    			for (int j=0; j < 14; j++) {
	    				cout<<MTSA_LP[i][j]<<", ";
					}
					cout<<"\nLab Report marks: ";
					for (int k=0; k < 14; k++) {
						cout<<MTSA_LR[i][k]<<", ";
					}
					cout<<"\nMid-Term marks: "<<MTSA_MMarks[i]<<endl;
	    			cout<<"Final-Term marks: "<<MTSA_FMarks[i]<<endl;
	    			cout<<"CEA Marks: "<<MTSA_Cea[i]<<endl;
	    			cout<<"\n-----------------------------------------------------------------------\n";
				}
				if (roll == MTSB_Roll[i]) {
	    			cout<<"Roll Number: "<<MTSB_Roll[i]<<endl;
	    			cout<<"Name: "<<MTSB_Name[i]<<endl;
	    			cout<<"Lab Performance marks: ";
	    			for (int j=0; j < 14; j++) {
	    				cout<<MTSB_LP[i][j]<<", ";
					}
					cout<<"\nLab Report marks: ";
					for (int k=0; k < 14; k++) {
						cout<<MTSB_LR[i][k]<<", ";
					}
					cout<<"\nMid-Term marks: "<<MTSB_MMarks[i]<<endl;
	    			cout<<"Final-Term marks: "<<MTSB_FMarks[i]<<endl;
	    			cout<<"CEA Marks: "<<MTSB_Cea[i]<<endl;
	    			cout<<"\n-----------------------------------------------------------------------\n";
				}
			}
		}
		
		
		void LabMarksDisplay(int roll, string whichMarks) {
			cout<<"\n-----------------------------------------------------------------------"<<endl;
			for (int i=0; i<14; i++){
				if(whichMarks == "BEBME_LP"){
					cout<<"Lab "<<i + 1<<":\t"<<BEBME_LP[roll][i]<<endl;
				} else if(whichMarks == "MTSA_LP"){
					cout<<"Lab "<<i + 1<<":\t"<<MTSA_LP[roll][i]<<endl;
				} else if(whichMarks == "MTSB_LP"){
					cout<<"Lab "<<i + 1<<":\t"<<MTSB_LP[roll][i]<<endl;
				} else if(whichMarks == "BEEPA_LP"){
					cout<<"Lab "<<i + 1<<":\t"<<BEEPA_LP[roll][i]<<endl;
				} else if(whichMarks == "BEBME_LR"){
					cout<<"Lab "<<i + 1<<":\t"<<BEBME_LR[roll][i]<<endl;
				} else if(whichMarks == "MTSA_LR"){
					cout<<"Lab "<<i + 1<<":\t"<<MTSA_LR[roll][i]<<endl;
				} else if(whichMarks == "MTSB_LR"){
					cout<<"Lab "<<i + 1<<":\t"<<MTSB_LR[roll][i]<<endl;
				} else if(whichMarks == "BEEPA_LR"){
					cout<<"Lab "<<i + 1<<":\t"<<BEEPA_LR[roll][i]<<endl;
				} 
			}
			cout<<"-----------------------------------------------------------------------"<<endl;
		}
		
		void MarksDisplay(int roll, string whichMarks){
			if(whichMarks == "BEBME_MMarks"){
				cout<<"Midterm marks: "<<BEBME_MMarks[roll]<<endl;
			} else if(whichMarks == "MTSA_MMarks"){
				cout<<"Midterm marks: "<<MTSA_MMarks[roll]<<endl;
			} else if(whichMarks == "MTSB_MMarks"){
				cout<<"Midterm marks: "<<MTSB_MMarks[roll]<<endl;
			} else if(whichMarks == "BEEPA_MMarks"){
				cout<<"Midterm marks: "<<BEEPA_MMarks[roll]<<endl;
			} else if(whichMarks == "BEBME_FMarks"){
				cout<<"Final marks: "<<BEBME_FMarks[roll]<<endl;
			} else if(whichMarks == "MTSA_FMarks"){
				cout<<"Final marks: "<<MTSA_FMarks[roll]<<endl;
			} else if(whichMarks == "MTSB_FMarks"){
				cout<<"Final marks: "<<MTSB_FMarks[roll]<<endl;
			} else if(whichMarks == "BEEPA_FMarks"){
				cout<<"Final marks: "<<BEEPA_FMarks[roll]<<endl;
			} else if(whichMarks == "BEBME_Cea"){
				cout<<"CEAwhat marks: "<<BEBME_Cea[roll]<<endl;
			} else if(whichMarks == "MTSA_Cea"){
				cout<<"Final marks: "<<MTSA_Cea[roll]<<endl;
			} else if(whichMarks == "MTSB_Cea"){
				cout<<"Final marks: "<<MTSB_Cea[roll]<<endl;
			} else if(whichMarks == "BEEPA_Cea"){
				cout<<"Final marks: "<<BEEPA_Cea[roll]<<endl;
			}
		}
		
    	
    	void EditMarks(TPortal t, int opt) {
    		int roll, markSelect, rolltemp;
    		float tempMarks;
    		char markTypeSelect;
			cout<<"Please Enter Roll Number Of The Student: ";
    		cin>>roll;
    		cout<<"\n-----------------------------------------------------------------------\n";
			switch (opt){
				case 1://BEBME
					for(int i=0; i<size-sizee[0]; i++){
						if(BEBME_Roll[i] == roll){
							rolltemp = i;
							t.DisplayStudentInfo(roll);
							cout<<"Marks:\nA---------------Lab Performance\nB---------------Lab Report\nC---------------Mid terms\nD---------------Final terms\nE---------------CEA";
							cout<<"\nEnter which marks you want to edit: ";
							cin>>markTypeSelect;
							switch (markTypeSelect){
								case 'A':
									t.LabMarksDisplay(rolltemp, "BEBME_LP");
									cout<<"\nInput the number corresponding to the marks displayed: ";
									cin>>markSelect;
									markSelect = markSelect - 1;
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.BEBME_LP[i][markSelect] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.LabMarksDisplay(rolltemp, "BEBME_LP");
									t.SaveFileBEBME(t);
								break;
								
								case 'B':
									t.LabMarksDisplay(rolltemp, "BEBME_LR");
									cout<<"\nInput the number corresponding to the marks displayed: ";
									cin>>markSelect;
									markSelect = markSelect - 1;
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.BEBME_LR[i][markSelect] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.LabMarksDisplay(rolltemp, "BEBME_LR");
									t.SaveFileBEBME(t);
								break;
								
								case 'C':
									t.MarksDisplay(rolltemp, "BEBME_MMarks");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.BEBME_MMarks[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "BEBME_MMarks");
									t.SaveFileBEBME(t);
								break;
								
								case 'D':
									t.MarksDisplay(rolltemp, "BEBME_FMarks");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.BEBME_FMarks[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "BEBME_FMarks");
									t.SaveFileBEBME(t);
								break;
									
								case 'E':
									t.MarksDisplay(rolltemp, "BEBME_Cea");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.BEBME_Cea[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "BEBME_Cea");
									t.SaveFileBEBME(t);
								break;
							}
						}
					}
				break;
				
				case 2://MTSA
					for(int i=0; i<sizee[2]; i++){
						if(MTSA_Roll[i] == roll){
							cout<<"It does go here (if condition roll = roll).\n";
							rolltemp = i;
							t.DisplayStudentInfo(roll);
							cout<<"Marks:\nA---------------Lab Performance\nB---------------Lab Report\nC---------------Mid terms\nD---------------Final terms\nE---------------CEA";
							cout<<"\nEnter which marks you want to edit: ";
							cin>>markTypeSelect;
							switch (markTypeSelect){
								case 'A':
									t.LabMarksDisplay(rolltemp, "MTSA_LP");
									cout<<"\nInput the number corresponding to the marks displayed: ";
									cin>>markSelect;
									markSelect = markSelect - 1;
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.MTSA_LP[i][markSelect] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.LabMarksDisplay(rolltemp, "MTSA_LP");
									t.SaveFileMTSA();
								break;
								
								case 'B':
									t.LabMarksDisplay(rolltemp, "MTSA_LR");
									cout<<"\nInput the number corresponding to the marks displayed: ";
									cin>>markSelect;
									markSelect = markSelect - 1;
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.MTSA_LR[i][markSelect] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.LabMarksDisplay(rolltemp, "MTSA_LR");
									t.SaveFileMTSA();
								break;
								
								case 'C':
									t.MarksDisplay(rolltemp, "MTSA_MMarks");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.MTSA_MMarks[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "MTSA_MMarks");
									t.SaveFileMTSA();
								break;
								
								case 'D':
									t.MarksDisplay(rolltemp, "MTSA_FMarks");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.MTSA_FMarks[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "MTSA_FMarks");
									t.SaveFileMTSA();
								break;
									
								case 'E':
									t.MarksDisplay(rolltemp, "MTSA_Cea");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.MTSA_Cea[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "MTSA_Cea");
									t.SaveFileMTSA();
								break;
							}
						}
					}
				break;
				
				case 3://MTSB
					for(int i=0; i<size-sizee[3]; i++){
						if(MTSB_Roll[i] == roll){
							rolltemp = i;
							t.DisplayStudentInfo(roll);
							cout<<"Marks:\nA---------------Lab Performance\nB---------------Lab Report\nC---------------Mid terms\nD---------------Final terms\nE---------------CEA";
							cout<<"\nEnter which marks you want to edit: ";
							cin>>markTypeSelect;
							switch (markTypeSelect){
								case 'A':
									t.LabMarksDisplay(rolltemp, "MTSB_LP");
									cout<<"\nInput the number corresponding to the marks displayed: ";
									cin>>markSelect;
									markSelect = markSelect - 1;
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.MTSB_LP[i][markSelect] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.LabMarksDisplay(rolltemp, "MTSB_LP");
									t.SaveFileMTSB();
								break;
								
								case 'B':
									t.LabMarksDisplay(rolltemp, "MTSB_LR");
									cout<<"\nInput the number corresponding to the marks displayed: ";
									cin>>markSelect;
									markSelect = markSelect - 1;
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.MTSB_LR[i][markSelect] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.LabMarksDisplay(rolltemp, "MTSB_LR");
									t.SaveFileMTSB();
								break;
								
								case 'C':
									t.MarksDisplay(rolltemp, "MTSB_MMarks");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.MTSB_MMarks[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "MTSB_MMarks");
									t.SaveFileMTSB();
								break;
								
								case 'D':
									t.MarksDisplay(rolltemp, "MTSB_FMarks");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.MTSB_FMarks[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "MTSB_FMarks");
									t.SaveFileMTSB();
								break;
									
								case 'E':
									t.MarksDisplay(rolltemp, "MTSB_Cea");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.MTSB_Cea[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "MTSB_Cea");
									t.SaveFileMTSB();
								break;
							}
						}
					}	
				break;
				
				case 4://BEEPA
					for(int i=0; i<size-sizee[1]; i++){
						if(BEEPA_Roll[i] == roll){
							rolltemp = i;
							t.DisplayStudentInfo(roll);
							cout<<"Marks:\nA---------------Lab Performance\nB---------------Lab Report\nC---------------Mid terms\nD---------------Final terms\nE---------------CEA";
							cout<<"\nEnter which marks you want to edit: ";
							cin>>markTypeSelect;
							switch (markTypeSelect){
								case 'A':
									t.LabMarksDisplay(rolltemp, "BEEPA_LP");
									cout<<"\nInput the number corresponding to the marks displayed: ";
									cin>>markSelect;
									markSelect = markSelect - 1;
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.BEEPA_LP[i][markSelect] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.LabMarksDisplay(rolltemp, "BEEPA_LP");
									t.SaveFileBEEPA();
								break;
								
								case 'B':
									t.LabMarksDisplay(rolltemp, "BEEPA_LR");
									cout<<"\nInput the number corresponding to the marks displayed: ";
									cin>>markSelect;
									markSelect = markSelect - 1;
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.BEEPA_LR[i][markSelect] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.LabMarksDisplay(rolltemp, "BEEPA_LR");
									t.SaveFileBEEPA();
								break;
								
								case 'C':
									t.MarksDisplay(rolltemp, "BEEPA_MMarks");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.BEEPA_MMarks[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "BEEPA_MMarks");
									t.SaveFileBEEPA();
								break;
								
								case 'D':
									t.MarksDisplay(rolltemp, "BEEPA_FMarks");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									
									t.BEEPA_FMarks[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "BEEPA_FMarks");
									t.SaveFileBEEPA();
								break;
									
								case 'E':
									t.MarksDisplay(rolltemp, "BEEPA_Cea");
									cout<<"\nPlease enter the marks you'd like to replace the selected marks with: ";
									cin>>tempMarks;
									t.BEEPA_Cea[i] = tempMarks;
									cout<<"\nMarks Updated Successfully!\n";
									t.MarksDisplay(rolltemp, "BEEPA_Cea");
									t.SaveFileBEEPA();
								break;
							}
						}
					}	
				break;
			}
			
		}
		
		void AddStudent(int opt) {
			if (opt == 1) {				//BEBME
				sizee[0] = sizee[0] - 1;
				int i = 0; 
				i = size-sizee[0];
				
				cout<<"Enter Student's Roll Number: ";
				cin>>BEBME_Roll[i];
				cout<<"Enter Student's Name: ";
				cin>>BEBME_Name[i];
				for (int j=0; j<14; j++) {
					cout<<"Enter Student's Lab "<<j+1<<" Lab Performance Marks: ";
					cin>>BEBME_LP[i][j];
				}
				for (int k=0; k<14; k++){
					cout<<"Enter Student's Lab "<<k+1<<" Lab Report Marks: ";
					cin>>BEBME_LR[i][k];
				}
				cout<<"Enter Student's Mid term Marks: ";
				cin>>BEBME_MMarks[i];
				cout<<"Enter Student's Final term Marks: ";
				cin>>BEBME_FMarks[i];
				cout<<"Enter Student's CEA Marks: ";
				cin>>BEBME_Cea[i];
					
				fstream BEBME_OOP;
    			BEBME_OOP.open("BEBME-OOP-GRADES.csv", ios::out | ios::app);
    			BEBME_OOP << BEBME_Roll[i] << ',' << BEBME_Name[i] << ',';
    		for (int j=0; j < 14; j++) {
    			BEBME_OOP << BEBME_LP[i][j] << ',';
			}
			for (int k=0; k < 14; k++) {
				BEBME_OOP << BEBME_LR[i][k] << ',';
			}
			BEBME_OOP << BEBME_MMarks[i] << ',' << BEBME_FMarks[i] << ',' << BEBME_Cea[i] << endl;
				
			} else if (opt == 2) {		//MTSA
				sizee[2] = sizee[2] - 1;
				int l = size-sizee[2];
				
				cout<<"Enter Student's Roll Number: ";
				cin>>MTSA_Roll[l];
				cout<<"Enter Student's Name: ";
				cin>>MTSA_Name[l];
				for (int j=0; j<14; j++) {
					cout<<"Enter Student's Lab "<<j+1<<" Lab Performance Marks: ";
					cin>>MTSA_LP[l][j];
				}
				for (int k=0; k<14; k++){
					cout<<"Enter Student's Lab "<<k+1<<" Lab Report Marks: ";
					cin>>MTSA_LR[l][k];
				}
				cout<<"Enter Student's Mid term Marks: ";
				cin>>MTSA_MMarks[l];
				cout<<"Enter Student's Final term Marks: ";
				cin>>MTSA_FMarks[l];
				cout<<"Enter Student's CEA Marks: ";
				cin>>MTSA_Cea[l];
				
				fstream MTSA_OOP;
    			MTSA_OOP.open("MTSA-CP-GRADES.csv", ios::out | ios::app);
    			MTSA_OOP << MTSA_Roll[l] << ',' << MTSA_Name[l] << ',';
    			for (int j=0; j < 14; j++) {
    			MTSA_OOP << MTSA_LP[l][j] << ',';
				}
				for (int k=0; k < 14; k++) {
				MTSA_OOP << MTSA_LR[l][k] << ',';
				}
				MTSA_OOP << MTSA_MMarks[l] << ',' << MTSA_FMarks[l] << ',' << MTSA_Cea[l] << endl;
				
			} else if (opt == 3) {		//MTSB
				sizee[3] = sizee[3] - 1;
				int m = size - sizee[3];
				
				cout<<"Enter Student's Roll Number: ";
				cin>>MTSB_Roll[m];
				cout<<"Enter Student's Name: ";
				cin>>MTSB_Name[m];
				for (int j=0; j<14; j++) {
					cout<<"Enter Student's Lab "<<j+1<<" Lab Performance Marks: ";
					cin>>MTSB_LP[m][j];
				}
				for (int k=0; k<14; k++){
					cout<<"Enter Student's Lab "<<k+1<<" Lab Report Marks: ";
					cin>>MTSB_LR[m][k];
				}
				cout<<"Enter Student's Mid term Marks: ";
				cin>>MTSB_MMarks[m];
				cout<<"Enter Student's Final term Marks: ";
				cin>>MTSB_FMarks[m];
				cout<<"Enter Student's CEA Marks: ";
				cin>>MTSB_Cea[m];
				
				fstream MTSB_OOP;
    			MTSB_OOP.open("MTSB-CP-GRADES.csv", ios::out | ios::app);
    			MTSB_OOP << MTSB_Roll[m] << ',' << MTSB_Name[m] << ',';
    			for (int j=0; j < 14; j++) {
    			MTSB_OOP << MTSB_LP[m][j] << ',';
				}
				for (int k=0; k < 14; k++) {
				MTSB_OOP << MTSB_LR[m][k] << ',';
				}
				MTSB_OOP << MTSB_MMarks[m] << ',' << MTSB_FMarks[m] << ',' << MTSB_Cea[m] << endl;
				
			} else if (opt == 4) {		//BEEPA
				sizee[1] = sizee[1] - 1;
				int n = size - sizee[1];
				
				cout<<"Enter Student's Roll Number: ";
				cin>>BEEPA_Roll[n];
				cout<<"Enter Student's Name: ";
				cin>>BEEPA_Name[n];
				for (int j=0; j<14; j++) {
					cout<<"Enter Student's Lab "<<j+1<<" Lab Performance Marks: ";
					cin>>BEEPA_LP[n][j];
				}
				for (int k=0; k<14; k++){
					cout<<"Enter Student's Lab "<<k+1<<" Lab Report Marks: ";
					cin>>BEEPA_LR[n][k];
				}
				cout<<"Enter Student's Mid term Marks: ";
				cin>>BEEPA_MMarks[n];
				cout<<"Enter Student's Final term Marks: ";
				cin>>BEEPA_FMarks[n];
				cout<<"Enter Student's CEA Marks: ";
				cin>>BEEPA_Cea[n];
				
				fstream BEEPA_OOP;
    			BEEPA_OOP.open("POWER-CP.csv", ios::out | ios::app);
    			BEEPA_OOP << BEEPA_Roll[n] << ',' << BEEPA_Name[n] << ',';
    			for (int j=0; j < 14; j++) {
    			BEEPA_OOP << BEEPA_LP[n][j] << ',';
				}
				for (int k=0; k < 14; k++) {
				BEEPA_OOP << BEEPA_LR[n][k] << ',';
				}
				BEEPA_OOP << BEEPA_MMarks[n] << ',' << BEEPA_FMarks[n] << ',' << BEEPA_Cea[n] << endl;
			}
		}
		
		void totalMarks(int opt){
			float sum = 0;
			if (opt == 1){  //BEBME
				for (int i = 0; i < size - sizee[0]; i++){
					for (int j = 0; j < 14; j++){
						sum = sum + BEBME_LP[i][j];
					}
					BEBME_totalLP[i] = sum/210/100*weight_LP;
					sum = 0;
				}
				for (int i = 0; i < size - sizee[0]; i++){
					for (int j = 0; j < 14; j++){
						sum = sum + BEBME_LR[i][j];
					}
					BEBME_totalLR[i] = (sum/210)*weight_LR;
					sum = 0;
				}
				for (int i = 0; i < size - sizee[0]; i++){
				BEBME_totalMid[i] = BEBME_MMarks[i]/40*weight_Mid;
				}
				for (int i = 0; i < size - sizee[0]; i++){
				BEBME_totalFinal[i] = BEBME_FMarks[i]/50*weight_Final;
				}
				for (int i = 0; i < size - sizee[0]; i++){
				BEBME_totalCea[i] = BEBME_Cea[i]/20*weight_Cea;
				}
			}
			if (opt == 2){  //MTSA
				for (int i = 0; i < size - sizee[0]; i++){
					for (int j = 0; j < 14; j++){
						sum = sum + MTSA_LP[i][j];
					}
					MTSA_totalLP[i] = sum/210*weight_LP;
					sum = 0;
				}
				for (int i = 0; i < size - sizee[2]; i++){
					for (int j = 0; j < 14; j++){
						sum = sum + MTSA_LR[i][j];
					}
					MTSA_totalLR[i] = (sum/210)*weight_LR;
					sum = 0;
				}
				for (int i = 0; i < size - sizee[2]; i++){
				MTSA_totalMid[i] = MTSA_MMarks[i]/40*weight_Mid;
				}
				for (int i = 0; i < size - sizee[2]; i++){
				MTSA_totalFinal[i] = MTSA_FMarks[i]/50*weight_Final;
				}
				for (int i = 0; i < size - sizee[2]; i++){
				MTSA_totalCea[i] = MTSA_Cea[i]/20*weight_Cea;
				}
			}
			if (opt == 3){  //MTSB
				for (int i = 0; i < size - sizee[3]; i++){
					for (int j = 0; j < 14; j++){
						sum = sum + MTSB_LP[i][j];
					}
					MTSB_totalLP[i] = (sum/210)*weight_LP;
					sum = 0;
				}
				for (int i = 0; i < size - sizee[3]; i++){
					for (int j = 0; j < 14; j++){
					}
					MTSB_totalLR[i] = (sum/210)*weight_LR;
					sum = 0;
				}
				for (int i = 0; i < size - sizee[3]; i++){
				MTSB_totalMid[i] = MTSB_MMarks[i]/40*weight_Mid;
				}
				for (int i = 0; i < size - sizee[3]; i++){
				MTSB_totalFinal[i] = MTSB_FMarks[i]/50*weight_Final;
				}
				for (int i = 0; i < size - sizee[3]; i++){
				MTSB_totalCea[i] = MTSB_Cea[i]/20*weight_Cea;
				}
			}
			if (opt == 4){  //BEEPA
				for (int i = 0; i < size - sizee[1]; i++){
					for (int j = 0; j < 14; j++){
						sum = sum + BEEPA_LP[i][j];
					}
					BEEPA_totalLP[i] = (sum/210)*weight_LP;
					sum = 0;
				}
				for (int i = 0; i < size - sizee[1]; i++){
					for (int j = 0; j < 14; j++){
						sum = sum + BEEPA_LR[i][j];
					}
					BEEPA_totalLR[i] = (sum/210)*weight_LR;
					sum = 0;
				}
				for (int i = 0; i < size - sizee[1]; i++){
					BEEPA_totalMid[i] = BEEPA_MMarks[i]/40*weight_Mid;
				}
				for (int i = 0; i < size - sizee[1]; i++){
					BEEPA_totalFinal[i] = BEEPA_FMarks[i]/50*weight_Final;
				}
				for (int i = 0; i < size - sizee[1]; i++){
					BEEPA_totalCea[i] = BEEPA_Cea[i]/20*weight_Cea;
				}
			}
		}
		
		
		void generateGrades(int opt) {
			if (opt == 1){
				for (int i = 0; i < size - sizee[0]; i++){
					BEBME_total[i] = BEBME_totalLP[i] + BEBME_totalLR[i] + BEBME_totalMid[i] + BEBME_totalFinal[i] + BEBME_totalCea[i];
				if (BEBME_total[i] >= 80){
					BEBME_grade[i] = 'A';
				}
				else if (BEBME_total[i] >= 70){
					BEBME_grade[i] = 'B';
				}
				else if (BEBME_total[i] >= 60){
					BEBME_grade[i] = 'C';
				}
				else if (BEBME_total[i] >= 50){
					BEBME_grade[i] = 'D';
				}
				else if (BEBME_total[i] >= 40){
					BEBME_grade[i] = 'E';
				}
				else if (BEBME_total[i] < 40){
					BEBME_grade[i] = 'F';
				}
			}
		}	
			if (opt == 2){
				for (int i = 0; i < size - sizee[2]; i++){
					MTSA_total[i] = MTSA_totalLP[i] + MTSA_totalLR[i] + MTSA_totalMid[i] + MTSA_totalFinal[i] + MTSA_totalCea[i];
				if (MTSA_total[i] >= 80){
					MTSA_grade[i] = 'A';
				}
				else if (MTSA_total[i] >= 70){
					MTSA_grade[i] = 'B';
				}
				else if (MTSA_total[i] >= 60){
					MTSA_grade[i] = 'C';
				}
				else if (MTSA_total[i] >= 50){
					MTSA_grade[i] = 'D';
				}
				else if (MTSA_total[i] >= 40){
					MTSA_grade[i] = 'E';
				}
				else if (MTSA_total[i] < 40){
					MTSA_grade[i] = 'F';
				}	
			}
		}
			if (opt == 3){
				for (int i = 0; i < size - sizee[3]; i++){
					MTSB_total[i] = MTSB_totalLP[i] + MTSB_totalLR[i] + MTSB_totalMid[i] + MTSB_totalFinal[i] + MTSB_totalCea[i];
					if (MTSB_total[i] >= 80){
						MTSB_grade[i] = 'A';
					}
					else if (MTSB_total[i] >= 70){
						MTSB_grade[i] = 'B';
					}
					else if (MTSB_total[i] >= 60){
						MTSB_grade[i] = 'C';
					}
					else if (MTSB_total[i] >= 50){
						MTSB_grade[i] = 'D';
					}
					else if (MTSB_total[i] >= 40){
						MTSB_grade[i] = 'E';
					}
					else if (MTSB_total[i] < 40){
						MTSB_grade[i] = 'F';
					}
				}
			}
			if (opt == 4){
				for (int i = 0; i < size - sizee[1]; i++){
					BEEPA_total[i] = BEEPA_totalLP[i] + BEEPA_totalLR[i] + BEEPA_totalMid[i] + BEEPA_totalFinal[i] + BEEPA_totalCea[i];
				
				if (BEEPA_total[i] >= 80){
					BEEPA_grade[i] = 'A';
				}
				else if (BEEPA_total[i] >= 70){
					BEEPA_grade[i] = 'B';
				}
				else if (BEEPA_total[i] >= 60){
					BEEPA_grade[i] = 'C';
				}
				else if (BEEPA_total[i] >= 50){
					BEEPA_grade[i] = 'D';
				}
				else if (BEEPA_total[i] >= 40){
					BEEPA_grade[i] = 'E';
				}
				else if (BEEPA_total[i] < 40){
					BEEPA_grade[i] = 'F';
				}
			}
		}
	}
	
		void deleteStudent(int opt) {
    		int delRoll;
    		//BEBME
    		if (opt == 1) {
    			cout<<"Enter roll number to Delete Student: ";
    			cin>>delRoll;
    			fstream BEBME_OOP;
    			BEBME_OOP.open("BEBME-OOP-GRADES.csv", ios::out|ios::trunc);
    			BEBME_OOP<<FileHeader<<endl;
    			for(int i=0; i < size-sizee[0]; i++){
    				if (BEBME_Roll[i] == delRoll) {
    					cout<<"\nStudent Found.\n";
						for(int h=i+1; h < (size-sizee[0]); h++){
    						BEBME_OOP << BEBME_Roll[h] << ',' << BEBME_Name[h] << ',';
    						for (int j=0; j < 14; j++) {
    							BEBME_OOP << BEBME_LP[h][j] << ',';
							}
							for (int k=0; k < 14; k++) {
								BEBME_OOP << BEBME_LR[h][k] << ',';
							}
							BEBME_OOP << BEBME_MMarks[h] << ',' << BEBME_FMarks[h] << ',' << BEBME_Cea[h] << endl;
						}
						i++;
						break;
					}
    				BEBME_OOP << BEBME_Roll[i] << ',' << BEBME_Name[i] << ',';
    				for (int j=0; j < 14; j++) {
    					BEBME_OOP << BEBME_LP[i][j] << ',';
					}
					for (int k=0; k < 14; k++) {
						BEBME_OOP << BEBME_LR[i][k] << ',';
					}
					BEBME_OOP << BEBME_MMarks[i] << ',' << BEBME_FMarks[i] << ',' << BEBME_Cea[i] << endl;
				}
				cout<<"\nStudent Has Been Terminated.\n";
    			
			} else if (opt == 2) {
				
				cout<<"Enter roll number to Delete Student: ";
    			cin>>delRoll;
    			fstream MTSA_OOP;
    			MTSA_OOP.open("MTSA-CP-GRADES.csv", ios::out|ios::trunc);
    			MTSA_OOP<<FileHeader<<endl;
    			for(int i=0; i < size-sizee[2]; i++){
    				if (MTSA_Roll[i] == delRoll) {
    					cout<<"\nStudent Found.\n";
						for(int h=i+1; h < (size-sizee[2]); h++){
    						MTSA_OOP << MTSA_Roll[h] << ',' << MTSA_Name[h] << ',';
    						for (int j=0; j < 14; j++) {
    							MTSA_OOP << MTSA_LP[h][j] << ',';
							}
							for (int k=0; k < 14; k++) {
								MTSA_OOP << MTSA_LR[h][k] << ',';
							}
							MTSA_OOP << MTSA_MMarks[h] << ',' << MTSA_FMarks[h] << ',' << MTSA_Cea[h] << endl;
						}
						i++;
						break;
					}
    				MTSA_OOP << MTSA_Roll[i] << ',' << MTSA_Name[i] << ',';
    				for (int j=0; j < 14; j++) {
    					MTSA_OOP << MTSA_LP[i][j] << ',';
					}
					for (int k=0; k < 14; k++) {
						MTSA_OOP << MTSA_LR[i][k] << ',';
					}
					MTSA_OOP << MTSA_MMarks[i] << ',' << MTSA_FMarks[i] << ',' << MTSA_Cea[i] << endl;
				}
				cout<<"\nStudent Has Been Terminated.\n";
				
			} else if (opt == 3) {
				
				cout<<"Enter roll number to Delete Student: ";
    			cin>>delRoll;
    			fstream MTSB_OOP;
    			MTSB_OOP.open("MTSB-CP-GRADES.csv", ios::out|ios::trunc);
    			MTSB_OOP<<FileHeader<<endl;
    			for(int i=0; i < size-sizee[3]; i++){
    				if (MTSB_Roll[i] == delRoll) {
    					cout<<"\nStudent Found.\n";
						for(int h=i+1; h < (size-sizee[3]); h++){
    						MTSB_OOP << MTSB_Roll[h] << ',' << MTSB_Name[h] << ',';
    						for (int j=0; j < 14; j++) {
    							MTSB_OOP << MTSB_LP[h][j] << ',';
							}
							for (int k=0; k < 14; k++) {
								MTSB_OOP << MTSB_LR[h][k] << ',';
							}
							MTSB_OOP << MTSB_MMarks[h] << ',' << MTSB_FMarks[h] << ',' << MTSB_Cea[h] << endl;
						}
						i++;
						break;
					}
    				MTSB_OOP << MTSB_Roll[i] << ',' << MTSB_Name[i] << ',';
    				for (int j=0; j < 14; j++) {
    					MTSB_OOP << MTSB_LP[i][j] << ',';
					}
					for (int k=0; k < 14; k++) {
						MTSB_OOP << MTSB_LR[i][k] << ',';
					}
					MTSB_OOP << MTSB_MMarks[i] << ',' << MTSB_FMarks[i] << ',' << MTSB_Cea[i] << endl;
				}
				cout<<"\nStudent Has Been Terminated.\n";
				
			} else if (opt == 4) {
				
				cout<<"Enter roll number to Delete Student: ";
    			cin>>delRoll;
    			fstream BEEPA_OOP;
    			BEEPA_OOP.open("POWER-CP.csv", ios::out|ios::trunc);
    			BEEPA_OOP<<FileHeader<<endl;
    			for(int i=0; i < size-sizee[1]; i++){
    				if (BEEPA_Roll[i] == delRoll) {
    					cout<<"\nStudent Found.\n";
						for(int h=i+1; h < (size-sizee[1]); h++){
    						BEEPA_OOP << BEEPA_Roll[h] << ',' << BEEPA_Name[h] << ',';
    						for (int j=0; j < 14; j++) {
    							BEEPA_OOP << BEEPA_LP[h][j] << ',';
							}
							for (int k=0; k < 14; k++) {
								BEEPA_OOP << BEEPA_LR[h][k] << ',';
							}
							BEEPA_OOP << BEEPA_MMarks[h] << ',' << BEEPA_FMarks[h] << ',' << BEEPA_Cea[h] << endl;
						}
						i++;
						break;
					}
    				BEEPA_OOP << BEEPA_Roll[i] << ',' << BEEPA_Name[i] << ',';
    				for (int j=0; j < 14; j++) {
    					BEEPA_OOP << BEEPA_LP[i][j] << ',';
					}
					for (int k=0; k < 14; k++) {
						BEEPA_OOP << BEEPA_LR[i][k] << ',';
					}
					BEEPA_OOP << BEEPA_MMarks[i] << ',' << BEEPA_FMarks[i] << ',' << BEEPA_Cea[i] << endl;
				}
				cout<<"\nStudent Has Been Terminated.\n";
				
			}
    		
		}
		
		void weightage(){
            cout<<"Enter the weightage percentage for Lab Performance: ";
            cin>>weight_LP;
            cout<<"Enter the weightage percentage for Lab Reports: ";
            cin>>weight_LR;
            cout<<"Enter the weightage percentage for Midterm Examination: ";
            cin>>weight_Mid;
            cout<<"Enter the weightage percentage for Final Examination: ";
            cin>>weight_Final;
            cout<<"Enter the weightage percentage for CEA: ";
            cin>>weight_Cea;
        }
		
        void Menu(TPortal t) {
            bool flag=true;
            int classNum;
            int menuOption;
            
            system("Color 0B");
            cout<<"________________________________________________________________________________\n\n:::::::::::::::::::     Welcome to the Teacher's Portal     ::::::::::::::::::::\n\n________________________________________________________________________________";
            while (flag = true) {
                t.ReadFileBEBME();
                t.ReadFileMTSA();
                t.ReadFileMTSB();
                t.ReadFileBEEPA();
                cout<<"\nClasses Available For Accessing:\n________________________________________________________________________________";
                cout<<"\n1. BEBME\n2. MTSA\n3. MTSB\n4. BEEPA\n\nEnter Any Class Number (Press 0 to exit the program): ";
                cin>>classNum;
                if (classNum == 0) exit(0);
                cout<<"________________________________________________________________________________\n1.Add New Student Data\n2.Edit Existing Student Data\n3.Delete The Student.\n4.Generate Total Marks.\n5.Enter Marks Weight.\n6.Generate Student Grades.\n\nChoose An Option(Press 0 to exit the program): ";
                cin>>menuOption;
                if (menuOption == 1){
                    t.AddStudent(classNum);
                } else if (menuOption == 2) {
                    t.EditMarks(t, classNum);
                } else if (menuOption == 3) {
                    t.deleteStudent(classNum);
                } else if (menuOption == 4){
                    t.totalMarks(classNum);
                } else if (menuOption == 5) {
                    t.weightage();
                } else if (menuOption == 6) {
                    t.generateGrades(classNum);
                    t.SaveFileBEBME();
                    t.SaveFileBEEPA();
                    t.SaveFileMTSA();
                    t.SaveFileMTSB();
                } else if (menuOption == 0) {
                    exit(0);
                }
            }
            
        }
};

int main(){
	TPortal T;
	
	T.Menu(T);
	
	return 0;
}
