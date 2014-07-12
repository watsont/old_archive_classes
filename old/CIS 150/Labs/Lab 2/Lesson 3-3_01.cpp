// Program Numbers sends numbers to the output stream in 
// specified formats. 

#include <iostream>
#include <iomanip>
using namespace std;

const int a = 1066;
const int b = 1492;
const int c = 512;
const int d = 1;
const int e = -23;

int main ( )

{ 
		cout<< fixed << showpoint << setw(1) << a;
		cout<< fixed << showpoint << setw(1) << b; 
		cout<< fixed << showpoint << setw(1) << c; 
		cout<< fixed << showpoint << setw(1) << d; 
		cout<< fixed << showpoint << setw(1) << e; 
		return 0;
}
