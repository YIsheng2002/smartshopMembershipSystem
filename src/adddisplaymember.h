#ifndef ADDDISPLAYMEMBER_H
#define ADDDISPLAYMEMBER_H

#include <fstream>

using namespace std;

struct Node 
{
    int id;
    string name;
    int age;
    Node* pnext;
};

class MembersData 
{
public:
    Node* phead;
    void savedatatofile(int id, string name, int age);
    MembersData();
    void adddata(string name, int age);
    void addnewmember();
    void displaymemberdata();
};




#endif
