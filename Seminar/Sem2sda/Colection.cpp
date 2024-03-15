#include "Collection.h"



// constructor fara param
// creeaza colectia vida
//in 
// out: colectia vida
Collection::Collection() {
	this->distinctelements = 0;
	this->capacity = 10;
	this->elements = new TElem[capacity];
	this->occurrences = new int[capacity];

	/*elements = new TElem[5];
	elements[0] = 2;
	elements[1] = -5;
	elements[2] = 7;
	occurrences = new int[5];
	occurrences[0] = 4;
	occurrences[1] = 9;
	occurrences[2] = 5;
	distinctelements = 3;
	capacity = 5;*/
}





void Collection::resize()
{
	this->capacity *= 2;
	TElem* newelems = new TElem[this->capacity];
	int* newoccurences = new int[this->capacity];
	for (int i = 0; i < this->distinctelements; i++)
	{
		newelems[i] = this->elements[i];
		newoccurences[i] = this->occurrences[i];
	}
	delete[] elements;
	delete[] occurrences;
	this->elements = newelems;
	this->occurrences = occurrences;
}





// adaugarea unui element de tip TElem in lista
//in: elementul de tip TElem ce va fi adaugat
void Collection::add(TElem elem)
{
	bool exist = false;
	int position;
	for (int i = 0; i < distinctelements; i++)
		if (elem == elements[i]) {
			exist = true;
			position = i;
		}

	if (exist)
		occurrences[position] = occurrences[position] + 1;
	else {
		if (distinctelements + 1 > capacity) {
			capacity *= 2;
			TElem* tmp = new TElem[capacity];
			for (int i = 0; i < distinctelements; ++i) {
				tmp[i] = elements[i];
			}
			delete[] elements;
			elements = tmp;
			int* tmp2 = new int[capacity];
			for (int i = 0; i < distinctelements; ++i) {
				tmp2[i] = occurrences[i];
			}
			delete[] occurrences;
			occurrences = tmp2;

		}
		elements[distinctelements] = elem;
		occurrences[distinctelements] = 1;
		distinctelements++;
	}
}

//void Collection::add(TElem elem) //add-ul meu
//{
//	int pozitie = -1, i = 0;
//	bool found = false;
//	for (int i = 0; i < distinctelements; i++)
//		if (elem == elements[i] && pozitie == -1)
//		{
//			pozitie = i;
//			found = true;
//		}
//	if (found)
//		occurrences[pozitie] = occurrences[pozitie] + 1;
//	else {
//		if (this->distinctelements == this->capacity)
//			resize();
//		elements[distinctelements] = elem; //pe ultima pozitie posibila punem noul element
//		occurrences[elem] = 1;
//		distinctelements++;
//	}
//}



// stergerea unui element de tip TElem din lista
// in: elementul care va fi sters
// out: true daca este gasit si sters, false in caz contrar
bool Collection::remove(TElem elem)
{

	bool exist = false;
	int position;
	for (int i = 0; i < distinctelements; i++) {
		if (elem == elements[i]) {
			exist = true;
			position = i;
		}
	}

	if (exist) {
		if (occurrences[position] > 1) {
			occurrences[position]--;
		}
		else {
			for (int i = position; i < distinctelements - 1; i++) {
				elements[i] = elements[i + 1];
				occurrences[i] = occurrences[i + 1];
			}
			distinctelements--;
		}
		return true;
	}
	return false;

	/*int pozitie = -1, i = 0;
	bool found = false;
	for (int i = 0; i < distinctelements; i++)
		if (elem == elements[i] && pozitie == -1)
		{
			pozitie = i;
			found = true;
		}
	if (pozitie == -1)
		return false;
	else
		if (occurrences[pozitie] > 1)
		{
			occurrences[pozitie]--;
			return true;
		}
		else
		{
			elements[pozitie] = elements[distinctelements - 1];
			occurrences[pozitie] = occurrences[distinctelements - 1];
			distinctelements--;
			return true;
		}
	return false;*/
}


//  returnarea lungimii listei de elemente
// in:
// out: lungimea listei
int Collection::size()
{
	int lungime = 0;
	for (int i = 0; i < this->distinctelements; i++)
		lungime +=  this->occurrences[i];
	return lungime;
		
}


// returneaza nr de aparitii pentru un element
// in: elementul de tip TElem
// out: numarul de aparitii al elementului
int Collection::nroccurrences(TElem elem)
{
	for (int i = 0; i < this->distinctelements; i++)
		if (elem == this->elements[i])
			return this->occurrences[i];
	return 0;
}

/*
* Returneaza elementul din lista care se gaseste pe o pozitie
* in: pozitia - parametru de tip intreg
* out: elementul de pe pozitia position din lista de elemente
*     -1 in cazul in care elementul de pe pozitia aceea nu exista

*/
int Collection::getAt(int position)
{
	if (position < this->distinctelements && position >=0)
		return this->elements[position];
	return -1;
}



// cautarea unui element in lista
// in: element de tip TElem
// out: true - daca elementul este gasit
//      false - caz contrar

bool Collection::search(TElem elem)
{
	for (int i = 0; i < this->distinctelements; i++) //nu trebuie neapart this pt ca nu mai avem si alt parametru distinctelements
		if (elem == this-> elements[i])
			return true;
	return false;
}


// destructor
Collection::~Collection()
{
	if (this->elements)
	{
		delete[] this->elements;
		delete[] this->occurrences;
		//distinctelements = 0;
	}
	/*delete[] elements;
	delete[] occurrences;
	distinctelements = 0;*/
}


//void Collection::afis() {
//	for (int i = 0; i <= this->size(); i++) {
//		cout << this->elements[i] << " " << this->nroccurrences(elements[i]) << std::endl;
//	}
//}
