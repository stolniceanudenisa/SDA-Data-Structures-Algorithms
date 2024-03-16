//
// Created by aluas on 25.03.2023.
//

#ifndef LAB_2_COLLECTION_H
#define LAB_2_COLLECTION_H
#include<iostream>
using namespace std;

typedef int TElem;

struct Element{     ///data care stocheaza bancnota si numarul de aparitii
    TElem valoare;
    int nr_aparitii;
};

class Collection {
private:
    Element* elements;      // un sir de elemente
    int distinctelements;   // numarul de elemente distincte
    int capacity;           //capacitatea sirului
public:
    Collection();               //constructor fara parametrii
    void Destructor();          //destructor
    void add(TElem elem);       //adaugare de noi obiecte in colectie
    bool remove(TElem elem);    //sterge un element din colectie
    bool search(TElem elem);    //cauta un element in clasa
    int size();                 //returneaza dimensiunea
    void redim();               //actualizeaza dimensiunea
    int nroccurrences(TElem elem);              //returneaza numarul de aparitii a unui obiect dat
    int getAt(int position);                    //returneaza numarul de aparitii a unui obiect de pe pozitia data
    int get_lungime();                          //returneaza numarul de elemente distincte din sir
    void set_numar_bancnote(Element elem);      //seteaza nr de aparitii a unui element deja existent
    TElem get_val(int position);                //returneaza obiectul aflat pe pozitia data
    Collection& operator=(const Collection& colectie);      //atribuie unui obiect de tipul colectie un alt obiect de acelasi tip

    //friend ostream& operator<<(ostream& os, Collection colectie);
};

#endif //LAB_2_COLLECTION_H
