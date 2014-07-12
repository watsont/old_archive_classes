/*
        Written by Watson Tong
                05/10/2008
                Program 1: Adventure
                Revised: 05/19/2008

        This program prompts the user for their name and the total number of adventurers.
        For each "turn" in the story, the user will have gained treasure at a fixed amount. The program will output
            the total amount of treasure the user has at the end of that "adventure".
        On that same turn, the user will have lost a certain percentage of adventurers. The number of remaining
            members will be outputed by the program as well.

*/
#include <iostream>
#include <string>

using namespace std;

string first;                                       //First name
string last;                                        //Last name
const int TREASURE_GAIN = 1234;                     //Rate of treasure gained per turn
const float LIVES = .75;                            //Fixed constant pertaining to lives lost per turn


int main()
{
    int party;                                      //Party must be integer; is the team + user
    int team;                                       //Team must be integer; is everyone except user
    string notEnough;                               //Not enough team members; used for output on l
    
    
    notEnough = "You do not have enough members. Please re-enter.";
    
    cout << "Please enter your first name: ";       //Prompts user to input first name
    cin  >> first;                                  //Stores first name
    cout << "Please enter your last name: ";        //Prompts for last name
    cin  >> last;                                   //Stores last name
    cout << "Hello " << first <<" "<< last<< "!"
         << endl
         << "You have initiated the "
         << "Pirate Adventure game!" << endl << endl;
    cout << "How many team members will you have?"
         << endl 
         <<"(please choose at least 15 members) ";
    cin  >> team;                                   //Prompts number of teammates
        
        while(team < 15)                            //Causes Loop if user enters less than 9 partners
           {cout << notEnough << endl;
            cin >> team;
           }
        
        party = team + 1;                           //Total amount of party members stored (Close to useless)
        
    cout << endl << endl
         << "And so the story unfolds:"
         << endl << endl
         <<"The brave party of " << party << " adventurers "
         << "go off on an adventure." << endl << endl << endl;
        
    cout << "They come across a strange purple cave and enter it. "                  //Story 1
         << endl << "On entering, Wimpy Wallace wets his shorts. "
         << "He and a few cowards leave for fear of spiders. "
         << "On the plus side, he has dropped "
         << TREASURE_GAIN<< " gold, which you take greedily." << endl << endl
         << "You have "<< int((team*LIVES)+.5)                    //Amount of followers the user has left
         << " members left and "                    
         << TREASURE_GAIN << " gold."<< endl << endl;                        
         
    system("PAUSE");                                       //Useful for Dev-C++ and makes reading easier for user to digest
                    
                    
    cout << endl << endl
         <<"Your party continues traveling. After a long journey, "                  //Story 2
         << endl << "you come across a giant statue whose hands hold a lever."
         << endl << "One of your party members pulls it and a trap springs."
         << endl <<"THOMP! You have gained "<< TREASURE_GAIN <<" gold, "
         << endl <<"but at the cost of your teammate's lives." << endl
         << endl<< "There are "
         << int((party*LIVES*LIVES)+.5) << " people left."  //Total amount of ALL adventurers left (different from followers!)
         << endl <<"You have a total of " << TREASURE_GAIN*2<<" gold."
         << endl << endl;
         
         system("PAUSE");                                  //Useful for Dev-C++ and makes reading easier for user to digest
         
    cout << endl << endl                                                             //Story 3
         <<"Your adventure comes to a halt as you reach a dead end. Not surprisingly, "
         << endl<<"your crew become mutinous. You quickly confront the rebellion and find that "
         << endl <<"the traitors have been hiding extra portions of food as well as gold "
         << endl <<"from the party the whole time. You once again have your crew under your control. "
         << endl <<"You take the traitors' share of food and gold."
         << endl << endl
         <<"You have a total of "<< int((team*LIVES*LIVES*LIVES)+.5) << " crew members"
         << endl <<"that are (for the moment) loyal to you "
         <<"as well as " << TREASURE_GAIN*3           //Final amount of followers as well as gold
         <<" gold. " << endl << endl
         <<"What an adventure! There are "<< int((party*LIVES*LIVES*LIVES)+.5)<< " lives left!"<< endl
         <<"And a whopping " <<TREASURE_GAIN*3<<" gold obtained!"
         << endl << endl;

system("PAUSE");                                           //Useful for Dev-C++ and makes reading easier for user to digest

return 0;
}
