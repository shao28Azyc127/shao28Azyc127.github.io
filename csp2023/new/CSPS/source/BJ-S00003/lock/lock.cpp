#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

ifstream cin("lock.in");
ofstream cout("lock.out");

unordered_map<string, int> hs;

void addd(string x) {
    for (int i = 0; i < 5; i++) {
        string tx = x;
        for (int j = 1; j <= 9; j++) {
            tx[i] = (x[i] - '0' + j) % 10 + '0';
            hs[tx]++;
            // cout << tx << endl;
        }
        // cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        string tx = x;
        for (int j = 1; j <= 9; j++) {
            tx[i] = (x[i] - '0' + j) % 10 + '0';
            tx[i + 1] = (x[i + 1] - '0' + j) % 10 + '0';
            hs[tx]++;
            // cout << tx << endl;
        }
        // cout << endl;
    }
}

int main() {
    hs.clear();
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s = "";
        int t;
        for (int i = 0; i < 5; i++) {
            cin >> t;
            s += t + '0';
        }
        addd(s);
        // cout << endl;
    }
    for (auto p : hs) {
        ans += (p.second == n);
    }
    cout << ans << endl;
    return 0;
}
