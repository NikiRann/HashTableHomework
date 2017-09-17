#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H


class HashTable
{
public:
    HashTable();

    int hash(string key);
    void addGeekyCamper(string name, int points);
    int numberOfGeekyCampersInIndex(int index);
    void printTable();
    void printGeekyCampersInIndex(int index);
    int getGeekyPoints(string name);
    void removeGeekyCamper(string name);
private:

    static const int tableSize = 100;

    struct geekycamper{
        string name;
        int geekycamppoints;
        geekycamper* next;
    };

    geekycamper* table[tableSize];

};

#endif // HASHTABLE_H
