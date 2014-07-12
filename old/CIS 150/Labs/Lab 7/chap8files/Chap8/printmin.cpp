// Program PrintMin prints the smallest of three input values.

#include <iostream>
using namespace std;

int  Minimum(int, int, int);	// function prototype
// Post: Minimum returns the minimum of three distinct values.

int main()
{
    int  one;
    int  two;
    int  three;
    cout  << "Input three integer values.  Press return." << endl;
    cin  >> one  >> two  >> three;
    cout  << "The minimum value of "  << one  << ", "  << two
	  << ", and "  << three  << " is "
	  << Minimum(one, two, three)  << "."  << endl;
    return 0;
}

//*****************************************************

int  Minimum(int first, int second, int third)
// Post: Returns minimum of three distinct int values.
{
    if (first < second && first < third)
	return first;
    else if (second < first && second < third)
	return second;
    else if (third < first && third < second)
	return third;
}


