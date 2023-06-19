#include <iostream>
#include ".\include\Membership.h"
using namespace std;

Membership::Membership(){
    numMember = 0;
    pHead = 0;
    pTail = pHead;
}

Membership::~Membership(){}


void Membership::AddMember(){
    string name, phoneNo, address, startDate, endDate;
    int age;
    Member *pNew = new Member;
    cout << "Enter member's name: ";
    cin >> name;
    cout << "Enter member's age: ";
    cin >> age;
    cout << "Enter member's phone number: ";
    cin >> phoneNo;
    cout << "Enter member's address: ";
    cin >> address;
    cout << "Enter member's startDate: ";
    cin >> startDate;
    cout << "Enter member's endDate: ";
    cin >> endDate;
    pNew->memberID = ++numMember; 
    pNew->name = name;
    pNew->age = age;
    if(pHead == 0){
        pHead = pNew;
        pTail = pHead;
    } else{
        pTail->link = pNew;
        pTail = pNew;
    }
    cout << "Data sucessfully added!" << endl;
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

