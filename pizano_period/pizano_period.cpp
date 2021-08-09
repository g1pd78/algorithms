#include <iostream>
#include <vector>

using namespace std;

class Fibonacci final {
public:
    static int get_remainder(int64_t n, int m) {
        /*  assert(n >= 1);
          assert(m >= 2);*/


        vector<int> pizano;

        pizano.push_back(0);
        pizano.push_back(1);

        for (int k = 2; k < 6 * m/*Ограничение последовательности Пизано*/; k++)
        {
            pizano.push_back((pizano[k - 1] + pizano[k - 2]) % m);
            if (pizano[k] == 1 && pizano[k - 1] == 0)
            {
                pizano.pop_back();
                pizano.pop_back();
                break;
            }
        }
        return pizano[n % pizano.size()];
    }
};

int main() {

    int64_t n;
    int m;

    cin >> n >> m;
    cout << Fibonacci::get_remainder(n, m) << endl;
}