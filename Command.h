/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
*/

#ifndef Command_H
#define Command_H

#include <iostream>
#include <string>
using namespace std;

class Command
{
private:
    string commandWord;
    string secondWord;

public:
    Command(string first, string second);
    string getCommandWord();  
    string getSecondWord();
	bool isUnknown();   
    bool hasSecondWord();
};

#endif