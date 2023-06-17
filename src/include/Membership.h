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

    /**Member* getMid(){
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
    }*/

    Member *merge(Member *a, Member *b)
    {
        // base case
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;
    
        // recursive case
        // take a head pointer
        Member *c;
    
        if(a->age < b->age)
        {
            c = a;
            c->link = merge(a->link, b);
        }
        else
        {
            c = b;
            c->link = merge(a, b->link);
        }
    
        return c;
    }

    Member *mid_point(Member *head)
    {
        // base case
        if(head == NULL || head->link == NULL)
            return head;
    
        // recursive case
        Member *fast = head;
        Member *slow = head;
    
        while(fast != NULL && fast->link != NULL)
        {
            fast = fast->link;
    
            if(fast->link == NULL)
                break;
    
            fast = fast->link;
            slow = slow->link;
        }
    
        return slow;
    }

    Member* merge_sort(Member *head)
    {
        // base case
        if(head == NULL || head->link == NULL)
            return head;
    
        // recursive case
        // Step 1: divide the linked list into
        // two equal linked lists
        Member *mid = mid_point(head);
        Member *a = head;
        Member *b = mid->link;
    
        mid->link = NULL;
    
        // Step 2: recursively sort the smaller
        // linked lists
        a = merge_sort(a);
        b = merge_sort(b);
    
        // Step 3: merge the sorted linked lists
        Member *c = merge(a, b);

        pHead = c;
        return c;
    }
};

#endif