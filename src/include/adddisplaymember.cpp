#include "adddisplaymembers.h"
#include <iostream>
#include <fstream>
#include <limits>

MembersData::MembersData() {
    phead = nullptr;
}

void MembersData::addnewmember() {
    Node* newNode = new Node;
    newNode->pnext = nullptr;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newNode->data[0]);
    cout << "Enter age: ";
    cin >> newNode->data[1];
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter phone number: ";
    getline(cin, newNode->data[2]);
    cout << "Enter address: ";
    getline(cin, newNode->data[3]);
    cout << "Enter date registered: ";
    getline(cin, newNode->data[4]);
    cout << "Enter expiration date: ";
    getline(cin, newNode->data[5]);

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
             << temp->data[0] << endl
             << temp->data[1] << endl
             << temp->data[2] << endl
             << temp->data[3] << endl
             << temp->data[4] << endl
             << temp->data[5] << endl
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

    int id = 1;
    string line;
    while (getline(file, line)) {
        Node* newNode = new Node;
        newNode->id = id++;

        for (int i = 0; i < 6; ++i) {
            getline(file, newNode->data[i]);
        }

        newNode->pnext = nullptr;

        if (phead == nullptr) {
            phead = newNode;
        } else {
            Node* temp = phead;
            while (temp->pnext != nullptr) {
                temp = temp->pnext;
            }
            temp->pnext = newNode;
        }

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
        file << temp->id << "\n";
        for (int i = 0; i < 6; ++i) {
            file << temp->data[i] << "\n";
        }
        file << "------" << "\n";
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
