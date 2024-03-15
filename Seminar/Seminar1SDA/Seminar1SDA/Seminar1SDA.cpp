// Seminar1SDA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>
using namespace std;
typedef int TElem;

// exemple

/*
v1 = [3, 6, 2, 10, 9]
v2 = [9, 2, 6, 8, 5, 1]
v3 = [10, 2, 4]
*/
int main()
{
    TElem v[10] = { 3, 6, 2, 10, 9 };
    QuickSort(v, 0, 5);
    for (int i = 1; i <= 5; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    TElem v2[10] = { 9, 2, 6, 8, 5, 1 };
    QuickSort(v2, 0, 6);
    for (int i = 1; i <= 6; i++)
    {
        cout << v2[i] << " ";
    }
    cout << endl;
    TElem v3[10] = { 10, 2, 4 };
    QuickSort(v3, 0, 3);
    for (int i = 1; i <= 3; i++)
    {
        cout << v3[i] << " ";
    }

}













void test2()
{
    int v[3] = { 12,13,14 };
    int p;
    p = find_elem(14, v, 3);
    assert(p == 2);
}
void test3()
{
    int v[4] = { 2,3,5,8 };
    int p;
    p = find_elem(5, v, 4);
    assert(p == 2);
}
void test4()
{
    int v[4] = { 2,3,5,6 };
    int p;
    p = find_elem(4, v, 4);
    assert(p == -1);
}
void test5()
{
    int v[1] = { 10 };
    int p;
    p = find_elem(10, v, 1);
    assert(p == 0);
}
void test6()
{
    int v[2] = { 5 };
    int p;
    p = find_elem(7, v, 2);
    assert(p == -1);
}
void testall()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
}
int main()
{

    int v[20], n;
    testall();
    return 0;
}
