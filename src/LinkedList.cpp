#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() 
{
    phead = nullptr;
}

void LinkedList::addData(string name, int age) //add new member
{ 
    Node* newNode = new Node; //create new node
    newNode->name = name;
    newNode->age = age;
    newNode->pnext = nullptr;

    if (phead == nullptr) //if the list is empty
    { 
        newNode->id = 1;
        phead = newNode;
    } else {
        Node* temp = phead; //temp pointer to traverse the list
        while (temp->pnext != nullptr) 
        {
            temp = temp->pnext;//move to the next node
        }
        newNode->id = temp->id + 1; //set the newnode id to the last node +1
        temp->pnext = newNode;
    }
    saveDataToFile(newNode->id, name, age); 
    cout << "Data added successfully!" << endl;
}

void LinkedList::displayData() {
    ifstream file("membersdata.txt");
    if (!file) 
    {
        cout << "No data available." << endl;
        return;
    }

    string line;
    while (getline(file, line)) 
    {
        cout << line << endl;
    }
    file.close();
}

void LinkedList::saveDataToFile(int id, string name, int age) 
{
    ofstream file("membersdata.txt", ios::app);//append to existing content of the file
    file << "ID: " << id << " | Name: " << name << " | Age: " << age << endl;
    file.close();
}
