#include "Interfata.h"
#include "ATM.h"
#include "Collection.h"
#include<iostream>
#include<vector>
#include <functional>
#include <cstring>
#include<fstream>
using namespace std;

int id = 1;


void print_menu() {
    cout << endl;
    cout << "Meniu" << endl;
    cout << "1. Afisare fonduri din ATM" << endl;
    cout << "2. Efectuare tranzactie (depozitare)" << endl;
    cout << "3. Efectuare tranzactie (scoatere bani)" << endl;
    //    cout<<"4. Adaugare bancnota in ATM"<<endl;
    //    cout<<"5. Stergere bancnota definitiv din ATM"<<endl;
    cout << "4. Afisare tranzactii de depozitare bani" << endl;
    cout << "0. Exit" << endl;
    cout << endl << "Introduceti o comanda: ";
}

/*
 * Functie care introduce automat bani in ATM
 */
void adauga_bancnote(ATM& atm) {
    int i;

    for (i = 1; i <= 30; i++) {
        atm.Add_bancnote(1);
        atm.Add_bancnote(5);
        atm.Add_bancnote(10);
        atm.Add_bancnote(20);


    }
    for (i = 1; i <= 10; i++) {
        atm.Add_bancnote(50);
        atm.Add_bancnote(100);
        atm.Add_bancnote(200);

    }
}


/*
 * Functie ce adauga o bancnota in ATM
 *
 */
void add_bancnote(ATM& atm) {
    TElem element;
    cout << "Introduceti valoarea bancnotei: ";
    cin >> element;
    cout << "Introduceti numarul de aparitii: ";
    int nr_aparitii;
    cin >> nr_aparitii;
    int i = 1;
    while (i <= nr_aparitii) {
        atm.Add_bancnote(element);
        i++;
    }
}

/*
 * Functie ce elimina o bancnota in ATM
 */
void elim_bancnota(ATM& atm) {
    cout << "Introduceti bancnota pe care doriti sa o eliminati: ";
    TElem element;
    cin >> element;
    atm.Elim_bancnota(element);
}
/*
 * Functie ce adauga tranzactie in ATM, unde se depoziteaza bani
 *
 se exploreaza toate combinațiile posibile de bancnote până când suma de bani rămasă de scris este zero.
 se selecteaza cea mai mare bancnotă disponibilă și se adaugă
 la soluție dacă suma rămasă este mai mare sau egală cu valoarea acesteia. Apoi se apelează recursiv cu suma
 rămasă diminuată cu valoarea bancnotei selectate și indicele curent
 după apelul recursiv, bancnota selectată este eliminată din soluție și algoritmul trece la următoarea bancnotă disponibilă.

 este folosit un vector pentru a ține evidența
 numărului fiecărei bancnote din combinația curentă și scoate toate combinațiile
 posibile de bancnote care însumează suma dată.
 */
void adaugare_tranzactie(int suma, ATM& atm) {
    char pozi2[100];
    Element* bancnote = new Element[100];
    cout << endl << "Introduceti suma: ";
    cin >> suma;
    vector<int> banknotes = { 100, 50, 10, 5, 1 };
    vector<int> counts(banknotes.size(), 0);

    std::function<void(int, int)> backtrack = [&](int remaining, int index) {
        if (remaining == 0) {

            cout << "Combinatii de a scrie suma: ";
            for (int i = 0; i < banknotes.size(); i++) {
                for (int j = 0; j < counts[i]; j++) {
                    cout << banknotes[i] << " ";
                }
            }
            cout << "\n";
        }
        if (index >= banknotes.size()) {
            return;
        }
        for (int i = index; i < banknotes.size(); i++) {
            if (remaining >= banknotes[i]) {
                counts[i]++;
                backtrack(remaining - banknotes[i], i);
                counts[i]--;
            }
        }
    };
    backtrack(suma, 0);

    cout << "Metode de alegere a platii: " << endl;
    cout << "0 - anulare / Introduceti combinatia: ";
 
    cin.get();
    cin.getline(pozi2, 100);

    if (strcmp(pozi2, "0") == 0)
        cout << "Tranzactie respinsa!";
    else
    {
        atm.tranzactie_retragere(pozi2, suma);
    }
}


/*
 * Functie ce adauga tranzactie in ATM, unde se scot bani
 *
 */
void adaugare2_tranzactie(int suma, ATM& atm) {
    int suma1, lungime = 0, poz = 0, indice = 0, alegere = 0;
    char pozi2[100];
    Element* bancnote = new Element[100];
    cout << endl << "Introduceti suma: ";
    cin >> suma;
    cout << "Modalitatile de a plati: " << endl;
    atm.combinatie_suma(indice, suma, bancnote, lungime, poz);

    cout << "0 - anulare / Introduceti optiunea dorita: ";
    cin >> alegere;
    indice = 0;
    if (alegere == 0) {
        cout << "Tranzactie respinsa!";
    }
    else {
        atm.prelucrare_tranzactia(alegere, suma, bancnote, lungime, poz);

        while (bancnote[lungime].valoare != -1) 
            lungime++;
        atm.scoatere_numerar(id, suma, lungime, bancnote);
        id++;
    }
    delete[] bancnote;
}
 

void Menu() {
    int opt = 1;
    Collection colectie;

    int nr_tranzactii = 0;
    int suma = 0;
    Tranzactie* tranzactie = new Tranzactie[100];

    ATM atm("Bancnote.txt", colectie, tranzactie, nr_tranzactii);

    while (opt) {

        print_menu();
        cin >> opt;
        switch (opt) {
        case 1:
            cout << atm;
            break;
        case 2:
            adaugare_tranzactie(suma,atm);
            break;
        case 3:
            adaugare2_tranzactie(suma,atm);
            break;
        /*case 4:
            add_bancnote(atm);
            break;
         case 5:
            elim_bancnota(atm);
            break;*/
        case 4:
            atm.addstring();
            break;
        default:
            break;
        }
    }
    colectie.Destructor();

}
