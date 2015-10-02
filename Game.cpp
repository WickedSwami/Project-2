#include <set>
#include <iostream>
#include <map>
#include <string>
#include "Game.h"
using namespace std;

    

Game::Game() 
{
    createRooms();
    Parser parser;
    Room* currentRoom;
}

/**
 * Create all the rooms and link their exits together.
 */
void Game::createRooms()
{
    Room outside, theater, pub, lab, office;
  
    // create the rooms
    outside = new Room("outside the main entrance of the university");
    theater = new Room("in a lecture theater");
    pub = new Room("in the campus pub");
    lab = new Room("in a computing lab");
    office = new Room("in the computing admin office");
    
    // initialise room exits
    outside.setExit("east", theater);
    outside.setExit("south", lab);
    outside.setExit("west", pub);

    theater.setExit("west", outside);

    pub.setExit("east", outside);

    lab.setExit("north", outside);
    lab.setExit("east", office);

    office.setExit("west", lab);

    currentRoom = outside;  // start game outside
}

/**
 *  Main play routine.  Loops until end of play.
 */
void Game::play() 
{            
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the game is over.
            
    bool finished = false;
    while (! finished) {
        Command command = parser.getCommand();
        finished = processCommand(command);
    }

    cout << "OK, quitter.";
}

/**
 * Print out the opening message for the player.
 */
void Game::printWelcome()
{
    cout << "Welcome to the World of Zuul!";
    cout << "World of Zuul is a new, incredibly boring adventure game.";
    cout << "Type 'help' if you need help." << endl;

    cout << currentRoom.getLongDescription();
}

/**
 * Given a command, process (that is: execute) the command.
 * @param command The command to be processed.
 * @return true If the command ends the game, false otherwise.
 */
bool Game::processCommand(Command command) 
{
    bool wantToQuit = false;

    if(command.isUnknown()) {
        cout << "I don't know what you mean..."
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord=="help") {
        printHelp();
    }
    else if (commandWord=="go") {
        goRoom(command);
    }
    else if (commandWord=="quit") {
        wantToQuit = quit(command);
    }
    // else command not recognised.
    return wantToQuit;
}

// implementations of user commands:

/**
 * Print out some help information.
 * Here we print some stupid, cryptic message and a list of the 
 * command words.
 */
void Game::printHelp() 
{
    cout <<"You are lost. You are alone." << endl;
    cout << "You wander around at the university." <<endl;
    cout << "Your command words are: " parser.showCommands();
}

/** 
 * Try to in to one direction. If there is an exit, enter the new
 * room, otherwise print an error message.
 */
void Game::goRoom(Command command) 
{
    if(!command.hasSecondWord()) {
        // if there is no second word, we don't know where to go...
        cout << "Go where?";
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room nextRoom = currentRoom.getExit(direction);

    if (nextRoom == null) {
        cout << "There is no door!";
    }
    else {
        currentRoom = nextRoom;
        cout << currentRoom.getLongDescription();
    }
}

/** 
 * "Quit" was entered. Check the rest of the command to see
 * whether we really quit the game.
 * @return true, if this command quits the game, false otherwise.
 */
bool Game::quit(Command command) 
{
    if(command.hasSecondWord()) {
        System.out.println("Quit what?");
        return false;
    }
    
    return true;  // signal that we want to quit   
}
