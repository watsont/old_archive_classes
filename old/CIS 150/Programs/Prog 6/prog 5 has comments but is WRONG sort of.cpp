/*
        Written by Watson Tong
                07/28/08
                Program 4: Banking
                Revised: 08/04/08
        Professor: Kiumi Akingbehin
        CIS 150: SU 08

        The purpose of this program is to continue to build on C++ skills.
        This time, we are writing a program that builds on using arrays. We are to
        take values from a file and then input them into arrays, where we will compute
        the student's individual averages, the averages of the subject, the averages of
        the students' averages, and the averages of the subjects' scores.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Global Constants
const int MAX_STUDENTS = 40;
const int SCORE_COLMS = 8;

//Function Prototypes
int ReadData (ifstream& inData, int& stuCount, int stuMemLoc,
     string LstName[], string FstName[], int stuID[], float Scores[][SCORE_COLMS]);
void IndvStuAvg (int stuMemLoc, int stuCount, float StudentAverage[],
                 float Scores[][SCORE_COLMS]);
void SubjAvg(int stuMemLoc, int stuCount, float SubjectAverage[],
              float Scores[][SCORE_COLMS]);
int main()
{
	ifstream inData;                                                            //Used to obtain data from file 
    int stuMemLoc = 0;                                                          //Used for a position in the array
    int stuCount = 0;                                                           //Will be passed as reference; keeps track of students
    float combStuAvg = 0.0;                                                     //Used for computing combined student average
    float combSubAvg = 0.0;                                                     //Used for computing combined subject average
	string LstName[MAX_STUDENTS];                                               //Array to hold Last Name
    string FstName[MAX_STUDENTS];                                               //Array to hold First Name
    int stuID[MAX_STUDENTS];                                                    //Array to hold Student ID
	float Scores[MAX_STUDENTS][SCORE_COLMS];                                    //Array to hold Students' scores
	float SubjectAverage[MAX_STUDENTS];                                         //Array to hold the average of each subject
	float StudentAverage[SCORE_COLMS];                                          //Array to hold the average of each student
	
	inData.open("prog5data.txt");                                               //Opens up file
	ReadData(inData, stuCount, stuMemLoc, LstName, FstName, stuID, Scores);
	                                                                            //Prints headings
	cout << "Legend: \nID  = Student ID\n" << "S#  = score of that subject\n"
	     << "AVG = Student's Average Score\n" << endl;
	     
	cout << "Student Name" << '\t'  << setw(3) << "ID" << setw(6) 
         << "S1" << setw(5) << "S2" << setw(5) << "S3" << setw(5)
         << "S4" << setw(5) << "S5" << setw(5) << "S6" << setw(5)
         << "S7" << setw(5) << "S8" << setw(7) << "AVG" << endl;
                                                                                // Prints out student's name, ID, subject Scores,
                                                                                
                                                                                cout << "stuMemLoc is " << stuMemLoc << endl;
    for (stuMemLoc = 0; stuMemLoc < stuCount; stuMemLoc++) {                    // and average score
        //cout << LstName[stuMemLoc] << " " << FstName[stuMemLoc]
          //   << '\t' << stuID[stuMemLoc];
        /*for(int i = 0; i < SCORE_COLMS; i++) {
            cout << fixed << setprecision(1) << setw(5)
                 << Scores[stuMemLoc][i];
        }*/
		
		cout << "stuMemLoc is currently at " << stuMemLoc << endl;
                                                                                    ///////////////////////////////////////
		IndvStuAvg (stuMemLoc, stuCount, StudentAverage, Scores);					//****** FOCUSING ON THIS FUNCTION/////
		cout << setw(7) << StudentAverage[stuMemLoc] << endl;
		//void IndvStuAvg (int stuMemLoc, int stuCount, float StudentAverage[],
          //       float Scores[][SCORE_COLMS]);
    }
                                                                                //Prints out average of subject score
    cout << "Subject Averages:    ";
    SubjAvg(stuMemLoc, stuCount, SubjectAverage, Scores);
    for(int j = 0; j < SCORE_COLMS; j++) {   
        cout << fixed << setprecision(1) << setw(5)
             << SubjectAverage[j];
        }
     
     cout << "\nstuMemLoc is " << stuMemLoc << endl;
     SubjAvg(stuMemLoc, stuCount, SubjectAverage, Scores);
                                                                                //Prints out average of students avg
    cout << "\n\nAVERAGE SCORE USING STUDENT AVERAGES: ";
         for (int k = 0; k < stuCount; k++) {
             combStuAvg = combStuAvg + StudentAverage[k];
         }
         cout << combStuAvg/stuCount;
                                                                                //Prints out average of subject avg
    /*cout << "\nAVERAGE SCORE USING SUBJECT AVERAGES: ";
         for (int l = 0; l < SCORE_COLMS; l++) {
             combSubAvg = combSubAvg + SubjectAverage[l];
         }
         cout << combSubAvg/SCORE_COLMS << endl << endl;*/
    system("PAUSE");
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
        temp = 0.0;                              //Resets temp so it won't hold previous values
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
                 << "directory as this source file. \n" << endl;
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
}
