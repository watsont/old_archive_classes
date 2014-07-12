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
    
        outData << fixed << setprecision(2) << acctId << " " << numMonths     //Stores data into outData
                << " " << initBal << " " << finalBal << endl;                 //  which is written to another file "newData.txt"
        allFinalBal = finalBal + allFinalBal;                                 //Computes the total of the final balances
    }
    
    inData.close();                                                  //Closes filestream inData (prog4data.txt)
    outData.close();                                                 //CLoses filestream outData (newData.txt)
    cout << "acctId" << "\t\t" << "numMonths" << "\t" << "initBal" //Ouputs column headings
         << "\t\t" << "finalBal" << endl << endl;
    inData.open("newData.txt");                                      //Opens filestream inData to access "newData.txt"
    
    //Loop for 'i' number of times equal to number of accounts. Displays values obtained from newData.txt
    for(int i = 1; i <= numAcct; i++)                                
    {
        inData >> acctId >> numMonths >> initBal >> finalBal;        //Take data from inData and place into variables
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

Account   InitBal  # of months FinalBal
1000      9        2.79        2.85
1234      23       95.04       100.83
3341      10       0.00        0.00
3221      21       -1.08       -1.08
7462      4        404.14      409.56
3425      11       4784.00     5007.89
3701      4        99.50       100.58
2701      4        -99.54      -99.54
3532      7        999.50      1028.17
4512      15       50.00       51.91
3667      15       500.00      525.59
3696      9        99.99       102.94
3917      9        100.00      103.04
2833      9        999.99      1037.26
3332      9        1000.00     1038.13
2462      0        -212.32     -212.32
5442      15       9999.99     10643.55
8817      11       990.50      1034.28
9183      200      20.00       32.95
1112      21       74.74       78.76
9287      1        74.74       74.93
2591      22       0.00        0.00
2837      3        1.50        1.51
3832      3        -0.78       -0.78
1003      15       7.47        7.76
8713      200      99.75       193.75
3452      5        1200.34     1225.56
9876     10        495.95      512.73
3276     10        -294.17     -294.17
2228     15        80.40       83.47
0000     7         77.77       79.14
7183     75        1.00        1.21


The cumulative total to ALL of the
accounts' balances is: 22870.45

*******************************************************************************/
