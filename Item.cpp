/* 
* @author: Eric Stuppard
* @version: October 12, 2015
*
*/

#include <iostream>
#include "Item.h"
using namespace std;

// Constructor for class Item
Item::Item(string name, string description)
{
	itemName = name;
	itemUse = description;
}

// retrieves the name of an item
// @return an item's name
string Item::getName()
{
	return itemName;
}

// retrieves an item's description
// @return an item's description
string Item::getDescription()
{
	return itemUse;
}