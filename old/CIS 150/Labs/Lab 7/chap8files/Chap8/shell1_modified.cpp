// Program Shell1 is for investigating the differences between
// automatic and static variables.

#include <iostream>
using namespace std;

void  TestLocals();

int main ()
{
    TestLocals ();
    TestLocals ();
    TestLocals ();
    
    system("PAUSE");
    return 0;
}

// ***************************************

void  TestLocals()
{
    int count = 1;
    
    cout << count;
    count++;
}

