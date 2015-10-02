#ifndef Game_H
#define Game_H

#include <set>
#include <iostream>
#include <map>
#include <string>
using namespace std;


class Game 
{
private: 
    Parser parser;
    Room currentRoom;
    void createRooms();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    bool quit(Command command);
        
public:
    Game();
    void play();
    void printWelcome();
    
};

#endif