/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
*
*
*/

#ifndef COMMANDWORDS_H
#define COMMANDWORDS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class CommandWords
{
private:
    vector<string> validCommands;

public:
    CommandWords();
    bool isCommand(string aString);
    void showAll();
    void fillValidCommands(vector<string> &commands);
};

#endif