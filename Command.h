#include <iostream>
#include <string>
using namespace std;

#ifndef COMMAND_H
#define COMMAND_H

class Command
{
private:
    string commandWord;
    string secondWord;

public:
    Command(String firstWord, String secondWord);
    string getCommandWord();  
    bool getSecondWord();
	bool isUnknown();   
    bool hasSecondWord()
};

#endif