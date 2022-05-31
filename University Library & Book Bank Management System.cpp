#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <istream>
#include <ios>

using namespace std;

//Pre determined constants:
const int MAX_BOOK_ID = 13;
const int DATE_SIZE = 11;
const int MAX_COPY_NUMBER = 17;
const int MAX_BOOKS = 200;
const int MAX_CATEGORIES = 30;
const int MAX_BOOK_NAME = 60;
const int MAX_CATEGORY_NAME = 20;
const int MAX_CATEGORY_NUMBER = 4;

void printMenu();
void TakeMenuInput(int& mainOption, char& subOption);

bool isValidBookId(char bookId[]);
bool isValidBookName(char bookName[]);
bool isValidCopyNumber(char bookCopy[]);
bool isValidCategoryName(char bookCategory[]);
bool isValidCategoryNumber(char bookCategory[]);

//Category related functions: 
bool AddCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize, char newCategoryId[], char newCategoryName[]);
bool UpdateCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize, char prevCategoryId[], char newCategoryId[], char newCategoryName[]);
bool DeleteCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize, char CategoryId[]);
void PrintCategories(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize);
bool SaveCategories(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char fileName[]);
bool LoadCategories(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char fileName[]);

//Book related functions:

bool AddBook(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char newBookId[], char newBookName[], int edition);
bool UpdateBook(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char prevBookId[], char newBookId[], char newBookName[], int edition);
bool DeleteBook(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char Bookld[]);
void PrintBooks(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize);
bool SaveBooks(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char filename[]);
bool LoadBooks(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char filename[]);

//Book Sample related functions:

bool AddBookSample (char CopyId[][MAX_COPY_NUMBER], char PulishedDates[][DATE_SIZE], int ArraySize, char newCopyId[], char newPublishDate[]);
bool UpdateBookSample (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char prevCopyId[], char newCopyId[], char newPublishDate[]);
bool DeleteBookSample (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char Copyld[]);
void PrintBookSamples (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char BookId[]);
bool SaveBookSamples (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char fileName[]);
bool LoadBookSamples (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char fileName[]);


int main() {
	int mainOption;
    char subOption;
    
    //LoadCategories();
    //LoadBookSamples();
    //LoadBooks();
    
    
    
    printMenu();
    TakeMenuInput(mainOption, subOption);
    
    
    
    
    
 return 0;
}


bool isValidBookId(char bookId[])
{
	int check = 1;
	if(bookId[0] >= '0' && bookId[0] <= '9' && bookId[1] >= '0' && bookId[1] <= '9' && bookId[2] >= '0' && bookId[2] <= '9'){
		if(bookId[3] == '-' && bookId[6] == '-'){
			if(bookId[4] >= 'A' && bookId[4] <= 'Z' || bookId[4] >= 'a' && bookId[4] <= 'z' && bookId[5] >= 'A' && bookId[5] <= 'Z' || bookId[5] >= 'a' && bookId[5] <= 'z'){
				if(bookId[7] >= '0' && bookId[7] <= '9' && bookId[8] >= '0' && bookId[8] <= '9' && bookId[9] >= '0' && bookId[9] <= '9' && bookId[10] >= '0' && bookId[10] <= '9' && bookId[11] >= '0' && bookId[11] <= '9'){
					return true;
				} 
						
			} 
					
		}
				
	} else{
		return false;
	}
 
}

bool isValidBookName(char bookName[])
{
	int i, check = 1;
	char checkChar;
	
	check = 1;
	
	for(int i = 0; i < 60; i++){
		if(i > 0){
			checkChar = bookName[i-1];
		}
		if(bookName[i] <= 'A' && bookName[i] >= 'Z' && bookName[i] <= 'a' && bookName[i] >= 'z' && bookName[i] != ':' && bookName[i] != ',' && bookName[i] != ' '){
			if(checkChar == ' ' && bookName[i] == ' ' || checkChar == ':' && bookName[i] == ':' || checkChar == ',' && bookName[i] == ','){
			
				check = 0;
			}
		}
	}
	if(check == 0){
		return false;
	} else if(check == 1){
		return true;
	}
	
}

bool isValidCopyNumber(char bookCopy[])

{
	if(isValidBookId(bookCopy) == true){
		if(bookCopy[12] == '#' && bookCopy[13] >= '0' && bookCopy[13] <= '9' && bookCopy[14] >= '0' && bookCopy[14] <= '9' && bookCopy[15] >= '0' && bookCopy[15] <= '9'){
			return true;
		}
		
	}
	
	
	return false;
}
bool isValidCategoryName(char bookCategory[]){
	
    for(int i = 0; i < MAX_BOOK_NAME; i++){
        if((bookCategory[i]>='A' && bookCategory[i]<='z') || bookCategory[i]==' '){
            if(bookCategory[i+1] ==' '){
                return false;
            }
        }
    }
return true;
}
                
bool isValidCategoryNumber(char bookCategory[]){
	
    if(bookCategory[0]>=0 || bookCategory[0]<=9 && bookCategory[1]>=0 || bookCategory[1]<=9 && bookCategory[2]>=0 || bookCategory[2]<=9 )
        return true;
    else
        return false;
}


// ******************************* CATEGORIES START *******************************
bool AddCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize, char newCategoryId[], char newCategoryName[])
{
 
}

bool UpdateCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize, char prevCategoryId[], char newCategoryId[], char newCategoryName[])
{
 
}

bool DeleteCategory(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize, char CategoryId[])
{
 
}

void PrintCategories(char CatergoryNo[][MAX_CATEGORY_NUMBER],char CatergoryName[][MAX_CATEGORY_NAME], int ArraySize)
{
 
}

bool SaveCategories(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char fileName[])
{
 
}

bool LoadCategories(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char fileName[])
{
 
}
// ******************************* CATEGORIES END *******************************


// *******************************  BOOKS  START  *******************************

bool AddBook(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char newBookId[], char newBookName[], int edition){
    
    
}

bool UpdateBook(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char prevBookId[], char newBookId[], char newBookName[], int edition){
    
    
}

bool DeleteBook(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char Bookld[]){
    
    
}

void PrintBooks(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize){
    
    
}

bool SaveBooks(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char filename[]){
    
    
}

bool LoadBooks(char BookId[][MAX_BOOK_ID],char CatergoryName[][MAX_BOOK_NAME], int Editions[], int ArraySize, char filename[]){
    
    
}

// *******************************   BOOKS END    *******************************

// *******************************BOOKSAMPLESSTART******************************* 

bool AddBookSample (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char newCopyId[], char newPublishDate[]){
    
    
}

bool UpdateBookSample (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char prevCopyId[], char newCopyId[], char newPublishDate[]){
    
    
}

bool DeleteBookSample (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char Copyld[]){
    
    
}

void PrintBookSamples (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char BookId[]){
    
    
}

bool SaveBookSamples (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char fileName[]){
    
    
}

bool LoadBookSamples (char CopyId[][MAX_COPY_NUMBER],char PulishedDates[][DATE_SIZE], int ArraySize, char fileName[]){
    
    
}

// ******************************* BOOK SAMPLES END******************************* 



void TakeMenuInput(int& mainOption, char& subOption)
{
	
	char bookCategoryNum[MAX_CATEGORY_NUMBER];
	char bookCategoryName[MAX_CATEGORY_NAME];
	char bookNewCategoryName[MAX_CATEGORY_NAME];
	char bookNewCategoryNum[MAX_CATEGORY_NUMBER];
    
    int bookEdition;
    char bookName[MAX_BOOK_NAME];
    char bookId[MAX_BOOK_ID];
    char bookNewId[MAX_BOOK_ID];
    
    cout<<"Choose Option=";
    cin>>mainOption>>subOption;
	
	
	
    switch(mainOption){
        case 1:
        //cout<<"Category Management";
        
        
        switch(subOption){
            case 'A':
        	    cout<<"Enter the details of the category(ID Name) : ";
        	    cin>>bookCategoryNum;
        	    cin>>bookCategoryName;
            	//cin.getline(bookCategoryName, 60);
            	if(isValidCategoryNumber(bookCategoryNum) && isValidCategoryName(bookCategoryName)){
            	    //AddCategory();
            	    cout<<"";
            	} else {
            	    cout<<"Enter valid book ID";
            	}
            break;
            
            case 'E':
        	    cout<<"Enter the Category Id to edit: ";
        	    cin>>bookCategoryNum;
        	    cout<<"Enter the new details of the category(ID Name): ";
        	    cin>>bookNewCategoryNum;
        	    cin>>bookNewCategoryName;
        	    if(isValidCategoryNumber(bookCategoryNum)){
					if(isValidCategoryNumber(bookNewCategoryNum) && isValidCategoryName(bookNewCategoryName)){
                		//UpdateCategory();
                		cout"";
					} else {
						cout<<"Enter a valid book ID and a valid book Name";
					}
				} else {
					cout<<"Enter a valid book ID";
				}
            break;
            
            case 'L':
                cout<<"Category ID       Name";
                
                //PrintCategories(bookCategoryNum, bookCategoryName, MAX_CATEGORIES);
            break;
            
            case 'D':
                cout<<"Enter the Category Id to Delete: ";
                cin>>bookCategoryNum;
                if(isValidCategoryNumber(bookCategoryNum)) {
                    //DeleteCategory();
                    cout<<"Category has been deleted successfully";
                    
                } else {
                    cout<<"Enter a valid book ID";
                }
                
            break;
        }
        break;
        
        case 2:
            //cout<<"Books Management";
    	        
            switch(subOption){

            	case 'A':
        	   		cout<<"Enter the details of the book(Id Edition Name) : ";
        	    	cin>>bookId;
        	    	cin>>bookEdition;
        	    	cin>>bookName[MAX_BOOK_NAME];
        	    	
            		
            		if(isValidBookId(bookId) && isValidBookName(bookName) && bookEdition <= 15 && bookEdition >= 1){
            		    //AddBook();
            		    cout"Book has been added successfully";
            		} else {
            		    cout<<"Enter valid book ID and ";
            		}
            	break;
            
            	case 'E':
        		    cout<<"Enter the Book Id to edit: ";
        	    	cin>>bookId;
        	    	cout<<"Enter the new details of the Book(Id Edition Name): ";
        	    	cin>>bookNewId;
        	    	cin>>bookEdition;
        	    	cin>>bookName[MAX_BOOK_NAME];
        	    	if(isValidBookId(bookId)){
						if(isValidBookId(bookNewId) && isValidBookName(bookName) && bookEdition <= 15 && bookEdition >= 1){
                			//UpdateBook();
                			cout<<"Book has been edited successfully";
						} else {
							cout<<"Enter a valid book ID and a valid book Name and valid book edition";
						}
					} else {
						cout<<"Enter a valid book ID";
					}
            	break;
            
            	case 'L':
                	cout<<"Book ID       Name      Edition      Category";

                	//PrintBooks();
            	break;
            
            	case 'D':
            	    cout<<"Enter the Book Id to Delete: ";
            	    cin>>bookId;
            	    if(isValidBookId(bookId)) {
            	        //DeleteBook();
            	        cout<<"Category has been deleted successfully";
            	    } else {
            	        cout<<"Enter a valid book ID";
            	    }
            	    
            	break;
        	}
            
            
            
    	break;
    	
        case 3:
            //cout<<"Book Copy Management";
            
            char CopyId[MAX_COPY_NUMBER];
            char PublishedDates[DATE_SIZE];
            char newCopyId[MAX_COPY_NUMBER];
            char newPublishDate[DATE_SIZE];
            
            switch(subOption){

                case 'A':
                       cout<<"Enter the details of the sample(Id Date-of-Purchase) : ";
                    cin>>CopyId;
                    cin>>PublishedDates;
                    
                    
                    if(isValidCopyNumber(CopyId)){
                        //AddBookSample();
                        cout<<"Book copy has been added successfully";
                    } else {
                        cout<<"Enter valid book copy ID";
                    }
                break;
            
                case 'E':
                    cout<<"Enter the Book Copy to edit: ";
                    cin>>CopyId;
                    cout<<"Enter the new details of the Book Copy(Id Date-of-Purchase): ";
                    cin>>newCopyId;
                    cin>>newPublishDate;
                    
                    if(isValidCopyNumber(CopyId)){
                        //UpdateBookSample();
                        cout<<"Book copy has been edited successfully";
                    } else {
                        cout<<"Enter a valid book copy ID";
                    }
                break;
            
                case 'L':
                    cout<<"Copy ID       Purchase Date";
                    //PrintBookSamples();
                break;
            
                case 'D':
                    cout<<"Enter the Book Copy Id to Delete: ";
                    cin>>CopyId;
                    if(isValidCopyNumber(CopyId)) {
                        //DeleteBookSample();
                        cout<<"Book copy has been deleted successfully";
                    } else {
                        cout<<"Enter a valid book copy ID";
                    }
                    break;
            }
                    
        break;
        
        case 0:
            cout<<"Exit Program";
            //SaveCategories();
        break;
        
        default:
            cout<<"unknown";
       
    }
	
}


void printMenu()
{
	cout<<"** Welcome to University Library Management System **\n";
	cout<<"Choose the following option\n";
	cout<<"1 Category Management(A,E,L,D)\n";
	cout<<"2 Books Management(A,E,L,D)\n";
	cout<<"3 Book Copies Management(A,E,L,D)\n";
	cout<<"0 Exit Program(0E)\n";
}
