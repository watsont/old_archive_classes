#include <iostream>
#include <string>

using namespace std;

int main()
{
    string display;
    string word;
    char letter;
    int position;
    int count;
    
    cout << "gimme a word ";
    cin >> word;
    cout << "gimme a letter";
    cin >> letter;
    position = word.find(letter);
    
    while(count < word.size())
    {
                display [count] = '_';
                count++;
    }
    if(position <= word.size())
    display[position]= letter;
    cout << "the word is now " << display;
    
    system("pause");
    return 0;
}
