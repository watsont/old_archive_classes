#include <iostream>
#include <string>

using namespace std;

int main()
{
    string display;
    string word;
    string space = " ";
    char letter;
    int position;
    int count;
    
    cout << "gimme a word ";
    cin >> word;
    cout << "gimme a letter ";
    cin >> letter;
    
    position = word.find(letter);
    display = word;
    count = 0;
    
    while(count < display.size())
    {
                display [count] = '_';
                display.insert(count, space);
                count=count + 2;
    }
    if(position <= word.size())
    display[position]= letter;
    cout << "the word is now " << display
         << " " << endl;
    
    system("pause");
    return 0;
}
