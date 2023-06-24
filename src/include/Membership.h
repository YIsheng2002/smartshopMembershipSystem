#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H
#include<string>

//This class is the linked list contain all members
//Written by Heng Yi Sheng :)
class Membership{
private:
    //This class represent each member
    class Member{
        public:
            int memberID, age;
            std::string name, phoneNo, address, startDate, endDate;
            Member* link;
    };

    Member *pHead;
    Member *pCurr;
    Member *pTail;
    int numMember;

    bool searchID();
    bool searchName();
    bool searchAge();
    
public:
    Membership();
    ~Membership();
    void AddMember(int, std::string, int, std::string, std::string, std::string, std::string);
    void printData();
    void SearchMember();
    void DeleteMember();
    void DeleteAllMember();
    bool readFile(std::string);
    bool writeFile(std::string);
};

#endif