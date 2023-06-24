#include <iostream>
#include ".\include\Membership.h"

using namespace std;

int main(){
    char cont = 't';
    int choice;
    Membership ms1;

    if(!ms1.readFile("membersdata.txt"))
    {
        return 0;
    }

    ms1.printData();
    cout << endl << endl;

    /*
    ms1.AddMember(198, "Clement Ho", 30, "60192287453", "789 Jalan Bukit Bintang, 55100",
    "08/03/2022", "08/03/2023");

    if(!ms1.writeFile("membersdata.txt"))
    {
        return 0;
    }

    ms1.printData();
    */

    return 0;
}