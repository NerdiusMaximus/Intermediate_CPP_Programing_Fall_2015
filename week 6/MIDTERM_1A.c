/* 
Intermediate CPP
Fall 2015
Michael Lowry
11/11/2015

MIDTERM PART 1_A

PROBLEM STATEMENT
1.	Write the following program
a.	 C program,  Point.c , that declares the following Point structure

struct Point{
	int X, Y;	//position
	float R;	// radius - distance from origin
};
The program contains the following Accessor functions:
"	void setData(struct Point*, int u, int v)
"	float getRadius(struct Point*);
"	void ScalePoint(struct Point *, int scale)

"	The program should create a Point P1 at X=3, Y=4;
"	The program should output Radius of P1
"	The program should scale point P1 by 5
"	The program should output the Radius of scaled P1
*/

#include <stdio.h>
#include <math.h>
struct Point
{
	int X,Y; //Position
	float R; //radial distance from Origin
};
//mutator and accessor function prototypes for Struct Point
void setData(struct Point*, int u, int v);
float getRadius(struct Point*);
void ScalePoint(struct Point*, int scale);

void printPoint(struct Point*);

int main()
{
	//create point P1 where X = 3, Y = 4
	struct Point P1;
	struct Point* P1_ptr = &P1;
	setData(P1_ptr, 3,4);
	//output the Radius of P1
	printPoint(P1_ptr);
	//Scale P1 by 5
	ScalePoint(P1_ptr,5);
	//Output the scaled radius of P1
	printPoint(P1_ptr);
}

void printPoint(struct Point* Point_ptr)
{
	printf("The Point values are: \nX = %i\tY = %i\tR = %g\n", Point_ptr -> X, Point_ptr ->Y,getRadius(Point_ptr));
}

//Function Definitions
void setData(struct Point* Point_ptr, int u, int v)
{
	Point_ptr -> X = (float)u;
	Point_ptr -> Y = (float)v;
	Point_ptr -> R = sqrt(u*u + v*v);
}
float getRadius(struct Point* Point_ptr)
{
	return Point_ptr -> R;
}
void ScalePoint(struct Point* Point_ptr, int scale)
{
	Point_ptr -> X = scale * (Point_ptr -> X);
	Point_ptr -> Y = scale * (Point_ptr -> Y);
	//recompute radius
	float u = Point_ptr -> X;
	float v = Point_ptr -> Y;
	Point_ptr -> R = sqrt(u*u + v*v);
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
