// Program Numbers sends numbers to the output stream in 
// specified formats. 

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

string morning = "Good Morning";
string sarah = "Sarah";
string sunshine = "Sunshine!";
string myString;

int main ( )
{ 
  cout << setw(16) << morning << endl
  << endl << setw(12) << sarah <<endl
  << endl << setw(14) << sunshine << endl;

		system("PAUSE");
		return 0;
}

