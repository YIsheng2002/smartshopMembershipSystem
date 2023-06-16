#include <iostream>
#include ".\include\Membership.h"
using namespace std;

int main(){
    char cont = 't';
    int choice;
    Membership ms1;

    ms1.AddMember(123, "Alex Teo", 20, "601125093553", 
    "123 Jalan Ampang, Kuala Lumpur, 50450", "03/09/2022", "03/09/2023");
    ms1.AddMember(456, "How Chai", 19, "60128946689", 
    "456 Jalan Bukit Bintang, Kuala Lumpur, 55100", "15/01/2023", "15/06/2023");
    ms1.AddMember(234, "Alex Ling", 22, "60162345678", 
    "789 Jalan Tun Razak, Kuala Lumpur, 50400", "10/12/2021", "20/05/2023");
    ms1.AddMember(189, "Bryan Lee", 19, "60138739394", 
    "321 Jalan Raja Chulan, Kuala Lumpur, 50200", "19/04/2022", "20/04/2023");
    ms1.SearchMember();

    return 0;
}