#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include "Room.h"
using namespace std;

Room::Room(string description) 
{
    this.description = description;
    exits = map<string, Room*>;
}

/**
 * Define an exit from this room.
 * @param direction The direction of the exit.
 * @param neighbor  The room to which the exit leads.
 */
void Room::setExit(string direction, Room* neighbor) 
{
    exits.insert(direction, neighbor);
}

string Room::getShortDescription()
{
    return description;
}


string Room::getLongDescription()
{
    return "You are " + description + ".\n" + getExitString();
}


string Room::getExitString()
{
    string returnString = "Exits:";

    set<string> keys = exits.keySet();
    for(String exit : keys) {
        returnString += " " + exit;
    }

    return returnString;
}

Room* Room::getExit(string direction) 
{
    if (exits.find(direction)!=exits.end())
    {
        return exits[direction];
    }

    return NULL;
}
