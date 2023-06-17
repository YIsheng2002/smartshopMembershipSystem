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
private:
    Node* phead;
    void saveDataToFile(int id, string name, int age);
public:
    MembersData();
    void addData(string name, int age);
    void displayData();
};


void addnewmember(MembersData& membersData);
void displaymemberdata(MembersData& membersData);

#endif