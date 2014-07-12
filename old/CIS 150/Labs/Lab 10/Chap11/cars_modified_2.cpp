// Program Cars reads a record from a file and writes 
// its contents back to another file with the price member 
// increased by 10%.  
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct  Date
{
    int  month;
    int  day;
    int  year;
};

struct  Car
{
    float price;
    Date purchased;
    string customer;
    bool sold;
    Date soldDate;
    string soldTo;
};

void  GetCar(ifstream&, Car&);// Reads a variable of Car from a file.
void  CarSold(Date , Car&);
void  WriteSold(ofstream&, Car);
void  WriteCar(ofstream&, Car);// Writes a variable of Car on a file.

int main ()
{
    int sellDate;
    int sellMonth;
    int sellYear;
    string response;
    Car  car;
    Date sellDat;
    ifstream dataIn;
    ofstream dataOut;
    ofstream dataSold;
    
    dataIn.open("cars.dat");
    dataOut.open("cars.out");
    dataSold.open("carsSold.txt");
    
    dataOut  << fixed  << showpoint;
    GetCar(dataIn, car); 
    while (!dataIn.eof())
    {
	      car.price = car.price * 1.10;
	      FirstQuestion: cout << endl                                           //Label FirstQuestion
                              << "Customer: " << car.customer                   
                              <<"\nHas the vehicle been resold? Yes or No.\n";
	      cin >> response;
          response = response.substr(0,1);
          
	      if (response == "Y" || response == "y")
          {    
             cout <<"What day did you resell the car on (DD)?" << endl;
             cin >> sellDate;
             sellDat.day = sellDate;
             cout << "What month did you resell the car in (MM)?" << endl;
             cin >> sellMonth;
             sellDat.month = sellMonth;
             cout << "What year did you resell the car in (YYYY)?" << endl;
             cin >> sellYear;
             sellDat.year = sellYear;
             cout << "Who did you sell it to?" << endl;
             cin >> response;
             car.soldTo = response;
             CarSold(sellDat , car);
             WriteSold(dataSold, car);             
          }
          else if (response == "N" || response == "n")
          { 
            WriteCar(dataOut, car);
          }
          
          else
          {
              cout << "Sorry, there was some incorrect input. Please retry. \n\n";
              cin.get();
              goto FirstQuestion;
          }
          
          GetCar(dataIn, car);
          
    }
    
    dataOut.close();
    dataSold.close();
    
    system ("PAUSE");
    return 0;
    
}

//*****************************************************

void  GetCar(ifstream&  dataIn, Car&  car)
// Pre:  File dataIn has been opened.
// Post: The fields of car are read from file dataIn.
{
    car.sold = false;
    dataIn >> car.customer
           >> car.price >> car.purchased.day
           >> car.purchased.month >> car.purchased.year;
    dataIn.ignore(2, '\n');
    return;
}

//*****************************************************

void  WriteCar(ofstream&  dataOut, Car  car)
// Pre:  File dataOut has been opened.
// Post: The fields of car are written on file dataOut,
//       appropriately labeled.
{
    dataOut << "Customer: "  << car.customer  << endl
	        << "Price:    "  << car.price  << endl
	        << "Purchased:"  << car.purchased.day  << "/"
	        << car.purchased.month  << "/"
	        << car.purchased.year  << endl;
}

//*********************************************************==old: "
void  CarSold(Date sellDat , Car& car)
{
      car.sold = true;
      car.soldDate.day = sellDat.day;
      car.soldDate.month = sellDat.month;
      car.soldDate.year = sellDat.year;
}
void  WriteSold(ofstream& dataSold, Car car)
{ 
     dataSold  << "Customer: "  << car.customer << endl
	           << "Price:    "  << car.price << endl
	           << "Purchased:"  << car.purchased.day  << "/"
	           << car.purchased.month << "/"
	           << car.purchased.year << " Sold Date: " << car.soldDate.day<< "/"
               << car.soldDate.month << "/"
               << car.soldDate.year << endl
               << "Sold to: " << car.soldTo << endl << endl;
}
