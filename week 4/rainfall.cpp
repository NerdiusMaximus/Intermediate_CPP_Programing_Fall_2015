/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/28/2015

Week 4 hw

Programming Project #1

Problem Statement: 
Write a program that reads in the average monthly rainfall for a city each month of the year and then reads in 
the actual monthly rainfall for each of the previous 12 months. The program then prints out a nicely formatted
table showing the rainfall for each of the previous 12 months as well as how much above or below average the 
rainfall was for each month. The average monthly rainfall is given for the months January, February, and so forth
in order. To obtain the actual rainfall for the previous 12 months, the program first asks what the current month 
is and then asks for the rainfall figures for the previous 12 months. The output should correctly label the months.

There are a variety of ways to deal with the month names. One straightforward method is to code the months as 
integers and do a conversion before doing the output. A large switch statement is acceptable in an output function.
The month input can be handled in any manner you wish, as long as it is relatively easy and plesant for the user.

After you have completed the above program, produce an enhanced version that also outputs a graph showing the 
average rainfall for each of the previous 12 months. The graph should be similar to the one shown in Display 5.4 
except that there should be two bar graphs for each month and they should be labeled as the average rainfall
and the rainfall for the most recent month. Your program should ask the user whether she or he wants to see 
the table or the bar graph, and then should display whichever format is requested. include a loop that allows 
the user to see either format as often as the user wishes until the user requests that the program ends.

*/

#include <iostream>
using namespace std;

void getMonth(int& month);
void getRainfall(int& month, int& rainfall);
void outputRain(int month, int rainfall[]);

int main(){
	//declare variables
		int month = 0;
		int averageRainfall[12] = {0}, actualRainfall[12] = {0};
		char input(0);
		cout << "Rainfall Calculator Program\n****************\n" << endl;
		
		//get current month
		getMonth(month);
		
		//get average rainfall from each month
		getRainfall(month, rainfall[]);
		
		//get actual rainfall from each month
		outputRain(month,rainfall[]);
		
	do{	//loop the output select
	
		//select type of output to choose
		
		//prompt user about bar graph or table
		
		//choose bar graph or table and output the corresponding type
	
		//prompt for continue or not
		cout << "\n\nWould you like to see the data again?\n(Y/N): ";
		cin >> input;
		
	}while ((input== 'Y' || input == 'y'));
	
	//end statement
	cout << "\n\n Program Complete! Rain rain, go away, come again another day...\n";
	return 0;
}

void getMonth(int& month)
{
	cout <<"\nPlease enter the month in integer MM format: ";
	cin >> month;
	
	return;
}//end getMonth

void getRainfall(int& month, int& rainfall[])
{
	//average NYC rainfall for a 12 month period, jan - dec
	//jan = rain[0], dec = rain[11]
	//int rain[11] = {85,57,90,96,114,98,101,87,104,94,69,85};

	
	
}

void outputRain(int month, int minutes, char timeOfDay)
{
	
}

/* Results: 


*/
