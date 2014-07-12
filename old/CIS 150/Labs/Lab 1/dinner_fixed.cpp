// Program Dinner prints out a dinner menu              // 1
#include <iostream>
#include <string>
using namespace std;

const string SALAD = "Green Salad";                            // 2
const string MEAT = "Chicken Marsala";                         // 3
const string VEGGIE = "Carrots with lemon butter";             // 4
const string STARCH = "Mashed potatoes";                             // 5
const string DESSERT = "Ice Cream";
int main ()                                                // 6
{
    string mainCourse;                                  // 7
     
    cout  << "First course: "  << SALAD  << endl;       // 8
    mainCourse = MEAT + " with " + VEGGIE + " and "          // 9
        + STARCH;                                       // 10
    cout  << "Main course: "  << mainCourse  << endl;   // 11
    cout  << "Dessert: "  << DESSERT << endl;                   // 12
    
system("pause");    
return 0;          // 13
}
