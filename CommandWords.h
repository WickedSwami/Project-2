#include <iostream>
#include <string>
using namespace std;

#ifndef COMMANDWORDS_H
#define COMMANDWORDS_H


class CommandWords
{
private:
    string validCommands[] = {"go", "quit", "help"};

public:
    CommandWords();
    bool isCommand(string aString);
    void showAll();
};

#endif;