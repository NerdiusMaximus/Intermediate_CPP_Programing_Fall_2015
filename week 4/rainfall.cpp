/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/28/2015

Week 4 hw

Programming Project #1

Problem Statement: 


*/

#include <iostream>
using namespace std;

void getMonth(int& month);
void getRainfall(int& month, int& rainfall[]);
void outputRain(int month, int rainfall[]);

int main(){
	//declare variables
		int month = 0, 
		int rainfall[12] = {0};
		cout << "Previous 12 Months Rainfall\n";
	do{
		//reset values
		month = 0; 
		//rainfall[12] = {0}; //reset all to zero
		
		getMonth(month);
		getRainfall(month, rainfall[]);
		outputRain(month,rainfall[]);
		
		cout << "\n\nWould you like to continue?\n(Y/N): ";
		cin >> cont;
		
	}while ((cont== 'Y' || cont == 'y'));
	
	cout << "\n\n Program Complete! Rain rain, go away, come again another day...\n";
	return 0;
}

void getMonth(int& month)
{
	cout <<"\nPlease enter the month in MM format: ";
	cin >> month;
	
	return;
}//end getMonth

void getRainfall(int month, int rainfall[])
{
	//average NYC rainfall for a 12 month period, jan - dec
	//jan = rain[0], dec = rain[11]
	int rain[11] = {85,57,90,96,114,98,101,87,104,94,69,85};
	
	//offset the array into the rainfall array from main
	
	for(int i = 0; i < 11 - month; ++i)
	{
		rainfall[i] = rain[month + i];
	}
	
	
}

void outputRain(int month, int minutes, char timeOfDay)
{
	
}

/* Results: 


--------------------------------
Process exited after 18.23 seconds with return value 0
Press any key to continue . . .
*/
