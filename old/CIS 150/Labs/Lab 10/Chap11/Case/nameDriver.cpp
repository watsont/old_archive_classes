#include <iostream>
#include "Name.h"

using namespace std;

int main()
{
      Name name1("David", "John", "Jones");
      Name name2;
      string name1w = name1.FirstName() + ' ' + name1.MiddleName()
          + ' ' + name1.LastName();

      for (int count = 1; count <= 3; count++)
      {
          name2.ReadName();
          string name2w = name2.FirstName() + ' ' 
              + name2.MiddleName() 
              + ' ' + name2.LastName();

          switch (name1.ComparedTo(name2))
          {
	        case BEFORE : cout << name1w << " comes before " 
                                 << name2w << endl;
	                      break;
	        case SAME   : cout << name1w << " is the same as " 
                                 << name2w <<  endl;
	                      break;
	        case AFTER  : cout << name1w << " comes after " 
                                 << name2w << endl;                                
         }
		
    }
    return 0;
}
