/* 
Intermediate CPP
Fall 2015
Michael Lowry
12/15/2015

Final Exam Part 1

PROBLEM STATEMENT:
1.	Polynomials appear in a wide variety of areas of mathematics and science. 
For example, they are used to form polynomial equations, which encode a wide 
range of problems, from elementary word problems to complicated problems in the sciences; 
they are used in calculus and numerical analysis to approximate other functions; they 
are used in error-correction algorithms in communications systems.  A typical 
polynomial can be described as follows:

    	P(x) = 2x4 + 3x3 - 12x2 + x - 19 (4th order polynomial)
      or 
P(x) = 2x7 + 5x5 - 7x2 + x - 19 (7th order polynomial)

Where the coefficients for the first and second equations can be described 
by the following array of integers

Coeff1[ ] = {-19, 1, -12, 3, 2}
Coeff2[ ] = {-19, 1, -7, 0, 0, 5, 0, 2}

Demonstrate the following operations for the following Polynomials:
P1(x) = 2x4 + 3x3 - 12x2 + x - 19 (4th order polynomial)
P2(x) = 2x7 + 7x5 - 6x2 + x - 19 (7th order polynomial)

//display the following results  for the polynomials defined above
o	P3 = P1 + P2;
o	P3 = P2 - P1;
o	P3 = P1*P2;
o	P3 = P1*10;
o	P3 = 10*P1;
o	bool flag  = (P1==P2);
o	P1[3] = P2[5];	// assign the 5th coefficient of P2 to 3rd coefficient of P1
o	int Z = P1(int  X = 5);   // evaluate  Polynomial for input X
     // suggest using Horner's method
o	The displayed polynomial for P2 should be printed as follows
2X^7 + 7X^5 - 6X^2 + 1X - 1


*/
using namespace std;
#include <iostream>
#include <cmath>
#define DEBUG


class Poly{
	private:
		int order;	//order of the polynomial
		int *coeff;	// pointer to array of coeff on the heap
		// size of coeff array predicated on (order + 1)
	
	public:
		Poly();		//default constructor - order=0 & coeff[0] =1
		Poly(int Order , int Default = 1);// creates  Nth order poly and inits all coeffs
		Poly(int Order, int *Coeff);  //creates an Nth polynomial & inits 
		Poly(const Poly &rhs);// copy constructor
		~Poly();		// destructor
		//mutators  & accessors
		void set();// Query user for coefficient values);
		void set(int coeff[ ], int size);  // input coeffs via external coeff vector
		int getOrder()const;  // get order of polynomial
		int * get()const; 	      //returns pointer to coeff array
	
		//overloaded operators
		Poly operator+( const Poly &rhs);		// add two polynomials
		Poly operator-( const Poly &rhs);		// subt two polynomials
		Poly operator*( const int scale);		// scale a  polynomial
		//	P2 = P1*scale
		//	Poly scale*Poly
		//	P2 = scale*P1
		Poly operator*(const Poly &rhs);		// mult two polynomials
		bool  operator==(const Poly &rhs);		// equality operator
		const int & operator[ ](int I)const;       // return the Ith coefficient
//		int & operator[ ](int I);                 	// return the Ith coefficient
		int operator( )(int X);			// evaluate P(x) according to a value of X
		Poly & operator=(const Poly & rhs);
		
		friend ostream & operator<<(ostream & Out, const Poly &rhs); //train cout how to print polynomials
	  
};

int main(){
	
	//Demonstrate the following operations for the following Polynomials:
	//P1(x) = 2x4 + 3x3 - 12x2 + x - 19 (4th order polynomial)
	//P2(x) = 2x7 + 7x5 - 6x2 + x - 19 (7th order polynomial)
	
	Poly P1;
//	P1.set([2,3,12,1,19],4);
//	P2.set([1,0,7,0,0,6,1,-19],7);
	
	P1.set();
	cout << P1;
	cout << "If X = 5, the resulting solution is: " << P1(5) << endl;
	
	
	//
	////display the following results  for the polynomials defined above
	//o	P3 = P1 + P2;
	//o	P3 = P2 - P1;
	//o	P3 = P1*P2;
	//o	P3 = P1*10;
	//o	P3 = 10*P1;
	//o	bool flag  = (P1==P2);
	//o	P1[3] = P2[5];	// assign the 5th coefficient of P2 to 3rd coefficient of P1
	//o	int Z = P1(int  X = 5);   // evaluate  Polynomial for input X
	//     // suggest using Horner's method
	//
	//
	//o	The displayed polynomial for P2 should be printed as follows
	//2X^7 + 7X^5 - 6X^2 + 1X - 1
	
};

//Constructors
Poly::Poly() // Default Constructor- order=0 & coeff[0] =1
{
	#ifdef DEBUG
	cout << "Default Constructor." << endl;
	#endif
	order = 0;
	coeff = new int[order+1];
	coeff[0]= 1;
}
Poly::Poly(int Order , int Default)// creates  Nth order poly and inits all coeffs
{
	#ifdef DEBUG
	cout << "Paramaterized Constructor (ints)." << endl;
	#endif
	order = Order; //initialize order
	coeff = new int[order+1];
	for(int i = 0; i< order+1;++i)
	{
		coeff[i] = Default; //defailt the coefficient matrix to Default value
	}
	
}
Poly::Poly(int Order, int *Coeff)  //creates an Nth polynomial & inits
{
	#ifdef DEBUG
	cout << "Paramaterized Constructor (int and pointer)." << endl;
	#endif
	order = Order; // sets order from argument
	coeff = new int[order+1];
	for(int i = 0; i< order+1;++i)
	{
		coeff[i] = Coeff[i]; //defailt the coefficient matrix to Default value
	}
}
Poly::Poly(const Poly &rhs)// copy constructor
{
	#ifdef DEBUG
	cout << "Copy Constructor." << endl;
	#endif
	
}
//Destructor
Poly::~Poly()	
{
	#ifdef DEBUG
	cout << "Activating Destructor..." << endl;
	#endif
	delete [] coeff; //delete all coeficients
	coeff = NULL; //safe pointer
	
}

//Function definitions
void Poly::set() //query the user for the values
{
	//get polynomial order
	cout << "Please enter the order of the polynomial (int greater than 1):" << endl;
	cin >> order;
	
	if (order < 1)
	{
		cout << "Cannot have less than 1 order polynomial";
		exit(1);
	}
	cout << "The order you entered was: " << order << endl;
	//create heap array of ints of size order +1
	coeff = new int[order +1];
	for(int i = 0; i < order+1; ++i)
	{
		cout << "Please enter the order " << order - i << " coefficient" << endl;
		cin >> coeff[i];
	}
	cout << "Input complete." << endl;
}
void Poly::set(int coeff[ ], int size)  // input coeffs via external coeff vector
{
	
}
int Poly::getOrder( )const  // get order of polynomial
{
	return order;
}
int * Poly::get( )const 	      //returns pointer to coeff array
{
	return coeff;
}
//overloaded operators
Poly Poly::operator+( const Poly &rhs)		// add two polynomials
{
	
}
Poly Poly::operator-( const Poly &rhs)		// subt two polynomials
{
	
}
Poly Poly::operator*( const int scale)		// scale a  polynomial
{
	
}
	//P2 = P1*scale
	//Poly scale*Poly
	//P2 = scale*P1
Poly Poly::operator*(const Poly &rhs)		// mult two polynomials
{
	
}
bool  Poly::operator==(const Poly &rhs)		// equality operator
{
	
}
const int & Poly::operator[ ](int I)const       // return the Ith coefficient
{
	return coeff[I];
}
//int & Poly::operator[ ](int I)                 	// return the Ith coefficient
//{
//	
//}
int Poly::operator( )(int X)			// evaluate P(x) according (to what?)
{
	int sum = 0; //init sum to hold accumulated number
	for(int i = 0; i < order; ++i)
	{
		sum += coeff[i] * pow(X,order-i);
	}
	sum += coeff[order]; // add the last integer
	
	return sum;
}
Poly & Poly::operator=(const Poly & rhs)
{//assign one polynomial object to another
	order = rhs.order;
	for(int i = 0; i< order + 1; ++i)
	{
		coeff[i] = rhs.coeff[i];
	}
}

ostream & operator<<(ostream & Out, const Poly &rhs)
{//Train cout how to use the stream insert operator to print polynomial objects
	for(int i = 0; i < rhs.order + 1; ++i)
	{
		if (rhs.coeff[i]==0)
		{//if coefficient is zero
			//dont print anything
			i++;//advance counter to the next coeff if zero found
		}
		if (i == 0)
		{//if is first coeff, leave off + 
			if(rhs.coeff[i] > 0)
			{//if positive
				Out << rhs.coeff[i] << "X^" << rhs.order-i << " ";
			}
			else if(rhs.coeff[i] < 0)
			{//if negative
				Out << rhs.coeff[i] << "X^" << rhs.order-i << " ";
			}
		}
		
		//if coeff is not the end nor the first
		if (i < rhs.order -1 && i > 0)
		{
			if(rhs.coeff[i] > 0)
			{//if positive
				Out << "+ " << rhs.coeff[i] << "X^" << rhs.order-i << " ";
			}
			else if(rhs.coeff[i] < 0)
			{//if negative
				Out << rhs.coeff[i] << "X^" << rhs.order-i << " ";
			}
		}
		if(i == rhs.order - 1)
		{//if coeff is second to last, leave out the ^1
			if(rhs.coeff[i] > 0)
			{//if positive
				Out << "+ " << rhs.coeff[i] << "X" << " ";
			}
			else if(rhs.coeff[i] < 0)
			{//if negative
				Out << rhs.coeff[i] << "X" << " ";
			}
		}
		
		if(i == (rhs.order) && rhs.order != 0)
		{//if is the last coeff and non zero
			if (rhs.coeff[i] > 0)
			{	
				Out << "+ " << rhs.coeff[i]; //output without the "X^"
			}
			else if (rhs.coeff[i] < 0)
			{
				Out << rhs.coeff[i]; //output without the "X^"
			}
		}
		
	}
	Out << endl;
}