/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/14/2015

Week 2 hw

Programming Project #1

Problem Statement: 
A liter is 0.264179 gallons. Write a program that will read in the number
of liters of gasoline consumed by the user's car and the number of miles 
traveled by the car and then output the number of miles per galon the car
delivered. Your program should allow the user to repeat the calculation 
as often as the user wishes. Define a function to compare the number of
miles per galon. Your program sould uses a globally defined constant for
the number of gallons per liter. 

*/

#include <iostream>
using namespace std;

#define GALLONS_PER_LITER 0.264179

double mpg(double liters, double miles);

int main(){
	
	while(1){
		double liters(0);
		double miles(0);
		char cont = 0;
		
		cout << "\nPlease enter the liters used: ";
		cin >> liters;
		
		cout <<"\nPlease enter the miles traveled: ";
		cin >> miles;
		
		cout << "\nThe number of miles per gallon is: " << mpg(liters, miles);
		
		cout << "\n\nWould you like to continue?\n(Type N to quit, any key to continue): ";
		cin >> cont;
		
		if (cont== 'N' || cont == 'n'){
			break;
		}
		
		//reset constants
		liters = 0;
		miles = 0;
		cont = 0;
		
	}//true loop
	
	cout << "\n\n Program Complete! Drive safely...";
}

double mpg(double liters, double miles){
	
	double answer = miles/(liters * GALLONS_PER_LITER);
	return answer;
}

/* Results


Please enter the liters used: 1

Please enter the miles traveled: 1

The number of miles per gallon is: 3.78531

Would you like to continue? Type N to quit
r

Please enter the liters used: 2

Please enter the miles traveled: 4

The number of miles per gallon is: 7.57062

Would you like to continue? Type N to quitn


 Program Complete! Drive safely...
--------------------------------
Process exited after 12.98 seconds with return value 0
Press any key to continue . . .
*/
