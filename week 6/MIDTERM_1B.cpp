/* 
Intermediate CPP
Fall 2015
Michael Lowry
11/11/2015

MIDTERM PART 1_A

PROBLEM STATEMENT
1.	Write the following program
b.	A C++ program, Point.cpp,  that declares the following Point structure

struct Point{
	int X, Y;	//position
	float R;	// radius - distance from origin 

// member functions
	void setData(int u, int v);
float getRadius()const;
void ScalePoint( int scale);

};
The program contains the following Accessor member functions:

"	The program should create a Point P1 at X=3, Y=4;
"	The program should output Radius of P1
"	The program should scale point P1 by 5
"	The program should output the Radius of scaled P1
"	

*/

#include <iostream>
#include <math.h>
using namespace std;

struct Point
{
	private:
		
		int X,Y; //Position
		float R; //radial distance from Origin
		
	public:
		
		//mutator and accessor function prototypes for Struct Point
		void setData(int u, int v)
		{
			X = u;
			Y = v;
			R = sqrt(u*u + v*v);
		};
		float getRadius()const{return R;};
		void ScalePoint(int scale){X *= scale; Y *= scale; R = sqrt(X*X + Y*Y); };
		void printPoint()const{	cout << "The Point values are: \nX = " << X << "\tY = " << Y << "\tR = " << R << endl;};
};

int main()
{
	//create point P1 where X = 3, Y = 4
	Point P1;
	P1.setData(3,4);
	//output the Radius of P1
	P1.printPoint();
	//Scale P1 by 5
	P1.ScalePoint(5);
	//Output the scaled radius of P1
	P1.printPoint();
}

/*
RESULTS: 

The Point values are:
X = 3   Y = 4   R = 5
The Point values are:
X = 15  Y = 20  R = 25

--------------------------------
Process exited after 0.01267 seconds with return value 44
Press any key to continue . . .
*/
