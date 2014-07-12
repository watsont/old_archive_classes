// Program Shell 3 prints appropriate messages based
// on a pressure reading read from a file.  Processing
// continues until the plant is evacuated when a pressure
// greater than 100 is read.


#include <iostream>
#include <fstream>
using namespace std;

int main ()

{
    int  pressure;
    int count;
    ifstream  data;
    
    count = 0;
    data.open("shell3.d4");
    
    while(data && count<60)
    {

	data  >> pressure;
    
       if(pressure < 0)
            {
                   cout << "Error in input.\n";
                   count++;
            }
       else if(pressure >=0 && pressure < 50)
            {
                        cout << "Pressure in the normal range.\n";
                        count++;
                        }
       else if(pressure >=50 && pressure < 100)
            {
                        cout << "Pressure on the high side\n";
                        count++;
            }
    }

       if (pressure >= 100)
           cout <<"Evacuate plant!!!!\n";
      
       if(count < 60)
           {
           cout << endl << "Insufficient data. "
                        << "Program terminated after " << count << " readings.\n";
           }           
    
    system("pause");
    return 0;
}


