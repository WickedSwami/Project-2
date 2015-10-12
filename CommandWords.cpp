/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
*/

#include <iostream>
#include <string>
#include "CommandWords.h"


//constructor for CommandWords; fills the list of valid commands
CommandWords::CommandWords()
{
    fillValidCommands(validCommands);
}

/*

returns true if a given string is a command

@param  a string of any length
@return  true if string is a command, false if otherwise

*/
bool CommandWords::isCommand(string aString)
{
    for(int i = 0; i < validCommands.size(); i++) 
    {
        if(validCommands.at(i)==aString)
            return true;
    }
    // if we get here, the string was not found in the commands
    return false;
}

//prints all available commands to the terminal
void CommandWords::showAll() 
{
    for(vector<string>::iterator command = validCommands.begin();
        command != validCommands.end(); command++)
    {
        cout << *command + "\n";
    }

}

//fills the list of valid commands the player can use
void CommandWords::fillValidCommands(vector<string> &commands)
{
    validCommands.push_back("go");
    validCommands.push_back("take");
    validCommands.push_back("quit");
    validCommands.push_back("help");    
}
