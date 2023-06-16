#include <iostream>
#include "UserData.h"

using namespace std;

void addUserData(LinkedList& linkedList) {
    string name;
    int age;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    linkedList.addData(name, age);
}

void displayUserData(LinkedList& linkedList) {
    linkedList.displayData();
}
