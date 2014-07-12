// Program Looping uses a count-controlled loop to read and 
// sum 10 integer values and an event-controlled loop to 
// read and sum values until a negative value is found.  
// The data is on file Looping.dat.                      

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    ifstream  inData;
    int  value;
    int  counter;
    int  sum;
    inData.open("Looping.dat");

    counter = 1;
    sum = 0;
    while (counter <= 10)
    {// ten values read and summed
        inData  >> value;
        sum = sum + value;
        counter++;
    }
    cout  << "The first sum is "  << sum  << endl;
    
    inData  >> value;
    sum = 0;
    while (value >= 0)
    {// values are read and summed until a negative is read
        sum = sum + value;
        inData  >> value;
    }
    cout  << "The second sum is "  << sum  << endl;
    system("PAUSE");
    return 0;
} 
