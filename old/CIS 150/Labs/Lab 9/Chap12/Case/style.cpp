//*****************************************************************
// Style Program
// A stylistic analysis of the following features of text is 
// computed:
//   number of words
//   average word length
//   number of sentences
//   average sentence length
//   number of uppercase letters
//   number of lowercase letters
//   number of digits 
// To save space, we omit from each function the precondition 
// comments that document the assumptions made about valid input 
// parameter data. These would be included in a program intended 
// for actual use.                                                                          
//*****************************************************************

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

enum Features {UPPER, LOWER, DIGIT, IGNORE, EOW, EOS};

// Function prototypes
void OpenFiles(ifstream&, ofstream&);
Features Decode(char character);
void ProcessCharacter(char, int&, int&, int&, int&, int&, int&);
void PrintTable(ofstream& table, int, int, int, int, int, int);

int main()
{
    // Prepare files for reading and writing
    ifstream text;
    ofstream table;
    OpenFiles(text, table);
  
    char character;                 // Input character	
  
    // Declare and initialize counters
    int uppercaseCounter = 0;
    int lowercaseCounter = 0;
    int digitCounter = 0;
    int wordCounter = 0;
    int sentenceCounter = 0;
    int ignoreCounter = 0;

  
    text.get(character);            // Input one character
    do
    { // Process each character
        ProcessCharacter(character, uppercaseCounter, 
            lowercaseCounter, digitCounter, sentenceCounter,
            wordCounter, ignoreCounter);
        text.get(character);          // Input one character  
    } while (text);                                              
    
    PrintTable(table, uppercaseCounter, lowercaseCounter,
        digitCounter, sentenceCounter, wordCounter, ignoreCounter);
  text.close();
  table.close();
  return 0;
}

//******************************************************************        

Features Decode( /* in */ char character ) // Character decoded

// Function Decode examines the character and returns its type
// Postcondition:
//     Return value is the enumerated type to which character
//     belongs

{
    if (isupper(character))
        return UPPER;  
    else if (islower(character))
        return LOWER;  
    else if (isdigit(character))
        return DIGIT;    
    else 
        switch  (character)
        {
            case '.'  :
            case '?'  :
            case '!'  :  return EOS;
                     
            case ' '  :
            case ','  :
            case ';'  :
            case ':'  :  
            case '\n' :  return EOW;
      
        }
    return IGNORE;  
}
    
//****************************************************************** 

void OpenFiles( /* inout */ ifstream& text,   // Input file
                /* inout */ ofstream& table ) // Output file

// Function OpenFiles reads in the names of the input file and the 
// output file and opens them for processing; input file name is
// written on the output file
// Postcondition:
//     Files have been opened AND the input file name has been
//     written on the output file

{
    string inFileName;
    string outFileName;
    cout << "Enter the name of the file to be processed" << endl;
    cin >> inFileName; 
    text.open(inFileName.c_str());
    cout << "Enter the name of the output file" << endl;
    cin >> outFileName;
    table.open(outFileName.c_str());
    table << "Analysis of characters on input file " << inFileName 
          << endl << endl;
}

//******************************************************************        

void PrintTable
    ( /* inout */ ofstream& table,      // Output file
      /* in */ int uppercaseCounter,    // Uppercase letters
      /* in */ int lowercaseCounter,    // Lowercase letters 
      /* in */ int digitCounter,        // Digits
      /* in */ int sentenceCounter,     // '.', '?', '!' 
      /* in */ int wordCounter,         // Words 
      /* in */ int ignoreCounter )      // Everything else

// Function PrintTable prints the percentages represented by each
// of the five categories
// Postcondition:
//     The output has been written on file table, appropriately
//     labeled

{
    int totalAlphaNum;
    totalAlphaNum = uppercaseCounter + lowercaseCounter 
        + digitCounter;
  
    // Print results on file table 
    table << "Total number of alphanumeric characters: " 
          << totalAlphaNum << endl;    
    table << "Number of uppercase letters: " << uppercaseCounter 
          << endl;
    table << "Number of lowercase letters: " << lowercaseCounter 
          << endl;
    table << "Number of digits: " << digitCounter << endl;  
    table << "Number of characters ignored: " << ignoreCounter 
          << endl;                          
  
    // Add number of end-of-sentence markers to the word count  
    wordCounter = wordCounter + sentenceCounter;
    
    // Write rest of results on file table
    table << "Number of Words: " <<  wordCounter << endl;
    table << "Number of Sentences: " << sentenceCounter << endl;
    table << "Average word length: " << fixed << setprecision(2) 
          << float(totalAlphaNum)/ wordCounter  << endl;
    table << "Average sentence length: " << fixed << setprecision(2) 
          << float(wordCounter) / sentenceCounter << endl;
  
}   

//*****************************************************************        

void ProcessCharacter
    ( /* in  */   char character,       // Character to be 
                                        // processed
      /* inout */ int& uppercaseCounter, // Uppercase letters
      /* inout */ int& lowercaseCounter, // Lowercase letters 
      /* inout */ int& digitCounter,     // Digits
      /* inout */ int& sentenceCounter,  // '.', '?', '!' 
      /* inout */ int& wordCounter,      // Words 
      /* inout */ int& ignoreCounter )   // Everything else

// Function ProcessCharacter examines character and increments the
// appropriate counter.
// Postcondition:
//     The category to which the character belongs has been 
//     incremented

{
    static bool endOfWord = false;

    switch (Decode(character))
    {
        case UPPER :  uppercaseCounter++;
                      endOfWord = false;
                      break;
        case LOWER :  lowercaseCounter++;
                      endOfWord = false;
                      break;
        case DIGIT :  digitCounter++;  
                      endOfWord = false;
                      break;
        case EOW   :  if (!endOfWord)
                      {
                          wordCounter++;
                          endOfWord = true;
                      }  
                      break;
        case EOS   :  sentenceCounter++;
                      break;
        case IGNORE:  ignoreCounter++;
                      break;            
    }   
}

