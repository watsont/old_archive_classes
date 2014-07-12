#include <iostream>

using namespace std;

const int MAX = 26;

int main ()
{
    int  CharCounter[MAX];
    int  index;

    for (index = 0; index < MAX; index++)
    {
        CharCounter[index] = 0;
    }
    
    for (index = 0; index < MAX; index++)
        cout << CharCounter [index] << endl;
 
        
    system("PAUSE");
    return 0;
}

