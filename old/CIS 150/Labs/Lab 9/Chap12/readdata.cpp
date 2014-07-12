// Program ReadData manipulates a two-dimensional table.

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int ROW_MAX = 8;
const int COL_MAX = 10;

typedef int ItemType;

typedef ItemType Table[ROW_MAX][COL_MAX];


int main ()
{
    Table  table;
    int  rowsUsed;
    int  colsUsed;
    ifstream  dataIn;
    ofstream  dataOut;

    dataIn.open("debug.dat");
    dataOut.open("debug.out");
    dataIn  >> colsUsed  >> rowsUsed;
    // Input table values.
    for (int col = 0; col < colsUsed; col++)
        for (int row = 0; row < rowsUsed; row++)
	    dataIn  >> table[row][col];

    // Output table values.
    for (row = 0; row < rowsUsed; row++)
    {
	for (col = 0; col < colsUsed; col++)
	    dataOut  << setw(3)  << table[row] [col];
        dataOut  << endl;
    }

    return 0;
}
