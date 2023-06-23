#include <iostream>
#include ".\include\Membership.h"
#include <fstream>
#include <sstream>
#include <ostream>
using namespace std;

int main(){
    char cont = 't';
    int choice;
    Membership ms1;

    std::string memberID, age, name, phoneNo, address, startDate, endDate, split;    

    std::ifstream file("membersdata.txt");


    if (!file.is_open()) 
    {
        cout<<"error"<<endl;
        return 0;
    }

    while (true)
    {
        if(!std::getline(file, split))
        {
            break;
        }

        std::getline(file, memberID);
        std::getline(file, name); 
        std::getline(file, age);
        std::getline(file, phoneNo);
        std::getline(file, address);
        std::getline(file, startDate);
        std::getline(file, endDate);
        
        ms1.AddMember(std::stoi(memberID), name, std::stoi(age), phoneNo, address,
        startDate, endDate);
    }
    
    file.close();

    ms1.SearchMember();

    return 0;
}