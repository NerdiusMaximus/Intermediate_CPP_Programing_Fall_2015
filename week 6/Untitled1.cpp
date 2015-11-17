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
	cout << "\nVector X Initialization\nVectorX;" << endl;
	Vector X;
	X.VectorPrint();
	
	cout << "\nVector Y Initialization \nVector Y(8,10);" << endl;
	Vector Y(8,10);
	Y.VectorPrint();
	
	cout << "\nVector X Resize\nX.resize(16);" <<endl;
	X.resize(16);
	X.VectorPrint();
	
	cout << "\nX.pop_front( );" << endl<<endl;
	X.pop_front( );
	X.VectorPrint();
	
	cout << "\nX.pop_back( );" << endl<<endl;
	X.pop_back( );
	X.VectorPrint();
	
	cout << "\nY.push_front(100);" << endl<<endl;
	Y.push_front(100);
	Y.VectorPrint();
	
	cout << "\nSetting 10th Value of Vector Y to -99" <<endl;
	Y.setValue(10,-99);
	Y.VectorPrint();
	
	
	cout << "\nSetting 9th Value of Vector Y to -99" <<endl;
	Y.setValue(9,-99);
	Y.VectorPrint();

	cout << "\nY.push_back(100);" <<endl;
	Y.push_back(100);
	Y.VectorPrint();

	cout << "\nX.VectorConcat(Y);" <<endl;
	X.VectorConcat(Y);
	X.VectorPrint();
	
	cout << "\nY.VectorPrint(12);" <<endl;
	Y.VectorPrint(12);
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
	#ifdef DEBUG
	cout << "Activating Copy Constructor..." << endl;
	#endif
	size = rhs.size;
	capacity = rhs.capacity;
	ptr = new int[rhs.capacity + 1]; //make a deep copy with a new pointer to the heap
}
//Destructor Definition
Vector::~Vector()
{
	#ifdef DEBUG
	cout << "Activating Destructor..." << endl;
	#endif
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
	#ifdef DEBUG
	cout << "Getting Capacity..." << endl;
	#endif
	return capacity;
}
int Vector::getSize()const
{
	#ifdef DEBUG
	cout << "Getting Size..." << endl;
	#endif
	return size;
}
void Vector::setValue(int element, int value)
{
	if(element > size)
	{
		cout << "\nWARNING: Cannot set value. There are only " << size << " elements. Cannot set element " << element << endl;
		cout << "Element not set. Vector remains unchanged" << endl;
	}
	else if (element <= size)
	{
		//store the value in the element (accounting for the fact that elements start from 0)
		*(ptr + (element-1)) = value;
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
	
	//if the capacity needs to be increased, add 8 first
	if (size+1 >= capacity){capacity+=8;}
	size ++;
	//put the value into the end of the vector
	*(ptr + size-1) = value;
	//increment the size of the vector to account for the new element
}
void Vector::push_front(int value)
{//add the value to the front of the vector (re-mapping all the rest)
	//if the capacity needs to be increased, add 8 first
	if (size+1 >= capacity){capacity+=8;}
	
	//create new temporary array to store values
	int* temp = new int[size+1];
	//
	for(int i = 0; i <= size+1; ++i)
	{
		temp[i] = *(ptr + i); //store the values of ptr into temp
	}
	//increment the size of the vector to account for the new element
	size ++;
	
	ptr[0] = value;//store value into the first element of ptr
	
	for(int i = 0; i<= size; ++i)
	{
		ptr[i+1] = temp[i];//store values from temp into ptr
	}
	delete [] temp; //free heap memory
}
int Vector::pop_back()
{//delete the first element from the back of the vector
	ptr[size] = 0;//zero out the last element
	size --;//decrement the size
}
int Vector::pop_front()
{//deletes the first element from the front of the vector
	//create new temporary array to store values
	int* temp = new int[size];
	for(int i = 0; i <= size; ++i)
	{
		temp[i] = *(ptr + i); //store the values of ptr into temp
	}
	
	for(int i = 0; i<= size-1; ++i)
	{
		ptr[i] = temp[i];//store values from temp into ptr
	}	
	//decrease size by one
	size--;
	
	delete [] temp; //free heap memory
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
	cout << "Vector Output first " << length << " elements:"<< endl;
	cout << "Size = " << size << endl;
	cout << "Capacity = " << capacity << endl;
	cout << "Vector elements: " << endl;
	for (int i = 0; i <= length; ++i)
	{
		if(i >= size){
			cout << "There are only " << size << " elements. Here are the first " << size << " elements. "<<endl;
			break;
		};
		cout << *(ptr + i) << "\t";
	}
	cout << endl << endl << "End output\n" << endl << endl;
}
void Vector::VectorConcat(const Vector & rhs)
{//concatenate rhs vector to existing vector
	#ifdef DEBUG
	cout << "Vector Concatenate..." << endl;
	#endif	
	int* temp = new int[size + rhs.size]; //create temp value to re-map values to new heap pointer
	//add the values from the left hand size object vector to the temp array
	
	for (int i = 0; i <= size; ++i)
	{
		*(temp + i) = *(ptr + i);
	}
	//take values from RHS and jam into LHS
	
	for (int i = 0; i <= rhs.size; ++i)
	{
		temp[size + i ] = rhs.ptr[i];
	}
	capacity = capacity + rhs.capacity; //make capacity larger
	size = size + rhs.size; //make vector larger
	
	//reassign ptr to temp 
	ptr = temp;
	
}
/*
Vector X Initialization
VectorX;
Default Constructor
Vector Output
Size = 0
Capacity = 16
Vector elements:
End output
Vector Y Initialization
Vector Y(8,10);
Overloaded Constructor
Vector Output
Size = 8
Capacity = 24
Vector elements:
10      10      10      10      10      10      10      10
End output
Vector X Resize
X.resize(16);
Begin resize method...
size = 16
this -> size = 0
Default Case:
 if(this -> size < size)
Vector Output
Size = 16
Capacity = 32
Vector elements:
0       0       0       0       0       0       0       0       0       0
0       0       0       0       0       0
End output
X.pop_front( );
Vector Output
Size = 15
Capacity = 32
Vector elements:
0       0       0       0       0       0       0       0       0       0
0       0       0       0       0
End output
X.pop_back( );
Vector Output
Size = 14
Capacity = 32
Vector elements:
0       0       0       0       0       0       0       0       0       0
0       0       0       0
End output
Y.push_front(100);
Vector Output
Size = 9
Capacity = 24
Vector elements:
100     10      10      10      10      10      10      10      10
End output
Setting 9th Value of Vector Y to -99
Vector Output
Size = 9
Capacity = 24
Vector elements:
100     10      10      10      10      10      10      10      -99
End output
Y.push_back(100);
Vector Output
Size = 10
Capacity = 24
Vector elements:
100     10      10      10      10      10      10      10      -99     0
End output
X.VectorConcat(Y);
Vector Concatenate...
Vector Output
Size = 24
Capacity = 56
Vector elements:
0       0       0       0       0       0       0       0       0       0
0       0       0       0       0       100     10      10      10      10
10      10      10      -99
End output
Y.VectorPrint(12);
Vector Output first 12 elements:
Size = 10
Capacity = 24
Vector elements:
100     10      10      10      10      10      10      10      -99     0
100     There are only 10 elements. Here are the first 10 elements.
End output
Activating Destructor...
Activating Destructor...
--------------------------------
Process exited after 0.1118 seconds with return value 0
Press any key to continue . . .
*/
