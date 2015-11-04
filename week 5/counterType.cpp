/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/20/2015

Week 5 hw

Programming Project #2

Problem Statement: 
Define a class for a type called CouterType. An object f this type is used to count things, so it 
records a count that is a non negative whole number. Include a mutator function that sets the 
counter to a count given as an argument. Include member functions to increase the count by one
and decrease the count by one. Be sure that no member function allows the value of the counter
to become negative. Also, include a member function that returns the current count value and one
that outputs the count. Embed your class definition in a test program
*/

#include <iostream>
using namespace std;

//class definition
class CounterType{
	//Private data
	int count;
	
	public: 
	//mutator function setCount
	void setCount(int Count){
		
		if (Count < 0)
		{
			cout << "Cannot set count below zero. Ending program" << endl;
			exit(1);
		}
		
		count = Count;
	};
	//mutator function upCount
	void upCount(){
		
		count++; 
		
	};
	//mutator function downCount
	void downCount(){
		
		if(count < 1)
		{
			cout << "Cannot count below zero. Ending program" << endl;
			exit(1);
		}
		count--;
	};
	//accessor function outputCount
	void outputCount(){
		cout << "The current count is: " << count << endl;
	};
	//accessor function getCount
	int getCount(){
		return count;
	};
};

int main(){
	
	CounterType counter; //instantiate an object of the CounterType class
	
	counter.setCount(10);
	counter.outputCount();
	counter.downCount();
	counter.outputCount();
	for (int i = 0; i < 10; ++i)
	{
		counter.upCount();
	}
	cout << "Count after loop is: " << counter.getCount() << endl;
	
	counter.setCount(-1);
	
}//end main

/* Results:
The current count is: 10
The current count is: 9
Count after loop is: 19
Cannot set count below zero. Ending program

--------------------------------
Process exited after 1.117 seconds with return value 1
Press any key to continue . . .

*/
