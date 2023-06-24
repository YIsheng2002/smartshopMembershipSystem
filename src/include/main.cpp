//this is just a test to call out the functions (._.
//later for the menu just call out the functions in case1 for add new member and case 2 for displaying the data that is saved in the file.

#include <iostream>
#include "adddisplaymember.h"

using namespace std;

int main() {
    MembersData membersData;
    int choice;

    do {
        cout << "Choose an option:" << endl;
        cout << "1. Add new member" << endl;
        cout << "2. Display members data" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                membersData.addnewmember();
                membersData.savedatatofile("membersdata.txt");
                break;
            case 2:
                membersData.readdatafromfile("membersdata.txt");
                membersData.displaydata();
                break;
            case 3:
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 3);

    return 0;
}
