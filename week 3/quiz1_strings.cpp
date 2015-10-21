/*
Intermediate CPP
Fall 2015
Michael Lowry
10/20/2015

QUIZ #1

Problem Statement:
You are given a character string  containing the following prose: 
"To be or not to be - that is the question: 
Whether 'tis nobler in the mind to suffer the slings 
and arrows of outrageous fortune, or to take arms 
against a sea of troubles and, by opposing, end them. To die, to sleep"

Write a program that contains the following functions:
1.	Calculates the length of the string ( int len stringLength( char string[ ]) 
2.	Calculates the number of times that a white space appears ( int symbol( char string[], char symbol)
3.	Reuse the above function to find out how many times the word "the" appears (int symbol( char string[], char *symbol)

PS - Do not use any  of the  <string.h>  functions except strcmp(char *, char *)
*/



#include <iostream>
#include <string.h>

//#define DEBUG

using namespace std;

int stringLength(char string[]);
//int symbol(char string[], char symbol);
int symbol(char string[], char symbol[]);

int main(){
//feed the computer Shakespeare
char string[] = "To be or not to be - that is the question: \
Whether 'tis nobler in the mind to suffer the slings and arrows of outrageous fortune, \
or to take arms against a sea of troubles and, by opposing, end them. To die, to sleep";

//calculate the length of the string
int length = stringLength(string);
cout << "The length of the prose is: " << length << ".\n\n";

#ifdef DEBUG
cout << "type some garbage #: ";
int garbage(0);
cin >> garbage;
#endif

//calculate the number of times a space appears
char derp[] = " ";
int numSpaces = symbol(string, derp);
cout << "There are "<< numSpaces << " spaces in the prose.\n\n";

#ifdef DEBUG
cout << "type some garbage #: ";
garbage = 0;
cin >> garbage;
#endif

//reuse the overloaded function to look for a word
char word[] = " the ";
int numWords = symbol(string, word);
cout << "There are " << numWords << " instances of the word: \"" << word << "\" in the prose.\n\n";

return 0;
}

int stringLength(char string[])
{
	int count = 0; 
	
	while((string[count])!='\0')	
	{//start a while loop that counts elements
		++count;
	}//end while
	
	return count;
}

int symbol(char string[], char symbol[])
{
	int symbolCount = 0;
	
	int wordLen = stringLength(symbol);
	#ifdef DEBUG
	cout << "wordLen = " << wordLen << endl;
	#endif
	
	int count = 0;
	int val = 0;
	
		
	char* temp;
	temp = new char [wordLen];
	
	while(string[count] != '\0')
	{
		for (int i = 0; i < wordLen; i++)
		{
			temp[i] = string[i + count];
		}
		temp[wordLen] = '\0';
				
		#ifdef DEBUG
		cout << "temp = " << temp[0] << endl;
		#endif

		val = strcmp(temp,symbol);
		#ifdef DEBUG
		//debug statements
		cout << "\ncount = " << count << endl;
		cout << "symbolCount = " << symbolCount << endl;
		cout << "\nstrings being compared: \n\n\"" << symbol << "\"\n\n\"" << temp  << "\"\n\n";
		cout << "val = " << val << "\n\n";
		#endif
		if (val == 0)
		{
			symbolCount++;
			#ifdef DEBUG
			cout << "incrementing counter for word match!" << endl;
			cout << "symbolCount = " << symbolCount << endl;
			#endif
			#ifdef DEBUG
			cout << "type some garbage #: ";
			int garbage = 0;
			cin >> garbage;
			#endif
			
		}
		else 
		{
			#ifdef DEBUG
			cout << "No increment of symbolCount" << endl;
			#endif
			#ifdef DEBUG
			cout << "type some garbage #: ";
			int garbage = 0;
			cin >> garbage;
			#endif
		}
		count++;
	}
	
	delete temp;
	
	return symbolCount;
}


/* RESULTS:

The length of the prose is: 216.

There are 43 spaces in the prose.

There are 3 instances of the word: " the " in the prose.


--------------------------------
Process exited after 1.085 seconds with return value 0
Press any key to continue . . .

*/
