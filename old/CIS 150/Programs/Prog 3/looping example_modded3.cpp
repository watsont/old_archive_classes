/*
        Written by Watson Tong
                06/
                Program 3: Hangman
                Revised: 
        
        The purpose of this program is to continue to build on C++ skills.
        This time, we are using functions to create a hangman program that
        a0sd0fasd0fas9f
*/
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

string Randomizer();                                  //Prototype
//Post condition: function generates a random number; opens wordList.txt
//and selects a word.
void MakeGuess (int characterComp);                   //Prototype
//Pre condition: word in file should have been read correctly.
//Post condition: function compares input from user to the randomly
//selected string.

int main()
{
    string wordToGuess;
    int numLetters;
    
    
    wordToGuess = Randomizer();           //This is the word to be guessed
    cout << wordToGuess << endl;            
    
    //char inputLetter; 
    
    numLetters = wordToGuess.length();
    cout << "There are " << numLetters << " letters in the word."<< endl;
 
    MakeGuess(numLetters);
 
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
    
    chooseRandWord.open("wordList.txt");
   
   /*
    if(!chooseRandWord)
    {    
         cout << "Error! Filecould not be read. " << endl;
         ;
    }
    else
    {*/
        while (count < randCount)
        {
        chooseRandWord >> randWord;    
        count++;      
        }
    //}
    chooseRandWord.close();

 return randWord;   
}
//*****************************************************************************

void MakeGuess (int characterComp)
{
    string display;
    string word;
    char letter;
    int position ;
    int count;
 
    /*
    cout<<"gimme a word ";
    cin >> word;
    cout<<"gimme a letter ";
    cin>> letter;   
    position = word.find(letter);
    display = word;
    count = 0;
    */
 
    
    cout << "Please enter a letter. " << endl;                 //Start of try
 
 
    while (count < word.size())
    {
        display[count] = '_';
        count++; 
    }   
    if (position <= word.size())
        display[position] = letter;
   
    cout<<"the word is now ";
    count = 0;
    while (count <   
    display.size())
    {
        cout<<display[count]<<" ";
        count++;
    }
   
   
    cout<<endl;   

    return;     
}
