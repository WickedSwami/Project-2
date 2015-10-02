#include <iostream>
#include <string>
#include "Command.h"
using namespace std;



    
Command::Command(string firstWord, string secondWord)
{
    commandWord = firstWord;
    this.secondWord = secondWord;
}


string Command::getCommandWord()
{
    return commandWord;
}


string Command::getSecondWord()
{
    return secondWord;
}


bool Command::isUnknown()
{
    return (commandWord == NULL);
}


bool Command::hasSecondWord()
{
    return (secondWord != NULL);
}
