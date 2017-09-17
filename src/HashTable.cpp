#include "HashTable.h"

using namespace std;

HashTable::HashTable()
{
    for (int p = 0; p < tableSize; p ++)
    {
        table[p] = new geekycamper;
        table[p]->name = "Empty";
        table[p]->geekycamppoints = 0;
        table[p]->next = NULL;
    }
}

int HashTable::hash(string key)
{
    int index = 0;

    for (int i = 0; i < key.length(); i ++)
        index += (int)key[i];

    return index % tableSize;
}

void HashTable::addGeekyCamper(string name, int points)
{
    int index = hash(name);
    if (table[index]->name == "Empty")
    {
        table[index]->name = name;
        table[index]->geekycamppoints = points;
    }
    else
    {
        geekycamper* ptr = table[index];
        geekycamper* newperson = new geekycamper;
        newperson->name = name;
        newperson->geekycamppoints = points;
        newperson->next = NULL;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newperson;
    }
}

int HashTable::numberOfGeekyCampersInIndex(int index)
{
    int k = 1;
    if (table[index]->name == "Empty")
        return 0;
    geekycamper* ptr = table[index];
    while (ptr->next != NULL)
    {
        k ++;
        ptr = ptr->next;
    }
    return k;
}

void HashTable::printTable()
{
    int numbersInIndex = 0;
    for (int i = 0; i < tableSize; i ++)
    {
        numbersInIndex = numberOfGeekyCampersInIndex(i);
        cout << "---------------------\n";
        cout << "index: " << i << endl;
        cout << table[i]->name << " " << table[i]->geekycamppoints << " " << numbersInIndex << endl;
        cout << "---------------------\n";
    }
}
void HashTable::printGeekyCampersInIndex(int index)
{
    geekycamper* ptr = table[index];
    if (ptr->name == "Empty")
        cout << "There is noone here \n";
    else
    {
        cout << ptr->name << " " << ptr->geekycamppoints << endl;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            cout << ptr->name << " " << ptr->geekycamppoints << endl;
        }
    }
}

int HashTable::getGeekyPoints(string name)
{
    int index = hash(name);
    geekycamper* ptr = table[index];
    if (ptr->name == "Empty")
        return -1;
    else
    {

        if (ptr->name == name)
            return ptr->geekycamppoints;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            if (ptr->name == name)
                return ptr->geekycamppoints;
        }
        return -1;
    }
}

void HashTable::removeGeekyCamper(string name)
{
    int index = hash(name);

    geekycamper* delPtr;
    geekycamper* P1;
    geekycamper* P2;

    if (table[index]->name == "Empty")
        cout << "Didn't found this geekycamper! \n";
    else if (table[index]->name == name && table[index]->next == NULL)
    {
        table[index]->name = "Empty";
        table[index]->geekycamppoints = 0;
        cout << name << " the geekycamper was deleted!\n";
    }
    else if (table[index]->name == name)
    {
        delPtr = table[index];
        table[index] = table[index]->next;
        delete delPtr;
        cout << name << " the geekycamper was deleted!\n";
    }
    else
    {
        P1 = table[index]->next;
        P2 = table[index];
        while (P1->next != NULL && P1->name != name)
        {
            P2 = P1;
            P1 = P1->next;
        }
        if (P1->next == NULL)
        {
            if (P1->name == name)
            {
                delPtr = P1;
                P1 = NULL;
                P2->next = P1;
                delete delPtr;
                cout << name << " the geekycamper was deleted!\n";
            }
            else
                cout << "Didn't found this geekycamper! \n";
        }
        else
        {
            delPtr = P1;
            P1 = P1->next;
            P2->next = P1;
            delete delPtr;
            cout << name << " the geekycamper was deleted!\n";
        }
    }
}
