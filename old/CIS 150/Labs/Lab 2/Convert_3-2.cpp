//Program Convert converts a temperature in Fahrenheit to
//Celsius and a termperature in Celsius to Farenheit.

#include <iostream>
using namespace std;

const float TEMP_IN_F = 122;
const float TEMP_IN_C = 37;

int main ()
{
	float fToC; //Place to store Celsius answer
	float cToF; // Place to store the Fahrenheit answer

	cToF = 9 * TEMP_IN_C / 5 + 32;
	fToC = 5 * TEMP_IN_F - 32 /9;
	cout << TEMP_IN_F << " in Fahrenheit is " << fToC
		 << " in Celsius. " << endl;
	cout << TEMP_IN_C << " in Celsius is "<<cToF
		 << " in Fahrenheit. " << endl;

	return 0;
}
