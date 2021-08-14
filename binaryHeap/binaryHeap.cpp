#include <iostream>
#include "heap.h"
#include <queue>
using namespace std;

int main() {
    heap task;
    int n, val;
    string com;
    priority_queue<int> asd;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> com;
        if (com == "Insert") {
            cin >> val;
            task.add(val);
        }
        else cout << task.max() << '\n';
       // task.print();
    }
    return 0;
}
//каждый раз пересобираю дерево /// переделать /// убрать restor()