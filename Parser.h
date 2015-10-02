#include <iostream>
#include <string>
#include "Command.h"
#include "CommandWords.h"
using namespace std;


#ifndef PARSER_H
#define PARSER_H

class Parser 
{
private:
    
    CommandWords commands;
    string toLowerCase(string);

public:
    Parser(commands);
    Command getCommand();
    void showCommands();
};

#endif
