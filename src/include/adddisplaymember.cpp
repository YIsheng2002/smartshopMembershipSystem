#include <iostream>
#include "adddisplaymember.h"
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

MembersData::MembersData() {
    phead = nullptr;
}

void MembersData::addnewmember() {
    string name;
    int age;
    string tel;
    string address;
    string datein;
    string dateout;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter phone number: ";
    getline(cin, tel);
    cout << "Enter address: ";
    getline(cin, address);
    cout << "Enter date registered: ";
    getline(cin, datein);
    cout << "Enter expiration date: ";
    getline(cin, dateout);

    adddata(name, age, tel, address, datein, dateout);
}

void MembersData::adddata(string name, int age, string tel, string address, string datein, string dateout) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->age = age;
    newNode->tel = tel;
    newNode->datein = datein;
    newNode->dateout = dateout;
    newNode->address = address;
    newNode->pnext = nullptr;

    if (phead == nullptr) {
        newNode->id = 1;
        phead = newNode;
    } else {
        Node* temp = phead;
        while (temp->pnext != nullptr) {
            temp = temp->pnext;
        }
        newNode->id = temp->id + 1;
        temp->pnext = newNode;
    }
}

void MembersData::displaydata() {
    cout << "[MEMBERS DATA LIST START]" << endl;
    if (phead == nullptr) {
        cout << "No members data available." << endl;
        return;
    }

    Node* temp = phead;
    while (temp != nullptr) {
        cout << temp->id << endl
             << temp->name << endl
             << temp->age << endl
             << temp->tel << endl
             << temp->address << endl
             << temp->datein << endl
             << temp->dateout << endl
             << "-------------------------------------" << endl;
        temp = temp->pnext;
    }

    cout << "[MEMBERS DATA LIST END]" << endl;
}

void MembersData::readdatafromfile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open the file!" << endl;
        return;
    }

    clearlinkedlist(); // Clear the existing linked list before updating

    int id;
    string name;
    int age;
    string tel;
    string address;
    string datein;
    string dateout;
    string line;

    while (getline(file, line)) {
        if (line.empty()) {
            continue; // Skip empty lines
        }

        id = stoi(line);// Read the member's ID

        getline(file, name);
        file >> age;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(file, tel);
        getline(file, address);
        getline(file, datein);
        getline(file, dateout);

        adddata(name, age, tel, address, datein, dateout);

        // Skip the separator line "------"
        getline(file, line);
    }

    file.close();
}

void MembersData::savedatatofile(const string& filename) {
    ofstream file(filename, ios::trunc);
    if (!file) {
        cout << "Error: Could not open the file!" << endl;
        return;
    }

    Node* temp = phead;
    while (temp != nullptr) {
        file << temp->id << "\n"
             << temp->name << "\n"
             << temp->age << "\n"
             << temp->tel << "\n"
             << temp->address << "\n"
             << temp->datein << "\n"
             << temp->dateout << "\n"
             << "------" << "\n";
        temp = temp->pnext;
    }

    file.close();
}

void MembersData::clearlinkedlist() {
    Node* temp = phead;
    while (temp != nullptr) {
        Node* nextNode = temp->pnext;
        delete temp;
        temp = nextNode;
    }

    phead = nullptr; // Set the head pointer to null after clearing the list
}
