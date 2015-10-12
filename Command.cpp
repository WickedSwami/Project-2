/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
*/

#include <iostream>
#include <string>
#include "Command.h"
using namespace std;



//constructor for commands    
Command::Command(string first, string second)
{
    commandWord = first;
    secondWord = second;
}


/*

retrieves the first word of a given command
@return the first word in a given command

*/

string Command::getCommandWord()
{
    return commandWord;
}


/*
retrieves the second word of a given command

@return the second word in a given command

*/
string Command::getSecondWord()
{
    return secondWord;
}


/*
tests to see if a command is valid

@return true or false, depending on whether or not the command
is recognized

*/
bool Command::isUnknown()
{
    return (commandWord.empty());
}


/*

tests to see if a command has a second word

@return true if the command has a second word, false otherwise

*/
bool Command::hasSecondWord()
{
    return (!secondWord.empty());
}
