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
    inData.open("Looping.d2");

    counter = 1;
    sum = 0;
    
   for (counter = 1; counter <=10; counter++)
    {
       inData >> value;
       sum = sum + value;
    }   
   
    cout << "The first sum is "  << sum  << endl;
       
    inData >> value;
    sum = 0;
    do
      {
          sum = sum + value;
          inData >> value;
      } while(value >=0);
      
    cout << "The second sum is " << sum << endl;
    
    system("PAUSE");
    return 0;
}
