#include <iostream>
#include <HashTable.h>
using namespace std;

int main(int argc,const char ** argv)
{
    HashTable geekycampers;
    geekycampers.addGeekyCamper("Petur", 19);
    geekycampers.addGeekyCamper("Puter", 7);
    geekycampers.addGeekyCamper("Puret", 76);
    geekycampers.removeGeekyCamper("Puter");
    geekycampers.printGeekyCampersInIndex(geekycampers.hash("Petur"));
    cout << geekycampers.getGeekyPoints("Puret") << endl;
    //geekycampers.printTable();
    return 0;
}
