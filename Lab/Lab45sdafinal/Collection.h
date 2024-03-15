#pragma once
 

#include<iostream>
 
#include "List.h"

using namespace std;
typedef int TElem;


// structura cu element de tip pereche
// care grupeaza elementul si frecventa lui de aparitie incolectie

struct Element
{
    TElem valoare;
    int nr_aparitii;
};


class Collection {
private:
    List<Element> elements;      // sirul elemente
    int distinctelements;   // numarul de elemente distincte
    int capacity;           //capacitatea sirului

public:
    //constructor fara parametri
    Collection();
    //destructor
    void Destructor();
    //functie de add obiect
    void add(TElem elem);
    //functie de stergere element
    bool remove(TElem elem);
    //functie ce stergere un nr de aparitii al unui element
    bool removeapp(TElem elem);
    //functie ce cauta un element
    bool search(TElem elem);
    //functie ce returneaza dimensiunea sirului
    int size();
    //functie ceactualizeaza dimensiunea
    void redim();
    //returneaza numarul de aparitii al unui obiect
    int nroccurrences(TElem elem);
    //returneaza numarul de aparitii a unui obiect de pe pozitia data
    int getAt(int position);
    //returneaza numarul de elemente distincte din sir
    int get_lungime();
    //seteaza nr de aparitii a unui element deja existent
    void set_numar_bancnote(Element elem);
    //returneaza obiectul aflat pe pozitia data
    TElem get_val(int position);
    //atribuie unui obiect de tipul colectie un alt obiect de acelasi tip
    Collection& operator=(const Collection& colectie);


};

 














//friend ostream& operator<<(ostream& os, Collection colectie);