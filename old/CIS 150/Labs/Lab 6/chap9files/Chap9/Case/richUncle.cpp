//******************************************************************
// Rich Uncle Program
// A table is printed to show the percentage of characters in the 
// file that belong to five categories: uppercase characters, 
// lowercase characters, decimal digits, blanks, and 
// end-of-sentence punctuation marks
// Assumptions: Input file is not empty and percentages are based 
// on total number of characters in the file   
// To save space, we omit from each function the precondition 
// comments that document the assumptions made about valid input 
// parameter data. These would be included in a program intended 
// for actual use.                                     
//******************************************************************

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// Function prototypes
void OpenFiles(ifstream&, ofstream&);
void IncrementCounter(char, int&, int&, int&, int&, int&, int&);
void PrintTable(ofstream& table, int, int, int, int, int, int);

int main()
{
    // Prepare files for reading and writing
    ifstream text;
    ofstream table;
    char character;
  
    // Declare and initialize counters
    int uppercaseCounter = 0;        // Number of uppercase letters
    int lowercaseCounter = 0;        // Number of lowercase letters
    int blankCounter = 0;            // Number of blanks
    int digitCounter = 0;            // Number of digits
    int punctuationCounter = 0;	     // Number of end '.', '?', '!'
    int allElseCounter = 0;          // Remaining characters
  
    OpenFiles(text, table);
    text.get(character);		// Input one character
    do 
    { // Process each character
        IncrementCounter(character, uppercaseCounter, 
            lowercaseCounter, blankCounter, digitCounter, 
            punctuationCounter, allElseCounter);
        text.get(character);
    } while (text);    
  
    PrintTable(table, uppercaseCounter, lowercaseCounter, 
        blankCounter, digitCounter, punctuationCounter, 
        allElseCounter);
      
    text.close();
    table.close();
    return 0;
} 

//******************************************************************        

void IncrementCounter
  ( /* in */    char character,         // Character being examined
    /* inout */ int& uppercaseCounter,  // Uppercase letters
    /* inout */ int& lowercaseCounter,  // Lowercase letters 
    /* inout */ int& blankCounter,      // Blanks
    /* inout */ int& digitCounter,      // Digits
    /* inout */ int& punctuationCounter, // '.', '?', '!' 
    /* inout */ int& allElseCounter )    // Everything else

// Function IncrementCounter examines character and increments the 
// appropriate counter
// Postondition:
//     The category to which the character belongs has been 
//     incremented

{
    if (isupper(character))
        uppercaseCounter++;
    else if (islower(character))
        lowercaseCounter++;
    else if (character == ' ')
        blankCounter++;
    else if (isdigit(character))
        digitCounter++;
    else if ((character == '.') || (character == '?') || 
             (character == '!'))
        punctuationCounter++;   
    else 
        allElseCounter++;
}

//******************************************************************        

void PrintTable
  ( /* inout */ ofstream& table,      // Output file
    /* in */ int uppercaseCounter,    // Uppercase letters
    /* in */ int lowercaseCounter,    // Lowercase letters 
    /* in */ int blankCounter,        // Blanks
    /* in */ int digitCounter,        // Digits
    /* in */ int punctuationCounter,  // '.', '?', '!' 
    /* in */ int allElseCounter )     // Everything else

// Function PrintTable prints the percentages represented by each
// of the five categories
// Postcondition:
//     The output has been written on file table, appropriately
//     labeled

{
    // Calculate total number of characters
    float total = uppercaseCounter + lowercaseCounter 
        + blankCounter + digitCounter + punctuationCounter 
        + allElseCounter;
  
    // Write output on stream table
    table << fixed << setprecision(3) 
          << "Percentage of uppercase characters: " 
          << uppercaseCounter / total * 100 << endl;
    table << fixed << setprecision(3) 
          << "Percentage of lowercase characters: "
          << lowercaseCounter / total* 100 << endl;
    table << fixed << setprecision(3) << "Percentage of blanks: "
          << blankCounter / total * 100 << endl;  
    table << fixed << setprecision(3) << "Percentage of digits: " 
          << digitCounter / total * 100 << endl;                         
    table << fixed << setprecision(3) 
          << "Percentage of end-of-sentence "
          << "punctuation " << punctuationCounter / total * 100 
          << endl;
}    
    
//****************************************************************** 

void OpenFiles( /* inout */ ifstream& text,   // Input file
                /* inout */ ofstream& table ) // Output file

// Function OpenFiles reads in the names of the input file and the 
// output file and opens them for processing.
// Postcondition:
//     Files have been opened AND the input file name has been

{
    string inFileName;      // User specified input file name
    string outFileName;     // User specified output file name
    cout << "Enter the name of the file to be processed" << endl;
    
    cin >> inFileName; 
    text.open(inFileName.c_str());
   
    cout << "Enter the name of the output file" << endl;
    cin >> outFileName;
    table.open(outFileName.c_str());
    
    // Write label on output file
    table << "Analysis of characters on input file " << inFileName 
          << endl;
}   

