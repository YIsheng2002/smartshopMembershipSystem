#ifndef ADDDISPLAYMEMBER_H
#define ADDDISPLAYMEMBER_H

#include <fstream>

using namespace std;

struct Node {
    int id;
    string name;
    int age;
    string tel;
    string address;
    string datein;
    string dateout;
    Node* pnext;
};

class MembersData {
public:
    Node* phead;

    MembersData();
    void addnewmember();
    void displaydata();
    void readdatafromfile(const string& filename);
    void savedatatofile(const string& filename);
    void clearlinkedlist();
};

#endif
