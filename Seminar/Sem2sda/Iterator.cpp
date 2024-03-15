#include "Iterator.h"

//Iterator::Iterator(Collection c) 
//{
//	this->collection = c;
//
//	if (collection.size() != 0)
//		this->position = 1;
//	else
//		this->position = 0;
//}
//
//bool Iterator::valid() 
//{
//	return (position > 0 && this->position <= this->collection.size());
//}
//
//
//void Iterator::first()
//{
//	if (collection.size() != 0)
//		this->position = 1;
//	//cout << this->collection.getAt(0) << endl;
//}
//
//void Iterator::next()
//{
//	position++;
//
//	//#include <bits/stdc++.h>
//	/*if (this->valid())
//		throw exception("Iterator out of range");
//	this->position++;*/
//}
//
//int Iterator::current()
//{
//	return collection.getAt(position - 1);
//
//	/*if (this->valid())
//		throw exception("Iterator out of range");
//	return (this->collection.getAt(this->position))*/
//}
//
//int Iterator::getCurrentOccurrences()
//{
//	return collection.nroccurrences(current());
//
//	/*if (this->valid())
//		return (this->collection.nroccurrences(this->collection.getAt(this->position)))
//		throw exception("Iterator out of range")*/
//}


Iterator::Iterator(Collection c) {
	this->collection = c;

	if (collection.size() != 0)
		this->position = 1;
	else
		this->position = 0;
}

bool Iterator::valid() {
	return (position > 0 && position <= this->collection.size());
}

void Iterator::first() {
	if (collection.size() != 0)
		this->position = 1;
}

void Iterator::next() {
	position++;
}

int Iterator::current() {
	return collection.getAt(position - 1);
}

int Iterator::getCurrentOccurrences() {
	return collection.nroccurrences(current());
}