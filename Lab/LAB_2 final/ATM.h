//
// Created by aluas on 14.03.2023.
//

#ifndef LAB_2_ATM_H
#define LAB_2_ATM_H
#include "Collection.h"
#include "Tranzactie.h"

#include<iostream>
using namespace std;

class ATM {
    private:
        Collection colectie_bancnote;
        Tranzactie* tranzactii;
        int nr_tranzactii;
        void afisare_colectie(Element bancnote[], int lungime, int k);
    public:
        ATM(const Collection& colectie, Tranzactie tranzactie[], int nr_tranzactii);
        void Retragere_numerar(int id, int suma, int lungime, Element bancnote[]);
        friend ostream& operator<<(ostream& os, ATM atm);
        void Add_bancnote(TElem valoare);
        void Elim_bancnota(TElem valoare);
        void Get_tranzactia(int& poz_stop,int suma, Element bancnote[], int lungime, int poz);
        void Generare_Tranzactii(int& indice,int suma, Element bancnote[], int lungime, int poz);
        //~ATM();
};

#endif //LAB_2_ATM_H