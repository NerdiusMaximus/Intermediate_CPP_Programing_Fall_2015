/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/20/2015

Week 3 hw

Programming Project #7

Problem Statement: 
Write a program that will read in a weight in pounds and ounces and outputs
the equivalent weight in kilograms and grams. Use at least three functions: 
one for input, one for calculating, and one for output. Include a loop that 
lets the user repeat this computation for new input values until the user 
says he or she wants to end the program. There are 2.2046 pounds in a kilogram, 
1000 grams in a kilogram, and 16 ounces in a pound.

*/

#include <iostream>

#define LBS_PER_KG 2.2046
#define G_PER_KG 1000
#define OZ_PER_LB 16.0

#define DEBUG

using namespace std;

void getWeight(double& lbs, double& oz);
void computeMetric(double& lb, double& oz, double& kg, double& g);
void outputWeight(double kg, double g);

int main(){
	//declare variables
	double lbs(0), oz(0), kg(0), g(0);
	char cont = 0;
	cout << "Weight Converter Program\n";
	do{
		//reset values for each loop
		lbs = 0; oz = 0; kg = 0; g = 0; cont = 0;
		
		getWeight(lbs, oz);
		computeMetric(lbs, oz, kg, g);
		outputWeight(kg,g);
		
		cout << "\n\nWould you like to continue?\n(Y/N): ";
		cin >> cont;
		
	}while ((cont== 'Y' || cont == 'y'));
	
	cout << "\n\n Program Complete! God bless the Metric System!\n";
	return 0;
}

void getWeight(double& lbs, double& oz)
{
	cout <<"\nPlease enter the weight in lbs: ";
	cin >> lbs;
	cout <<"\nPlease enter the weight in oz: ";
	cin >> oz;
	
	return;
}//end getTime
void computeMetric(double& lb, double& oz, double& kg, double& g)
{
	//convert oz to lbs
	double templbs = (oz / OZ_PER_LB) + lb; // accumulate the decimal lbs
	kg = (templbs / LBS_PER_KG); //convert the lbs to kg
	g = (kg - (int)kg%G_PER_KG) * 1000;
	kg = (kg - g/1000);
	#ifdef DEBUG 
	cout << "kg = " <<  kg << endl;
	cout << "g = " <<  g << endl;
	#endif
}

void outputWeight(double kg, double g)
{
	//format the output to 0 decimal places
	cout.setf(ios::fixed);
	//cout.setf(ios::showpoint);
	cout.precision(0);
	
	cout << "\nThe weight in Metric is: " << kg << " kg ";
	//cout.precision(2);
	cout << g << " g. \n\n";
}

/* Results: 
Weight Converter Program

Please enter the weight in lbs: 0

Please enter the weight in oz: 8
kg = 0
g = 226.799

The weight in Metric is: 0 kg 227 g.



Would you like to continue?
(Y/N): y

Please enter the weight in lbs: 1

Please enter the weight in oz: 8
kg = 0
g = 680

The weight in Metric is: 0 kg 680 g.



Would you like to continue?
(Y/N): y

Please enter the weight in lbs: 10

Please enter the weight in oz: 3
kg = 4
g = 621

The weight in Metric is: 4 kg 621 g.



Would you like to continue?
(Y/N): y

Please enter the weight in lbs: 80

Please enter the weight in oz: 12
kg = 36
g = 628

The weight in Metric is: 36 kg 628 g.



Would you like to continue?
(Y/N): n


 Program Complete! God bless the Metric System!

--------------------------------
Process exited after 63.7 seconds with return value 0
Press any key to continue . . .

*/
