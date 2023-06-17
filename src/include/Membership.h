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

public:
    Member *pHead;
    Member *pCurr;
    int numMember;

    Membership();
    ~Membership();
    void AddToFront();
    void printData();

    Member* getMid(){
        int currNum = 0;
        Member* midNode = pHead;
        while (currNum != numMember/2)
        {
            midNode = midNode->link;
            currNum++;
        }
        return midNode;
    }

    Member* merge(Member* firstHalf, Member* secondHalf){
        Member* mergedList;
        if (firstHalf->age < secondHalf->age){
            mergedList = firstHalf;
            firstHalf = firstHalf->link;
        } else {
            mergedList = secondHalf;
            secondHalf = secondHalf->link;
        }
        pCurr = mergedList;

        while (firstHalf != NULL && secondHalf != NULL){
            if(firstHalf->age < secondHalf->age){
                mergedList = firstHalf;
                firstHalf = firstHalf->link;
            }else {
            mergedList = secondHalf;
            secondHalf = secondHalf->link;
            }
        }

        while (firstHalf != NULL){
            pCurr->link = pHead;
            firstHalf = firstHalf->link;
            pCurr = pCurr->link;
        }
        while (secondHalf != NULL)
        {
            pCurr->link = secondHalf;
            secondHalf = secondHalf->link;
            pCurr = pCurr->link;
        }
        
        return mergedList;
    }

    Member* mergeSort( Member *firstNode){
        while (firstNode != NULL)
        {
            Member* midNode = getMid();
            Member* secondHalf = mergeSort(midNode->link);
            midNode->link = NULL;
            Member* firstHalf = mergeSort(pHead);
            return merge(firstHalf,secondHalf);
            pCurr = pHead;  
        } 
        
        return pHead;
    }

    int num(){
        return 50;
    }
};

#endif