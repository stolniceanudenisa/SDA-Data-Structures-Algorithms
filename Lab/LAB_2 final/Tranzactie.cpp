//
// Created by aluas on 14.03.2023.
//

#include "Tranzactie.h"

Tranzactie::Tranzactie(int id, int suma, Element bancnote[], int nr_bancnote) {
    this->Id_tranzatie =  id;
    this->suma = suma;
    this->nr_banconte = nr_bancnote;
    this->bancnote = new Element[nr_bancnote];
    for(int i = 0; i< nr_bancnote;i++)
        this->bancnote[i] = bancnote[i];
}

Tranzactie::Tranzactie() {
    this->Id_tranzatie = -1;
    this->suma = -1;
    this->bancnote = new Element[1];
    this->nr_banconte = -1;
}

void Tranzactie::Destructor() {
    delete[] this->bancnote;
}

Tranzactie &Tranzactie::operator=(const Tranzactie &tranzactie) {
    this->Id_tranzatie = tranzactie.Id_tranzatie;
    this->suma = tranzactie.suma;
    this->nr_banconte = tranzactie.nr_banconte;
    delete[] this->bancnote;
    this->bancnote = new Element[this->nr_banconte];
    for(int i = 0;i<this->nr_banconte;i++)
        this->bancnote[i] = tranzactie.bancnote[i];
    return *this;
}

ostream &operator<<(ostream &os, Tranzactie tranzactie) {
    cout<<"id: "<<tranzactie.Id_tranzatie<<" suma: "<<tranzactie.suma<<endl;
    cout<<"Plata: ";
    for(int i = 0;i<tranzactie.nr_banconte;i++)
        cout<<tranzactie.bancnote[i].valoare<<"->"<<tranzactie.bancnote[i].nr_aparitii<<", ";
    cout<<endl;
    return os;
}
