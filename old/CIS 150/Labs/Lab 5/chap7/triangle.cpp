#include <iostream>
#include <fstream>
using namespace std;

void  CheckTriangle(int, int, int);

main ()
{
    int  a;
    int  b;
    int  c;
    ifstream  dataIn;

    dataIn.open("Triangle.Dat");
    dataIn  >> a;
    while (dataIn)
    {
	dataIn  >> b  >> c;
	cout  << a  << " "  << b  << " "  << c;
	CheckTriangle(a, b, c);
	dataIn  >> a;
    }
    return 0;
}

void  CheckTriangle(int b, int c, int a)
{
    if ((a == b) && (b == c))
        cout  << "Equalateral"  << endl;
    else
        if (a == b)
            cout  << "Isoscelese"  << endl;
        else
            cout  << "Scalene"  << endl;
}

      

