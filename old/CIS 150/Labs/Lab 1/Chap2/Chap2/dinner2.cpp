// Program Dinner prints out a dinner menu
#include <iostream>
#include <string>
using namespace std;

string SALAD = "Green Salad";
string MEAT = "Chicken Marsala";
string VEGGIE = "Carrots with lemon butter";
string STARCH = "Mashed potatoes";
string DESSERT = "Apple pie";

int main ()
{
    string mainCourse;

    cout  << "First course: "  << SALAD  << endl;
    mainCourse = MEAT + " with " + VEGGIE + " and " 
        + STARCH;
    cout  << "Main course: "  << mainCourse  << endl;
    cout  << "Dessert: "  << DESSERT;
    
    system("pause");
    return 0;
}

