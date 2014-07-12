// Program Problems demonstrates some problems associated  
// with real arithmetic.                              

#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
    float  oneTenth;
    float  one;
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);

    oneTenth = 1.0 / 10.0;
    cout  << " 1/10 "  << setprecision(5)  << setw(7)  
          << oneTenth  << endl;
    one = oneTenth + oneTenth + oneTenth + oneTenth + oneTenth + oneTenth + oneTenth + oneTenth + oneTenth + oneTenth;
    cout  << " 1/10 (10 times) "  << setw(7)
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
