#pragma once
#include "DO.h"


class Iterator
{
	friend class DO;
	private:
	//constructorul primeste o referinta catre Container
		//iteratorul va referi primul element din container
		Iterator(const DO& d);

		//contine o referinta catre containerul pe care il itereaza
		const DO& dict;
		/* aici e reprezentarea specifica a iteratorului*/
		int curent;
		int* pozitii;
		int dimensiune;
		int prim;
		int ultim;
public:
	//scrie functia de prim()
	void prim();

};
