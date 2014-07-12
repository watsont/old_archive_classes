// Program Shell2 prints appropriate messages based on a
// pressure reading input from the keyboard.

#include <iostream>
using namespace std;

 
int main ()
{
    int  pressure;

    cout << "Enter an integer pressure reading. "
	 << " Press Return."  << endl;
    cin >> pressure;

   if( pressure > 5 && pressure <100)
   {
        cout << "Everything seems normal. \n";
        
   }
    
    system("pause");
    return 0;
}
