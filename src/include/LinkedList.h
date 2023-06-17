#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <fstream>
using namespace std;

struct Node 
{
    int id;
    string name;
    int age;
    Node* pnext;
};

class LinkedList 
{
private:
    Node* phead;
    void saveDataToFile(int id, string name, int age);
public:
    LinkedList();
    void addData(string name, int age);
    void displayData();
};

#endif
