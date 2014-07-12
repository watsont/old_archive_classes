// Program Shell2 reads characters from file DataIn and 
// writes them to DataOut with the following changes:             
//    all letters are converted to uppercase, digits are
//    unchanged, and all other characters except blanks and         
//    newline markers are removed.                                       

#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;

enum CharType {LO_CASE, UP_CASE, DIGIT, BLANK_NEWLINE, OTHER};

enum CharType  kindOfChar(char);
// Gets the enumerator equivalent to its character input.

int main ()
{
    ifstream  dataIn;
    ofstream  dataOut;
    char  character;

    dataIn.open("ReFormat.dat");
    dataOut.open("DataOut.dat");

    dataIn  >> character;    // priming read
    while (dataIn)
    {
	switch (kindOfChar(character))
	{

	  // FILL IN THE Code to output the correct character

	}
	dataIn  >> character;
    }
    return 0;
}


/*************************************************/

enum CharType  kindOfChar(char character)
// Post: character is converted to the corresponding
//       constant in the enumeration type CharType.
{
    if (isupper(character))
	return  UP_CASE; // TO BE FILLED IN
    else if (islower(character))
        return LO_CASE; // TO BE FILLED IN 
    else if isdigit(character)
        return DIGIT; // TO BE FILLED IN                                                   
    else if (character == ' ' || character == '\n')
        return  BLANK_NEWLINE;// TO BE FILLED IN               
    else
        return OTHER; // TO BE FILLED IN
}

