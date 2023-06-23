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
    void adddata(string name, int age, string tel, string address, string datein, string dateout);
    void displaydata();
    void readdatafromfile(const string& filename);
    void savedatatofile(const string& filename);
    
    //void displaymemberdata(const string& filename);
    void clearlinkedlist();
};

#endif
