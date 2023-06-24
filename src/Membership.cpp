#include <iostream>
#include <iomanip>
#include ".\include\Membership.h"
#include <fstream>
#include <ostream>

using namespace std;

//Contructor
Membership::Membership(){
    numMember = 0;
    pHead = 0;
    pTail = 0;
}

//Destructor
Membership::~Membership(){}

//Add new member to front?
void Membership::AddMember(int memberID, std::string name, int age, std::string phoneNo,
std::string address, std::string startDate, std::string endDate){

    Member *pNew = new Member();
    pNew->memberID = memberID;
    pNew->name = name;
    pNew->age = age;
    pNew->phoneNo = phoneNo;
    pNew->address = address;
    pNew->startDate = startDate;
    pNew->endDate = endDate;
    pNew->link = pHead;
    pHead = pNew;
    numMember++;
}

void Membership::printData(){   
    pCurr = pHead;

    cout << setw(10) << "Member ID" << setw(20) << "Name" << setw(10) 
    << "Age" << setw(20) << "Phone Number" << setw(50) << "Address" 
    << setw(20) << "Start Date" << setw(20) << "End Date" << endl;

    while (pCurr != nullptr)
    {
        cout << setw(10) << pCurr->memberID << setw(20) << pCurr->name << setw(10) 
        << pCurr->age << setw(20) << pCurr->phoneNo << setw(50) << pCurr->address 
        << setw(20) << pCurr->startDate << setw(20) << pCurr->endDate << endl;
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
        found = searchID();
    }

    else if (option == 'b' || option == 'B') // search member by name
    {
        found = searchName();
    }

    else if (option == 'c' || option == 'C') // search by age 
    {
        found = searchAge();
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

// Written by Emanuel Ling Hao En
// Delete all the data in membership
void Membership::DeleteAllMember()
{
    pHead = 0;
    pCurr = pTail = pHead;
    numMember = 0;
}

// Written by Emanuel Ling Hao En
// Search by member id
bool Membership::searchID()
{
    int target_id;
    bool found = false, haveTitle = false;

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
    return found;
}

// Written by Emanuel Ling Hao En
// Search by name
bool Membership::searchName()
{
    std::string target;
    bool haveTitle = false, found = false;

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
    return found;
}

//Written by Emanuel Ling Hao En
// Search by age
bool Membership::searchAge()
{
    int target_age;
    bool haveTitle = false, found = false;

    cout << "Please enter the target age: ";
    cin >> target_age;

    pCurr = pHead;
    while (pCurr != nullptr)
    {
        if (pCurr->age == target_age)
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
    return found;
}

// Written by Emanuel Ling Hao En
// read the data from the file
bool Membership::readFile(std::string fileName)
{
    std::string memberID, age, name, phoneNo, address, startDate, endDate, split;    

    std::ifstream file(fileName);


    // if fail to open the file, return false
    if (!file.is_open()) 
    {
        cout << "Fail to open the file" << endl;
        return false;
    }

    while (true)
    {
        // if not read the split line means that already reach the end of line, break the loop
        if(!std::getline(file, split))
        {
            break;
        }

        // read the data from the file
        std::getline(file, memberID);
        std::getline(file, name); 
        std::getline(file, age);
        std::getline(file, phoneNo);
        std::getline(file, address);
        std::getline(file, startDate);
        std::getline(file, endDate);
    
        AddMember(stoi(memberID), name, stoi(age), phoneNo, address, startDate, endDate);
    }
    
    file.close();
    return true;
}

// Written by Emanuel Ling Hao En
// Write the date to the file
bool Membership::writeFile(string fileName)
{
    std::ofstream file(fileName);

    // if fail to open the file, return false
    if (!file.is_open()) 
    {
        cout << "Fail to open the file" << endl;
        return false;
    }

    pCurr = pHead;

    // while no reach the end of the linked list
    while (pCurr != nullptr)
    {
        // write the data into the file
        file << "-------------------------------\n";
        file << pCurr->memberID << "\n";
        file << pCurr->name << "\n";
        file << pCurr->age << "\n";
        file << pCurr->phoneNo << "\n";
        file << pCurr->address << "\n";
        file << pCurr->startDate << "\n";
        file << pCurr->endDate << "\n";
        pCurr = pCurr->link;
    }
    cout << "file saved" << endl;
    return true;
}
