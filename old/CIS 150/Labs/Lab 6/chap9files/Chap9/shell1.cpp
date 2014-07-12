// Program Shell1 counts punctuation marks in a file.

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
    ifstream  inData;
    char symbol;
    int  periodCt = 0;
    int  commaCt = 0;
    int  questionCt = 0;
    int  colonCt = 0;
    int  semicolonCt = 0;

    inData.open("switches.dat");
    while (inData)
    {
        cin >> symbol;
        switches (symbol)
        {
            case '.' : periodCt++;
                       break;
            case '?' : questionCt++;
                       break;
            case ',' : commaCt++;
                       bread;
            case ':' : colonCt++;
                       break;
            case ';' : semicolonCt++;
                       break;
            default  :; 
        }
        cout << ".:" << periodCt  << " ::"  << colonCt  << " ;:" << semicolonCt
             << ",:" << commaCt  << "?:"  << questionCt << endl;
    } 
            
    return 0;
}
