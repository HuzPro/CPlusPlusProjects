#include<stdio.h>
#include <TIME.H>
int main()
{ 
/*printf("***********************************\n");
printf("*PASSWORD PROTECTED PERSONAL DIARY*\n");
printf("***********************************\n\n");
printf("          MAIN MENU:           \n\n");
printf("ADD RECORD          [1]\n");
printf("VIEW RECORD         [2]\n");
printf("EDIT RECORD         [3]\n");
printf("DELETE RECORD       [4]\n");
printf("EDIT PASSWORD       [5]\n");
printf("EXIT                [6]\n\n\n\n");

printf("_________________________________________________________________________\n\n\n");

printf("***** Welcome to Contact Management System *****\n\n");
printf("                   MAIN MENU                      \n");
printf("           =========================                 \n");
printf("           [1] Add a new Contact\n");
printf("           [2] List all Contacts\n");
printf("           [3] Search for a contact\n");
printf("           [4] Edit a Contact\n");
printf("           [5] Delete a Contact\n");
printf("           [6] Exit\n");
printf("           =========================                 \n");*/


/*int first_num;
int second_num;

int answer = 1;

printf("Enter first number:\t");
scanf("%d", &first_num);

printf("Enter second number:\t");
scanf("%d", &second_num);

answer = first_num * second_num;

printf("The Answer is %d", answer);*/

/*
float fpnum;
char alpha;
char c;

printf("Enter a character:\t");
scanf("%c", &c);
printf("You have entered: %c\n", c);

printf("The ASCII value of %c is %d,", c, c);*/



/*
float first_num, second_num, third_num, avg;

printf("Enter first number:\t");
scanf("%f", &first_num);
printf("Enter second number:\t");
scanf("%f", &second_num);
printf("Enter Third numer:\t");
scanf("%f", &third_num);

avg = (first_num + second_num + third_num)/3;
printf("The average is %f", avg);
*/





/*
float radius, vol;

printf("Enter the radius of sphere:\t");
scanf("%f", &radius);

vol = (4.0/3.0) * 3.14159 * (radius * radius * radius);

printf("The volume of the sphere is: %f\t", vol);
*/





/*
int num, rem;

printf("Enter a number:\t");
scanf("%d", &num);
rem = num % 2;

if(rem == 0){
	printf("%d is an even number.", num);
	
} else {
	printf("%d is an odd number.", num);
	
}
*/


/*
int marks;

printf("Enter the marks please, Hurry up chop chop, I don't have all day you know -_-");
scanf("%d", &marks);
 if(marks >= 0 && marks <= 100){
 	printf("The marks entered are valid, Yaaaaaay Hurray! You managed to enter the correct marks, congratulations! You should get an award!");
 } else {
 	printf("Wow... I can't believe it. Are you blind? Can you not even enter the correct marks!? Seriously? My god...'");
 }

*/



/*
int year, age;

printf("Enter your year of birth please :)\t");
scanf("%d", &year);
printf("Thank you, please hold for a moment\n");
sleep(5);
 if(year % 4 == 0) {
 	printf("Wow! You were born in a leap year!");
 } else {
 	age = 2019 - year;
 	printf("Your age is:%d", age);
 }
*/



/*
int marks, total;

printf("Enter marks out of 100\n");
scanf("%d", &marks);
if(marks >= 0 && marks <= 50){
	printf("Your grade: F\n");
} else if(marks >=51 && marks <= 80){
	printf("Your grade: B");
} else if(marks >= 81 && marks<= 100){
	printf("Your grade: A");
} else {
	printf("You have entered invalid marks. Your marks must be in the range 0-100.");
}
*/

/*
int first_num, second_num, total;
char operator;

printf("Enter first number:\t");
scanf("%d", &first_num);

printf("Enter second number:\t");
scanf("%d", &second_num);

printf("Enter operator:\t");
scanf(" %c", &operator);

if(operator == '+'){
	total = first_num + second_num;
} else if(operator == '-'){
	total = first_num - second_num;
} else if(operator == '*'){
	total = first_num * second_num;
} else if (operator == '/'){
	total = first_num / second_num;
}

printf("Total is: %d", total);
*/


/*
int x;

printf("input the value of x\n");
scanf("%d", &x);

switch (x) {
	case 1: {
	printf("x is 1");
		break;
	}
	case 2: {
		printf("x is 2");
		break;
	}
	case 3: {
		printf("x is 3");
		break;
	}
}
*/






/*
int marks;

printf("Enter the number of marks you have obtained in the entry test:\n");
scanf("%d", &marks);

switch (marks){
	case 50 ... 70:{
		printf("You may take admission in the 'Management Sciences' department.");
		break;
	}
	case 71 ... 90: {
		printf("You may take admission in the 'Computer Sciences' department.");
		break;
	}
	case 91 ... 100:{
		printf(" You may take admission in the 'Electrical Engineering' department.");
		break;
	}
}
*/




/*
int side1, side2, side3;

printf("Enter the first length:\n");
scanf("%d", &side1);

printf("Enter the second length:\n");
scanf("%d", &side2);

printf("Enter the third length:\n");
scanf("%d", &side3);

if(side1 + side2 > side3 || side1 + side3 > side2 || side2 + side3 > side1){
	printf("These lengths can make a valid triangle.");
} else {
	printf("These lengths can not make a valid triangle.");
}
*/


/*
int firstnum, secondnum, thirdnum;

printf("Enter first number:\n");
scanf("%d", &firstnum);

printf("Enter second number:\n");
scanf("%d", &secondnum);

printf("Enter third number:\n");
scanf("%d", &thirdnum);

if(((firstnum + secondnum) > thirdnum) && ((secondnum + thirdnum) > firstnum) && ((firstnum + thirdnum) > secondnum)) {
	printf("Triangle is valid");
} else {
	printf("Triangle is invalid");
}
*/
       


/*
int firstnum, secondnum, thirdnum;

printf("Enter first number\t");
scanf("%d", &firstnum);
printf("Enter second number\t");
scanf("%d", &secondnum);
printf("Enter third number\t");
scanf("%d", &thirdnum);


if((firstnum < secondnum && secondnum < thirdnum) || (firstnum == secondnum && secondnum < thirdnum)){
	printf("Here are your numbers in ascending order:\n1. %d\n2. %d\n3. %d\n", firstnum, secondnum, thirdnum);
} else if(secondnum < firstnum && firstnum < thirdnum){
	printf("Here are your numbers in ascending order:\n1. %d\n2. %d\n3. %d\n", secondnum, firstnum, thirdnum);
} else if(thirdnum < secondnum && secondnum < firstnum){
	printf("Here are your numbers in ascending order:\n1. %d\n2. %d\n3. %d\n", thirdnum, secondnum, firstnum);
} else if((firstnum < thirdnum && thirdnum < secondnum) || (firstnum == thirdnum && thirdnum < secondnum)){
	printf("Here are your numbers in ascending order:\n1. %d\n2. %d\n3. %d\n", firstnum, thirdnum, secondnum);
} else if((secondnum < thirdnum && thirdnum < firstnum) || (secondnum == thirdnum && thirdnum < firstnum)){
	printf("Here are your numbers in ascending order:\n1. %d\n2. %d\n3. %d\n", secondnum, thirdnum, firstnum);
} else if(thirdnum < firstnum && firstnum < secondnum){
	printf("Here are your numbers in ascending order:\n1. %d\n2. %d\n3. %d\n", thirdnum, firstnum, secondnum);
} else if(firstnum == secondnum && secondnum == thirdnum){
	printf("All your numbers are equal:\n1. %d\n2. %d\n3. %d\n", firstnum, secondnum, thirdnum);
} else if(firstnum == secondnum && secondnum > thirdnum){
	printf("Here are your numbers in ascending order:\n1. %d\n2. %d\n3. %d\n", thirdnum, secondnum, firstnum);
} else if(firstnum == thirdnum && thirdnum > secondnum){
	printf("Here are your numbers in ascending order:\n1. %d\n2. %d\n3. %d\n", secondnum, thirdnum, firstnum);
} else if(secondnum == thirdnum && thirdnum > firstnum){
	printf("Here are your numbers in ascending order:\n1. %d\n2. %d\n3. %d\n", firstnum, thirdnum, secondnum);
} 
*/











/*char o;
int firstnum, secondnum, total;*/

/*
printf("Enter first number\n");
scanf("%d", &firstnum);
printf("Enter second number\n");
scanf("%d", &secondnum);
printf("Enter operator\n");
scanf(" %c", &o);


switch (o){
	case '+':{
		total = firstnum + secondnum;
		printf("%d + %d = %d", firstnum, secondnum, total);
		break;
	}
	case '-':{
		total = firstnum - secondnum;
		printf("%d - %d = %d", firstnum, secondnum, total);
		break;
	}
	case '*':{
		total = firstnum * secondnum;
		printf("%d * %d = %d", firstnum, secondnum, total);
		break;
	}
	case '/':{
		total = firstnum / secondnum;
		printf("%d / %d = %d", firstnum, secondnum, total);
		break;
	}
	default :{
		printf("You have entered an invalid operator");
		break;
	}
}
*/





/*
int i = 0, num = 0;

printf("Enter a number\n");
scanf("%d", &num);

printf("Natural numbers less than %d are:\n", num);

for (i = 1; i < num; i++)
	{
		printf("%d", i);
		printf("\n");
	}
	*/

/*int i = 0, j = 0, num = 0;

printf("Enter a number\n");
scanf("%d", &num);

for (i = 0; i<num; i++){
	for (j = 0; j < i; j++){
		printf("*");
	}
	printf("\n");
}*/



/*
int num = 0;
printf("******ENTER NEGATIVE TO EXIT******");

while(num >= 0)
{
	printf("\nENTER A NUMBER:\t");
	scanf("%d", &num);
}
printf("\n******PROGRAM ENDED******");
*/


/*
int num, x=1, total;

printf("Enter the number you'd want the table of to be displayed...lol\n");
scanf("%d", &num);
printf("\n\n");

for (x = 1; x < 11; x++){
	total = num * x;
	printf(" %d * %d = %d\n", num, x, total);
}
*/


/*
int num, x = 0, y, even = 1, odd = 0, rows, z;

printf("Enter number\n");
scanf("%d",&num);





for(x=num; x>=1; --x)
    {
        for(z=1; z<=x; ++z)
        {
            printf("test");
        }
        printf("\n");
    }



*/


/*
int num, factorial=1, x, y;

printf("Enter number\n");
scanf("%d", &num);
y=num;
while(y>=1){
factorial=factorial*y;
y--;
} printf("Factorial of %d is %d\n", num, factorial);
*/



//(A)
/*
int i, j, num = 1;


for (i = 1; i <= 5; i=i+1){
	for(j = 1; j <= i; j = j + 1){
		printf("%d ", num);
	} 
	printf("\n");
}
*/

//B
/*
int i, j, num = 5;


for (i = 1; i <= 5; i=i+1){
	for(j = 1; j <= i; j = j + 1){
		printf("%d ", num);
	} 
	printf("\n");
}
*/

//C

/*
int i, j, num = 5;


for (i = 1; i <= 5; i=i+1){
	for(j = 1; j <= i; j = j + 1){
		printf("%d ", num);
	} 
	printf("\n");
	num = num - 1;
}
*/

//D
/*
int i, j, num = 1;


for (i = 1; i <= 5; i=i+1){
	for(j = 1; j <= i; j = j + 1){
		printf("%d ", num);
		num = num + 1;
	} 
	printf("\n");
}
*/

//E
/*
int i, j, s, num = 5, num_s = 5;
char star = '*';
char space = ' ';

for (i = 1; i <= 5; i=i+1){
		for(s = 1; s <= num; num = num - 1){
			printf("%c", space);
		}
	for(j = 1; j <= i; j = j + 1){

		num = num_s - j;
		printf("%c ", star);
	} 
	
	printf("\n");
}
*/

//F

/*
int i, j, num = 1;


for (i = 1; i <= 5; i=i+1){
	for(j = 1; j <= 5; j = j + 1){
		printf("%d ", num);
		;
	} 
	num = num + 1;
	printf("\n");
}
*/

int i, j, num;

printf("Input number:\n");
scanf("%d", num);
printf(" ",num);




































return 0;
}
