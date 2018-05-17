
#include "stdafx.h"
#include "HashTable.h"
//template <class T>
HashTable::HashTable(int SIZE)
{
	construct(SIZE);
	counter = 0;
}
//template <class T>
void HashTable::construct(int customLength)
{
	this->size = customLength;
	//this->counter = 0;
	this->hashArray = new int[size];
	for (int i = 0; i < this->size; i++)
	{
		hashArray[i] = EMPTY;
	}

}
//template <class T>
HashTable::~HashTable()
{
	delete[] hashArray;

}
//add value/hash
//template <class T>
void HashTable::addValue(int value)
{
	//double factor = loadFactor();
	// load factor over 0.5 doubles
	if (counter >= this->size - 2)
	{
		dubSize((2 * this->size));
		/*	std::cout << " doubled the size ";*/
	}
	if (value == EMPTY)
	{
		return;
	}
	int arrayIndex = hasher(value);

	//DELETED HAS NOT YET BEEN INIT
	while(hashArray[arrayIndex] != EMPTY && hashArray[arrayIndex] != DELETED)
	{
		arrayIndex++;
		arrayIndex%this->size;

	}

	hashArray[arrayIndex] = value;
	counter++;
}
//display nums and stuff
//template <class T>
std::string HashTable::displayTable()
{
	std::stringstream buffer;
	//size is doubling twice
	for (int i = 0; i < size; i++)
	{
		if (hashArray[i] == EMPTY)
			buffer << " EMPTY ";
		else
			if (hashArray[i] == DELETED)
				buffer << " DELETED ";
			else
				buffer << hashArray[i] << " ";
	}
	return buffer.str();
}
//searches for key
//template <class T>
bool HashTable::findValue(int key)
{
	int arrayIndex = hasher(key);

	while (hashArray[arrayIndex] != EMPTY)
	{
		if (hashArray[arrayIndex] == key)
		{
			return true;
		}++arrayIndex;
		arrayIndex%this->size;
	}
	return false;
} //deletes key
//template <class T>
bool HashTable::removeValue(int key)
{
	int arrayIndex = hasher(key);

	while (hashArray[arrayIndex] != EMPTY)
	{
		if (hashArray[arrayIndex] == key)
		{
			int  value = hashArray[arrayIndex];
			hashArray[arrayIndex] = DELETED;
			return true;
		}++arrayIndex;
		arrayIndex%this->size;
	}
	return false;
}
// creates array
//dub size array
//template <class T>
bool HashTable::dubSize(int newSize)
{
	int copySize = this->size;
	int* oldArray = hashArray;
	construct(newSize);
	for (int i = 0; i < copySize; i++)
	{
		hashArray[i] = oldArray[i];
	}
	delete[]oldArray;
	return true;
}
