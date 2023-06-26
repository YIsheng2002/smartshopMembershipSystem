#include <iostream>
#include ".\include\Membership.h"
using namespace std;

void printMenu();

int main(){
    char cont = 't';
    string filename = "membershipList";
    int choice;
    Membership ms1;
    cout << "Welcome to Smartshop Membership System\n\n";

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
            break;
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
            break;
        default: 
            std::cout << "Invalid input pls enter the number in the menu.";
            break;
        }
    }  
    return 0;
}

void printMenu(){
    std::cout << "Menu\n";
    std::cout << "_____________________\n";
    std::cout << "1. Add Member\n";
    std::cout << "2. Display Member\n";
    std::cout << "3. Delete Member\n";
    std::cout << "4. Search Member\n";
    std::cout << "5. Sort Member\n";
    std::cout << "6. Save to File\n";
    std::cout << "7. Delete All Member\n";
    std::cout << "8. Exit\n";
    std::cout << "______________________\n";
}
