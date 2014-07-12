// Program Convert converts a temperature in Fahrenheit to 
// Celsius or a temperature in Celsius to Fahrenheit
// depending on whether the user enters an F or a C..

#include <iostream>
using namespace std;

int  ConvertedTemp(int, char);

int main ()
{
    char  letter;		// Place to store input letter
    int  tempIn;		// Temperature to be converted

    cout  << "Input Menu"  << endl  << endl;
    cout  << "F:  Convert from Fahrenheit to Celsius"  << endl;
    cout  << "C:  Convert from Celsius to Fahrenheit"  << endl;
    cout  << "Q:  Quit"  << endl;
    cout  << "Type a C, F,  or Q; then press return."  << endl;

    cin  >> letter;
    
    switch (letter)
    {
           case 'q' :
           case 'Q' : 
                break;
           case 'c' :
           case 'C' :
           case 'F' :
           case 'f' :
                break;
           default: cout << "Sorry, " << letter << " is not an expected input\n"
                         << "character. Please try again.\n" << endl
                         << "Type a C, F,  or Q; then press return." << endl;
                         cin  >> letter;
                   break;
    }
    
    while (letter != 'Q' && letter != 'q')
    {
    
    cout << endl;
    cout  << " Type an integer number, and press return."
	      << endl;
	cin  >> tempIn;
    
	if (letter == 'F' || letter == 'f')
	    cout << "Fahrenheit to Celsius"  << endl;
	else
	    cout << "Celsius to Fahrenheit"  << endl;
	cout  << "Temperature to convert: "  << tempIn
	      << endl;
	cout  << "Converted temperature:  "
	      << ConvertedTemp(tempIn, letter)
	      << endl  << endl;
	cout  << "Type a C, F,  or Q; then press return."
	      << endl;

	cin  >> letter;
    }
    
    return 0;
}

// *******************************************

int  ConvertedTemp(int tempIn, char letter)
{
    if (letter == 'C' || letter == 'c')
        return (9 * tempIn / 5) + 32;
    else
        return 5 * (tempIn - 32) / 9;
}

