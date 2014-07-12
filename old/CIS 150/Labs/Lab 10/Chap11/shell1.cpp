const int FEET_IN_YARDS = 3;
const int YARDS_IN_MILES = 1760;

struct  Distance
{
    long  feet;
    long  yards;
    long  miles;
};

Distance  AddDistance(Distance, Distance);
Distance  ConvertYards(long);
Distance  ConvertFeet(long);
void      PrintDistance(Distance);

//*********  Distance Operations ********************

Distance  AddDistance
    (Distance  distance1, Distance  distance2)
// Pre:  distance1 and distance2 contain valid data.
// Post: Returns distance1 + distance2.
{
    // FILL IN Code to add two variables of Distance.
}

//******************************************************

Distance  ConvertYards(long  yards)
// Post: yards has been converted into a variable of 
//       Distance.
{
    // FILL IN Code to convert yards to a variable of 
    // Distance.
}
//******************************************************

Distance  ConvertFeet(long  feet)
// Post:  feet has been converted into a variable of 
//        Distance.
{
    // FILL IN Code to convert feet to a variable of 
    // Distance.
}

//******************************************************

void  PrintDistance(Distance  Distance)
// Post:  A vriable of Distance is printed as as feet, 
//        yards, and miles.
{
    // FILL IN Code to print a variable of Distance.
}
