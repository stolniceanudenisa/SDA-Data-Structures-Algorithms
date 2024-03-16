//
// Created by aluas on 14.03.2023.
//

#ifndef LAB_2_TRANZACTIE_H
#define LAB_2_TRANZACTIE_H
#include "Collection.h"
#include<iostream>
using namespace std;

typedef int TElem;

class Tranzactie {
    private:
        int Id_tranzatie;
        int suma;
        Element* bancnote;
        int nr_banconte;
    public:
        Tranzactie(int id, int suma, Element bancnote[], int nr_bancnote);   //Constructor cu parametrii
        Tranzactie();                                                        //Constructor implicit
        void Destructor();                                                   //Destructor
        friend ostream& operator<<(ostream& os, Tranzactie tranzactie);      //Supra incarcare operator afisare
        Tranzactie& operator=(const Tranzactie& tranzactie);                 //operator de atribuire
};


#endif //LAB_2_TRANZACTIE_H
