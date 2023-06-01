#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H
#include<string>

class Membership{
private:
    class Member{
        public:
            int memberID, age;
            std::string name;
            Member* link;
    };

    Member *pHead;
    Member *pCurr;
    int numMember;

public:
    Membership();
    ~Membership();
    void AddToFront();
    void printData();
};

#endif