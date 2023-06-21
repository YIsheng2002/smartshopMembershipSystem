#include <iostream>
#include <iomanip>
#include ".\include\Membership.h"
using namespace std;

Membership::Membership(){
    numMember = 0;
    pHead = 0;
    pTail = pHead;
}

Membership::~Membership(){}

//Name:Yasrizal Hakim Bin Yaresham
//This function is to add new member to the end of the linked list
void Membership::AddMember(){
    string name, phoneNo, address, startDate, endDate;
    int age;
    Member *pNew = new Member;
    //get user input
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
    //add data into Node of linked list
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

//Written by: Yasrial Hakim Bin Yaresham
//This function display all the member's datas in linked list
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

// Written by Emanuel Ling Hao En
// Seach member by id, name or age
void Membership::searchMember(){
    char option;
    string target;
    bool found = false, valid = true, haveTitle = false;
    cout << "Search by: a) MemberID  b) name  c) age" << endl;
    cin >> option;

    if (option == 'a' || option == 'A') // search by memberID
    {
        int target_id;
        cout << "Please enter target member id: ";
        cin >> target_id;
        
        pCurr = pHead;
        while (pCurr != nullptr)
        {
            if (pCurr->memberID == target_id) // found the Member by MemberID
            {
                if (!haveTitle)
                {
                    cout << setw(10) << "Member ID" << setw(20) << "Name" << setw(10) 
                    << "Age" << setw(20) << "Phone Number" << setw(50) << "Address" 
                    << setw(20) << "Start Date" << setw(20) << "End Date" << endl;
                    haveTitle = true; 
                }
                // display the MemberID, name and age of the Member
                cout << setw(10) << pCurr->memberID << setw(20) << pCurr->name << setw(10) 
                << pCurr->age << setw(20) << pCurr->phoneNo << setw(50) << pCurr->address 
                << setw(20) << pCurr->startDate << setw(20) << pCurr->endDate << endl;
                found = true;
                break;
            }
            else
            {
                pCurr = pCurr->link;
            }
        }
    }

    else if (option == 'b' || option == 'B') // search member by name
    {
        std::string target;
        cout << "Please enter the target name: ";
        cin >> target;

        size_t index;
        pCurr = pHead;
        while (pCurr != nullptr)
        {
            // if the target name contains in name of the member
            // it will return the index of the target name in name
             index = pCurr->name.find(target);
            if (index != std::string::npos) // match
            {
                if (!haveTitle)
                {
                    cout << setw(10) << "Member ID" << setw(20) << "Name" << setw(10) 
                    << "Age" << setw(20) << "Phone Number" << setw(50) << "Address" 
                    << setw(20) << "Start Date" << setw(20) << "End Date" << endl;
                    haveTitle = true; 
                }
                // display the MemberID, name and age of the Member
                cout << setw(10) << pCurr->memberID << setw(20) << pCurr->name << setw(10) 
                << pCurr->age << setw(20) << pCurr->phoneNo << setw(50) << pCurr->address 
                << setw(20) << pCurr->startDate << setw(20) << pCurr->endDate << endl;
                found = true;
            }
            pCurr = pCurr->link;
        }
    }

    else if (option == 'c' || option == 'C') // search by age 
    {
        int target;
        cout << "Please enter the target age: ";
        cin >> target;

        pCurr = pHead;
        while (pCurr != nullptr)
        {
            if (pCurr->age == target)
            {
                if (!haveTitle)
                {
                    cout << setw(10) << "Member ID" << setw(20) << "Name" << setw(10) 
                    << "Age" << setw(20) << "Phone Number" << setw(50) << "Address" 
                    << setw(20) << "Start Date" << setw(20) << "End Date" << endl;
                    haveTitle = true; 
                }
                // display the MemberID, name and age of the Member
                cout << setw(10) << pCurr->memberID << setw(20) << pCurr->name << setw(10) 
                << pCurr->age << setw(20) << pCurr->phoneNo << setw(50) << pCurr->address 
                << setw(20) << pCurr->startDate << setw(20) << pCurr->endDate << endl;
                found = true;
            }
            pCurr = pCurr->link;
        }
    }
    else // user not enter option a, b or c
    {
        cout << "Please enter the valid option" << endl;
        valid = false;
    }

    if (!found && valid) // user enter the valid option but have not found the target data
    {
        cout << "No Data found" << endl;
    }
}

// Written by Emanuel Ling Hao En
// Delete member by memberID
void Membership::deleteMember(){
    int target;
    bool found = false;
    cout << "Please enter the member id: ";
    cin >> target;

    pCurr = pHead;
    Member *pLast = pCurr;

    while (pCurr != nullptr)
    {
        if (pCurr->memberID == target)
        {
            if (pCurr == pHead)
            {
                pHead = pCurr->link;
            }
            else
            {
                pLast->link = pCurr->link;
            }
            numMember--;
            found = true;
            cout << "Delete success" << endl;
            break;
        }
        else
        {
            pLast = pCurr;
            pCurr = pCurr->link;
        }
    }
    if (!found)
    {
        cout << "Target memberID not found." << endl;
    }
}

void Membership::deleteAllMember()
{
    pHead = 0;
    pCurr = pTail = pHead;
    numMember = 0;
}
