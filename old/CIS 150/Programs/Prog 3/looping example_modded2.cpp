/*
                


*/
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

string Randomizer();
//Post condition: function generates a random number; opens wordList.txt
//and selects a word.
void MakeGuess (int characterComp);
//Pre condition: word in file should have been read correctly.
//Post condition: function compares input from user to the randomly
//selected string.

bool FileFail (int);

int main()
{
    string wordToGuess;
    wordToGuess = Randomizer();
    bool fileRead;
    char inputLetter;
    int numLetters;
    
    cout << wordToGuess << endl;            //This is the word to be guessed
    
   
    fileRead = FileFail(status);
    
    if (fileRead == true)
        cout << "The program has been terminated." << endl;
    else
    {
     
    numLetters = wordToGuess.length();
    cout << "There are " << numLetters << " letters in the word."<< endl;
 
    MakeGuess(numLetters);
    }
 system("pause");
 return 0;   
}



//*****************************************************************************
string Randomizer()
//Post: Generates a random number and then looks up a word
{
    string wordToGuess;
    ifstream chooseRandWord;
    srand(time(NULL));
    string randWord;
    int count = 0;
    int randCount;
    randCount = rand()%12 +1;
    
    chooseRandWord.open("wordList2.txt");
    if(!chooseRandWord)
    {    
         cout << "Error! Filecould not be read. " << endl;
         FileFail(int FileFail) = 1;
    }
    else
    {
        while (count < randCount)
        {
        chooseRandWord >> randWord;    
        count++;      
        }
    }
    chooseRandWord.close();

 return randWord;   
}
//*****************************************************************************

void MakeGuess (int characterComp)
{
     int undsCount = 0;
     
     
     cout << "The word is ";
     
     while(undsCount < characterComp)
     {
         cout <<"_ ";
         undsCount++;
     }
     
     
     cout << endl
          << "Please enter a letter \n";
     
     
     
     
     
     
     
     
     
return;     
}
