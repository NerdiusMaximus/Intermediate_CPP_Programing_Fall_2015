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

Coeff1[  ] = {-19, 1, -12, 3, 2}
Coeff2[[ ] = {-19, 1, -7, 0, 0, 5, 0, 2}



Design and code a polynomial class in C++ that has the following properties:



class Poly{
private:
	int order;	//order of the polynomial
	int *coeff;	// pointer to array of coeff on the heap
			// size of coeff array predicated on (order + 1)

public:
	Poly( );		//default constructor - order=0 & coeff[0] =1
	Poly(int Order , int Default = 1) ;// creates  Nth order poly
                                       // and inits all coeffs
Poly(int Order, int *Coeff);  //creates an Nth polynomial & inits 
	 ~Poly( );		// destructor
	   :::::::                     // copy constructor

//mutators  & accessors
void set( ){// Query user for coefficient values);
void set(int coeff[ ], int size);  // input coeffs via external coeff vector
int getOrder( )const;  // get order of polynomial
int * get( ); 	      //returns pointer to coeff array

//overloaded operators
  Poly operator+( const Poly &rhs);		// add two polynomials
  Poly operator-( const Poly &rhs);		// subt two polynomials
  Poly operator*( const int scale);		// scale a  polynomial
	P2 = P1*scale
  Poly scale*Poly
	P2 = scale*P1
  Poly operator*(const Poly &rhs);		// mult two polynomials
  bool  operator==(const Poly &rhs);		// equality operator
  const int & operator[ ](int I)const;       // return the Ith coefficient
  int & operator[ ](int I);                 	// return the Ith coefficient

  int operator( )(int X);			// evaluate P(x) according 

  Poly & operator=(const Poly & rhs);
  friend ostream & operator<<(ostream & Out, const Poly &rhs);
  

//other member functions
};

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
		int & operator[ ](int I);                 	// return the Ith coefficient
		int operator( )(int X);			// evaluate P(x) according (to what?)
		Poly & operator=(const Poly & rhs);
		
		friend ostream & operator<<(ostream & Out, const Poly &rhs); //train cout how to print polynomials
	  
};

int main(){
	
	//Demonstrate the following operations for the following Polynomials:
	//P1(x) = 2x4 + 3x3 - 12x2 + x - 19 (4th order polynomial)
	//P2(x) = 2x7 + 7x5 - 6x2 + x - 19 (7th order polynomial)
	
	Poly P1, P2;
//	P1.set([2,3,12,1,19],4);
//	P2.set([1,0,7,0,0,6,1,-19],7);
	
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
	order = 0;
	coeff = new int[order+1];
	coeff[0]= 1;
}
Poly::Poly(int Order , int Default)// creates  Nth order poly and inits all coeffs
{
	order = Order; //copy order
	coeff = new int[order+1];
	for(int i = 0; i< order+1;++i)
	{
		coeff[i] = Default;
	}
	
}
Poly::Poly(int Order, int *Coeff)  //creates an Nth polynomial & inits
{
	
}
Poly::Poly(const Poly &rhs)// copy constructor
{
	
}
//Destructor
Poly::~Poly()	
{
	delete [] coeff; //delete all coeficients
	coeff = NULL; //safe pointer
	
}

//Function definitions
void Poly::set() //query the user for the values
{
	//get polynomial order
	cout << "Please enter the order of the polynomial:" << endl;
	cin >> order;
	cout << "The order you entered was: " << order << endl;
	//create heap array of ints of size order +1
	coeff = new int[order +1];
	for(int i = 0; i < order+1; ++i)
	{
		cout << "Please enter the " << i << " coefficient" << endl;
		cin >> coeff[i];
	}
	cout << "Input complete." << endl;
}
void Poly::set(int coeff[ ], int size)  // input coeffs via external coeff vector
{
	
}
int Poly::getOrder( )const  // get order of polynomial
{
	
}
int * Poly::get( )const 	      //returns pointer to coeff array
{
	
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
	
}
int & Poly::operator[ ](int I)                 	// return the Ith coefficient
{
	
}
int Poly::operator( )(int X)			// evaluate P(x) according (to what?)
{
	
}
Poly & Poly::operator=(const Poly & rhs)
{
	
}

ostream & operator<<(ostream & Out, const Poly &rhs) //train cout how to print polynomials
{
	for(int i = 0; i < order; ++i)
	{
		if (coeff[i]==0)
		{
			//dont print anything
			i++;
		}
		
		
		Out << coeff[i] << "X^" << order-i << " ";
		
	}
	Out << endl;
}
