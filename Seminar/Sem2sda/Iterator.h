#pragma once
#include "Collection.h"

class Iterator {
private:
	Collection collection;
	int position;
public:
	Iterator(Collection c); // init 
	bool valid();
	void first();
	void next();
	int current();
	int getCurrentOccurrences();
};