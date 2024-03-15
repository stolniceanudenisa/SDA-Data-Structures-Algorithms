#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


Colectie::Colectie() {
    prim = nullptr;
    ultim = nullptr;
    len = 0;
}


void Colectie::adauga(TElem e) {
    if (prim == nullptr) {
        // Cazul în care colecția este goală
        Nod* nou = new Nod;
        nou->element = e;
        nou->frecventa = 1;
        nou->prev = nullptr;
        nou->next = nullptr;
        prim = nou;
        ultim = nou;
        len++;
    }
    else {
        // Cazul în care colecția nu este goală
        Nod* nod = prim;
        while (nod != nullptr && nod->element != e) {
            nod = nod->next;
        }

        if (nod != nullptr) {
            // Elementul există deja în colecție, creștem frecvența
            nod->frecventa++;
        }
        else {
            // Elementul nu există în colecție, adăugăm un nou nod
            Nod* nou = new Nod;
            nou->element = e;
            nou->frecventa = 1;
            nou->prev = ultim;
            nou->next = nullptr;
            ultim->next = nou;
            ultim = nou;
            len++;
        }
    }
}


bool Colectie::sterge(TElem e) {
    Nod* nod = prim;
    while (nod != nullptr && nod->element != e) {
        nod = nod->next;
    }

    if (nod == nullptr) {
        // Elementul nu există în colecție
        return false;
    }
    else {
        if (nod->frecventa > 1) {
            // Dacă frecvența este mai mare decât 1, scădem frecvența
            nod->frecventa--;
        }
        else {
            // Dacă frecvența este 1, ștergem nodul din colecție
            if (nod == prim) {
                prim = nod->next;
                if (prim != nullptr) {
                    prim->prev = nullptr;
                }
                else {
                    ultim = nullptr;
                }
            }
            else if (nod == ultim) {
                ultim = nod->prev;
                ultim->next = nullptr;
            }
            else {
                nod->prev->next = nod->next;
                nod->next->prev = nod->prev;
            }
            delete nod;
            len--;
        }
        return true;
    }
}


bool Colectie::cauta(TElem elem) const {
    Nod* nod = prim;
    while (nod != nullptr) {
        if (nod->element == elem) {
            return true;
        }
        nod = nod->next;
    }
    return false;
}

int Colectie::nrAparitii(TElem elem) const {
    int count = 0;
    Nod* nod = prim;
    while (nod != nullptr) {
        if (nod->element == elem) {
            count += nod->frecventa;
        }
        nod = nod->next;
    }
    return count;
}


int Colectie::dim() const {
    return len;
}


bool Colectie::vida() const {
    return len == 0;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
    Nod* nod = prim;
    while (nod != nullptr) {
        Nod* next = nod->next;
        delete nod;
        nod = next;
    }
}


