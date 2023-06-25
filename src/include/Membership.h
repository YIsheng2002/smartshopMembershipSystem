#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H
#include<string>

class Membership{
private:
    class Member{
        public:
            int memberID, age;
            std::string name, phoneNo, address, startDate, endDate;
            Member* link;
    };

public:
    Member *pHead;
    Member *pCurr;
    Member *pTail;
    int numMember;
    int sortType;

    Membership();
    ~Membership();
    void GetData();
    void AddMember(int, std::string, int, std::string, std::string, std::string, std::string);
    void printData();
    void SearchMember();
    void deleteMember();
    void deleteAllMember();
    bool searchID();
    bool searchName();
    bool searchAge();
    bool readFile(std::string);
    bool writeFile(std:: string);


    //written by Heng Yi Sheng
    //merge by Member's id(when user choose sort by ID)
    Member *mergeID(Member *a, Member *b)
    {
        // base case
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;
    
        // recursive case
        // take a head pointer
        Member *c;
    
        if(a->memberID < b->memberID)
        {
            c = a;
            c->link = mergeID(a->link, b);
        }
        else
        {
            c = b;
            c->link = mergeID(a, b->link);
        }
    
        return c;
    }

    //written by Heng Yi Sheng
    //merge by Member's id(when user choose sort by AGE)
    Member *mergeAge(Member *a, Member *b)
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
            c->link = mergeAge(a->link, b);
        }
        else
        {
            c = b;
            c->link = mergeAge(a, b->link);
        }
    
        return c;
    }

    //written by Heng Yi Sheng
    //merge by Member's id(when user choose sort by NAME)
    Member *mergeName(Member *a, Member *b)
    {
        // base case
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;
    
        // recursive case
        // take a head pointer
        Member *c;
    
        if(a->name.compare(b->name)>=0)
        {
            c = a;
            c->link = mergeName(a->link, b);
        }
        else
        {
            c = b;
            c->link = mergeName(a, b->link);
        }
    
        return c;
    }

    //written by Heng Yi Sheng
    //find the mid node for sorting purpose
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

    //written by Heng Yi Sheng
    //merge sort
    Member* merge_sort(Member *head)
    {
        // base case
        if(head == NULL || head->link == NULL)
            return head;
    
        // recursive case
        // divide the linked list into
        // two equal linked lists
        Member *mid = mid_point(head);
        Member *a = head;
        Member *b = mid->link;
    
        mid->link = NULL;
    
        // recursively sort the smaller
        // linked lists
        a = merge_sort(a);
        b = merge_sort(b);

        Member *c;
    
        // merge the sorted linked lists
        if(sortType == 1){
            c = mergeID(a, b);
        } else if(sortType == 2){
            c = mergeName(a, b);
        } else if(sortType == 3){
            c = mergeAge(a, b);
        }

        pHead = c;
        return c;
    }

    //written by Heng Yi Sheng
    //print sort menu and get user choice
    void sortMenu(){
        int c;
        std::cout << "Sort by:\n";
        std::cout << "1. Member ID\n";
        std::cout << "2. Member Name\n";
        std::cout << "3. Member Age\n";
        std::cout << "Enter your choice: (1/2/3)\n";
        std::cin >> c;

        sortType = c;
        merge_sort(pHead);  
    }
};

#endif