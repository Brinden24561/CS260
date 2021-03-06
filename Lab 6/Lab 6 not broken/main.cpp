// Lab 6 not broken.cpp : Defines the entry point for the console application.
//

#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <string>


// if you are have not yet built one of these
// comment out that line
//#include "HashTable.h"
#include "StringHash.h"
//#include "ChainHash.h"

using namespace std;

// uncomment the test you want to run
//#define INT_HASH
#define STRING_HASH
//#define CHAIN_TEST

int main(int argc, const char * argv[]) {

	const int NUM_VALUES = 10;
	int values[NUM_VALUES] = { 10, 5, 30, 15, 20, 40, 60, 25, 50, 35 };


	string string_values[NUM_VALUES] = { "dog", "god", "cat", "act", "horse", "cow", "elephant", "otter", "seal", "ales" };

#ifdef STRING_HASH

	// this tests the string hashing code


	// change this to your class name
	StringHash stringHash;

	// place 10 items in a hash table
	try {

		for (int i = 0; i < NUM_VALUES; i++)
			stringHash.addValue(string_values[i]);
	}
	catch (std::length_error & ex) {
		cout << "Inserting failed with exception: " << ex.what() << endl;
		exit(1);
	}
	
	// dump the array
	cout << "Displaying the array before find and delete" << endl;
	cout << stringHash.displayTable() << endl;
	
	// now see if find works
	cout << "Looking for pig, should not find -- " << (stringHash.findValue("pig") ? "found" : "not found") << endl;
	cout << "Looking for otter, should find -- " << (stringHash.findValue("otter") ? "found" : "not found") << endl;
	
	// now delete 5 and see if still found
	cout << "Deleting otter, should work -- " << (stringHash.removeValue("otter") ? "found" : "not found") << endl;
	// now looking again
	cout << "Looking for otter again, should not find -- " << (stringHash.findValue("otter") ? "found" : "not found") << endl;

	// dump the array
	cout << endl << "Displaying the array after deleting otter, s/b replaced with \"dele\"" << endl;
	cout << stringHash.displayTable() << endl;
	
#endif //STRING_HASH
	cin.get();

	return 0;
}