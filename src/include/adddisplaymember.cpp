#include "adddisplaymember.h"
#include <iostream>
#include <fstream>
#include <limits>

MembersData::MembersData() {
    phead = nullptr;
}

void MembersData::addnewmember() {
    Node* newNode = new Node;
    newNode->pnext = nullptr;

    // Read member details from the user
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newNode->name);
    cout << "Enter age: ";
    cin >> newNode->age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter phone number: ";
    getline(cin, newNode->tel);
    cout << "Enter address: ";
    getline(cin, newNode->address);
    cout << "Enter date registered: ";
    getline(cin, newNode->datein);
    cout << "Enter expiration date: ";
    getline(cin, newNode->dateout);

    // Assign an ID to the new member and update the linked list
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

    clearlinkedlist();

    int id;
    string name;
    int age;
    string tel;
    string address;
    string datein;
    string dateout;
    string line;

    Node* prevNode = nullptr;

    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        id = stoi(line);

        getline(file, name);
        file >> age;
        file.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(file, tel);
        getline(file, address);
        getline(file, datein);
        getline(file, dateout);

        Node* newNode = new Node;
        newNode->id = id;
        newNode->name = name;
        newNode->age = age;
        newNode->tel = tel;
        newNode->address = address;
        newNode->datein = datein;
        newNode->dateout = dateout;
        newNode->pnext = nullptr;

        if (prevNode == nullptr) {
            phead = newNode;
        } else {
            prevNode->pnext = newNode;
        }

        prevNode = newNode;

        getline(file, line); // Skip the separator line "------"
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

    phead = nullptr;
}
