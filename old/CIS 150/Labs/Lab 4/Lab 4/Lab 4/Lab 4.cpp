#include <stdafx.h>
#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;


int main()
{
	ofstream outfile;
	ifstream infile1;
	ifstream infile2;
	ifstream infile3;           // ifstream is a data type
	                           // ifstream = Input file stream
	infile1.open("data1.txt");  //open data file named 'datafile1.txt'
	infile2.open("data2.txt");
	infile3.open("data3.txt");
	outfile.open("outdata.txt");
	int temp = 0;
	
	while(!infile1.eof())       // while the input file, 'infile' is not at the
	{	                       // End Of File (eof)


		infile1 >> temp;          // load the variable 'temp'
		cout << temp <<endl;      // display the variable temp to the screen
		
		outfile << temp <<endl;
	}

	while(!infile2.eof())       // while the input file, 'infile' is not at the
	{	                       // End Of File (eof)


		infile2 >> temp;          // load the variable 'temp'
		cout << temp <<endl;      // display the variable temp to the screen
		
		outfile << temp <<endl;
	}	
	
	while(!infile3.eof())       // while the input file, 'infile' is not at the
	{	                       // End Of File (eof)


		infile3 >> temp;          // load the variable 'temp'
		cout << temp <<endl;      // display the variable temp to the screen
		
		outfile << temp <<endl;
	}
	infile1.close();            // close the input file
	infile2.close();
	infile3.close();
	outfile.close();



    system("pause");
	return 0;
}
