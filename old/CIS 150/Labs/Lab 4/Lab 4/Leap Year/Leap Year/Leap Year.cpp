#include "stdafx.h"
#include <iostream>
#include <fstream>  //for filestream data
using namespace std;

bool isLeapYear( int year );   //prototype for Boolean function

int main()
{

	ifstream yearFile;
	int theYear = 0;

	yearFile.open("years.txt");


	while(!yearFile.eof())
	{
		yearFile >> theYear;
		
		if(isLeapYear(theYear))
			cout << theYear << " is a leap year." << endl;
		else
			cout << theYear << " is not a leap year." << endl;

	}
	// Add code here to * LOOP * through the different years
	// and determine if each year is a leap year or not
	// if it is, print out "the year <the actual year> is a leap year"
	// if it is not, print out "the year <the actual year> is NOT a leap year"
	// PRINT to the monitor / console

	yearFile.close();


	return 0;
}

// ----- determine whether an input YEAR is a leap year or not
bool isLeapYear( int year )
{
	if (year % 4 !=0)
	{
		//if NOT divisible by 4, it is not a leap year
		return false;
	}
	else if (year % 100 != 0)  //year IS divisible by 4, AND NOT by 100
	{
		return true;
	}
	else if (year % 400 != 0)   //year NOT divisible by 400
	{
		return false;
	}
	else
	{
		return true;
	}

}