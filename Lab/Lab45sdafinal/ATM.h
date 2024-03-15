#pragma once
 
#include "Collection.h"
#include "Tranzactie.h"

#include<iostream>
#include<string>
#include<vector>
using namespace std;
 

class ATM {
private:
    Collection colectie_bancnote;
    Tranzactie* tranzactii;
    int nr_tranzactii;
    int idu;
    std::vector<std::string> output;
    string filename;
    void afisare_colectie(Element bancnote[], int lungime, int k);


public:
    ATM(string fileBancnote, const Collection& colectie, Tranzactie tranzactie[], int nr_tranzactii);
  
    void tranzactie_retragere(char pozi2[], int suma); // functie pentru adaugarea unei tranzactii unde se depoziteaza bani
    void tranzactie_retragere2(char pozi2[], int suma); // functie pentru adaugarea unei tranzactii unde se scot bani

    friend ostream& operator<<(ostream& os, ATM atm);
    void Add_bancnote(TElem valoare); // functie care adauga bancnota individuala in ATM
    void Elim_bancnota(TElem valoare);

    void prelucrare_tranzactia(int& poz_stop, int suma, Element bancnote[], int lungime, int poz);
    void combinatie_suma(int& indice, int suma, Element bancnote[], int lungime, int poz);
    void scoatere_numerar(int id, int suma, int lungime, Element bancnote[]);
    void addstring();
    ATM() {
        idu = 1;
    }

};

 
 