/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/20/2015

Week 3 hw

Programming Project #4

Problem Statement: 
Wire a program that converts from 24 hour time notation to 12 hour notation. For example, 
it should convert 14:25 to 2:25 pm. The ouput is given as two integers. There should be at
least three functions: one for input, one to do the conversion, and one for output. Record
the A.M./P.M. information as a value of type char, 'A' for A.M., and 'P' for P.M. (The 
function will have other parameters as well.) Include a loop that lets the user repeat
this computation for new input values again and again until the user says he or she wants
to end the program. 

*/

#include <iostream>
using namespace std;

void getTime(int& hours, int& minutes);
void compute12Hour(int& hours, int& minutes, char& timeOfDay);
void outputTime(int hours, int minutes, char timeOfDay);

int main(){
	//declare variables
		int hours = 0, minutes = 0; char timeOfDay = 0;
		char cont = 0;
		cout << "Time Converter Program\n";
	do{
		//reset values
		hours = 0; minutes = 0; char timeOfDay = 0; cont = 0;
		
		getTime(hours, minutes);
		compute12Hour(hours, minutes, timeOfDay);
		outputTime(hours,minutes,timeOfDay);
		
		cout << "\n\nWould you like to continue?\n(Y/N): ";
		cin >> cont;
		
	}while ((cont== 'Y' || cont == 'y'));
	
	cout << "\n\n Program Complete! Time is money, go use it wisely!\n";
	return 0;
}

void getTime(int& hours, int& minutes)
{
	cout <<"\nPlease enter the hours in 24 hour time format: ";
	cin >> hours;
	cout <<"\nPlease enter the minutes in 24 hour time format: ";
	cin >> minutes;
	
	return;
}//end getTime
void compute12Hour(int& hours, int& minutes, char& timeOfDay)
{
	if(hours > 12)
	{
		timeOfDay = 'P';
		hours = hours - 12;
	}
	else
	{
		timeOfDay = 'A';
	}
	
	return;
}

void outputTime(int hours, int minutes, char timeOfDay)
{
	if (timeOfDay == 'A')
		cout << "\nThe 12 hours time is: " << hours << ":" << minutes << " " << "A.M.\n";
	if (timeOfDay == 'P')
		cout << "\nThe 12 hours time is: " << hours << ":" << minutes << " " << "P.M.\n";
}

/* Results: 

Time Converter Program

Please enter the hours in 24 hour time format: 23

Please enter the minutes in 24 hour time format: 15

The 12 hours time is: 11:15 P.M.


Would you like to continue?
(Y/N): y

Please enter the hours in 24 hour time format: 6

Please enter the minutes in 24 hour time format: 24

The 12 hours time is: 6:24 A.M.


Would you like to continue?
(Y/N): y

Please enter the hours in 24 hour time format: 12

Please enter the minutes in 24 hour time format: 34

The 12 hours time is: 12:34 A.M.


Would you like to continue?
(Y/N): n


 Program Complete! Time is money, go use it wisely!

--------------------------------
Process exited after 18.23 seconds with return value 0
Press any key to continue . . .
*/
