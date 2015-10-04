/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
*
*
*/

#ifndef Game_H
#define Game_H

#include <set>
#include <iostream>
#include <map>
#include <string>
#include "Room.h"
#include "Parser.h"
#include "Command.h"
#include "#CommandWords.h"
using namespace std;


class Game 
{
private: 
    Parser parser;
    Room *currentRoom;
      
public:
    Game();
    void play();
    void printWelcome();
    void createRooms();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    bool quit(Command command);    
    
};

#endif