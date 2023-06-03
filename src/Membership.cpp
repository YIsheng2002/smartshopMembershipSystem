#include <iostream>
#include ".\include\Membership.h"
using namespace std;

//Contructor
Membership::Membership(){
    numMember = 0;
    pHead = 0;
}

//Destructor
Membership::~Membership(){}

//Add new member to front?
void Membership::AddMember(int memberID, std::string name, int age){

    Member *pNew = new Member();
    pNew->memberID = memberID;
    pNew->name = name;
    pNew->age = age;
    pNew->link = pHead;
    pHead = pNew;
    numMember++;
}

void Membership::printData(){   
    pCurr = pHead;
    while (pCurr != nullptr)
    {
        cout << "id:" << pCurr->memberID << '\t' << "name:" << 
        pCurr->name << '\t' << "age:" << pCurr->age << endl;
        pCurr = pCurr->link;
    }
}

// Written by Emanuel Ling Hao En
// Seach member by id, name or age
void Membership::SearchMember(){
    char option;
    string target;
    bool found = false, valid = true;
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
                // display the MemberID, name and age of the Member
                cout << "id:" << pCurr->memberID << '\t' << "name:" << 
                pCurr->name << '\t' << "age:" << pCurr->age << endl;
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
                cout << "id:" << pCurr->memberID << '\t' << "name:" << 
                pCurr->name << '\t' << "age:" << pCurr->age << endl;
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
                cout << "id:" << pCurr->memberID << '\t' << "name:" << 
                pCurr->name << '\t' << "age:" << pCurr->age << endl;
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
void Membership::DeleteMember(){
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



