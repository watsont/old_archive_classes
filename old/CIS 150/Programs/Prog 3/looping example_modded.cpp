#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

string Randomizer();
void MakeGuess (char characterComp);

int main()
{
    string wordToGuess;
    wordToGuess = Randomizer();
    cout << wordToGuess << endl;
    
    char inputLetter;
    MakeGuess(inputLetter);
    int numLetters = wordToGuess.length();
    cout << numLetters << endl;
 
 
 system("pause");
 return 0;   
}



//*****************************************************************************
string Randomizer()
{
    string wordToGuess;
    ifstream chooseRandWord;
    srand(time(NULL));
    string randWord;
    int count = 0;
    int randCount;
    randCount = rand()%12 +1;
    
    chooseRandWord.open("wordList.txt");
    
    
    while (count < randCount)
    {
    //cout << endl << count << endl << randCount << endl;                   //Remove comments to test if loop is works properly
    
      chooseRandWord >> randWord;    
    
    count++;      
    }
   // cout << randWord << endl;
    chooseRandWord.close();

 return randWord;   
}
//*****************************************************************************

void MakeGuess (char characterComp)
{
     cout << "The word is " << characterComp << " .\n";
     cout << "Please enter a letter \n";
     
     
     
     
     
     
     
     
     
return;     
}
