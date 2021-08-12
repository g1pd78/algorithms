#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main() {
    int n, size;
    pair<char, string> codes[100];
    string ans = "", bistr;

    cin >> n >> size;
    for (int i = 0; i < n; i++)
    {
        string buff;
        cin >> buff;
        codes[i].first = buff[0];
        cin >> codes[i].second;
    }
    cin >> bistr;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < n; j++) {
            bool change = true;
            for (int k = 0; k < codes[j].second.size() && codes[j].second.size() + i <= size; k++)
                if (codes[j].second[k] != bistr[i + k]) {
                    change = false;
                    break;
                }
            if (change) {
                i += codes[j].second.size() - 1;
                ans += codes[j].first;
                break;
            }
        }
    }
    cout << ans;
}