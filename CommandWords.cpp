#include <iostream>
#include <string>
#include "CommandWords.h"


CommandWords::CommandWords()
{
    string validCommands[] = {"go", "quit", "help"};
}

bool CommandWords::isCommand(string aString)
{
    for(int i = 0; i < validCommands.length; i++) 
    {
        if(validCommands[i]==aString)
            return true;
    }
    // if we get here, the string was not found in the commands
    return false;
}

void CommandWords::showAll() 
{
    for(vector::iterator command = validCommands.begin();
        command != validCommands.end(); command++)
    {
        cout << *command;
    }

}
