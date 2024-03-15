// Sem2sda.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Teste.h"
#include "Collection.h"
#include "Iterator.h"
using namespace std;

int main()
{
    testAll();
    Collection c;
    cout << c.search(2);
    //    c.add(2);
    //    c.add(2);
    //    c.add(2);
    //    c.add(2);
    //    c.add(2);
    //    c.add(4);
    //    c.add(4);
    //    c.add(4);
    //    c.add(4);

    cout << "-----------" << endl;
    Iterator it(c);

    while (it.valid())
    {
        cout << it.current() << " " << it.getCurrentOccurrences() << endl;
        it.next();
    }
    return 0;
}
