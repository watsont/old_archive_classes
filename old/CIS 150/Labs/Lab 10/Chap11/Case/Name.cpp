//*****************************************************************
// IMPLEMENTATION FILE (Name.cpp)
// The file implements the Name member functions
//*****************************************************************
 
#include "Name.h" 
#include <iostream>
 
Name::Name()

// Default constructor
// Postcondition:
//   first, middle, and last have been set to blanks

{
    first = " ";
    middle = " ";
    last = " ";
}

//******************************************************************
  
Name::Name( /* in */ string firstName,    // First name
            /* in */ string middleName,   // Middle name
            /* in */ string lastName )    // Last name

// Parameterized constructor
// Postcondition:
//     firstName has been stored in first; middleName has been
//     stored in midd; lastName has been stored in last 

{
    first = firstName;               // Assign parameters 
    last = lastName;
    middle = middleName;
}

//******************************************************************
 
void Name::SetName( /* in */ string firstName,    // First name
                   /* in */ string middleName,   // Middle name
                   /* in */ string lastName )     // Last name

// Postcondition:
//     firstName has been stored in first; middleName has been
//     stored in middle; lastName has been stored in last 

{
  first = firstName;               // Assign parameters 
  last = lastName;
  middle = middleName;
}

//******************************************************************

void Name::ReadName()

// Postcondition:
//     Name  prompted for and read from the standard input device

{
    cout << "Enter first name: ";    // Prompt for first name
    cin >> first;                    // Get first name
    cout << "Enter middle name: ";   // Prompt for middle name
    cin >> middle;                   // Get middle name
    cout << "Enter last name: ";     // Prompt for last name
    cin >> last;                     // Get last name 
}

//******************************************************************

string Name::FirstName() const

// Postcondition:
//   Return value is first 

{
    return first;
}  

   
//******************************************************************

string Name::LastName() const

// Postcondition:
//   Return value is last 

{
    return last;
} 

   
//******************************************************************

string Name::MiddleName() const

// Postcondition:
//   Return value is middle 

{
    return middle;
} 

   
//******************************************************************

char Name::MiddleInitial() const

// Postcondition:
//   Return value is middle initial

{
    return middle[0];
} 

//******************************************************************

RelationType Name::ComparedTo( /* in */ Name otherName ) const

// Precondition:
//     Input parameter contains a valid name 
// Postcondition:
//     Return value is
//          BEFORE, if this name comes before otherName
//          SAME, if this name and otherName are the same
//          AFTER, if this name is after otherName
{
    if (last < otherName.last)
        return BEFORE;
    else if (otherName.last < last)
        return AFTER;
    else if (first < otherName.first)
        return BEFORE;
    else if (otherName.first < first)
        return AFTER;
    else if (middle < otherName.middle)
        return BEFORE;
    else if (otherName.middle < middle)
        return AFTER;  
    else
        return SAME;
 }               

