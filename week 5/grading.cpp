/* 

Intermediate CPP
Fall 2015
Michael Lowry
10/20/2015

Week 4 hw

Programming Project #1

Problem Statement: 
Write a grading program for a class with the following grading policies:
a. there are two quizzes, each graded on the basis of 10 points.
b. there is one midterm exam and one final exam, each graded on the basis of 100 points.
c. The final exam counts for 50% of the grade, the midterm counts for 25%, and the two
quizzes together count for a total of 25%. (Do not forget to n ormalize the quiz scores. 
They should be converted to a percentage before being averaged in).

Any grade of 90 or more is an A, any grade 80 or more (but less than 90) is a B, any 
grade 70 or more but less than 80 is a C, any grade of 60 or more (but less than 70) is a D, 
and any grade below 60 is an F. The program will read in the student's scores and output the 
student's record, which consists of two quiz and two exam scores as well as the student's 
average numeric score for the entire course, and final letter grade. Define and use a 
structure for the student record.

*/

#include <iostream>
using namespace std;

struct student{
	
	int quiz1;
	int quiz2;
	int midterm;
	int final;
	
	double final_grade;
	char letter_grade;
	
};

int main(){
	
	
	
}//end main
