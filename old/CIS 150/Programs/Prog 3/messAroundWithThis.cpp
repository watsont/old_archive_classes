#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;
int main()
{
   int count = 0;
   int randomizer = 0;
   int lineNumber = 0;
   ifstream inGuess;
  
   srand(time(NULL));
   
      while (!inGuess.eof())
      {
         inGuess.open("wordList.txt");
         
         while (count < 100)
         {
            cout << rand()%12 +1 << endl;    
            count++;
   
           
         }
      }
 system("pause");   
 return 0;   
}


//Random initializer portion


         srand(time(NULL));
         
         
int randomizer(int   )
{      
         while (count < 12)                    //Doesn't take the first "random"
                                               //number
         {
            rand()%12 +1 >> lineNumber;    
            cout << lineNumber << endl;
            count++;
         }
}
