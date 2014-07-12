/*
        Written by Watson Tong
                08/08/08
                Program 4: Banking
                Revised: 08/18/08
        Professor: Kiumi Akingbehin
        CIS 150: SU 08

        The purpose of this program is to continue to build on C++ skills.
        Last time, we wrote a program that builds on using arrays. We were to
        take values from a file and then input them into arrays, where we would compute
        the student's individual averages, the averages of the subject, the averages of
        the students' averages, and the averages of the subjects' scores. This time
        we are to arrange the information based on the increasing alphabetical last
        name of the student.
*/
#include <iostream>                                                             //For input/output
#include <fstream>                                                              //For file input/output
#include <iomanip>                                                              //For sewtw and setprecision
#include <string>                                                               //For strings
#include <cctype>                                                               //For tolower functhion
#include <cstring>                                                              //For strcmp
using namespace std;

//Global Constants
const int MAX_STUDENTS = 40;
const int SCORE_COLMS = 8;
const int FULL_ARRAY_LEN = 40 + int((SCORE_COLMS * 8.5)+.5);

//Function Prototypes
int ReadData (ifstream& inData, int& stuCount, int stuMemLoc,
             string LstName[], string FstName[], int stuID[],
             float Scores[][SCORE_COLMS]);
void IndvStuAvg (int stuMemLoc, int stuCount, float StudentAverage[],
                 float Scores[][SCORE_COLMS]);
void SubjAvg(int stuMemLoc, int stuCount, float SubjectAverage[],
              float Scores[][SCORE_COLMS]);
int StoreName (ostream& outData, string LstName[], string FstName[],            
              int stuID[], float Scores[][SCORE_COLMS], float StudentAverage[],
              int stuCount);
int SwapName (ifstream& newData, string FullArray[], int stuCount);

int main()
{
	ifstream inData;                                                            //Used to obtain data from file into arrays
	ifstream newData;                                                           //Used to obtain data from file, then put into a single array
	ofstream outData;                                                           //Used to store values from arrays into another file
    int stuMemLoc = 0;                                                          //Used for a position in the array
    int stuCount = 0;                                                           //Will be passed as reference; keeps track of students
    float combStuAvg = 0.0;                                                     //Used for computing combined student average
    float combSubAvg = 0.0;                                                     //Used for computing combined subject average
	string LstName[MAX_STUDENTS];                                               //Array to hold Last Name
    string FstName[MAX_STUDENTS];                                               //Array to hold First Name
    int stuID[MAX_STUDENTS];                                                    //Array to hold Student ID
	float Scores[MAX_STUDENTS][SCORE_COLMS];                                    //Array to hold Students' scores
	float SubjectAverage[MAX_STUDENTS];                                         //Array to hold the average of each subject
	float StudentAverage[MAX_STUDENTS];                                         //Array to hold the average of each student
	string FullArray[FULL_ARRAY_LEN];                                           //Array to hold ALL information
	
	inData.open("prog5data.txt");                                               //Opens up file to read in info
	ReadData(inData, stuCount, stuMemLoc, LstName, FstName, stuID, Scores);
	inData.close();
	
	//Prints headings
	cout << "Legend: \nID  = Student ID\n" << "S#  = score of that subject\n"
	     << "AVG = Student's Average Score\n" << endl;
	     
	cout << "Student Name" << '\t'  << setw(3) << "ID" << setw(6) 
         << "S1" << setw(5) << "S2" << setw(5) << "S3" << setw(5)
         << "S4" << setw(5) << "S5" << setw(5) << "S6" << setw(5)
         << "S7" << setw(5) << "S8" << setw(7) << "AVG" << endl;
    // Prints out student's name, ID, subject Scores, and average score
    for (stuMemLoc = 0; stuMemLoc < stuCount; stuMemLoc++) {
        cout << LstName[stuMemLoc] << " " << FstName[stuMemLoc]
             << '\t' << stuID[stuMemLoc];
        for(int i = 0; i < SCORE_COLMS; i++) {
            cout << fixed << setprecision(1) << setw(5)
                 << Scores[stuMemLoc][i];
        }
    IndvStuAvg (stuMemLoc, stuCount, StudentAverage, Scores);
    cout << setw(7) << StudentAverage[stuMemLoc] << endl;
    }
    
    //Prints out average of subject score
    cout << "Subject Averages:    ";
    SubjAvg(stuMemLoc, stuCount, SubjectAverage, Scores);
    for(int j = 0; j < SCORE_COLMS; j++) {   
        cout << fixed << setprecision(1) << setw(5)
             << SubjectAverage[j];
        }
    //Prints out AVG of students
    cout << "\n\nAVERAGE SCORE USING STUDENT AVERAGES: ";
         for (int k = 0; k < stuCount; k++) {
             combStuAvg = combStuAvg + StudentAverage[k];
         }
         cout << combStuAvg/stuCount;
    
    cout << "\nAVERAGE SCORE USING SUBJECT AVERAGES: ";
         for (int l = 0; l < SCORE_COLMS; l++) {
             combSubAvg = combSubAvg + SubjectAverage[l];
         }
         cout << combSubAvg/SCORE_COLMS << endl << endl;
    
    //Stores known info in formatted list
    cout << "\n*** Data sorted alphabetically by student's last name ***\n\n";
    
    cout << "Student Name" << '\t'  << setw(3) << "ID" << setw(6) 
         << "S1" << setw(5) << "S2" << setw(5) << "S3" << setw(5)
         << "S4" << setw(5) << "S5" << setw(5) << "S6" << setw(5)
         << "S7" << setw(5) << "S8" << setw(7) << "AVG" << endl;
         
    outData.open ("sorted_progData.txt");
    StoreName (outData, LstName, FstName, stuID, Scores,
             StudentAverage, stuCount);
    outData.close();
    
    //Prints out new information
    newData.open ("sorted_progData.txt");
    SwapName (newData, FullArray, stuCount);                                            
    
    newData.close();
    system("PAUSE");
	return 0;
}
//******************************************************************************
int SwapName (ifstream& newData, string FullArray[FULL_ARRAY_LEN], int stuCount)//*** This function organizes the names AND prints them out!
{
    string temp;
    string tempAlpha;                                                                   //Will be a "temporary" string to hold the first name
    string tempBeta;                                                                    //Will be a "temporary" string to hold the second name
    int count = 0;
    if (!newData) {
        cout << "\nError reading file \"sorted_progData.txt\" !\n"
             << "Please make sure that you have "
             << "read permissions to this file!\n"
             << "Press enter to exit." << endl;
        cin.get();
        return 1;  
    }
    else {                                                                     
        for (int i = 0; i < stuCount; i++) {                                            //Loop stores data from outData into array FullArray.
            getline(newData, FullArray[i]);                                             //Grabs data from file and stores into array (with same formatting)
        }
    }
    
    while ( count < stuCount) {                                                         
            for (int k = 0; k < stuCount-1; k++) {
                tempAlpha = FullArray[k];
                
                for (int l = 0; l < SCORE_COLMS + 4; l++) {                             //Info is stored for (num of subject columns + 4; one each for Last
                    tempBeta = FullArray[k+1];                                          //and first Name, one for stuID, and another for score avg
                }
                
                if (tempAlpha > tempBeta) {                                             //If first value is greater than second
                                                                                        //swap them
                   temp = FullArray[k];
                   FullArray[k] = FullArray[k+1];
                   FullArray[k+1] = temp;
                }
            }
            
            count++;
    }
    
    for (int i = 0; i < stuCount; i++) {                                                //Prints out names
        cout << FullArray[i] << endl;
    }
    
    cout << endl;
    return 0;
}
//******************************************************************************
int StoreName (ostream& outData, string LstName[], string FstName[],            //This function serves to create a new file containing
              int stuID[], float Scores[][SCORE_COLMS], float StudentAverage[], //known info to be used later (organizing the data)
              int stuCount)
{
    if (!outData) {                                                                     //If no file found, exit
            cout << "\nError writing to file 'sorted_progData.txt'! .\n"
                 << "Please make sure that you have enough hard drive space\n"
                 << "or that you have read and write permissions to this file.\n"
                 << "Press enter to exit" << endl;
            cin.get();
            return 1;  
    }
    else {                                                                              //If file found, continue
        for (int g = 0; g < stuCount; g++) {                                            //Loop stores data into external file
            
            outData << LstName[g] << " " << FstName[g] << "\t" << stuID[g];
            for (int h = 0; h < SCORE_COLMS; h++) {
            
                outData << fixed << setprecision(1) << setw(5) << Scores[g][h];
            }
            outData << fixed << setprecision(1) << setw(7) << StudentAverage[g]
                    << endl;
        }
    }
    
    return 0;
}
//******************************************************************************
void SubjAvg(int stuMemLoc, int stuCount, float SubjectAverage[],               //This function serves to give the average
              float Scores[][SCORE_COLMS])                                      //of each subject
{
    float temp = 0.0;
    for (stuMemLoc = 0; stuMemLoc < SCORE_COLMS; stuMemLoc++) {
        for (int index = 0; index < stuCount; index++) {
            temp = temp + Scores[index][stuMemLoc];
        }
            SubjectAverage[stuMemLoc] = temp/stuCount;
        temp = 0.0;                                                                  //Resets temp so it won't hold previous values
    }  
}
//******************************************************************************
void IndvStuAvg (int stuMemLoc, int stuCount, float StudentAverage[],           //This function serves to give the average
                  float Scores[][SCORE_COLMS])                                  //of each student
{
     float temp = 0.0;
     for (int index = 0; index < SCORE_COLMS; index++) {
         temp = temp + Scores[stuMemLoc][index];
     }
     StudentAverage[stuMemLoc] = temp/SCORE_COLMS;
     
}
//******************************************************************************
int ReadData (ifstream& inData, int& stuCount, int stuMemLoc, string LstName[], //This function serves to read information from
               string FstName[], int stuID[], float Scores[][SCORE_COLMS])      //the file
{
    stuCount = 0;
    stuMemLoc = 0;
    
    if(!inData) {                                                                     //If no file found, exit
            cout << "No file to read. Please make sure file is in same"
                 << "directory as this source file. \n"
                 << "Press enter to exit" << endl;
            cin.get();
            return 1;
        }
    else {                                                                            //If file found, continue
        //Priming Read
        inData >> LstName[stuMemLoc] >> FstName[stuMemLoc] >> stuID[stuMemLoc];
        while (!inData.eof())                                                         //Keep looping until all data read
        {    
            for (int index =0; index < SCORE_COLMS; index++) {                        //Stores values in space[index] of
                inData >> Scores[stuMemLoc][index];                                   // element [stuMemLoc]
            }
            stuMemLoc++;
            stuCount++;
            inData >> fixed >> setprecision(1) >> LstName[stuMemLoc]                  
                   >> FstName[stuMemLoc] >> stuID[stuMemLoc];
          }
    }
    
    return 0;
}
//******************************************************************************
