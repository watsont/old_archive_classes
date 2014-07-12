// Program Shell3 reads miles and hours and prints miles
// per hour.

#include <iostream>
#include <iomanip>
using namespace std;

void GetData(float&, float&);                              //Prototype
        
int main ()
{
    float  miles;
    float  hours;
    float  milesPerHour;

    cout  << fixed  << showpoint;

    GetData(miles,hours);

    milesPerHour = miles / hours;
    cout  << setw(10)  << miles
          << setw(10)  << hours
          << setw(10)  << milesPerHour  << endl;
          
    system("pause");
    return 0;
}

//*****************************************************


void GetData(float &miles, float &hours)
{
     cout << "Enter number of miles ";
     cin  >> miles;
     cout << "Enter number of hours ";
     cin  >> hours;
     return;
}

