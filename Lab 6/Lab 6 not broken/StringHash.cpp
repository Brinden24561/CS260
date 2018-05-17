#include "stdafx.h"
#include "StringHash.h"
#include <sstream>
#include <string>
#include <iostream>
// creates array
StringHash::StringHash()
{
	this->counter = 0;
	this->size = 10;
	construct(this->size);
}
void StringHash::construct(int SIZE)
{
	stringArray = new std::string[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		stringArray[i] = EMPTY;
	}
}

StringHash::~StringHash()
{
	delete[]stringArray;
}
void StringHash::addValue(std::string key)
{
	//double factor = loadFactor();
	// load factor over 0.5 doubles
	if (counter >= this->size - 2)
	{
		dubSize();
		/*	std::cout << " doubled the size ";*/
	}
	if (key.length() == 0)
	{
		return;
	}
	int arrayIndex = 0;
	int pow27 = 1;
	std::string str(key);
	/*starts at right most letter then moves left
	multiples by 27 each letter */
	for (int i = str.length() - 1; i >= 0; i--)
	{
		int letter = str.at(i);
		arrayIndex += pow27 * letter;
		pow27 *= 27;
	}
	arrayIndex = hasher(arrayIndex);
	//std::cout << "array index is ->" << arrayIndex;

	//DELETED HAS NOT YET BEEN INIT
	while (stringArray[arrayIndex] != EMPTY && stringArray[arrayIndex] != DELETED)
	{
		arrayIndex++;
		if (arrayIndex >= this->size)
		{
			arrayIndex = 0;
		}

	}

	stringArray[arrayIndex] = key;
	//std::cout << "the array at index " << arrayIndex << " is " << stringArray[arrayIndex] << " \n ";
	counter++;
}

//display nums and stuff
std::string StringHash::displayTable()
{
	std::stringstream buffer;
	//size is doubling twice
	for (int i = 0; i < size; i++)
	{
		if (stringArray[i] == EMPTY)
			buffer << " EMPTY ";
		else
			if (stringArray[i] == DELETED)
				buffer << " DELETED ";
			else
				buffer << stringArray[i] << " ";
	}
	return buffer.str();
}

//searches for key
bool StringHash::findValue(std::string key)
{

	if (key.length() == 0)
	{
		return "";
	}
	int arrayIndex = 0;
	int pow27 = 1;
	std::string str(key);
	/*starts at right most letter then moves left
	multiples by 27 each letter */
	for (int i = str.length() - 1; i >= 0; i--)
	{
		int letter = str.at(i);
		arrayIndex += pow27 * letter;
		pow27 *= 27;
	}
		arrayIndex = hasher(arrayIndex);
	while (stringArray[arrayIndex] != EMPTY)
	{
		if (stringArray[arrayIndex] == key)
		{
			return true;
		}++arrayIndex;
		
	}
	return false;
}

//deletes key
bool StringHash::removeValue(std::string key)
{
	if (key.length() == 0)
	{
		return "";
	}
	int arrayIndex = 0;
	int pow27 = 1;
	std::string str(key);
	/*starts at right most letter then moves left
	multiples by 27 each letter */
	for (int i = str.length() - 1; i >= 0; i--)
	{
		int letter = str.at(i);
		arrayIndex += pow27 * letter;
		pow27 *= 27;
	}
	arrayIndex = hasher(arrayIndex);
	while (stringArray[arrayIndex] != EMPTY)
	{
		if (stringArray[arrayIndex] == key)
		{
			stringArray[arrayIndex] = DELETED;
			return true;
		}
		++arrayIndex;

	}
	return false;
}
bool StringHash::dubSize(int newSize)
{
	int copySize = this->size;
	std::string* oldArray = stringArray;
	construct(newSize);
	for (int i = 0; i < copySize; i++)
	{
		stringArray[i] = oldArray[i];
	}
	delete[]oldArray;
	return true;
}
