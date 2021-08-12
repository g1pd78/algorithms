#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
    heap test;
    int arr[] = { 1, 2, 3, 4, 3, 1, 2};
    test.buildHeap(arr, 4);
    cout << test.max() << '\n';
    test.add(13);
    cout << test.max() << '\n';
    cout << "OK";
}
