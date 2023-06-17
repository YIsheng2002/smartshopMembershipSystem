//this is just a test to call out the functions (._.
//later for the menu just call out the function in case1 for add new member and case 2 for displaying the data that is saved in the file.

#include <iostream>
#include "LinkedList.h"
#include "UserData.h"

using namespace std;

int main() {
    LinkedList linkedList; //LinkedList class
    int choice;

    do 
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add user data" << endl;
        cout << "2. Display user data" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addUserData(linkedList);
                break;
            case 2:
                displayUserData(linkedList);
                break;
            case 3:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        cout << endl;
    } while (choice != 3);

    return 0;
}
