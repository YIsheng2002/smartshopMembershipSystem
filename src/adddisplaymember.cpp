#include <iostream>
#include "adddisplaymember.h"
using namespace std;



MembersData::MembersData() 
{
    phead = nullptr;
}



void MembersData::addnewmember() 
{
    string name;
    int age;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
    adddata(name, age);
}



void MembersData::adddata(string name, int age) //add new member
{ 
    Node* newNode = new Node; //create new node
    newNode->name = name;
    newNode->age = age;
    newNode->pnext = nullptr;

    if (phead == nullptr) //if the list is empty
    { 
        newNode->id = 1;
        phead = newNode;
    } else 
    {
        Node* temp = phead; //temp pointer to go thru the list
        while (temp->pnext != nullptr) 
        {
            temp = temp->pnext;//move to the next node
        }
        newNode->id = temp->id + 1; //set the newnode id to the last node +1
        temp->pnext = newNode;
    }
    savedatatofile(newNode->id, name, age); 
    cout << "Data sucessfully added!" << endl;
}




void MembersData::displaymemberdata() 
{
    ifstream file("membersdata.txt");
    if (!file) 
    {
        cout<<"error"<<endl;
        return;
    }

    string line;
    while (getline(file, line)) 
    {
        cout << line << endl;
    }
    file.close();
}



void MembersData::savedatatofile(int id, string name, int age) 
{
    ofstream file("membersdata.txt", ios::app);//append to existing content of the file
    file << "ID: " << id << " | Name: " << name << " | Age: " << age << endl;
    file.close();
}


