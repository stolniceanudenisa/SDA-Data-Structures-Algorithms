//
// Created by aluas on 25.03.2023.
//

#include "Collection.h"
#include<iostream>
using namespace std;
typedef int TElem;

Collection::Collection() {
    this->distinctelements = 0;
    this->capacity = 10;
    this->elements = new Element[this->capacity];
}

void Collection::add(TElem elem) {
    if(search(elem)){
        int ok = 1;
        for(int i = 0; i< this->distinctelements&&ok; i++)
            if(this->elements[i].valoare == elem){
                this->elements[i].nr_aparitii ++;
                ok =0;
            }
    }
    else{
        if(this->distinctelements == capacity)
            redim();
        this->elements[this->distinctelements].nr_aparitii = 1;
        this->elements[this->distinctelements].valoare = elem;
        this->distinctelements++;
    }
}

bool Collection::remove(TElem elem) {
    if(search(elem))
    {
        int i = 0;
        while(this->elements[i].valoare != elem)
            i++;
        for(int j = i; j< this->distinctelements - 1;j++)
            this->elements[j] = this->elements[j+1];
        this->distinctelements --;
        return true;
    }
    return false;
}

bool Collection::search(TElem elem) {
    for(int i = 0; i< this->distinctelements; i++)
        if(this->elements[i].valoare == elem)
            return true;
    return false;
}

int Collection::size() {
    int sum = 0;
    for(int i = 0; i< this->distinctelements; i++)
        sum = sum + this->elements[i].valoare* this->elements[i].nr_aparitii;
    return sum;
}

int Collection::nroccurrences(TElem elem) {
    if(search(elem)){
        int i = 0;
        while(this->elements[i].valoare != elem)
            i++;
        return this->elements[i].nr_aparitii;
    }
    return -1;
}

void Collection::Destructor() {
    delete[] this->elements;
    this->capacity = 0;
    this->distinctelements = 0;
}

int Collection::getAt(int position) {
    return this->elements[position].nr_aparitii;
}

void Collection::Collection::redim() {
    this->capacity = this->capacity*2;
    Element* new_elems = new Element[this->capacity];
    for(int i = 0; i<this->distinctelements;i++)
        new_elems[i] = this->elements[i];
    delete[] this->elements;
    this->elements = new_elems;
}

//IMPLEMENTARE IN PLUS
int Collection::get_lungime() {
    return this->distinctelements;
}

TElem Collection::get_val(int position) {
    return this->elements[position].valoare;
}

Collection &Collection::operator=(const Collection &colectie) {
    this->distinctelements = colectie.distinctelements;
    this->capacity = colectie.capacity;
    delete[] this->elements;
    this->elements = new Element[this->capacity];
    for(int i = 0;i<this->capacity;i++)
        this->elements[i] = colectie.elements[i];
    return *this;
}

void Collection::set_numar_bancnote(Element elem) {
    if(search(elem.valoare))
    {
        int i = 0;
        while(this->elements[i].valoare != elem.valoare)
            i++;
        this->elements[i].nr_aparitii = elem.nr_aparitii;
    }
}
