#include <iostream>
#include <string>
using namespace std;
int main()
{
 string display;
 string word;
 char letter;
 int position ;
 int count;
 
 cout<<"gimme a word ";
 cin >> word;
 cout<<"gimme a letter ";
 cin>> letter;   
 position = 
         word.find(letter);
 display = word;
 count = 0;
 while (count < word.size())
   {
     display[count] = '_';
     count++; 
    }   
 if (position <= word.size())
   display[position] = letter;
   
 cout<<"the word is now ";
 count = 0;
 while (count <   
 display.size())
   {
    cout<<display[count]<<" ";
    count++;
   } 
 cout<<endl;   
 system("pause"); 
 return 0; 
}
