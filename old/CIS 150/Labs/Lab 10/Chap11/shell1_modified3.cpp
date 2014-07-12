#include <iostream>

using namespace std;

const int FEET_IN_YARDS = 3;
const int YARDS_IN_MILES = 1760;

struct  Distance
{
    float  feet;
    float  yards;
    float  miles;
};

Distance AddDistance(Distance, Distance, Distance);
Distance ConvertYards(long);
Distance ConvertFeet(long);
void PrintDistance(Distance, Distance, Distance, float);
float MilesPerHour (Distance, long);
int main()
{
    Distance distance1;
    Distance distance2;
    Distance distance3 = {0, 0, 37};
    long feet = 15000;
    long yards = 12000;
    long time = 45;
    float MPH;
    
    distance1 = ConvertYards( yards);
    distance2 = ConvertFeet ( feet);
    Distance combDistance = AddDistance (distance1, distance2, distance3);
    MPH = MilesPerHour(combDistance, time);
    
    PrintDistance (combDistance, distance1, distance2, MPH);
    
    system("PAUSE");
    return 0;
}
//*********  Distance Operations ********************

Distance  AddDistance
    (Distance  distance1, Distance  distance2, Distance distance3)
// Pre:  distance1 and distance2 contain valid data.
// Post: Returns distance1 + distance2.
{
    Distance combDistance;
    combDistance.feet = distance1.feet + distance2.feet + distance3.feet;
    combDistance.yards = distance1.yards + distance2.yards + distance3.yards;
    combDistance.miles = distance1.miles + distance2.miles + distance3.miles;
    
    if (combDistance.feet > 3)
    {
        combDistance.feet = combDistance.feet - 3;
        combDistance.yards = combDistance.yards + 1;
    }
    if (combDistance.yards > 1760)
    {
        combDistance.yards = combDistance.yards - 1760;
        combDistance.miles = combDistance.miles + 1;
    }
    
    return (combDistance);
}

//******************************************************

Distance  ConvertYards(long  yards)
// Post: yards has been converted into a variable of 
//       Distance.
{
    Distance convertYards;
    convertYards.feet = 0;
    convertYards.yards = (yards % YARDS_IN_MILES);
    convertYards.miles = (yards / YARDS_IN_MILES);
    
    return (convertYards);
    
}
//******************************************************

Distance  ConvertFeet(long  feet)
// Post:  feet has been converted into a variable of 
//        Distance.
{
    Distance convertFeet;
    convertFeet.feet = (feet % FEET_IN_YARDS);
    convertFeet.yards = ((feet / FEET_IN_YARDS) % YARDS_IN_MILES);
    convertFeet.miles = ((feet/ FEET_IN_YARDS) / YARDS_IN_MILES);
    
    return (convertFeet);
}

//******************************************************
float MilesPerHour (Distance combDistance, long time)
{
    float mph1;
    float mph2;
    float mph3;
    float totalMPH;
    
    mph1 = ((combDistance.feet / FEET_IN_YARDS) / YARDS_IN_MILES) / time * 60.0;
    mph2 = (combDistance.yards/YARDS_IN_MILES) / time * 60.0;
    mph3 = (combDistance.miles/ time) * 60.0;
    totalMPH = mph1 + mph2 + mph3;
    return (totalMPH);
}

void  PrintDistance(Distance combDistance, Distance distance1, Distance distance2, float MPH)
// Post:  A vriable of Distance is printed as as feet, 
//        yards, and miles.
{
    cout << "Distance of Distance1 + Distance2 is " << endl
         << "Feet: " << combDistance.feet
         << ", Yards: " << combDistance.yards
         << ", Miles: " << combDistance.miles << endl << endl;
    cout << "Feet conversion of distance is " << endl
         << "Feet: " << distance1.feet
         << ", Yards: " << distance1.yards
         << ", Miles: " << distance1.miles << endl << endl;
    cout << "Yard conversion of distance is " << endl
         << "Feet: " << distance2.feet
         << ", Yards: " << distance2.yards
         << ", Miles: " << distance2.miles << endl << endl;
    cout << "Miles Per Hour Traveled is " << MPH << endl << endl;
         
         
}
