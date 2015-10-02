#include <iostream>
#include <string>
#include "Command.h"
using namespace std;



    
Command::Command(string first, string second)
{
    commandWord = first;
    secondWord = second;
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
