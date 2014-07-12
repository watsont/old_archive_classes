//******************************************************************
// Profile Program
// This program inputs a name, weight, height, blood pressure readings, 
// and cholesterol values.  Appropriate health messages are written for
// each of the input vales.
//******************************************************************

#include <fstream>
#include <iostream>

using namespace std;

void Cholesterol(ofstream& healthProfile, int HDL, int LDL);
void BMI(ofstream& healthProfile, float pounds, float inches);  
void Blood(ofstream& healthProfile, int systolic, int diastolic);
int main()
{
  // Declare and open the output file
  ofstream healthProfile;
  healthProfile.open("Profile");
  
  // Declare the patient's name
  string firstName;
  string lastName;
  string middleInitial;
  
  // Declare the health statistics
  int HDL;
  int LDL;
  float pounds;
  float inches;
  int systolic;
  int diastolic;
  
  // Enter the patient's name
  cout << "Enter the patient's first name: ";
  cin >> firstName;
  cout << "Enter the patient's last name: ";
  cin >> lastName;
  cout << "Enter the patient's middle initial: ";
  cin >> middleInitial;
  
  // Enter the patient's health statistics
  cout << "Enter the patient's HDL: ";
  cin >> HDL;
  cout << "Enter the patient's LDL: ";
  cin >> LDL;
  cout << "Enter the patient's weight in pounds: ";
  cin >> pounds;
  cout << "Enter the patient's height in inches: ";
  cin >> inches;
  cout << "Enter the patient's systolic blood pressure reading: ";
  cin >> systolic;
  cout << "Enter the patient's diastolic blood pressure reading: ";
  cin >> diastolic;
  
  // Evaluate the patient's statistics
  healthProfile << "Patient's name: " << firstName << ' ' << middleInitial
    << ". " << lastName << endl;
  Cholesterol(healthProfile, HDL, LDL);
  BMI(healthProfile, pounds, inches);  
  Blood(healthProfile, systolic, diastolic);
  healthProfile << endl;
  healthProfile.close();
  return 0;
}   
  
//******************************************************************
// Cholesterol function
// This function takes HDL (good cholesterol) and LDL (bad cholesterol)
// as inputs and prints out a  health message based on their values 
// on file healthProfile.
//******************************************************************


void Cholesterol(ofstream& healthProfile, int HDL, int LDL)
{
  float ratio = LDL/HDL;		// Calculate ratio of LDL to HDD
  
  healthProfile << "Cholesterol Profile" << endl;
  // Print message based on HDL value
  if (HDL < 40)
    healthProfile << "   HDL is too low" << endl;
  else if (HDL < 60)
    healthProfile << "   HDL is okay" << endl;
  else
    healthProfile << "   HDL is excellent" << endl;    
  // Print message based on LDL value
  if (LDL < 100)
    healthProfile << "   LDL is optimal" << endl;
  else if (LDL < 130)
    healthProfile << "   LDL is near optimal" << endl;
  else if (LDL < 160)
    healthProfile << "   LDL is borderline high" << endl;
  else if (LDL < 190)
    healthProfile << "   LDL is high" << endl;
  else
    healthProfile << "   LDL is very high" << endl;
    
  if (ratio < 3.22)
    healthProfile << "   Ratio of LDL to HDL is good" << endl;
  else
    healthProfile << "   Ratio of LDL to HDL is not good" << endl;
}                 

//******************************************************************
// BMI Function
// This function takes weight in pounds and height in inches and
// calculates the body mass index (BMI prints a health message
// based on the BMI. Input in English weights.
//******************************************************************

void BMI(ofstream& healthProfile, float pounds, float inches)
{
  const int BMI_CONSTANT = 703;		// Constant in English formula
  
  float bodyMassIndex = pounds * BMI_CONSTANT / (inches * inches);
  
  healthProfile << "Body Mass Index Profile" << endl;
  
  // Print health message based on bodyMassIndex
  
  healthProfile << "   Your body mass index is " << bodyMassIndex << ". " << 
endl;
  healthProfile << "   Interpretation of BMI " << endl;
  if (bodyMassIndex < 20)
    healthProfile << "   Underweight: BMI is too low" << endl;
  else if (bodyMassIndex <= 25)
    healthProfile << "   Normal: BMI is average"  << endl;
  else if (bodyMassIndex <=  30)
    healthProfile << "   Overweight: BMI is too high"  << endl;
  else
    healthProfile << "   Obese: BMI is dangerously high" << endl;
}  

//******************************************************************
// Blood Pressure function
// This function takes blood pressure readings (systolic/diastolic)
// as inputs and prints out a  health message based on their values 
// on file healthProfile.
//******************************************************************


void Blood(ofstream& healthProfile, int systolic, int diastolic)
{
   healthProfile << "Blood Pressure Profile" << endl;
   if (systolic < 120)
     healthProfile << "   Systolic reading is optimal" << endl;
   else if (systolic < 130)
     healthProfile << "   Systolic reading is normal" << endl;
   else if (systolic < 140)
     healthProfile << "   Systolic reading is high normal" << endl;  
   else if (systolic < 160)
     healthProfile << "   Systolic indicates hypertension Stage 1" << endl;
   else if (systolic < 180)
     healthProfile << "   Systolic indicates hypertension Stage 2" << endl;
   else
     healthProfile << "   Systolic indicates hypertension Stage 3" << endl;
     
   if (diastolic < 80)
     healthProfile << "   Diastolic reading is optimal" << endl;
   else if (diastolic < 85)
     healthProfile << "   Diastolic reading is normal" << endl;
   else if (diastolic < 90)
     healthProfile << "   Diastolic reading is high normal" << endl;
   else if (diastolic < 100)
     healthProfile << "   Diastolic indicates hypertension Stage 1" << endl;
   else if (diastolic < 110)
     healthProfile << "   Diastolic indicates hypertension Stage 2" << endl;
   else
     healthProfile << "   Diastolic indicates hypertension Stage 3" << endl;
}                
       
          

