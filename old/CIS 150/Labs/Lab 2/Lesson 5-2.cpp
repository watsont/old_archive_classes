// Program Shell1 prints appropriate messages based on a
// grade read from the keyboard.

#include <iostream>
using namespace std;

int main ()
{
    int grade;
    
    cout << "Enter an integer grade between 50 and 100."
         << "  Press return. " << endl;
         cin >> grade;
         
         if (grade>= 80)
            cout << "Congratulations!" << endl;
         else if (grade < 70)
            cout << "Try harder" << endl;
         else if (grade <= 80 && grade > 70)
            cout << "Average" << endl;
            
         system("PAUSE");
         return 0;
}
