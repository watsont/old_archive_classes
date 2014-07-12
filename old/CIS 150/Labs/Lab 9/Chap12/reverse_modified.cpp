// Program Reverse reads numbers into an array
// and prints them out in reverse order.   

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 10;

int main ()
{
    int  numbers[MAX];
    ifstream  inData;
    int  value;
    int  index;

    inData.open("reverse.dat");
    for (index = 0; index < MAX; index++)
    {
        inData >> numbers[index];
        value = value + numbers [index];
    }
    
    for (index = MAX - 1; index >= 0; index--)
        cout << numbers[index] << endl;
        cout << "The sum of the values stored in numbers is "
             << value << " ." << endl;
        
    system("PAUSE");
    return 0;
}

