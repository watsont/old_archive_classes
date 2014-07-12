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
void      PrintDistance(Distance, Distance, Distance);

//*********  Distance Operations ********************

Distance  AddDistance
    (Distance  distance1, Distance  distance2)
// Pre:  distance1 and distance2 contain valid data.
// Post: Returns distance1 + distance2.
{
    Distance combDistance;
    combDistance.feet = distance1.feet + distance2.feet;
    combDistance.yards = distance1.yards + distance2.yards;
    combDistance.miles = distance1.miles + distance2.miles;
    
    if (combDistance.feet feet > 3)
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
    convertFeet.yards = ((feet / FEET_IN_YARDS) % FEET_IN_MILES);
    convertFeet.miles = (feet/ FEET_IN_YARDS) / FEET_IN_MILES);
    
    return (convertFeet);
}

//******************************************************

void  PrintDistance(Distance combDistance, Distance convertYards, Distance convertFeet)
// Post:  A vriable of Distance is printed as as feet, 
//        yards, and miles.
{
    cout << "Distance of Distance1 + Distance2 is " << endl
         << "Feet: " << combDistance.feet
         << " Yards: " << combDistance.yards
         << " Miles: " << combDistance.miles << endl;
    cout << "Distance is " << endl << "Feet: " << convertFeet.feet
         << " Yards: " << convertYards.yards
         << " Miles: " << convertMiles.miles << endl;
    cout << "Distance is " << endl << "Feet: " << convertYards.feet
         << " Yards: " << convertYards.yards
         << " Miles: " << convertYards.miles << endl; 
}
