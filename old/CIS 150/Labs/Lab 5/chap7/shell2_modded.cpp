// Program Shell2 promps for the number of dollar signs for
// the top of the box.  That number / 2 - 2  lines are 
// printed with dollar signs on the sides.        

#include <iostream>
#include <iomanip>

using namespace std;

void  Print(int numSigns);                             //Function prototype
//Post: A defined box is printed using the number of money signs input by user.


int main ()
{
    int  number = 0;

    cout  << "Enter the number of dollar signs for the top; "
	  << "press return. "  << endl;
    cout  << "Enter end-of-file characer (#) to quit."  << endl;
    cin  >> number;
         if (number == '#')
            return 1;
         else
        Print(number);
	    
   	cout  << endl
          <<"Enter the number of dollar signs for the top; "
          << "press return. "  << endl;
    cout  << "Enter end-of-file characer (#) to quit."  << endl;
         cin  >> number;  
           if (number == '#')
            return 1;
         else
        Print(number);


    system("pause");
    return 0;
}

//**************************************

void  Print(int numSigns)                              //Name of function
//Post: A defined box is printed using the number of money signs input by user.

{                                                      //Begin Action
        int topCount = 1;
        int bottomCount = 1;
        int countRows =1;
        
        int insideSpacing;
        insideSpacing = (numSigns/2)-1;
        
        
        while(topCount <= numSigns)                    //Displays Top
        {
             cout << "$";
             topCount++;
        }
        
        cout << endl;
        
        
        while(countRows < insideSpacing)               //Displays Inside
        {
             cout <<"$" << setw(numSigns-1) << "$" << endl;         
             countRows++;                
        }
        
        
        while(bottomCount <= numSigns)                 //Displays Bottom; is identical to Top
        {   
             cout << "$";                         
             bottomCount++;            
        }
        
        cout << endl;
    
    return; 
}                                                      //End Action

