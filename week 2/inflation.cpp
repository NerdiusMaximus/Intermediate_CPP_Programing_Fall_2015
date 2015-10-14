/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/14/2015

Week 2 hw

Programming Project #2

Problem Statement: 
Write a program to calculate the rate of inflation for the past year.
The program asks for the price fo an item (such as a hot dog or a one
carat diamond) both one year ago and today. It estimates the inflation
rate as the difference in price divided by the year ago price. Your
program should allow the user to repeat the calculation as often as the
user wishes. Define a function to compute the rate of inflation. The 
inflation rate should be a value of type double giving the rate as a 
percentage, for example 5.3 for 5.3%. 

*/
#include <iostream>
using namespace std;

#define GALLONS_PER_LITER 0.264179

double inflation(double oldPrice, double newPrice);

int main(){

//format the output to 2 decimal places
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
	
	while(1){
		double oldPrice(0);
		double newPrice(0);
		char cont = 0;
		
		cout << "\nPlease enter the price of an item one year ago: ";
		cin >> oldPrice;
		
		cout <<"\nPlease enter price of the same item today: ";
		cin >> newPrice;
		
		cout << "\nThe approximate inflation rate is: " << inflation(oldPrice, newPrice) << "%\n";
		
		cout << "\n\nWould you like to continue?\n(Type N to quit, any letter to continue): ";
		cin >> cont;
		
		if (cont== 'N' || cont == 'n'){
			break;
		}
		
		//reset constants
		oldPrice = 0;
		newPrice = 0;
		cont = 0;
		
	}//true loop
	
	cout << "\n\n Program Complete! Invest early for best results!";
}

double inflation(double oldPrice, double newPrice){
	
	double answer = 100.0*(newPrice - oldPrice)/oldPrice;
	return answer;
}
/* Results:

Please enter the price of an item one year ago: 1.50

Please enter price of the same item today: 2.00

The approximate inflation rate is: 33.33%


Would you like to continue?
(Type N to quit, any letter to continue): y

Please enter the price of an item one year ago: 1000.00

Please enter price of the same item today: 1050.00

The approximate inflation rate is: 5.00%


Would you like to continue?
(Type N to quit, any letter to continue): y

Please enter the price of an item one year ago: 1234.56

Please enter price of the same item today: 1245.67

The approximate inflation rate is: 0.90%


Would you like to continue?
(Type N to quit, any letter to continue): n


 Program Complete! Invest early for best results!
--------------------------------
Process exited after 36.03 seconds with return value 0
Press any key to continue . . .
*/
