// Program ReFormat reads characters from file DataIn and 
// writes them to DataOut with the following changes:             
//    all letters are converted to uppercase, digits are
//    unchanged, and all other characters except blanks and         
//    newline markers are removed.                                       

#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;

int main ()
{
    ifstream  dataIn;
    ofstream  dataOut;
    char  character;

    dataIn.open("ReFormat.dat");
    dataOut.open("DataOut.dat");

    dataIn.get(character);    // priming read
    while (dataIn)
    {
	    if (islower(character))
	    {
	        toupper(character);
	        dataOut << character;
	    }
        else if (isupper(character) || isdigit(character) || (character == ' ') 
            || (character == '\n'))
	            <<  dataOut  << character;
	    
	dataIn.get(character);
    }
    return 0;
}

