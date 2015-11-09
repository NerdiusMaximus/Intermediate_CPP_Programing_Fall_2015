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
#define DEBUG

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
	void setValue(int element, int value);// KEY TO ALL OTHERS
	//other member functions
    void resize(int size, int value = 0); //resize vector and init new values
    void push_back(int value);  
	void push_front(int value);
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
	Vector X;
	cout << "Vector X Init" << endl;
	X.VectorPrint();
	
	Vector Y(8,10);
	cout << "Vector Y Init" << endl;
	Y.VectorPrint();
	
	X.resize(16);
	cout << "Vector X Resize" <<endl;
	X.VectorPrint();
	//	X.pop_front( );
	//	X.pop_back( );
	//	Y.push_front(100);
	//	Y.setValue(10,-99);
	//	Y.push_back(100);
	//	X.VectorConcat(Y);
	
	
	//	Y.Print(12);
}

//Constructor Definitions
Vector::Vector()//default constructor
{
	cout << "Default Constructor" << endl;
	size = 0; //default zero length vector
	capacity = 16;
	int* temp = new int[capacity+1];
	ptr = temp;
	
}
Vector::Vector(int size, int value)//overloaded constructor
{
	this -> size = size;
	cout << "Overloaded Constructor" << endl;
	capacity = size + 16; //first attempt: add 16 to every size for capacity. Could add size /2 to size...
	int* temp = new int[capacity+1];
	ptr = temp;
	//initialize vector values
	for (int i = 0; i < size; ++i)
	{
		*(ptr + i) = value;
	}
	
}
Vector::Vector(Vector& rhs)//copy constructor
{
	cout << "Activating Copy Constructor..." << endl;
	size = rhs.size;
	capacity = rhs.capacity;
	ptr = new int[rhs.capacity + 1];
}
//Destructor Definition
Vector::~Vector()
{
	cout << "Activating Destructor..." << endl;
	delete [] ptr; //free heap memory
	ptr = NULL; //safe the pointer
}
//Accessor/Mutator Function Definitions
int Vector::getValue(int element)
{
	cout << "Reterning element # " << element << endl;
	return *(ptr + element); //dereference the pointer plus element to return the int value
}
int Vector::getCapacity()
{
	cout << "Getting Capacity..." << endl;
	return capacity;
}
int Vector::getSize()const
{
	cout << "Getting Size..." << endl;
	return size;
}
void Vector::setValue(int element, int value)
{
	if(element < size) //base case for recursive method
	{
		*(ptr + element) = value;
	}
	if(element > size && element < capacity){
		//call resize function and then set element (can do recursive?)
		resize(size,value);
		setValue(element, value);
	}
	else if(element > capacity)
	{
		//call resize function and then set element (can do recursive?)
		resize(size,value);
		setValue(element,value);
	}
}
//other member functions
void Vector::resize(int size, int value)//resize vector and init new values
{
	#ifdef DEBUG
	cout << "Begin resize method..." << endl;
	cout << "size = " << size << endl;
	cout << "this -> size = " << this -> size << endl;
	#endif
	if (this -> size < size){
		#ifdef DEBUG
		cout << "Default Case: \n if(this -> size < size)" << endl;
		#endif
		this -> size = size;
		capacity = size + 16;
		//create new int pointer to array of new sizes
		int* temp = new int[capacity];
		//copy values from existing int array to new array
		for (int i = 0; i < this -> size; ++i)
		{
			*(temp + i) = value;// Need to decide what to do here
			//Should values be initialized to 0 if and only if there are 0 length to start?
			//or should they contain the former values of the vector if size > 0?
		}
		//dump new values into temp
		for (int i = 0; i < size;++i)
		{
			*(temp + size + i) = value;
		}
		//re-assign pointer to new heap array
		ptr = temp;
		
		//delete [] temp;//clean up heap memory
	}
	else if (this->size > size && size >= 0)
	{
		#ifdef DEBUG 
		cout << "Case: this->size > size && size >= 0" << endl;
		#endif
		cerr << "Error: Resizing a Vector to a smaller value can truncate data" << endl;
		exit(1);
	}
	else if (size <0)
	{
		#ifdef DEBUG
		cout << "Case: size < 0" << endl;
		#endif
		cerr << "Error: Cannot create negative length vector" << endl;
		exit(2);
	}
	
}
void Vector::push_back(int value)
{//add the value to the back of the vector
	if (size+1 >= capacity){capacity+=8;}
	*(ptr + size+1) = value;
	size ++;
}
void Vector::push_front(int value)
{//add the value to the front of the vector (re-mapping all the rest)
	
}
int Vector::pop_back()
{//deleted the first element from the back of the vector
	
}
int Vector::pop_front()
{//deletes the first element from the front of the vector
	
}
void Vector::VectorPrint( )
{//prints the entire vector
	cout << "Vector Output" << endl;
	cout << "Size = " << size << endl;
	cout << "Capacity = " << capacity << endl;
	cout << "Vector elements: " << endl;
	for (int i = 0; i < size; ++i)
	{
		cout << *(ptr + i) << "\t";
	}
	cout << endl << endl << "End output" << endl;
}
void Vector::VectorPrint(int length)
{//prints the first length elements
	cout << "Vector Output first " << length << "elements:"<< endl;
	cout << "Size = " << size << endl;
	cout << "Capacity = " << capacity << endl;
	cout << "Vector elements: " << endl;
	for (int i = 0; i < length; ++i)
	{
		cout << *(ptr + i) << "\t";
	}
	cout << endl << endl << "End output" << endl;
}
void Vector::VectorConcat(const Vector & rhs)
{//concatenate rhs vector to existing vector
	cout << "Vector Concatenate..." << endl;
	//call resize function to rezie current vector to size = size + rhs.size
	resize(size + rhs.size, 0);
	//push_back() each element of rhs onto this vector
	for (int i = 0; i < size; ++i)
	{
		*(ptr + i) = *(rhs.ptr + rhs.size + i);
	}
}
