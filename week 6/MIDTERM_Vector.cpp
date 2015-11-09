/* 
Intermediate CPP
Fall 2015
Michael Lowry
11/11/2015

MIDTERM PART 2

PROBLEM STATEMENT
2.	Write a program that emulates the STL  integer Vector class.  The  Vector class should have the following format:

class Vector{
	int size;
	int capacity;  	//make sure to be generous
     int * ptr;		//pointer to heap
public:
//Vector Constructors & Destructors
	Vector();		//constructor - creates zero length vector
	Vector(int Size, int Value = 0);  //overloaded constructor
	~Vector();			//destructor
	Vector(Vector & rhs);  	// copy constructor
//Accessor/Mutators
	int getSize()const;
	int getValue(int element);
     int getCapacity();
	void setValue(int element, int value);
	    //other member functions
                    void resize(int size, int value = 0); //resize vector and init new values
                    void push_back(int value);  
		void push_front(int value)
                    int pop_back();
                    int pop_front();
void VectorPrint( );	//prints the entire vector
                      void VectorPrint(int length);	//prints the first length elements
//concatenate rhs vector to existing vector
                      void VectorConcat(const Vector & rhs);  
};
Demonstrate that the following cases work:
(i)	Vector X(8);
(ii)	Vector Y(8,10);
(iii)	X.resize(16)
(iv)	X.pop_front( );
(v)	X.pop_back( );
(vi)	Y.push_front(100);
(vii)	Y.setValue(10,-99);
(viii)	Y.push_back(100);
(ix)	X.VectorConcat(Y);
(x)	X.Print();
(xi)	Y.Print();
(xii)	Y.Print(12);
*/

#include <iostream>
using namespace std;

class Vector{
	private://added for good measure (but not required)
	int size;
	int capacity;  	//make sure to be generous
    int * ptr;		//pointer to heap
	public:
	//Vector Constructors & Destructors
	Vector();		//constructor - creates zero length vector
	Vector(int Size, int Value = 0);  //overloaded constructor
	~Vector();			//destructor
	Vector(Vector & rhs);  	// copy constructor
	//Accessor/Mutators
	int getSize()const;
	int getValue(int element);
    int getCapacity();
	void setValue(int element, int value);
	//other member functions
    void resize(int size, int value = 0); //resize vector and init new values
    void push_back(int value);  
	void push_front(int value)
    int pop_back();
    int pop_front();
	void VectorPrint( );	//prints the entire vector
    void VectorPrint(int length);	//prints the first length elements
	//concatenate rhs vector to existing vector
    void VectorConcat(const Vector & rhs);  
};

int main()
{
	//Demonstrate that the following cases work:
	//	Vector X(8);
	//	Vector Y(8,10);
	//	X.resize(16)
	//	X.pop_front( );
	//	X.pop_back( );
	//	Y.push_front(100);
	//	Y.setValue(10,-99);
	//	Y.push_back(100);
	//	X.VectorConcat(Y);
	//	X.Print();
	//	Y.Print();
	//	Y.Print(12);
}

//Constructor Definitions
Vector::Vector()//default constructor
{
	
}
Vector::Vector(int size, int value = 0)//overloaded constructor
{
	
}
Vector::Vector(Vector& rhs)//copy constructor
{
	
}
//Destructor Definition
Vector::~Vector()
{
	
}
//Accessor/Mutator Function Definitions
int Vector::getCapacity()const
{
	
}
int Vector::getValue(int element)
{
	
}
int Vector::getCapacity()
{
	
}
void Vector::setValue(int element, int value)
{
	
}
//other member functions
void Vector::resize(int size, int value = 0)//resize vector and init new values
{
	
}
void Vector::push_back(int value)
{
	
}
void Vector::push_front(int value)
{
	
}
int Vector::pop_back()
{//deleted the first element from the back of the vector
	
}
int Vector::pop_front()
{//deletes the first element from the front of the vector
	
}
void Vector::VectorPrint( )
{//prints the entire vector
	
}
void Vector::VectorPrint(int length)
{//prints the first length elements
	
}
void Vector::VectorConcat(const Vector & rhs)
{//concatenate rhs vector to existing vector
	
}
