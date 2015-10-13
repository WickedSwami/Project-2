/* 
* @author: Eric Stuppard
* @version: October 12, 2015
*
*/


#ifndef Item_H
#define Item_H

#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
	string itemName;
	string itemUse;

public:
	Item(string name, string description);
	string getName();
	string getDescription();

};

#endif
