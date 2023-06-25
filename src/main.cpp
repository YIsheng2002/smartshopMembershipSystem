#include <iostream>
#include ".\include\Membership.h"
using namespace std;

void printMenu();

int main(){
    char cont = 't';
    string filename = "membershipList";
    int choice;
    Membership ms1;

    ms1.readFile(filename);
    while (cont!='f')
    {
        printMenu();
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            ms1.GetData();
            break;
        case 2:
            ms1.printData();
            break;
        case 3:
            ms1.deleteMember();
        case 4:
            ms1.SearchMember();
            break;
        case 5:
            ms1.sortMenu();
            break;
        case 6:
            ms1.writeFile(filename);
            break;
        case 7:
            ms1.deleteAllMember();
            break;
        case 8:
            cont= 'f';
        default: 
            std::cout << "Invalid input pls enter the number in the menu.";
            break;
        }
    }  
    return 0;
}

    void printMenu() {
        std::cout << "MENU"<< endl;
        std::cout << "______________________"<< endl;
        std::cout << "1. Add Member" << endl;
        std::cout << "2. Display Member" << endl;
        std::cout << "3. Delete Member" << endl;
        std::cout << "4. Search Member" << endl;
        std::cout << "5. Sort Member"<< endl;
        std::cout << "6. Save to file" << endl;
        std::cout << "7. Delete All Member" << endl;
        std::cout << "8. Exit"<< endl;
        std::cout << "______________________"<< endl;
    }