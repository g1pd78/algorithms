#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

template <class Int>
Int gcd(Int a, Int b) {
    assert(a >= 0 && b >= 0);
    return b ? gcd(b, a % b) : a;
}



int main(void) {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}