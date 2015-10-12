/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
*
*
*/

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
  
    // create the rooms
    Room *grayMatter = new Room("gray matter", "Holds all necessary components of the brain");
    Room *cerebrum = new Room("cerebrum", "Responsible for the brain's primary functions");
    Room *frontalLobe = new Room("frontal lobe", "Controls creative thought (judgment, behavior, personality, etc.)");
    Room *temporalLobe = new Room("temporal lobe", "Manages visual/auditory memories, language control center");
    Room *parietalLobe = new Room("parietal lobe", "Responsible for sensory comprehension");
    Room *sensoryCortex = new Room("sensory cortex", "Receives sensory input from spinal cord");
    Room *motorCortex = new Room("motor cortex", "Helps the brain control voluntary bodily movements");

    Room *cerebellum = new Room("cerebellum", "Controls balance, posture, and coordination");

    Room *limbicSystem = new Room("limbic system", "Emotional/hormonal control center of the brain");
    Room *amygdala = new Room("amygdala", "Facilitates anger/fear/panic responses");
    Room *hippocampus = new Room("hippocampus", "Helps with long-term memory/learning and spacial reasoning");
    Room *hypothalamus = new Room("hypothalamus", "Regulates somatic processes/responses (hunger, thirst, homeostasis, etc.)");
    Room *thalamus = new Room("thalamus", "Controls attention, manages bodily sensations (i.e. pain)");

    Room *brainStem = new Room("brain stem", "Regulates involuntary somatic processes (heartbeat, metabolism, etc.)");
    Room *midBrain = new Room("midbrain", "Controls body movement, vision, hearing");
    Room *pons = new Room("pons", "Works with cerebellum to control posture/movement, regulates sleep cycle");
    Room *medulla = new Room("medulla", "Controls heartbeat and breathing");
    
    // initialise room exits
    grayMatter->setExit("east", limbicSystem);
    grayMatter->setExit("south", brainStem);
    grayMatter->setExit("west", cerebellum);
    grayMatter->setExit("north",cerebrum);

    cerebrum->setExit("east", temporalLobe);
    cerebrum->setExit("south", grayMatter);
    cerebrum->setExit("west", frontalLobe);
    cerebrum->setExit("north", parietalLobe);


    parietalLobe->setExit("south", cerebrum);
    parietalLobe->setExit("east", motorCortex);
    parietalLobe->setExit("west", sensoryCortex);

    motorCortex->setExit("west",parietalLobe);
    sensoryCortex->setExit("east",parietalLobe);

    limbicSystem->setExit("west", grayMatter);
    limbicSystem->setExit("north", amygdala);
    limbicSystem->setExit("east", hippocampus);
    limbicSystem->setExit("southeast", hypothalamus);
    limbicSystem->setExit("south", thalamus);
    
    amygdala->setExit("south",limbicSystem);
    hippocampus->setExit("west", limbicSystem);
    hypothalamus->setExit("northwest", limbicSystem);
    thalamus->setExit("north",limbicSystem);

    brainStem->setExit("north", grayMatter);
    brainStem->setExit("west", midBrain);
    brainStem->setExit("south", pons);
    brainStem->setExit("east", medulla);

    midBrain->setExit("east", brainStem);
    pons->setExit("north", brainStem);
    medulla->setExit("west", brainStem);

    // start game in the grey matter
    currentRoom = grayMatter;  
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
    cout << "Welcome to Fester! ";
    cout << "Fester is a game in which you explore the brain of an infected patient. ";
    cout << "Find the phage before it's too late and the patient goes insane! ";
    cout << "Type 'help' if you need help." << endl;

    cout << "You are now in ";
    cout << (*currentRoom).getName();
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
        cout << "I don't know what you mean..." << endl;
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
    cout << "You fire through the synapses without a purpose" <<endl;
    cout << "Your command words are:" << endl;
    parser.showCommands();
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
    Room * nextRoom = (*currentRoom).getExit(direction);

    if (nextRoom == NULL) {
        cout << "There is no door!" << endl;
    }
    else {
        currentRoom = nextRoom;
        cout << "You are now in the ";
        cout<< (*currentRoom).getName() << endl;
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
        cout << "Quit what? Help me out here, guy..." << endl;
        return false;
    }
    
    return true;  // signal that we want to quit   
}
