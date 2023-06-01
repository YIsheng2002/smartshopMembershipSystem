#include <iostream>
#include ".\include\Membership.h"
using namespace std;

Membership::Membership(){
    numMember = 0;
    pHead = 0;
}

Membership::~Membership(){}

void Membership::AddToFront(){
    string name;
    int age;
    Member *pNew = new Member;
    cout << "Enter member's name: ";
    cin >> name;
    cout << "Enter member's age: ";
    cin >> age;
    pNew->memberID = ++numMember;
    pNew->name = name;
    pNew->age = age;
    pNew->link = pHead;
    pHead = pNew;
}

void Membership::printData(){
    pCurr = pHead;
    while (pCurr != 0)
    {
        cout << "Member's id : " << pCurr->memberID << endl;
        cout << "Member's name : " << pCurr->name << endl;
        cout << "Member's age : " << pCurr->age << endl;
        pCurr = pCurr->link;
    }
    cout << endl;    
}



