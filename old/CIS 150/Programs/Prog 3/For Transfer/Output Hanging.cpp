
/*#include <iostream>

using namespace std;

void OutputHanging (int);

int main()
{
    int wrong =0;
    
    cout << "place in wrong for trials. \n";
    cin >> wrong;
    OutputHanging (wrong);
    
    system("pause");
    return 0;
}
*/                                      //Everything works so far.
void OutputHanging (int wrong)
{
     if (wrong == 6)                        //User attmepts to guess word with 6 fails
        cout << endl                        
             << "       __________        " << endl
             << "       |         }       " << endl
             << "       |        \\O/     " << endl
             << "       |         |       " << endl
             << "       |        / \\     " << endl
             << "       |                 " << endl
             << "_______|_________________" << endl
             << endl;
        else if (wrong == 5)                //User attmepts to guess word with 5 fails
        cout << endl
             << "       __________        " << endl
             << "       |         }       " << endl
             << "       |        \\O/     " << endl
             << "       |         |       " << endl
             << "       |        /        " << endl
             << "       |                 " << endl
             << "_______|_________________" << endl
             << endl;
        else if (wrong == 4)                //User attmepts to guess word with 4 fails
        cout << endl
             << "       __________        " << endl
             << "       |         }       " << endl
             << "       |        \\O/     " << endl
             << "       |         |       " << endl
             << "       |                 " << endl
             << "       |                 " << endl
             << "_______|_________________" << endl
             << endl;
        else if (wrong == 3)                //User attmepts to guess word with 3 fails
        cout << endl
             << "       __________        " << endl
             << "       |         }       " << endl
             << "       |        \\O      " << endl
             << "       |         |       " << endl
             << "       |                 " << endl
             << "       |                 " << endl
             << "_______|_________________" << endl
             << endl;
        else if (wrong == 2)                //User attmepts to guess word with 2 fails
        cout << endl
             << "       __________        " << endl
             << "       |         }       " << endl
             << "       |         O       " << endl
             << "       |         |       " << endl
             << "       |                 " << endl
             << "       |                 " << endl
             << "_______|_________________" << endl
             << endl;
        else if (wrong == 1)                //User attmepts to guess word with 1 fails
        cout << endl
             << "       __________        " << endl
             << "       |         }       " << endl
             << "       |         O       " << endl
             << "       |                 " << endl
             << "       |                 " << endl
             << "       |                 " << endl
             << "_______|_________________" << endl
             << endl;
        else if (wrong == 0)                //User attmepts to guess word with 0 fails
        cout << endl
             << "       __________        " << endl
             << "       |         }       " << endl
             << "       |                 " << endl
             << "       |                 " << endl
             << "       |                 " << endl
             << "       |                 " << endl
             << "_______|_________________" << endl
             << endl;

     return;
}
