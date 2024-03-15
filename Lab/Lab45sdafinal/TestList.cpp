//
// Created by camel on 4/10/2023.
//

#include "TestList.h"
#include "List.h"
#include <cassert>

void TestList::test_push_back()
{
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert(newList.size() == 4);
}

void TestList::test_get_at() {
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert(newList.get_at(0) == 1);
    assert(newList.get_at(1) == 2);
    assert(newList.get_at(2) == 3);
    assert(newList.get_at(3) == 4);
}

void TestList::test_update() {
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    newList.update(2, 17);
    assert(newList.get_at(0) == 1);
    assert(newList.get_at(1) == 2);
    assert(newList.get_at(2) == 17); // cel de pe pozitia 2 s a modificat in 17
    assert(newList.get_at(3) == 4);
}

void TestList::test_search()
{
    List<int> newList;
    assert(newList.search(1) == -1);
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert(newList.search(0) == -1);
    assert(newList.search(1) == 0);
    assert(newList.search(2) == 1);
    assert(newList.search(3) == 2);
    assert(newList.search(4) == 3);
}

void TestList::test_getat()
{
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    newList.set_at(2, 30);
    assert(newList.get_at(2) == 30);
}

void TestList::test_deleteat()
{
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert(newList.delete_at(0) == 1);
    assert(newList.size() == 3);
    assert(newList.delete_at(2) == 4);
    assert(newList.size() == 2);

    List<int> newList2;
    newList2.push_back(1);
    newList2.push_back(2);
    newList2.push_back(3);
    newList2.push_back(4);
    assert(newList2.delete_at(2) == 3);
    assert(newList2.size() == 3);
}

void TestList::teste_push_front() {
    List<int> newList;
    newList.push_front(1);
    newList.push_front(2);
    newList.push_front(3);
    newList.push_front(4);
    assert(newList.size() == 4);
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(4);
    assert(newList.size() == 8);

}

void TestList::test_get_first_last() {
    List<int> newList;
    newList.push_back(1);
    newList.push_back(2);
    newList.push_back(3);
    newList.push_back(7);

    Node<int>* node;
    node = newList.getFirst();
    assert(node->getInfo() == 1); // primul element este 1
    node = newList.getLast();
    assert(node->getInfo() == 7); // ultimul element este 7
    newList.push_front(1);
    newList.push_front(2);
    newList.push_front(3);
    newList.push_front(4);
    node = newList.getFirst();
    assert(node->getInfo() == 4);


    List<int> newList2;
    newList2.push_front(1);
    newList2.push_front(2);
    newList2.push_front(3);
    newList2.push_front(4);
    node = newList2.getFirst();
    assert(node->getInfo() == 4);
    node = newList2.getLast();
    assert(node->getInfo() == 1);
}
