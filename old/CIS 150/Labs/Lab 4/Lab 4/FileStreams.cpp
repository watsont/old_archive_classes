#include <stdafx.h>
#include <iostream>
#include <fstream>
using namespace std;


int main()
{

	ifstream infile;           // ifstream is a data type
	                           // ifstream = Input file stream
	infile.open("data1.txt");  //open data file named 'datafile1.txt'
	int temp = 0;
	
	while(!infile.eof())       // while the input file, 'infile' is not at the
	{	                       // End Of File (eof)


		infile>>temp;          // load the variable 'temp'
		cout<<temp<<endl;      // display the variable temp to the screen
	}

	infile.close();            // close the input file
	
    system("pause");
	return 0;
}
