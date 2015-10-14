/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/14/2015

Week 2 hw

Programming Project #6

Problem Statement: 
Write a function that computes the average and standard deviation of four scores.
The stancard deviation is defined to be the square root of the average of the four
values: (si - a)^2, where a is the average of the four scores s1, s2, s3, and s4.
The function will have six parameters and call two other functions. Embed the 
function in a program that allows you to test the function again and again until
you tell the program you are finished.

*/
#include <iostream>
using namespace std;

#define GALLONS_PER_LITER 0.264179

double stats(double s1, double s2, double s3, double s4);

int main(){
	
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

double stats(double oldPrice, double newPrice){
	
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
