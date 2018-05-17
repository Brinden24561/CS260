#pragma 
#include "stdafx.h"
#include <string>

////template <class T>
class StringHash
{	private:
	int size = 10;
	std::string* stringArray;
	std::string EMPTY = "EMPTY";
	std::string DELETED = "GONE";
	int counter;
	// hashes it out
	int hasher(int value)
	{
		return value % this->size;
	}
public:


	// creates array
	StringHash();
	void construct(int);

	~StringHash();
	void addValue(std::string value);

	//display nums and stuff
	std::string displayTable();

	//searches for key
	bool findValue(std::string key);

	//deletes key
	bool removeValue(std::string key);
	bool dubSize(int newSize = 20);

	
};
