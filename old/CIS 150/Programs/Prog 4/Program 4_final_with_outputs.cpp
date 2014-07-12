/*
        Written by Watson Tong
                07/13/08
                Program 4: Banking
                Revised: 07/20/08
        Professor: Kiumi Akingbehin
        CIS 150: SU 08

        The purpose of this program is to continue to build on C++ skills.
        This time, we are writing a program that builds on using control structures.
        This program uses a pre-made file set of data; from the data, the program computes the final balance
        of each account, based on the number of months each initial balance has been compounded for, at an
        interest rate that is based on the balance for that month.
*/

#include <iostream>
#include <iomanip>      //For setprecision
#include <fstream>      //For reading in data
#include <string>
using namespace std;

int main()
{
    int numAcct = 0;                                   //Declares and initializes the number of accounts
    int numMonths = 0;                                 //Declares and initializes the number of months
    string acctId;                                     //Declares the string to hold the account ID
    float intrRate = 0.0;                              //Declares and initializes the interest rate
    float initBal = 0.0;                               //Declares and initializes the initial balance
    float finalBal = 0.0;                              //Declares and initializes the final balance
    float tempBal = 0.0 ;                              //Declares and initializes the temporary balance
    float allFinalBal = 0.0;                           //Declares and initializes the total sum of all accounts
    ifstream inData;                                   //Declared to open up data file for reading
    ofstream outData;                                  //Declared to open up data file for writing
    
    inData.open("prog4data.txt");                                    //Opens up data file
    outData.open("newData.txt");                                     //Creates and opens up data file
    inData >> numAcct;                                               //Reads in first value for number of accounts
    
    //*Loop for 'i' number of times equal to number of accounts
    for(int i = 1; i <= numAcct; i++)                                
    {
        inData >> acctId >> initBal >> numMonths;                    //Stores values into variables from inData
        tempBal = initBal;                                           //Sets tempBal to hold initBal's value
        finalBal = tempBal;                                          //Sets finalBal to hold tempBal's value
    
    //*Loop for 'j' number of times equal to number of months
        for(int j = 1; j <= numMonths; j++)                          
        {
            if(tempBal >= 0.0 && tempBal < 100.00)                   //If this condition is true, then the intrest rate is 3.0
                intrRate = 3.0;
            else if (tempBal > 99.99 && tempBal < 1000.00)           //If this condition is true, then the intrest rate is 4.0
                intrRate = 4.0;
            else if (tempBal > 999.99)                               //If this condition is true, then the intrest rate is 5.0
                intrRate = 5.0;
            else if (tempBal < 0.00)                                 //If this condition is true, then the interest rate is 0.0
                intrRate = 0.0;
            else                                                                //Used for debugging if tempBal does not work
                cout << "\a" << "error computing interest rate on acctId "      //  and if conditions are not met
                     << acctId << endl
                     << "whose intrRate was " << intrRate << endl
                     << "and whose tempBal was " << tempBal << endl
                     << "on its " << j << "th run" << endl;
        
            tempBal = (intrRate/100 * tempBal * 1.0/12.0) + tempBal;            //Computes the temporary balance
            finalBal = tempBal;                                                 //Stores the value of tempBal into finalBal
        }
    
        outData << fixed << setprecision(2) << acctId << " " << initBal         //Stores data into outData
                << " " << numMonths << " " << finalBal << endl;                 //  which is written to another file "newData.txt"
        allFinalBal = finalBal + allFinalBal;                                   //Computes the total of the final balances
    }
    
    inData.close();                                                  //Closes filestream inData (prog4data.txt)
    outData.close();                                                 //CLoses filestream outData (newData.txt)
    cout << "acctId" << "\t\t" << "numMonths" << "\t" << "initBal" //Ouputs column headings
         << "\t\t" << "finalBal" << endl << endl;
    inData.open("newData.txt");                                      //Opens filestream inData to access "newData.txt"
    
    //Loop for 'i' number of times equal to number of accounts. Displays values obtained from newData.txt
    for(int i = 1; i <= numAcct; i++)                                
    {
        inData >> acctId >> initBal >> numMonths >> finalBal;        //Take data from inData and place into variables
        cout << acctId << "\t\t" << numMonths << "\t\t" << initBal   //Output to console the variables
             << "\t\t" << finalBal << endl;
    }
    //inData >> fixed >> setprecision(2) >> "Final total is " << allFinalBal " .";
        
    cout << fixed << setprecision(2) << endl
        << "The cumulative total to ALL of the"                      //Outputs the cumulative total
        << "accounts' balances is: " << allFinalBal << endl;
        
    inData.close();                                                  //Closes file stream inData (newData.txt)
    
    system("PAUSE");                                                 //Used for Dev-C++ to pause; useless in other compilers
    return 0;   
}


/*******************************************************************************
         Values that have been stored in "newData.txt" have the same format as the 
         input file (acctId, initBal, numMonths, and Final Bal).
         
             Output to *file* "newData.txt":
                   *(Output to console is the same except the columns are output
                   * as acctId, # of months, initBal, finalBal)
         
Account   InitBal  # of months FinalBal

1000      2.79      9         2.85
1234      95.04     23        100.83
3341      0.00      10        0.00
3221      -1.08     21        -1.08
7462      404.14    4         409.56
3425       4784.00  11        5007.89
3701       99.50    4         100.58
2701       -99.54   4         -99.54
3532       999.50   7         1028.17
4512       50.00    15        51.91
3667       500.00   15        525.59
3696       99.99    9         102.94
3917       100.00   9         103.04
2833       999.99   9         1037.26
3332       1000.00  9         1038.13
2462       -212.32  0         -212.32
5442       9999.99  15        10643.55
8817       990.50   11        1034.28
9183       20.00    200       32.95
1112       74.74    21        78.76
9287       74.74    1         74.93
2591       0.00     22        0.00
2837       1.50     3         1.51
3832       -0.78    3         -0.78
1003       7.47     15        7.76
8713       99.75    200       193.75
3452       1200.34  5         1225.56
9876       495.95   10        512.73
3276       -294.17  10        -294.17
2228       80.40    15        83.47
0000       77.77    7         79.14
7183       1.00     75        1.21

The cumulative total to ALL of the
accounts' balances is: 22870.45

*******************************************************************************/
