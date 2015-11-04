/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/20/2015

Week 5 hw

Programming Project #3

Problem Statement: 
The type Point is a fairly simple data type, but under another name (the template class Pair) this data type 
is defined and used in the C++ Standard Template Library, although you need not know anything about the standard 
template library to do this excercise. Write a definition fo a class named Point that might be used to store and
manipulate the location of a point in the plane. You will need to delcare and implement the following member functions:

a. A member function set that sets the private data after an object of this class is created.

b. a member function to move the point by an amount along the vertical and horizontal directions specified by the
first and second arguments.

c. A member function to rotate the point 90 degrees clockwise about the origin

d. Two constant inspector functions to retrieve the current coordinates of the point. 

Document these functions with appropriate comments. Embed your class in a test program that requests data for several
points, creates the points, and then excercises the member functions.
*/

#include <iostream>
using namespace std;

//class definition
class Point{
	//Private data
	double x, y; //x and y coords of a point on a plane
	
	public: 
	//mutator functions
	void set(double X, double Y); //set data manually
	
	void translate(double X, double Y);//moves the points by x and y amounts in x and y directions
	
	void rotate90(); //roates 90 degrees clockwise about the origin
	
	//accessor functions 
	const double getx(); //get x value
	
	const double gety(); //get y value
	
};

int main(){		

	Point coord1; //declare a point
	char input(0);
	do{
		input = 0;
		double temp1 = 0, temp2 = 0;
		cout << "Please enter X and Y coordinates:\nX Value: ";
		cin >> temp1;
		cout << "\nY Value: ";
		cin >> temp2;
		coord1.set(temp1,temp2);
		cout << "\nYou entered: X = " << coord1.getx() << "\tY = " << coord1.gety() << endl;
		coord1.translate(coord1.getx()/2, coord1.gety()/2); //translate positive by half the disatance 
		cout << "Translating + half the value of coords...\nX = " << coord1.getx() << "\tY = " << coord1.gety() << endl;
		coord1.rotate90();
		cout << "Rotating by 90 clockwise...\n X = " << coord1.getx() << "\tY = " << coord1.gety() << endl;
		
		cout << "Enter anohter point? (Y/N): " << endl;
		cin >> input;
	}while(input == 'y' || input == 'Y');
}//end main

//function definitions
void Point::set(double X, double Y)
{
	//store user values into private object data
	x = X;
	y = Y;
}
void Point::translate(double X, double Y)
{
	//add translate amounts to each point
	x += X;
	y += Y;
}
void Point::rotate90()
{
	//change the sign of x coordinates
	x *= -1;
	//swith X and Y coordinates
	double temp = x; //store x in a temp variable
	x = y;//store y into x
	y = temp; //store y as the old x from temp
}
const double Point::getx()
{
	//access and return the current value of x
	return x;
}
const double Point::gety()
{
	//access and return the current value of y
	return y;
}

/* Results:
Please enter X and Y coordinates:
X Value: 12

Y Value: 4

You entered: X = 12     Y = 4
Translating + half the value of coords...
X = 18  Y = 6
Rotating by 90 clockwise...
 X = 6  Y = -18
Enter anohter point? (Y/N):
y
Please enter X and Y coordinates:
X Value: 12.567

Y Value: 8.345

You entered: X = 12.567 Y = 8.345
Translating + half the value of coords...
X = 18.8505     Y = 12.5175
Rotating by 90 clockwise...
 X = 12.5175    Y = -18.8505
Enter anohter point? (Y/N):
y
Please enter X and Y coordinates:
X Value: 25

Y Value: 36.5

You entered: X = 25     Y = 36.5
Translating + half the value of coords...
X = 37.5        Y = 54.75
Rotating by 90 clockwise...
 X = 54.75      Y = -37.5
Enter anohter point? (Y/N):
n

--------------------------------
Process exited after 44.29 seconds with return value 0
Press any key to continue . . .

*/
