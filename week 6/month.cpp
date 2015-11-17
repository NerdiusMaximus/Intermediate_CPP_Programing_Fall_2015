/*
Intermediate CPP
Fall 2015
Michael Lowry
11/18/2015

Week 6 homework

Problem Statement:
1. Define a class called Month that is an abstract data type for a month. Your class will have
one member variable of type int to represent a month (1 for January, 2 for February, and
so forth). Include all the following member functions: a constructor to set the month using
the first three letters in the name of the month as three arguments, a constructor to set the
month using an integer as an argument (1 for January, 2 for February, and so forth), a
default constructor, an input function that reads the month as an integer, an input function
that reads the month as the first three letters in the name of the month, an output
function that outputs the month as an integer, an output function that outputs the month
as the first three letters in the name of the month, and a member function that returns the
next month as a value of type Month. Embed your class definition in a test program.

*/
#define DEBUG

#include <iostream>
#include <strings.h>
using namespace std;

class Month
{
	private:
		int month;
		
	public:
		//constructors
		Month();
		Month(char first, char second, char third);
		Month(int Month);
		
		//mutators
		void inputMonth();
		void inputMonthName();
		
		//accessors
		void outputNumber();
		void outputName();
		
		Month nextMonth();
	
};

int main ()
{
	//demonstrate this shit works here
}

//constructor definitions
Month::Month()
{//default constructor
	month = 0; //set month to no month
}
Month::Month(int Month)
{
	month = Month; //set member data to the input
}
Month::Month(char first, char second, char third)
{
	//select which month to use
	
}

//Mutator definitions
void Month::inputMonth()
{
	int numInput = 0;
	cout << "Please enter the month as an integer number: ";
	cin >> numInput;
	month = numInput;
}
void Month::inputMonthName()
{
	char input[3] = {0};
	cout << "Please enter the month as three letters: ";
	cin >> input;
	
	//easier way: take input as three single characters
	//better way: take the input and strcmp with the array of char arrays to find a match! 
	//somehow..........
	/*
	J A N
	F E B
	M A R
	A P R
	M A Y
	J U N
	J U L
	A U G 
	S E P
	O C T
	N O V
	D E C
	*/
}
void Month::outputName()
{
	
}
void Month::outputNumber()
{
	
}
Month Month::nextMonth()
{
	int nextMonth = month + 1;
	Month next(nextMonth);
	
	return next;
}
