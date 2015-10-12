/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
*/

#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include "Room.h"
using namespace std;


// Constructor for Room
Room::Room(string name, string description)
{
    roomName = name;
    roomDescription = description;
}

/**
 * Define an exit from this room.
 * @param direction The direction of the exit.
 * @param neighbor  The room to which the exit leads.
 */
void Room::setExit(string direction, Room* neighbor) 
{
    exits.insert(pair<string, Room *>(direction, neighbor));
}


/*
* Holds a short description of the rooom
* @return the description of the character's current room
*
*/
string Room::getShortDescription()
{
    return roomDescription;
}

string Room::getName()
{
    return roomName;
}

/*
* Lists the exits in a given room
* @return the exits in a given room
*
*/
string Room::getExitString()
{
    string returnString = "Exits: ";

    for(map<string, Room *>::const_iterator it = exits.begin();
        it != exits.end(); it++)
    {
        returnString += " " + it->first; + "/n";
    }
    return returnString;
}


/*
* Outputs the main character's current room and its available 
* exits
*
* @return current room, directions of available exits
*
*/
string Room::getLongDescription()
{
    return "You are " + roomName + ".\n" + getExitString();
}


/*
* Lists the room located in the direction given by the player
*
* @param a direction entered by the user
*
* @return the room located in a given direction, NULL 
* if otherwise
*
*/
Room * Room::getExit(string direction) 
{
    if (exits.find(direction)!=exits.end())
    {
        return exits[direction];
    }

    return NULL;
}
