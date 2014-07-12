#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Global Constants
const int MAX_STUDENTS = 40;
const int SCORE_COLMS = 8;

//Function Prototypes
void ReadData (ifstream& inData, int& stuCount, int stuMemLoc,
     string LstName[], string FstName[], int stuID[], float Scores[][SCORE_COLMS]);
float IndvStuAvg (int stuMemLoc, int stuCount, float StudentAverage[],
                 float Scores[][SCORE_COLMS]);
void SubjAvg(int stuMemLoc, int stuCount, float SubjectAverage[],
              float Scores[][SCORE_COLMS]);
int main()
{
	ifstream inData;
    ofstream outData;   
    int stuMemLoc = 0;
    int stuCount = 0;
    float stu_total = 0.0;
    float combStuAvg = 0.0;
	string LstName[MAX_STUDENTS];
    string FstName[MAX_STUDENTS];
    int stuID[MAX_STUDENTS];
	float Scores[MAX_STUDENTS][SCORE_COLMS];
	float SubjectAverage[MAX_STUDENTS];
	float StudentAverage[SCORE_COLMS];
	
	inData.open("prog5data.txt");
    outData.open("newData.txt");
	ReadData(inData, stuCount, stuMemLoc, LstName, FstName, stuID, Scores);
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
                 << Scores[stuMemLoc][i]; //<< " ";
            }
        stu_total = IndvStuAvg (stuMemLoc, stuCount, StudentAverage, Scores);
        cout << setw(7) << stu_total << endl;
    }
    
    cout << endl << "Subject averages:    ";
    SubjAvg(stuMemLoc, stuCount, SubjectAverage, Scores);
        for(int j = 0; j < SCORE_COLMS; j++) {   
            cout << fixed << setprecision(1) << setw(5)
                 << SubjectAverage[j];
        }
    cout << "Average of student averages: ";
         
         for (int k = 0; k < stuCount; k++) {
             
         
             combStuAvg = 0;
         }
    cout << endl;
    
    system("PAUSE");
	return 0;
}
//******************************************************************************
//void ReadData (ifstream& inData, int stuCount, int stuMemLoc, string LstName[],
//             string FstName[], int stuID[], float Scores[][SCORE_COLMS])
void SubjAvg(int stuMemLoc, int stuCount, float SubjectAverage[],
              float Scores[][SCORE_COLMS])
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
float IndvStuAvg (int stuMemLoc, int stuCount, float StudentAverage[],
                  float Scores[][SCORE_COLMS])
{
     float temp = 0.0;
     float stuAvg =0.0;
     for (int index = 0; index < SCORE_COLMS; index++) {
         temp = temp + Scores[stuMemLoc][index];
     }
     
     stuAvg = temp/SCORE_COLMS;    
     return stuAvg;
}
//******************************************************************************
void ReadData (ifstream& inData, int& stuCount, int stuMemLoc, string LstName[],
               string FstName[], int stuID[], float Scores[][SCORE_COLMS])
{
    stuCount = 0;
    stuMemLoc = 0;
    
    if(!inData) {
            cout << "No file to read. Please make sure file is in same"
                 << "directory as this source file. \n" << endl;
            cin.get();
        }
    else {
        //Priming Read
        inData >> LstName[stuMemLoc] >> FstName[stuMemLoc] >> stuID[stuMemLoc];
        while (!inData.eof())
        {    
            for (int index =0; index < SCORE_COLMS; index++) {
                inData >> Scores[stuMemLoc][index];  
            }
            stuMemLoc++;
            stuCount++;
            inData >> LstName[stuMemLoc] >> FstName[stuMemLoc] >> stuID[stuMemLoc];
          }
    }
}
//******************************************************************************

     
