#ifndef Command_H
#define Command_H

#include <iostream>
#include <string>
using namespace std;

class Command
{
private:
    string commandWord;
    string otherWord;

public:
    Command(string first, string second);
    string getCommandWord();  
    bool getSecondWord();
	bool isUnknown();   
    bool hasSecondWord();
};

#endif