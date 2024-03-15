#pragma once

 
#include "Collection.h"
#include<iostream>
using namespace std;

typedef int TElem;

//clasa Tranzactie

class Tranzactie {
private:
    int Id_tranzatie;
    int suma;
    Element* bancnote;
    int nr_banconte;
public:
    //Constructor implicit
    Tranzactie();

    //Constructor cu parametri
    Tranzactie(int id, int suma, Element bancnote[], int nr_bancnote);

    //operator de atribuire
    Tranzactie& operator=(const Tranzactie& tranzactie);

    //Destructor
    void Destructor();

    //Supra incarcare operator afisare
    friend ostream& operator<<(ostream& os, Tranzactie tranzactie);

    string ToString();
};

 