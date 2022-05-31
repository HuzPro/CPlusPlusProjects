#include <iostream>
#include <stdlib.h>
using namespace std;

const char Pcharx = 'X';
const char Pcharo = 'O'; 

void OutPut(char tictac[3][3]);

void TakeInput(int &turn, char tictac[3][3], char Pcharo, char Pcharx, char &position);

void SwitchCoordinates(char &position, char tictac[3][3], char Pcharo, char Pcharx, int &turn);

void WinCondition(char tictac[3][3], char Pcharo, char Pcharx, int &WinCheck);



int main() {
    
    int turnno = 0, turn, WinCheck = 0;
    char position, tictac[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    
    turn = (rand()%2) + 1 ;
    cout<<"After A Coin Flip It Was Decided Player "<<turn<<" Will Play First!\n\n";
    
    	
    do {
    		TakeInput(turn, tictac, Pcharo, Pcharx, position);
    	    SwitchCoordinates(position, tictac, Pcharo, Pcharx, turn);
    	    turnno = turnno + 1;
        	if (turn ==1) {
        		turn++;
			}
			else if (turn == 2) {
				turn--;
			}
    		WinCondition(tictac,Pcharo, Pcharx,WinCheck);
    		
	} while (WinCheck != 1 && WinCheck != 2 && turnno < 9);

	
	if (turnno == 9) {
    	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\nThe match has ended in a draw!\n\n"<<endl;
    	OutPut(tictac);
	}
	if (WinCheck == 1) {
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 1 has won the game!\n-------------------------------------------------------------------\n";
		OutPut(tictac);
		cout<<"\n\n***CONGRATULATIONS!!!***\n";
	
	} else if (WinCheck == 2) {
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\nPlayer 2 has won the game!\n-------------------------------------------------------------------\n";
		OutPut(tictac);
		cout<<"\n\n***CONGRATULATIONS!!!***\n";
	}

			
	return 0;
}

void OutPut(char tictac[3][3]){
    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
        	if(j == 0){
        		cout<<"    ";
        	}
            cout<<tictac[i][j];
            if (j < 2){
            	cout<<" | ";
            }
            
        }
        cout<<"\n";
        if(i < 2){
        	cout<<"   ---|---|--- ";
        }
        cout<<"\n";
    }
    
}



void TakeInput(int &turn, char tictac [3][3], char Pcharo, char Pcharx, char &position){
    
    string coordinates = "    A | B | C  \n   ---|---|--- \n    D | E | F  \n   ---|---|--- \n    G | H | I  ";
    
    	if (turn == 1) {
    		cout<<"It's Player "<<turn<<"'s turn! Enter a letter for the position for "<<Pcharo<<"\n\n";
			OutPut(tictac);
			cout<<endl<<coordinates<<"\n\nEnter coordinates from A - I: ";
			cin>>position;
    	}
   	 
   		if (turn == 2) {
    		cout<<"It's Player "<<turn<<"'s turn! Enter a letter for the position for "<<Pcharx<<"\n\n";
			OutPut(tictac);
			cout<<endl<<coordinates<<"\n\nEnter coordinates from A - I: ";
			cin>>position;
    	}
    
}



void SwitchCoordinates(char &position, char tictac[3][3], char Pcharo, char Pcharx, int &turn) {
	
		if(turn == 1){
			if (position == 'A' || position == 'a'){
				tictac[0][0] = Pcharo;
			}
			else if (position == 'B' || position == 'b'){
				tictac[0][1] = Pcharo;
			}
			else if (position == 'C' || position == 'c'){
				tictac[0][2] = Pcharo;
			}
			else if (position == 'D' || position == 'd'){
				tictac[1][0] = Pcharo;
			}
			else if (position == 'E' || position == 'e'){
				tictac[1][1] = Pcharo;
			}
			else if (position == 'F' || position == 'f'){
				tictac[1][2] = Pcharo;
			}
			else if (position == 'G' || position == 'g'){
				tictac[2][0] = Pcharo;
			}
			else if (position == 'H' || position == 'h'){
				tictac[2][1] = Pcharo;
			}
			else if (position == 'I' || position == 'i'){
				tictac[2][2] = Pcharo;
			}
		}
		 else if (turn == 2){
			if (position == 'A' || position == 'a'){
				tictac[0][0] = Pcharx;
			}
			else if (position == 'B' || position == 'b'){
				tictac[0][1] = Pcharx;
			}
			else if (position == 'C' || position == 'c'){
				tictac[0][2] = Pcharx;
			}
			else if (position == 'D' || position == 'd'){
				tictac[1][0] = Pcharx;
			}
			else if (position == 'E' || position == 'e'){
				tictac[1][1] = Pcharx;
			}
			else if (position == 'F' || position == 'f'){
				tictac[1][2] = Pcharx;
			}
			else if (position == 'G' || position == 'g'){
				tictac[2][0] = Pcharx;
			}
			else if (position == 'H' || position == 'h'){
				tictac[2][1] = Pcharx;
			}
			else if (position == 'I' || position == 'i'){
				tictac[2][2] = Pcharx;
			}
		}
	}
			
	
		
	


void WinCondition(char tictac[3][3], char Pcharo, char Pcharx, int &WinCheck){
	
	if((tictac[0][0] == Pcharo && tictac [1][1] == Pcharo && tictac[2][2] == Pcharo) || (tictac[0][2] == Pcharo && tictac [1][1] == Pcharo && tictac[2][0] == Pcharo) || (tictac[0][0] == Pcharo && tictac [0][1] == Pcharo && tictac[0][2] == Pcharo) || (tictac[1][0] == Pcharo && tictac [1][1] == Pcharo && tictac[1][2] == Pcharo) || (tictac[2][0] == Pcharo && tictac [2][1] == Pcharo && tictac[2][2] == Pcharo) || (tictac[0][0] == Pcharo && tictac [1][0] == Pcharo && tictac[2][0] == Pcharo) || (tictac[0][1] == Pcharo && tictac [1][1] == Pcharo && tictac[2][1] == Pcharo) || (tictac[0][2] == Pcharo && tictac [1][2] == Pcharo && tictac[2][2] == Pcharo)) {
		WinCheck = 1;
	} else
	if((tictac[0][0] == Pcharx && tictac [1][1] == Pcharx && tictac[2][2] == Pcharx) || (tictac[0][2] == Pcharx && tictac [1][1] == Pcharx && tictac[2][0] == Pcharx) || (tictac[0][0] == Pcharx && tictac [0][1] == Pcharx && tictac[0][2] == Pcharx) || (tictac[1][0] == Pcharx && tictac [1][1] == Pcharx && tictac[1][2] == Pcharx) || (tictac[2][0] == Pcharx && tictac [2][1] == Pcharx && tictac[2][2] == Pcharx) || (tictac[0][0] == Pcharx && tictac [1][0] == Pcharx && tictac[2][0] == Pcharx) || (tictac[0][1] == Pcharx && tictac [1][1] == Pcharx && tictac[2][1] == Pcharx) || (tictac[0][2] == Pcharx && tictac [1][2] == Pcharx && tictac[2][2] == Pcharx)) {
		WinCheck = 2;
	}
	
}
