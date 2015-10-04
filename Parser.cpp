/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
*
*
*/

#include <iostream>
#include <string>
#include <set>
#include "Parser.h"
using namespace std;


Parser::Parser(){}

Command Parser::getCommand() 
{
    cout << "> ";
    string inputLine;
    string word1;
    string word2;

    getline(cin, inputLine);
    inputLine = toLowerCase(input)

    set<string> words;
    int location = inputLine.find_first_of(" ");
    while (location!= string::npos)
    {
        string word = inputLine.substr(0,location);
        if(word != "")
        {
            words.insert(word);
        }
        
        inputLine = inputLine.substr(location+1);
        location = inputLine.find_first_of(" ");
    }

    words.insert(inputLine);
    if(commands.isCommand(word1)) {
        return new Command(word1, word2);
    }
    else {
        return new Command(null, word2); 
    }
}

void Parser::showCommands()
{
    commands.showAll();
}
