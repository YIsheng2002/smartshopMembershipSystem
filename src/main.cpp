#include <iostream>
#include ".\include\Membership.h"
using namespace std;

int main(){
    char cont = 't';
    int choice;
    Membership ms1;

    ms1.AddMember(123, "Alex Teo", 20);
    ms1.AddMember(456, "How Chai", 19);
    ms1.AddMember(234, "Alex Ling", 22);
    ms1.AddMember(189, "Bryan Lee", 19);
    ms1.SearchMember();

    return 0;
}