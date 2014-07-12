// Program Shell3 calculates a person's percentage of
// calories from fat and prints an appropriate message. 

#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string foodItem;
    int   gramsOfFat;
    int   calories;
    float fatCalPercent;

    cout  << fixed  << showpoint;

    cout  << "Enter the name of a food item."  
          << "  Press return."  << endl;
    getline(cin, foodItem);

    cout  << "Enter the grams of fat; press return."  << endl;
    cin   >> gramsOfFat;

    cout  << "Enter the number of calories; press return."
          << endl;
    cin   >> calories;
  
          fatCalPercent = ((gramsOfFat*9.0)/calories)*100;
  
    cout << endl << "Percent from Fat is: "
         << fatCalPercent << "% \n" << endl;
    
    if(fatCalPercent > 30.0)
         cout << "This item is NOT Heart Healthy!! \n";
    else
         cout << "This item is Heart Healthy! \n";
    
    system("pause");
    return 0;
}

