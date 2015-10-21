/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/20/2015

Week 3 hw

Programming Project #4

Problem Statement: 
Write a program that will read in a length in feet and inches and output
the length in meters and centimeters. Use at least three functions: one for
input, one for calculating, and one for output. Include a loop that lets the
user repeat this computation for new input values until the user says he or
she wants to end the program. There are 0.3048 meters in a foot, 100 centimeters
in a meter, and 12 inches in a foot. 

*/

#include <iostream>

#define M_PER_F 0.3048

#define DEBUG

using namespace std;

void getLength(double& feet, double& inches);
void computeMetric(double& feet, double& inches, double& meters, double& centimeters);
void outputLength(double meters, double centimeters);

int main(){
	//declare variables
	double feet(0), inches(0), meters(0), centimeters(0);
	char cont = 0;
	cout << "Length Converter Program\n";
	do{
		//reset values for each loop
		feet = 0; inches = 0; meters = 0; centimeters = 0; cont = 0;
		
		getLength(feet, inches);
		computeMetric(feet, inches, meters, centimeters);
		outputLength(meters,centimeters);
		
		cout << "\n\nWould you like to continue?\n(Y/N): ";
		cin >> cont;
		
	}while ((cont== 'Y' || cont == 'y'));
	
	cout << "\n\n Program Complete! God bless the Metric System!\n";
	return 0;
}

void getLength(double& feet, double& inches)
{
	cout <<"\nPlease enter the lengh in feet: ";
	cin >> feet;
	cout <<"\nPlease enter the length in inches: ";
	cin >> inches;
	
	return;
}//end getTime
void computeMetric(double& feet, double& inches, double& meters, double& centimeters)
{
	//convert feet to inches
	double tempFeet = (inches / 12.0) + feet; //add the feet to the fractional foot from inches
	meters = tempFeet * M_PER_F; //multiply by constant meters per foot
	#ifdef DEBUG 
	cout << "meters = " <<  meters << endl;
	#endif
	centimeters = (meters - (int)meters%1000) * 100;
	#ifdef DEBUG 
	cout << "centimeters = " <<  centimeters << endl;
	#endif
}

void outputLength(double meters, double centimeters)
{
	//format the output to 0 decimal places
	cout.setf(ios::fixed);
	//cout.setf(ios::showpoint);
	cout.precision(0);
	
	cout << "\nThe length in Metric is: " << meters << " M ";
	//cout.precision(2);
	cout << centimeters << " cm. \n\n";
}

/* Results: 
Length Converter Program

Please enter the lengh in feet: 10

Please enter the length in inches: 6
meters = 3.2004
centimeters = 20.04

The length in Metric is: 3 M 20 cm.



Would you like to continue?
(Y/N): y

Please enter the lengh in feet: 1

Please enter the length in inches: 6
meters = 0
centimeters = 46

The length in Metric is: 0 M 46 cm.



Would you like to continue?
(Y/N): y

Please enter the lengh in feet: 0

Please enter the length in inches: 6
meters = 0
centimeters = 15

The length in Metric is: 0 M 15 cm.

Would you like to continue?
(Y/N): n


 Program Complete! God bless the Metric System!

--------------------------------
Process exited after 43.19 seconds with return value 0
Press any key to continue . . .

******************************************************
HIGHER PRECISION IN cm VALUE IF UNCOMMENT LINE 87
Length Converter Program

Please enter the lengh in feet: 10

Please enter the length in inches: 6
meters = 3.2004
centimeters = 20.04

The length in Metric is: 3 M 20.04 cm.



Would you like to continue?
(Y/N): y

Please enter the lengh in feet: 1

Please enter the length in inches: 6
meters = 0.46
centimeters = 45.72

The length in Metric is: 0 M 45.72 cm.



Would you like to continue?
(Y/N): y

Please enter the lengh in feet: 0

Please enter the length in inches: 6
meters = 0.15
centimeters = 15.24

The length in Metric is: 0 M 15.24 cm.



Would you like to continue?
(Y/N): y

Please enter the lengh in feet: 150

Please enter the length in inches: 3.5
meters = 45.81
centimeters = 80.89

The length in Metric is: 46 M 80.89 cm.



Would you like to continue?
(Y/N): n


 Program Complete! God bless the Metric System!

--------------------------------
Process exited after 36.83 seconds with return value 0
Press any key to continue . . .

*/
