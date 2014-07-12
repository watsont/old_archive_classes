#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

int main()
{
    
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
    cout << randWord;
    chooseRandWord.close();
    
 system("pause");   
 return 0;   
}
