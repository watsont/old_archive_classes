#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int main()
{
    int countRandom = 0;
    //int countLineNumber =0;
    int lineNumber =0;
    ifstream randomWord;
    string toGuessWord;
    
    srand(time(NULL));
 
    while (countRandom < 12)                  //Does not take the first random number
    {
          int lineNumber = rand()%12 +1;
          cout << lineNumber << endl;    
          countRandom++;
    }
 
    while(countLineNumber <= lineNumber)
    {
          int countLineNumber =0;
          randomWord.open("wordList.txt");
          if(!randomWord)
          {    
               cout << endl
                    << "Error! Filecould not be read. "
                    << endl;
               system("pause");
               return 1;
          }
          randomWord >> toGuessWord;
          cout << endl << toGuessWord << endl;
                     
                     
          countLineNumber++;           
    }
    
 system("pause");   
 return 0;
}
