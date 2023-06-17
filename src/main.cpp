//this is just a test to call out the functions (._.
//later for the menu just call out the function in case1 for add new member and case 2 for displaying the data that is saved in the file.

#include <iostream>
#include "adddisplaymember.h"

using namespace std;

int main() {
    MembersData membersData; //MembersData class
    int choice;

    do 
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add new member " << endl;
        cout << "2. Display members data" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                membersData.addnewmember();
                break;
            case 2:
                membersData.displaymemberdata();
                break;
            case 3:
                cout << "bye" << endl;
                break;
            default:
                cout << "no option. please try again" << endl;
                break;
        }
        cout << endl;
    } while (choice != 3);

    return 0;
}
