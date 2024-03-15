// Lab45sdafinal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Interfata.h"
#include "List.h"
#include "TestList.h"

using namespace std;
 
int main() {
    TestList t;
    t.test_push_back();
    t.test_get_at();
    t.test_update();
    t.test_search();
    t.test_getat();
    t.teste_push_front();
    t.test_get_first_last();
    t.test_deleteat();
    std::cout << "Testele au trecut!" << std::endl;
    
    
    
    Menu();
    return 0;
}
