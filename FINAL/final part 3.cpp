/*
3. Create a C++ program that contains the following classes
		
int daysMonth[12] ={31, 28,31,30,
31,30,30,31,30,31,30,31}; 

class Date{
		private:
			int day, month,year;

			static int day_cnt;
			static int monthsYear;
		public:
			//constructors &destructors
			Date;
			Date(int Day, int Month, int Year);
			~Date(){
			Date(const Date & rhs);
			// mutators & accessors
			 
			int calcDiff( const Date &Today);
	};

class Bond{	
		private:
			char *name;	// name of bond
			float value;
			Date purchaseDate;
			Date maturityDate;
			Date Today;
			Bond();
		public:
//Constructors & use initialization list
Bond(char *Name, int Value, Date d1, Date d2);
~Bond()	//Destructor
//Accessors & Mutators
void setToday( Date & hoy);
//Methods
int CalcDaysMaturity(Date &hoy );
};  //end of class	

	int Date::monthsYear = 12;
	int Date::day_cnt = 0;

int main()
{
	Date Purchase1(2,28,2012);
	Date Maturity1(12,31,2025);
	Date Purchase2(7,27,2017);
	Date Maturity2(17,31,2035);
        Date Today(12,4,2015);
	Bond Y("NYC_Obligation", 885.0, Purchase1, Maturity1);
Bond *bond_ptr = new Bond( "GW_Bridge_Obligation",895.0, Date(7,27,2017),Date(17,31,2035) );

	return 0;
}

o	Bond X( );   // forbidden
o	Bond  Y("NYC_Obligation", 885.0, Purchase, Maturity);
o	Bond *bond_ptr = new Bond("GW_Bridge_Obligation", 895.0, Purchase, Maturity)
o	int days = Y.calcDaysToMaturity(Today);

Develop the code for the above class, debug and test.  
*/

using namespace std;
#include <iostream>

//globals
int daysMonth[12] ={31, 28,31,30,
31,30,30,31,30,31,30,31}; 

class Date{
	private:
		int day, month, year;
		static int day_cnt;
		static int monthsYear;
	public:
		//constructors &destructors
		Date();
		Date(int Day, int Month, int Year);
		~Date();
		Date(const Date & rhs);
		// mutators & accessors
		int calcDiff( const Date &Today);
	};

class Bond{	
	private:
		char *name;	// name of bond
		float value;
		Date purchaseDate;
		Date maturityDate;
		Date Today;
		Bond(); //default constructor is private; no bond object can be created without data
	public:
		//Constructors & use initialization list
		Bond(char *Name, int Value, Date d1, Date d2);
		//Destructor
		~Bond();	
		//Accessors & Mutators
		void setToday( Date &hoy);
		//Methods
		int CalcDaysMaturity(Date &hoy);
		
};  //end of class	

//static variables for date class
int Date::monthsYear = 12;
int Date::day_cnt = 0;

int main()
{
	//date formatted as day, month, year
	Date Purchase1(2,28,2012);
	Date Maturity1(12,31,2025);
	Date Purchase2(7,27,2017);
	Date Maturity2(17,31,2035);
    Date Today(12,4,2015);
	Bond Y("NYC_Obligation", 885.0, Purchase1, Maturity1);
	Bond *bond_ptr = new Bond( "GW_Bridge_Obligation",895.0, Date(27,7,2017),Date(31,7,2035) );

	return 0;
}

//function definitions

//Date class function definitions
Date::Date()
{//Default constructor
	day = 1;
	month =1;
	year = 1;
	day_cnt ++;
}
Date::Date(int Day, int Month, int Year)
{//Parametrized Constructor
	day = Day;
	month = Month;
	year = Year;
	day_cnt ++;
}
Date::~Date()
{//Destructor
	day_cnt --;
}
Date::Date(const Date & rhs)
{//Copy Constructor
	month = rhs.month;
	day = rhs.day;
	year = rhs.year;
	day_cnt++;
}
int Date::calcDiff( const Date &Today)
{
	//NEED TO DETERMINE HOW MANY DAYS WITHIN EACH MONTH 
	int diff = 0;
	Date temp;
	temp.day= day - Today.day;
	temp.month = month - Today.month;
	temp.year = year - Today.month;
	
	//determine total number of days
	diff = Temp.day +  Temp.month * 
	
	return diff;
}

//Bond class function definitions
Bond::Bond(char *Name, int Value, Date d1, Date d2)
{//parameterized constructor
	
	name = Name;
	value = Value;
	purchaseDate = d1;
	maturityDate = d2;
	
}
Bond::~Bond()
{//destructor
	
}

void Bond::setToday( Date & hoy)
{
	Today = hoy;
}
int Bond::CalcDaysMaturity(Date &hoy )
{
	
}

