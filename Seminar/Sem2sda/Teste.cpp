#include "Teste.h"
#include <assert.h>
#include "Collection.h"
#include <iostream>
using namespace std;

void testAll()
{
	cout << "Testele au trecut" << endl;
	testSize();
	testAdd();
	testRemove();
	testSearch();
	testNrOccurences;
	testGetAt();
}


void testSize()
{
	Collection c = Collection();
	c.add(5);
	c.add(2);
	c.add(-1);
	c.add(-28);
	assert(c.size() == 4);
	c.add(0);
	c.add(3);
	c.add(-33);
	c.add(-222);
	assert(c.size() == 8);
}

void testAdd()
{
	Collection c = Collection();
	c.add(5);
	c.add(2);
	c.add(-1);
	c.add(-28);
	assert(c.getAt(0) == 5);
	assert(c.getAt(2) == -1);
	assert(c.getAt(0) == 5);
}

void testRemove()
{
	Collection c = Collection();
	c.add(5);
	c.add(2);
	c.add(-1);
	assert(c.search(5) == true && c.size()==3);
	c.remove(2);
	assert(c.search(2) == false && c.size() == 2);
}

void testSearch()
{
	Collection c = Collection();
	c.add(5);
	c.add(2);
	c.add(-1);
	assert(c.search(5) == true);
	assert(c.search(3) == false);
	assert(c.search(2) == true);
	assert(c.search(-1) == true);
	assert(c.search(1000) == false);
}

void testNrOccurences()
{
	Collection c = Collection();
	c.add(5);
	c.add(2);
	c.add(-1);
	c.add(5);
	c.add(6);
	c.add(-1);
	assert(c.nroccurrences(5) == 2);
	assert(c.nroccurrences(-1) == 2);
	assert(c.nroccurrences(2) == 1);
	assert(c.nroccurrences(6) == 1);
}

void testGetAt()
{
	Collection c = Collection();
	c.add(5);
	c.add(5);
	c.add(8);
	c.add(-5);
	c.add(100);
	//assert(c.getAt(0) == 8);
	assert(c.getAt(5) == -1);
	assert(c.getAt(3) == 100);
}
