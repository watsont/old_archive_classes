// Program Box writes a box using periods.
#include <iostream>
#include <iomanip>
using namespace std;

void WriteBox();
// Post: Writes a box (20 x 4) of dots on the screen. 


int main()
{   
    cout << "A box: " << endl;
    WriteBox();
    cout << "Box has been drawn." << endl;
    return 0;
}
//********************************************
void WriteBox()              			 // name of the action
// Post: A box (20 x 4) is printed using periods.

{                         			 // begin action
  cout << "...................." << endl;
  cout << "." << setw(19)  << "."  << endl;
  cout << "." << setw(19)  << "."  << endl;
  cout << "...................." << endl;
}						// end action
