/* 
* @author: Eric Stuppard
* @version: September 30, 2015
*
* Parser class reads user input, creates commands 
* for program to use
*/

#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"
using namespace std;

//constructor for Parser (no instance variables)
Parser::Parser(){}


/*
tells the parser to retrive a commands from player input
@return the player's command to the parser for use
*/
Command Parser::getCommand() 
{
    cout << "> ";
    string inputLine;
    string word1;
    string word2;

    getline(cin, inputLine);

    vector<string> words;
    int location = inputLine.find_first_of(" ");
    while (location!= string::npos)
    {
        string word = inputLine.substr(0,location);
        if(word != "")
        {
            words.push_back(word);
        }
        
        inputLine = inputLine.substr(location+1);
        location = inputLine.find_first_of(" ");
    }
    words.push_back(inputLine);

    if (words.size()>1) {
        word1 = words[0];
        word2 = words[1];
        cout << word2 << endl;
    } else {
        word1 = words[0];
    }


    if(commands.isCommand(word1)) {
        Command *thisCommand = new Command(word1,word2);
        return *thisCommand;
    }
    else {
        Command *thatCommand = new Command("", word2);
        return *thatCommand; 
    }
}


//prints all valid commands to the terminal
void Parser::showCommands()
{
    commands.showAll();
}
