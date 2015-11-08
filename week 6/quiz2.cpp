/*
Intermediate CPP
Fall 2015
Michael Lowry
11/11/2015

QUIZ #2

Problem Statement:

"	Create a class X that contains four member functions, with 0, 1, 2, and 3 int arguments, respectively. 
"	Create a main( ) that makes an object of your class and calls each of the member functions. 
"	Now modify the class so it has instead a single member function with all the arguments defaulted. Does this change your main( )?

*/

#include <iostream>
using namespace std;

class X 
{
	int value1;
	int value2;
	int value3;
	
	public:
	void setval(); //sets all values to zero
	void setval(int value1); //sets first value
	void setval(int value1, int value2); //sets first two values
	void setval(int value1, int value2, int value3); //sets all values
	
	void outputVal();
};


int main () 
{
	//instantiate an object of class x
	X x_obj;
	//call member function 1
	x_obj.setval(); //set all values of the function to zero
	x_obj.outputVal();
	//call member function 2
	x_obj.setval(1);
	x_obj.outputVal();
	//call member function 3
	x_obj.setval(1,2);
	x_obj.outputVal();
	//call member function 4
	x_obj.setval(1,2,3);
	x_obj.outputVal();
}

//function definitions
void X::setval()
{
	value1 = 0;
	value2 = 0;
	value3 = 0;
}

void X::outputVal(){
	
cout << "value1 = " << value1 << "\tvalue2 = " << value2 << "\tvalue3 = " << value3 << endl;

}

void X::setval(int Value1)
{
	value1 = Value1;
}

void X::setval(int Value1, int Value2)
{
	value1 = Value1;
	value2 = Value2;
}

void X::setval(int Value1, int Value2, int Value3)
{
	value1 = Value1;
	value2 = Value2;
	value3 = Value3;
}

/*
RESULTS:

value1 = 0      value2 = 0      value3 = 0
value1 = 1      value2 = 0      value3 = 0
value1 = 1      value2 = 2      value3 = 0
value1 = 1      value2 = 2      value3 = 3

--------------------------------
Process exited after 0.08243 seconds with return value 0
Press any key to continue . . .

*/
