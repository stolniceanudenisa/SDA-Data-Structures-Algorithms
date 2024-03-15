
#include "Collection.h"
#include<iostream>
using namespace std;
typedef int TElem;

// constructorul
Collection::Collection() {
    this->distinctelements = 0;
    this->capacity = 10;

}

// adaugare element in colectia de elemente
void Collection::add(TElem elem) {
    if (search(elem)) {
        int ok = 1;
        for (int i = 0; i < this->distinctelements && ok; i++)
            if (this->elements.get_at(i).valoare == elem) {
                int nrAparitii = this->elements.get_at(i).nr_aparitii + 1;
                Element elem2;
                elem2.valoare = elem;
                elem2.nr_aparitii = nrAparitii;
                this->elements.update(i, elem2);
                ok = 0;
            }
    }
    else {
        if (this->distinctelements == capacity)
            redim();
        Element elem2;
        elem2.valoare = elem;
        elem2.nr_aparitii = 1;
        this->elements.push_back(elem2);
        this->distinctelements++;
    }


}
//stergere element
bool Collection::remove(TElem elem) {
    if (search(elem))
    {
        int i = 0;
        while (this->elements.get_at(i).valoare != elem)
            i++;
        for (int j = i; j < this->distinctelements - 1; j++) {
            this->elements.update(j, this->elements.get_at(j + 1));
        }
        this->distinctelements--;
        return true;
    }
    return false;
}


//cauta un element
bool Collection::search(TElem elem) {

    for (int i = 0; i < this->distinctelements; i++)
        if (this->elements.get_at(i).valoare == elem)
            return true;
    return false;
}

// returneaza lungimea vectorului
int Collection::size() {
    int nr = 0;
    for (int i = 0; i < this->distinctelements; i++)
        nr = nr + this->elements.get_at(i).valoare * this->elements.get_at(i).nr_aparitii;
    return nr;
}

// returneaza numarul de aparitii al unui element
int Collection::nroccurrences(TElem elem) {

    if (search(elem)) {
        int i = 0;
        while (this->elements.get_at(i).valoare != elem)
            i++;
        return this->elements.get_at(i).nr_aparitii;
    }
    return -1;
}

//destructorul
void Collection::Destructor() {
    this->capacity = 0;
    this->distinctelements = 0;
    this->elements.Destructor();
}


//returneaza nr aparitii ale unui element de pe o anumita pozitie
int Collection::getAt(int position) {

    return this->elements.get_at(position).nr_aparitii;

}



//returneaza lungimea listei
int Collection::get_lungime() {
    return this->distinctelements;
}


//returneaza valoarea unui element de pe o anumita pozitie
TElem Collection::get_val(int position) {
   
    return this->elements.get_at(position).valoare;
}


// seteaza numarul curent de bancnote cu alta valoare
void Collection::set_numar_bancnote(Element elem) {
  
    if (search(elem.valoare))
    {
        int i = 0;
        while (this->elements.get_at(i).valoare != elem.valoare)
            i++;
        this->elements.update(i, elem);
    }
}


void Collection::Collection::redim() {
    this->capacity = this->capacity * 2;
    //    Element* new_elems = new Element[this->capacity];
    //    for(int i = 0; i<this->distinctelements;i++)
    //        new_elems[i] = this->elements[i];
    //    delete[] this->elements;
    //    this->elements = new_elems;
}










Collection& Collection::operator=(const Collection& colectie) {

    this->distinctelements = colectie.distinctelements;
    this->capacity = colectie.capacity;
    //for (int i = 0; i < this->capacity; i++)
        //this->elements.update(i, colectie.elements.get_at(i)); 

    return *this;

}




// sterge nr de aparitii al unui element
bool Collection::removeapp(TElem elem) {
    //    if(search(elem)){
    //        int i = 0;
    //        while(this->elements[i].valoare != elem)
    //            i++;
    //        return this->elements[i].nr_aparitii--;
    //    }
        return -1;
}
