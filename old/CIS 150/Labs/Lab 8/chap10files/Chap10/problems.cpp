// Program Problems demonstrates some problems associated  
// with real arithmetic.                              

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    float  oneThird;
    float  one;
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);

    oneThird = 1.0 / 3.0;
    cout  << " 1/3 "  << setprecision(5)  << setw(7)  
          << oneThird  << endl;
    one = oneThird + oneThird + oneThird;
    cout  << " 1/3 + 1/3 + 1/3 "  << setw(7)
          << one  << endl;
    if (one == 1.0)
        cout  << "Result when used in test is 1.0."  
              << endl;
    else
        cout  << "Result when used in test is NOT 1.0."  
        << endl;
    system("PAUSE");
    return 0;
}
