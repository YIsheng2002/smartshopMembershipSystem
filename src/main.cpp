#include <iostream>
#include ".\include\Membership.h"
using namespace std;

int main(){
    char cont = 't';
    int choice;
    Membership ms1;

    while (cont=='t')
    {
        cout << "MENU"<< endl;
        cout << "1. Add Item" << endl;
        cout << "2. Display Item" << endl;
        cout << "3. Sort Item" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            ms1.AddMember();
            break;
        case 2:
            ms1.printData();
            break;
        case 3:
            cout << ms1.merge_sort(ms1.pHead);
            break;
        default: 
            break;
        }

        cout << "Do you want to continue(t/f):";
        cin >> cont;
    }

    return 0;
}