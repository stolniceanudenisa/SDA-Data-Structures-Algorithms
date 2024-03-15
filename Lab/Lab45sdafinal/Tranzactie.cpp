
#include "Tranzactie.h"
#include "Collection.h"
#include <string>

//constructor cu parametri
Tranzactie::Tranzactie(int id, int suma, Element bancnote[], int nr_bancnote) {
    this->Id_tranzatie = id;
    this->suma = suma;
    this->nr_banconte = nr_bancnote;
    this->bancnote = new Element[nr_bancnote];
    for (int i = 0; i < nr_bancnote; i++)
        this->bancnote[i] = bancnote[i];
}

//constructor fara parametri
Tranzactie::Tranzactie() {
    this->Id_tranzatie = -1;
    this->suma = -1;
    this->bancnote = new Element[1];
    this->nr_banconte = -1;
}

//destructor
void Tranzactie::Destructor() {
    delete[] this->bancnote;
}

//operator de atribuire
Tranzactie& Tranzactie::operator=(const Tranzactie& tranzactie) {
    this->Id_tranzatie = tranzactie.Id_tranzatie;
    this->suma = tranzactie.suma;
    this->nr_banconte = tranzactie.nr_banconte;
    //delete[] this->bancnote;
    this->bancnote = new Element[this->nr_banconte];
    for (int i = 0; i < this->nr_banconte; i++)
        this->bancnote[i] = tranzactie.bancnote[i];
    return *this;
}

//operator
ostream& operator<<(ostream& os, Tranzactie tranzactie) {
    cout << "S-a efectuat tranzactia cu id-ul: " << tranzactie.Id_tranzatie << "; unde a fost scoasa suma: " << tranzactie.suma << endl;
    cout << "platindu-se cu bancnotele: ";
    for (int i = 0; i < tranzactie.nr_banconte; i++)
        cout << tranzactie.bancnote[i].valoare << "*" << tranzactie.bancnote[i].nr_aparitii << "  ";
    cout << endl;
    return os;
}

string Tranzactie::ToString() {
    string s;
    s = "id-ul: " + to_string(this->Id_tranzatie) + ", suma: " + to_string(this->suma) + ", plata: ";
    for (int i = 0; i < this->nr_banconte; i++)
        s = s + to_string(this->bancnote[i].valoare) + "*" + to_string(this->bancnote[i].nr_aparitii) + ", ";
    return s;
}



