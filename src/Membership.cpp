#include <iostream>
#include <iomanip>
#include ".\include\Membership.h"
#include <fstream>

using namespace std;

//Constructor
Membership::Membership(){
    numMember = 0;
    pHead = 0;
    pTail = pHead;
}

//Destructor
Membership::~Membership(){}

//Name:Yasrizal Hakim Bin Yaresham
//This function is to get new member data
void Membership::GetData(){
    string name, phoneNo, address, startDate, endDate;
    int memberID, age;
    bool exist = false; //member ID exist or not
    //get user input
    std::cout << "Enter member's member ID: \n";
    std::cin >> memberID;

    pCurr = pHead;
    //loop to run through linked list
    while (pCurr != nullptr)
    {
        if (pCurr->memberID == memberID){ //check is member ID exists
            exist = true;
            break;
        }
        pCurr = pCurr->link;
    }
    if(exist == true)
    {
        std::cout << "This member id already exists.\n";
        std::cout << "Please enter a valid ID.\n\n";
        
    } else{ 

    std::cout << "Enter member's name: \n";
    std::cin.ignore();
    std::getline(std::cin,name);
    std::cout << "Enter member's age: \n";
    std::cin >> age;
    std::cout << "Enter member's phone number: \n";
    std::cin.ignore();
    std::getline(std::cin,phoneNo);
    std::cout << "Enter member's address: \n";
    std::cin.ignore();
    std::getline(std::cin,address);
    std::cout << "Enter member's startDate: \n";
    std::cin.ignore();
    std::getline(std::cin,startDate);
    std::cout << "Enter member's endDate: \n";
    std::cin.ignore();
    std::getline(std::cin,endDate);
    
    
    AddMember(memberID, name, age, phoneNo, address, startDate, endDate);
    std::cout << "Member add successfully. Thank you.";
    }
}

//Name:Yasrizal Hakim Bin Yaresham
//This function is to add new member to the end of the linked list
void Membership::AddMember(int memberID, string name, int age, string phoneNo, string address, string startDate, string endDate){
    //add data into Node of linked list
    Member *pNew = new Member;
    pNew->memberID = memberID; 
    pNew->name = name;
    pNew->age = age;
    pNew->phoneNo = phoneNo;
    pNew->address = address;
    pNew->startDate = startDate;
    pNew->endDate = endDate;
    if(pHead == 0){
        pHead = pNew;
        pTail = pHead;
    } else{
        pTail->link = pNew;
        pTail = pNew;
        pTail->link = nullptr;
    }
}

//Written by: Yasrial Hakim Bin Yaresham
//This function display all the member's datas in linked list
void Membership::printData(){   
    pCurr = pHead;

    std::cout << setw(10) << "Member ID" << setw(20) << "Name" << setw(10) 
    << "Age" << setw(20) << "Phone Number" << setw(50) << "Address" 
    << setw(20) << "Start Date" << setw(20) << "End Date" << endl;

    while (pCurr != nullptr)
    {
        std::cout << setw(10) << pCurr->memberID << setw(20) << pCurr->name << setw(10) 
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
    std::cout << "Search by: a) MemberID  b) name  c) age" << endl;
    std::cin >> option;

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
        std::cout << "Please enter the valid option" << endl;
        valid = false;
    }

    if (!found && valid) // user enter the valid option but have not found the target data
    {
        std::cout << "No Data found" << endl;
    }
}

// Written by Emanuel Ling Hao En
// Search by member id
bool Membership::searchID()
{
    int target_id;
    bool found = false, haveTitle = false;

    std::cout << "Please enter target member id: ";
    std::cin >> target_id;
        
    pCurr = pHead;
    while (pCurr != nullptr)
    {
        if (pCurr->memberID == target_id) // found the Member by MemberID
        {
            if (!haveTitle)
            {
                std::cout << setw(10) << "Member ID" << setw(20) << "Name" << setw(10) 
                << "Age" << setw(20) << "Phone Number" << setw(50) << "Address" 
                << setw(20) << "Start Date" << setw(20) << "End Date" << endl;
                haveTitle = true; 
            }
            // display the MemberID, name and age of the Member
            std::cout << setw(10) << pCurr->memberID << setw(20) << pCurr->name << setw(10) 
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

    std::cout << "Please enter the target name: ";
    std::cin >> target;

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
                std::cout << setw(10) << "Member ID" << setw(20) << "Name" << setw(10) 
                << "Age" << setw(20) << "Phone Number" << setw(50) << "Address" 
                << setw(20) << "Start Date" << setw(20) << "End Date" << endl;
                haveTitle = true; 
            }
            // display the MemberID, name and age of the Member
            std::cout << setw(10) << pCurr->memberID << setw(20) << pCurr->name << setw(10) 
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

    std::cout << "Please enter the target age: ";
    std::cin >> target_age;

    pCurr = pHead;
    while (pCurr != nullptr)
    {
        if (pCurr->age == target_age)
        {
            if (!haveTitle)
            {
                std::cout << setw(10) << "Member ID" << setw(20) << "Name" << setw(10) 
                << "Age" << setw(20) << "Phone Number" << setw(50) << "Address" 
                << setw(20) << "Start Date" << setw(20) << "End Date" << endl;
                haveTitle = true; 
            }
            // display the MemberID, name and age of the Member
            std::cout << setw(10) << pCurr->memberID << setw(20) << pCurr->name << setw(10) 
            << pCurr->age << setw(20) << pCurr->phoneNo << setw(50) << pCurr->address 
            << setw(20) << pCurr->startDate << setw(20) << pCurr->endDate << endl;
            found = true;
        }
        pCurr = pCurr->link;
    }
    return found;
}

// Written by Mohamad Azri bin Azman
// read the data from the file
bool Membership::readFile(std::string fileName)
{
    std::string memberID, age, name, phoneNo, address, startDate, endDate, split;    

    ifstream file(fileName);

    // if fail to open the file, return false
    if (!file.is_open()) 
    {
        return false;
    }

    while (true)
    {
        // if not read the split line means that already reach the end of line, break the loop
        if(!getline(file, split))
        {
            break;
        }

        // read the data from the file
        getline(file, memberID);
        getline(file, name); 
        getline(file, age);
        getline(file, phoneNo);
        getline(file, address);
        getline(file, startDate);
        getline(file, endDate);
    
        AddMember(stoi(memberID), name, stoi(age), phoneNo, address, startDate, endDate);
    }
    
    file.close();
    return true;
}

// Written by Mohamad Azri bin Azman
// Write the date to the file
bool Membership::writeFile(string fileName)
{
    ofstream file(fileName);

    // if fail to open the file, return false
    if (!file.is_open()) 
    {
        std::cout << "Fail to open the file" << endl;
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
    std::cout << "file saved" << endl;
    return true;
}

// Written by Emanuel Ling Hao En
// Delete member by memberID
void Membership::deleteMember(){
    int target;
    bool found = false;
    std::cout << "Please enter the member id: ";
    std::cin >> target;

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
            std::cout << "Delete success" << endl;
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
        std::cout << "Target memberID not found." << endl;
    }
}

// Written by Emanuel Ling Hao En
// Delete all member by memberID
void Membership::deleteAllMember()
{
    pHead = 0;
    pCurr = pTail = pHead;
    numMember = 0;
}
