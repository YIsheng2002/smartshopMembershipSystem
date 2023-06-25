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
            ms1.SearchMember();
            break;
        case 4:
            ms1.sortMenu();
            break;
        case 5:
            ms1.writeFile(filename);
            break;
        case 6:
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
        std::cout << "1. Add Member" << endl;
        std::cout << "2. Display Member" << endl;
        std::cout << "3. Search Member" << endl;
        std::cout << "4. Sort Member"<< endl;
        std::cout << "5. Save to file" << endl;
        std::cout << "6. Exit"<< endl;
    }