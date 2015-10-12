/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
*
*
*/

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
    string roomName;
    string roomDescription;
    map<string, Room*> exits;       

public:
    Room(string name, string description);
    void setExit(string direction, Room *neighbor);
    string getName();
    string getShortDescription();
    string getLongDescription();
    string getExitString();
    Room* getExit(string direction);
};

#endif
