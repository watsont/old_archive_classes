#include <iostream>
#include <climits>

using namespace std;

int main()
{
    cout << "Here is INT_MAX \t" << INT_MAX << ": " << endl
         << "Here is 1 + INT_MAX \t" << 1 + INT_MAX << ": " <<endl
         << "Here is 1 + (- INT_MAX) " << 1 + (- INT_MAX) << ": " <<endl
         << "Here is 1 -INT_MAX \t" << 1 - INT_MAX << ": " << endl
         << "Here is 1- (-INT_MAX)) \t" << 1 - (- INT_MAX) << ": " << endl;
    
    cout << "Also, here is INT_MIN \t" << INT_MIN << ": " << endl;
    
 system("PAUSE");
 return 0;   
}
