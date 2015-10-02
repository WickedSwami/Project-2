#ifndef Room_H
#define Room_H

#include <set>
#include <iostream>
#include <map>
#include <string>
using namespace std;


class Room 
{
private:
    string description;
    map<string, Room> exits; 
    string getExitString();       

public:
    Room(string description);
    void setExit(string direction, Room* neighbor);
    string getShortDescription();
    string getLongDescription();
    Room* getExit(string direction);
};

#endif
