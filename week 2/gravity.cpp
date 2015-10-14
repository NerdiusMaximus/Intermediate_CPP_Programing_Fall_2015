/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/14/2015

Week 2 hw

Programming Project #4

Problem Statement: 
The gravitational attractive force between two bodies with masses m1 and m2 seperated 
by a distance d is given by the following formula: 

F = (G*m1*m2)/(d^2)

where G is the universal gravitational constant: 

G = 6.673x10-8 cm^3/(g*sec^2)

Write a function definition that takes arguments for the masses of the two bodies and
the distance between them and returns the gravitational force between them. Since you
will use the above formula, the gravitational force will be in dynes. One dyne equals a

1 dyne = (g*cm)/(sec^2)

You should use a globally defined constant for the universal gravity constant. Embed
your function definition into a complete program that computes the gravitational force
between two objects given suitable inputs. Your program should allow the user to repeat
the calculation as often as the user wishes.

*/
#include <iostream>
using namespace std;

#define G 6.673e-8

double gravity(double m1, double m2, double d);

int main(){
	
	while(1){
		double m1(0);
		double m2(0);
		double d(0);
		char cont = 0;
		
		cout << "\nPlease enter the mass of body one: ";
		cin >> m1;
		
		cout <<"\nPlease enter the mass of body two: ";
		cin >> m2;

		cout <<"\nPlease enter the distance between the masses: ";
		cin >> d;
		
		cout << "\nThe gravitational force is: " << gravity(m1,m2,d) << " dynes.";
		
		cout << "\n\nWould you like to continue?\n(Type N to quit, any letter to continue): ";
		cin >> cont;
		
		if (cont== 'N' || cont == 'n'){
			break;
		}
		
		//reset constants
		m1 = 0;
		m2 = 0;
		d = 0;
		cont = 0;
		
	}//true loop
	
	cout << "\n\n Program Complete! Look up for falling apples.\n";
}

double gravity(double m1, double m2, double d){
	
	double answer = (G*m1*m2)/(d*d);
	return answer;
}
/* Results:


Please enter the mass of body one: 10000.2

Please enter the mass of body two: 20000.4

Please enter the distance between the masses: 100

The gravitational force is: 0.00133465 dynes.

Would you like to continue?
(Type N to quit, any letter to continue): y

Please enter the mass of body one: 5000000.00

Please enter the mass of body two: 10000000.00

Please enter the distance between the masses: 1000.0

The gravitational force is: 3.3365 dynes.

Would you like to continue?
(Type N to quit, any letter to continue): n


 Program Complete! Look up for falling apples.

--------------------------------
Process exited after 72.83 seconds with return value 0
Press any key to continue . . .
*/
