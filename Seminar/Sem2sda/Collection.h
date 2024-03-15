#pragma once


typedef int TElem;

class Collection {
private:
    TElem* elements;
    int* occurrences;
    int distinctelements;
    int capacity;
    void resize();
public:
    Collection(); //init
    ~Collection();
    void add(TElem elem);
    bool remove(TElem elem);
    bool search(TElem elem);
    int size();
    int nroccurrences(TElem elem);
    int getAt(int position);
};
