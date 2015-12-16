/*

class String{
		char *s_ptr;		//ptr to heap
		int len;
      public:
		String( ); 		//default constructor - empty string
		String(char *);	//parameterized constructor
		~String();		//destructor
		String(const String &rhs);		//copy constructor
	//accessor & mutators
		int getLen( );			//get length of string
		void setLen(int );		//reset length of string
     //overloaded operators
		String & operator=(const String & rhs);  //string assignment (copy)
		String operator+(const String & rhs);     //concatenate strings
                 bool operator==(const String & rhs);     //identical strings ???
		 char operator[ ](int spot);		        //retrieve nth letter
                 friend 
		ostream &operator<<(ostream &out, const String & Rhs);

	//other member functions
                 char * find(char target);		        //target finder
		
		
};

Demonstrate the following capabilities
	String S1("To be or not to be");
	String S2("that is the question");
	String S3;
	S3 = S1 + S2;
     cout << "S1 = " << S1 << " S2 = " << S2;
	cout << "S3";

	bool T = (S1 == S2);

     int offset = 7;
	cout << "S1[offset] = " << S1[offset] << endl;

	//modify the letter 'o' in S1 to be 'u'

"	For the above problem you can use the string functions contained within <string.h> (e.g. strlen( ), strcat( …. ) , etc

*/

class String{
		char *s_ptr;//ptr to heap
		int len;
	public:
		//constructors/destructor
		String( ); 		//default constructor - empty string
		String(char *);	//parameterized constructor
		~String();		//destructor
		String(const String &rhs);		//copy constructor
		
		//accessor & mutators
		int getLen( );			//get length of string
		void setLen(int );		//reset length of string
		
		//overloaded operators
		String & operator=(const String & rhs);  //string assignment (copy)
		String operator+(const String & rhs);     //concatenate strings
		bool operator==(const String & rhs);     //identical strings ???
		char operator[ ](int spot);		        //retrieve nth letter

		friend ostream &operator<<(ostream &out, const String & Rhs);
	
	//other member functions
	char * find(char target);		        //target finder
    }
    
int main()
{
	String S1("To be or not to be? ");
	String S2("That is the question");
	String S3;
	S3 = S1 + S2;
	cout << "S1 = " << S1 <<s1[offset] << endl;
	//modify the letter 'o' in S1 to be the letter 'u'
	
}

//function definitions
String::String()
{//Default constructor
	
}
String::String(char * rhs)
{//parametrized constructor
	
}
String::String(const String &rhs)
{//copy constructor
	
}
String::~String()
{//Destructor
	delete s_ptr;
}

int String::getLen()
{
	return len;
}
void String::setLen(int Len)
{
	len = Len;
}
String & operator=(const String & rhs)  //string assignment (copy)
{
	
}
String operator+(const String & rhs)    //concatenate strings
{
	strcat(s_ptr,rhs.s_ptr);
}
bool operator==(const String & rhs)     //identical strings ???
{
	if(len != rhs.getLen())
	{//if not equal length, strings not equal!
		return false;
	}
	else
	{
		for(int i = 0; i < len;++i)
		{
			if(s_ptr[i] != rhs.s_ptr[i])
			{
				return false;
			}
			else
			{
				return true;
			}
		}
	}
}
char operator[ ](int spot)		        //retrieve nth letter
{
	char result = *s_ptr[spot];
	
	return result;
}
