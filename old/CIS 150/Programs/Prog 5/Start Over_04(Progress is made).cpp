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
     string LstName[], string FstName[], int stuID[], float scores[][SCORE_COLMS]);
float IndvStuAvg (int stuMemLoc, int stuCount, float scores[][SCORE_COLMS]);

int main()
{
	ifstream inData;
    ofstream outData;   
    int stuMemLoc = 0;
    int stuCount = 0;
    float stu_total = 0.0;
	string LstName[MAX_STUDENTS];
    string FstName[MAX_STUDENTS];
    int stuID[MAX_STUDENTS];
	float scores[MAX_STUDENTS][SCORE_COLMS];
	
	inData.open("prog5data.txt");
    outData.open("newData.txt");
	ReadData(inData, stuCount, stuMemLoc, LstName, FstName, stuID, scores);
	
	//Add A Legend for cout such as avg = average in case there is not enough room.
	cout << "Legend: \nID  = Student ID\n" << "S-  = score of that subject\n"
	     << "AVG = Student's Average Score\n" << endl;
	
	
	cout << "Student Name " << setw(4) << "ID" << setw(6) << "S1" << setw(6) << "S2"
         << setw(6) << "S3" << setw(6) << "S4" << setw(6) << "S5" << setw(6) << "S6"
         << setw(6) << "S7" << setw(6) << "S8" << endl;
    // Prints out student's name, ID, subject scores, and average score
    for (stuMemLoc = 0; stuMemLoc < stuCount; stuMemLoc++) {
            cout << LstName[stuMemLoc] << " " << FstName[stuMemLoc]
                 << setw(6) << stuID[stuMemLoc];
            for(int i = 0; i < SCORE_COLMS; i++) {
                //code
            cout << fixed << setprecision(1) << setw(5)<< scores[stuMemLoc][i] << " ";
            }
            cout << endl; 
            stu_total = IndvStuAvg (stuMemLoc, stuCount, scores);
            //cout  << '\t' << setw(12) << stu_total << endl;
    }
    
    
    system("PAUSE");
	return 0;
}
//******************************************************************************
//void ReadData (ifstream& inData, int stuCount, int stuMemLoc, string LstName[],
//             string FstName[], int stuID[], float scores[][SCORE_COLMS])
               
float IndvStuAvg (int stuMemLoc, int stuCount, float scores[][SCORE_COLMS])
{
     float temp = 0.0;
     float stuAvg =0.0;
     for (int index = 0; index < SCORE_COLMS; index++) {
         temp = temp + scores[stuMemLoc][index];
     }
     
     stuAvg = temp/SCORE_COLMS;    
     return stuAvg;
}
//******************************************************************************
void ReadData (ifstream& inData, int& stuCount, int stuMemLoc, string LstName[],
               string FstName[], int stuID[], float scores[][SCORE_COLMS])
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
                inData >> scores[stuMemLoc][index];  
            }
            stuMemLoc++;
            stuCount++;
            inData >> LstName[stuMemLoc] >> FstName[stuMemLoc] >> stuID[stuMemLoc];
          }
    }
}
//******************************************************************************

     
