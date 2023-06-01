#include <iostream>
#include ".\include\Membership.h"
using namespace std;

int main(){
    char cont = 't';
    int choice;
    Membership ms1;

    while (cont=='t')
    {
        cout << "MENU :" << endl;
        cout << "1. Add Member" << endl;
        cout << "2. Display Member" << endl;        
        cin >> choice;

        if (choice == 1)
        {
            ms1.AddToFront();
        } else{
            ms1.printData();
        }
        

        cout << "Do you want to continue? (t/f)";
        cin >> cont;
        cout << endl << endl;
    }
    

    return 0;
}
