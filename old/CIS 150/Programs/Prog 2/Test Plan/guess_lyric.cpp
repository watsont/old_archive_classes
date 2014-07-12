/*
        Written by Watson Tong
                05/25/2008
                Program 2: Lyric Guess
                Revised: 
                        
        This program will output several lines of lyrics from a song of the programmer's
        choice (Don't Stop Believing). It is up to the user to guess the next four words
        of the song when prompted by the program. The program will then compare the given
        input from the user to the programmer's stored(expected) output. The user is given
        a total of two tries to complete the missing words. At the end of each try, the
        program displays the number of correct words the user has guessed and an
        appropriate message (correctly guessed all = "Congratulations!"; other results
        will be "Nice Try!".
        
        In the case that the user does not choose the correct words in the first try, the
        user will be given by the program the first two words as a hint. Following this
        will be another prompt for the user to correctly guess the words for a last try.
        Again, the program will display how many words the user has guessed correctly and
        give an appropriate message. The program now outputs to the console the correct
        word and terminates.
  
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
                                                                              //Declare variables
    string allRight;
    string someRight;
    string lyrics;
    string word1;
    string word2;
    string word3;
    string word4;
    string ans1;
    string ans2;
    string ans3;
    string ans4;
    string format;
    string horizStar;
    int tries;
    int correct;
    
    allRight = "Good job! You got all of them right...";                      //Output when all words are correct
    someRight = "Good try. Better luck next time!";                           //Output when not all words are correct
    lyrics = "\"Just a small town girl, living in a lonely world\" ";
    ans1 = "she";                                                             //Assigned values for words to be compared to
    ans2 = "took";                                                            //Same as above
    ans3 = "the";                                                             //Same as above
    ans4 = "midnight";                                                        //Same as above
    tries = 0;                                                                //Used for looping statement
    correct = 0;                                                              //Used for number of correct guesses
    format = "\", \"";                                                        //Useful for placing quotation marks around output
    horizStar = "*******************************************************";    //Separates lines for easier reading of output
                                                                              //Reminder to self of lyric to fill in:
                                                                              //She took the midnight train going anywhere
    
    cout << "Guess the next 4 words for the song. "                           //Prompts user for input
         << "Please use lowercase letters" << endl
         << "(punctuation not needed)! " << endl;
         
    while (tries<2)                                                           //Loop ensures user only has two tries
          {
                 cout << endl << horizStar
                      << endl << "After entering first word, press enter and continue "      //More prompt info and given lyrics
                      << endl << "to enter the rest of the words. " << endl << endl 
                      << lyrics << endl << endl;
                 cin  >> word1 >> word2 >> word3 >> word4;                                   //Input from user
                 cout << endl << "you have entered " << "\"" << word1 << format << word2     //Echoes input
                      << format << word3 << "\"" << ", and "<< "\"" << word4 << "\""
                      << endl << endl;
                                                                                             //Compares for at least
                                                                                             //one wrong word
                                                                                             //If all words are not right, then...
                      if (word1 != ans1 || word2 != ans2 || word3 != ans3 || word3 != ans3 || word4 != ans4)
                      {
                                if(word1 == ans1)                                            //If word # is equal to ans #, then
                                         correct++;                                          //increment correct by one
                                if(word2 == ans2)
                                         correct++;
                                if(word3 == ans3)
                                         correct++;
                                if(word4 == ans4)
                                         correct++;
                                                                                           //Outputs number of words correct
                                cout << "You answered " << correct <<" word(s) right! \n"
                                     << someRight << endl;
                                     
                                     if (tries!=1)                                         //Hint displays, but only
                                                                                           //on first failure
                                     {
                                                   cout << "*Hint*: the first two words are \"" << ans1
                                                        <<"\" \"" << ans2 << "\" ." << endl;
                                     }
                                correct=0;
                       }
                                                                                           //Compares for all words correct
                      else if(word1 == ans1 && word2 == ans2 && word3 == ans3 && word3 == ans3 && word4 == ans4)
                      { 
                                     cout << endl << allRight << endl;
                                     
                                     tries=2;                                             //Forces the while loop to end because
                      }                                                                   //the user has guessed all words right
                           
                 cin.sync();                                                              //Discards data stored in words to
                                                                                          //prevent extra words in first try from
                                                                                          //appearing in secord try
                                                                                          
                 tries++;                                                                 //Increases counter for tries
          }                                                                               //to be used in loop
                                                                              
    cout << endl << horizStar << endl                                         //Outputs last messages
         << "The correct words are: \"" << ans1 << format << ans2
         << format << ans3 << format << ans4 << "\"." << endl
         << horizStar << endl
         << endl << "That's it for today in...Don't Forget The Lyrics(TM) Home Edition!"
         << endl << endl;
    
system("pause");
return 0; 

}


