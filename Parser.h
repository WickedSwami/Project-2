/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
*
*
*/

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include "Command.h"
#include "CommandWords.h"
using namespace std;


class Parser 
{
private:
    
    CommandWords commands;
    string toLowerCase(string);

public:
    Parser();
    Command getCommand();
    void showCommands();
};

#endif
