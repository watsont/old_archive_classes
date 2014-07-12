//*****************************************************************
// SPECIFICATION FILE (Name.h)
// This file gives the specification of the Name abstract data
// data type. There are two constructors: one takes the first, 
// middle, and last name as parameters and the second prompts for 
// and reads the name from the standard input device
//*****************************************************************

#include <iostream>
#include <string>

using namespace std;

enum RelationType{BEFORE, SAME, AFTER};

class Name
{
public:
    Name();
        // Default constructor
        // Postcondition:
        //     first, middle, and last have been set to blanks
  
    Name( /* in */ string firstName, 
          /* in */ string middleName, 
          /* in */ string lastName );
        // Parameterized constructor
        // Postcondition:
        //     first is firstName AND middle is middleName AND 
        //     last is lastName
 
    void SetName( /* in */ string firstName, 
                  /* in */ string middleName, 
                  /* in */ string lastName );
    // Postcondition:
    //     first is firstName AND middle is middleName AND 
    //     last is lastName

    void ReadName();
    // Postcondition:
    //     Name is prompted for and read from the standard input 
    //     device
  
    string FirstName() const;
    // Postcondition:
    //     Return value is this person's first name
  
    string LastName() const;
    // Postcondition:
    //     Return value is this person's last name
  
    string MiddleName() const;
    // Postcondition:
    //     Return value is this person's middle name
  
    char MiddleInitial() const;
    // Postcondition:
    //     Return value is this person's middle initial
  
    RelationType ComparedTo( /* in */ Name otherName ) const;
    // Postcondition:
    //   Return value is
    //          BEFORE, if this name comes before otherName
    //          SAME, if this name and otherName are the same
    //          AFTER, if this name is after otherName
  
private:   
    string first;            // Person's first name
    string last;             // Person's last name
    string middle;           // Person's middle name
};
