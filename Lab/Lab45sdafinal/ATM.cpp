
#include "ATM.h"
#include "Collection.h"
#include<iostream>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;


// Funcie ce afiseaza tranzactiile

void ATM::afisare_colectie(Element bancnote[], int lungime, int k)
{
    std::cout << k << ": ";
    k++;
    for (int i = 0; i < lungime; i++)
        std::cout << bancnote[i].valoare << "*" << bancnote[i].nr_aparitii << ' ';
    std::cout << endl;
}

// Constructor ATM ce include filename, elementele colectiei, tranzactiile si nr de tranzactii

ATM::ATM(string fileBancnote, const Collection& colectie, Tranzactie tranzactie[], int nr_tranzactii)
{
    this->colectie_bancnote = colectie;
    this->tranzactii = new Tranzactie[nr_tranzactii];
    this->nr_tranzactii = nr_tranzactii;
    for (int i = 0; i < nr_tranzactii; i++)
        this->tranzactii[i] = tranzactie[i];
    filename = fileBancnote;
    ifstream fB(fileBancnote);
    while (!fB.eof()) {
        int bancnota, nr;
        fB >> bancnota >> nr;
        while (nr) {
            colectie_bancnote.add(bancnota);
            nr--;
        }
    }
    fB.close();
}


// nefolosit
//Functie pentru adaugarea unei bancnote in atm
void ATM::Add_bancnote(TElem valoare) {
    this->colectie_bancnote.add(valoare);
    ofstream fout(filename);
    for (int i = 0; i < colectie_bancnote.get_lungime(); i++)
        fout << colectie_bancnote.get_val(i) << ' ' << colectie_bancnote.getAt(i) << endl;
    fout.close();
}

//nefolosit
void ATM::Elim_bancnota(TElem valoare) {
    //this->colectie_bancnote.remove(valoare);
    this->colectie_bancnote.remove(valoare);
    ofstream fout(filename);
    for (int i = 0; i < colectie_bancnote.get_lungime(); i++)
        fout << colectie_bancnote.get_val(i) << ' ' << colectie_bancnote.getAt(i) << endl;
    fout.close();

}



/*
 * functie care efectueaza o tranzactie
 * unde se depoziteaza bani in ATM
 *
 */
void ATM::tranzactie_retragere(char pozi2[], int suma) {

    int array1[100];
    int nr = 0;

    char* nextToken = nullptr;
    char* token = strtok_s(pozi2, " ", &nextToken);
    while (token != NULL) {
        array1[nr++] = atoi(token);
        token = strtok_s(NULL, " ", &nextToken);
    }
    for (int i = 0; i < nr; i++)
    {

        this->colectie_bancnote.add(array1[i]);
    }
    std::cout << "Tranzactie efectuata.";
    std::cout << endl;
    std::cout << endl;

    idu++;
    string output_line = "S-a efectuat tranzactia cu id-ul " + to_string(idu) + " unde a fost depozitata o suma de " + to_string(suma) + " lei, s-au folosit bancnotele: ";
    for (int l = 0; l < nr; l++)
        output_line += to_string(array1[l]) + " ";
    output.push_back(output_line);


}

 
void ATM::tranzactie_retragere2(char pozi2[], int suma)
{
    int array1[100];
    int nr = 0;

    char* nextToken = nullptr;
    char* token = strtok_s(pozi2, " ", &nextToken);
    while (token != NULL) {
        array1[nr++] = atoi(token);
        token = strtok_s(NULL, " ", &nextToken);
        for (int i = 0; i < nr; i++)
        {
            this->colectie_bancnote.removeapp(array1[i]);
        }
        cout << "Tranzactie efectuata.";
        cout << endl;
        cout << endl;
        string output_line = "S-a efectuat tranzactia cu id-ul " + to_string(idu) + " unde a fost scoasa o suma de " + to_string(suma) + " lei, s-au folosit bancnotele: ";
        for (int l = 0; l < nr; l++)
            output_line += to_string(array1[l]) + " ";
        output.push_back(output_line);
        idu++;
    }
}


 

ostream& operator<<(ostream& os, ATM atm) {
    cout << "Bancnotele disponibile din ATM:" << endl;
    for (int i = 0; i < atm.colectie_bancnote.get_lungime(); i++)
        cout << "Valoarea bancnotei: " << atm.colectie_bancnote.get_val(i) << ", numarul de bancnote: " << atm.colectie_bancnote.getAt(i) << endl;
    cout << endl << "Tranzactiile efectuate de retragere bani: " << endl;
    for (int i = 0; i < atm.nr_tranzactii; i++) {
        cout << atm.tranzactii[i];
        cout << endl;
    }
    return os;
}


void ATM::addstring() {
    for (const auto& str : output) {
        std::cout << str << std::endl;
    }
}

/*
 *
 * Când funcția este apelată pentru prima dată, alegere este setat la numărul maxim de bancnote care
 * pot fi utilizate (int_poz în programul principal), suma este suma care trebuie plătită, bancnote este
 * o serie de structuri de elemente unde vor stocațe bancnotele utilizate în combinația curentă,
 * lungimea este lungimea container ului de bancnote și poz este indexul primei bancnote care poate fi utilizată.

  dacă suma este zero, a fost găsită o combinație de bancnote.
 Decrementează alegere pentru a semnala că a fost găsită o combinație validă și setează
 valoarea ultimului element din tabloul bancnote la -1.

Dacă suma nu este zero, funcția trece prin colecția de bancnote, pornind de la indexul poz.
 Pentru fiecare bancnotă, o scade din suma de câte ori este posibil și stochează numărul de ori în k.
 De asemenea, stochează valoarea bancnotei și de câte ori a fost utilizată în container ului de bancnote

  funcția se autoinvocă recursiv, trecând la noua valoare a sumei, matricea de bancnote actualizată și
 indexul următoarei bancnote din colecție (i+1). Dacă alegere devine zero în timpul apelului recursiv, funcția iese din buclă.

Dacă apelul recursiv revine și suma este mai mică decât zero, înseamnă că ultima bancnotă folosită a
 fost prea mult, astfel încât funcția ajustează k și matricea bancnote în consecință.

În cele din urmă, funcția adaugă înapoi valoarea bancnotelor folosite la suma și continuă cu
 următoarea bancnotă din buclă.

În cazul introducerii 1*2 5*2, funcția va începe cu suma egală cu 12 (suma totală de plătit)
 și va parcurge colecția de bancnote, începând cu primul indice (poz=0). Va încerca să folosească
 cât mai multe bancnote de 1, apoi se va trece la următoarea bancnotă (i=1) și va încerca să folosească
 cât mai multe 5 bancnote. Dacă se găsește o combinație de bancnote, funcția va reveni și va imprima rezultatul.
 Dacă nu se găsește nicio combinație de bancnote, funcția va reveni și programul va
 solicita utilizatorului să aleagă o altă opțiune.
 */



void ATM::prelucrare_tranzactia(int& poz_stop, int suma, Element bancnote[], int lungime, int poz)
{
    if (suma == 0)
    {
        poz_stop--;
        bancnote[lungime].valoare = -1;
    }
    else {
        for (int i = poz; i < this->colectie_bancnote.get_lungime() && poz_stop; i++) {
            if (poz_stop == 0) break;
            int k = 0;
            TElem bancnota = this->colectie_bancnote.get_val(i);
            while (suma >= 0) {
                suma = suma - bancnota;
                k++;
                bancnote[lungime].valoare = bancnota;
                bancnote[lungime].nr_aparitii = k;
                prelucrare_tranzactia(poz_stop, suma, bancnote, lungime + 1, i + 1);
                if (poz_stop == 0) break;
            }
            if (suma < 0) {
                suma = suma + bancnota;
                k--;
                bancnote[lungime].nr_aparitii = k;
            }
            suma = suma + k * bancnota;
        }
    }
}

void ATM::combinatie_suma(int& indice, int suma, Element bancnote[], int lungime, int poz)
{
    if (suma == 0)
        afisare_colectie(bancnote, lungime, indice);
    else {
        for (int i = poz; i < this->colectie_bancnote.get_lungime(); i++) {
            int k = 0;
            TElem bancnota = this->colectie_bancnote.get_val(i);
            while (suma >= 0) {
                suma = suma - bancnota;
                k++;
                bancnote[lungime].valoare = bancnota;
                bancnote[lungime].nr_aparitii = k;
                if (suma == 0) indice++;
                combinatie_suma(indice, suma, bancnote, lungime + 1, i + 1);
            }
            if (suma < 0) {
                suma = suma + bancnota;
                k--;
                bancnote[lungime].nr_aparitii = k;
            }
            suma = suma + k * bancnota;
        }
    }
}

void ATM::scoatere_numerar(int id, int suma, int lungime, Element bancnote[])
{
    int ok = 1;
    for (int i = 0; i < lungime; i++)
        if (bancnote[i].nr_aparitii > this->colectie_bancnote.nroccurrences(bancnote[i].valoare)) { // verificam suma totala
            ok = 0;
        }
    if (!ok)
        cout << "ATM-ul nu contine bancnotele necesare acestei tranzactii!!" << endl; // daca se doreste sa se scoata
    else                                                                      // suma mai mare decat toti banii din ATM
    {
        cout << "Tranzactie efectuata cu succes!" << endl;
        for (int i = 0; i < lungime; i++) {
            Element el;
            el.valoare = bancnote[i].valoare;   //stergerea aparitiilor bancnotelor care au fost scoase din ATM
            el.nr_aparitii = this->colectie_bancnote.nroccurrences(el.valoare) - bancnote[i].nr_aparitii;
            this->colectie_bancnote.set_numar_bancnote(el);
        }
        this->tranzactii[this->nr_tranzactii] = Tranzactie(id, suma, bancnote, lungime);
        this->nr_tranzactii++;


        ofstream fout1(filename);
        for (int i = 0; i < colectie_bancnote.get_lungime(); i++)
            fout1 << colectie_bancnote.get_val(i) << ' ' << colectie_bancnote.getAt(i) << endl;


        fout1.close();
        ofstream fout("Tranzactii.txt");                      // trimitem in fisierul tranzactii.txt tranzactiile care au fost efectuate
        for (int i = 0; i < nr_tranzactii; i++) {
            fout << tranzactii[i].ToString() << endl;
        }
        fout.close();
    }
}
