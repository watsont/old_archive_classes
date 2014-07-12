//******************************************************************
// Statistics Program
// This program calculates the average, high score, low score, 
// number above the average, and number below the average for 
// a file of test scores.
// To save space, we omit from each function the precondition 
// comments that document the assumptions made about valid input 
// parameter data. These would be included in a program intended 
// for actual use.                                                                          
//******************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Declare function prototypes
void OpenFiles(ifstream& inData, ofstream& outData);
void InputGrades(int grades[], int& numGrades, ifstream& inData);
float CalculateAverage(int const grades[], int numGrades);
int CalculateHighest(int const grades[]);
int CalculateLowest(int const grades[]);
int CalculateAboveAverage(int const grades[], float average);
int CalculateBelowAverage(int const grades[], float average);
void PrintResults(ofstream& outData, int numGrades, float average, 
    int highest,int lowest, int aboveAverage, int belowAverage);

int main()
{
    int grades[101];         // Array of counters for each grade
    int numGrades;           // Number of grades
    float average;           // Average grade
    int highest;             // Highest grade
    int lowest;              // Lowest grade
    int aboveAverage;        // Number of grades above the average
    int belowAverage;        // Number of grades below the average
 
    // Delcare and open files
    ifstream inData;
    ofstream outData;
    OpenFiles(inData, outData);
  
    // Read and process grades
    InputGrades(grades, numGrades, inData);		
    average = CalculateAverage(grades, numGrades); 
    highest = CalculateHighest(grades);        
    lowest = CalculateLowest(grades);          
    aboveAverage = CalculateAboveAverage(grades, average);
    belowAverage = CalculateBelowAverage(grades, average);
    PrintResults(outData, numGrades, average, highest, lowest,
        aboveAverage, belowAverage);
   
    inData.close();
    outData.close();
    return 0;
}            
       
//****************************************************************** 

void OpenFiles( /* inout */ ifstream& text, 
                /* inout */ ofstream& outFile )

// Function OpenFiles reads in the names of the input file and 
// the output file and opens them for processing
     // Postcondition:
     //     Files have been opened AND a label has been written on 
     //     the output file

{
    string inFileName;
    string outFileName;
         cout << "Enter the name of the file to be processed" 
              << endl;
    cin >> inFileName; 
    text.open(inFileName.c_str());
    cout << "Enter the name of the output file" << endl;
    cin >> outFileName;
    outFile.open(outFileName.c_str()); 
    outFile << "Analysis of exams on file " << inFileName 
          << endl << endl;
}

//******************************************************************

float CalculateAverage
    ( /* inout */ int const grades[], // Grade structure
      /* in */     int numGrades )    // Number of grades

// This function calculates the average test score
// Postcondition:
//     Return value is the average grade

{
    int sum = 0;
    // Sum number of grades times index
    for (int index = 0; index <= 100; index++)
        sum = sum + grades[index] * index;
    
    return float(sum) / float(numGrades);
}    
 
//******************************************************************

void InputGrades
    ( /* inout */ int grades[],    // Grade structure
      /* inout */ int& numGrades,  // Number of grades
      /* inout */ ifstream& inData) // Input file

// Grades are input from file inData.  Each slot in grades is set
// to zero. As each grade is read in, the grade is used as an 
// index and that slot is incremented.
// Precondition: 
//     File is not empty
// Postcondition:
//     For each grade in the file, grades, indexed by the grade,
//     has been incremented 

{
    int grade;
    // Zero out the array of counters
    for (int index = 0; index <= 100; index++)
        grades[index] = 0;
    numGrades = 0;   
  
    inData >> grade; 			// Read a character
    
    // Increment counters for grades
    while (inData)
    { // Process data
        grades[grade]++;
        numGrades++;
        inData >> grade;
    }
}     

//******************************************************************

int CalculateHighest
    ( /* in */ int const grades[] ) // Grade structure

// This function calculates the highest grade by beginning at index
// 100 and working backward until a nonzero slot is found.  The 
// index of this slot is the highest grade.
// Postcondition:
//     Return value is the highest grade

{
    int highGrade = 100;
    // Index of first nonzero grade is the high grade
    while (grades[highGrade] == 0)
        highGrade--;
    return highGrade;
}    

//******************************************************************

int CalculateLowest
    ( /* in */ int const grades[] ) // Grade structure

// This function calculates the lowest grade by beginning at index
// 0 and working forward until a nonzero slot is found.  The index
// of this slot is the lowest grade.
// Postcondition:
//     Return value is the lowest grade

{
    // Index of first nonzero grade is the low grade
    int lowGrade = 0;
    while (grades[lowGrade] == 0)
        lowGrade++;
    return lowGrade;
}    

//******************************************************************

int CalculateAboveAverage
  ( /* in */ int const grades[],       // Grade structure
    /* inout */  float average )  // Average grade

// This function calculates the number of grades above the average
// by counting the numbers in the array from the rounded
// average to the 100th slot.
// Postcondition:
//     Return value is the number of grades above average
{
    int roundedAverage = (int) (average + 0.5);
    int index;
    int number = 0;
    for (index = roundedAverage; index <= 100; index++)
        number = number + grades[index];
    return number;
}    

//******************************************************************

int CalculateBelowAverage
  ( /* in */ int const grades[],       // Grade structure
   /* inout */  float average )  // Average grade

// This function calculates the number of grades below the average
// by counting the numbers in the array from index 0 to index
// truncated average.
// Postcondition:
//     Return value is the number of grades below average

{ 
    int truncatedAverage = (int) (average);
    int index;
    int number = 0;
    // Sum number of grades below average
    for (index = 0; index < truncatedAverage; index++)
        number = number + grades[index];
    return number;
}    

//******************************************************************

void PrintResults
    ( /* inout */ ofstream& outData, // Output file
      /* in */    int numGrades,     // Number of grades
      /* in */    float average,     // Average
      /* in */    int highest,       // Max grade
      /* in */    int lowest,        // Min grade
      /* in */    int aboveAverage,  // Number above 
      /* in */    int belowAverage)  // Number below

// Statistics are printed on file outData
// Precondition:
//     Output file has been successfully opened
// Postcondition:
//     Statistics have been written on outData, appropriately
//     labeled

{
    outData << "The number of grades is " << numGrades << endl;
    outData << fixed << setprecision(2) 
            << "The average grade is " << average << endl;
    outData << "The highest grade is " << highest << endl;
    outData << "The lowest grade is " << lowest << endl;
    outData << "The number of grades above the average is " 
            << aboveAverage  << endl;
    outData << "The number of grades below the average is "
            << belowAverage << endl;
}   

