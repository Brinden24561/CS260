
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
//template<typename T>
class HashTable
{	private:
	int size;
	int* hashArray;
	static const int EMPTY = -1;
	static const int DELETED = -2;
	int counter;
	// hashes it out
	int hasher(int value)
	{return value % this->size;}
public:

	HashTable(int SIZE);

	// creates array
	void construct(int customLength);
	
	~HashTable();

	//add value/hash
	void addValue(int value);

	//display nums and stuff
	std::string displayTable();

	//searches for key
	bool findValue(int key); 
	
	//deletes key
	bool removeValue(int key);

	//dub size array
	bool dubSize(int newSize);

	//load factor tracker for dub size

};

