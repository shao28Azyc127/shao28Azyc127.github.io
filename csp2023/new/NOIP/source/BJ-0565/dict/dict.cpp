#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define print1(x) cout << x << endl;
#define print2(x, y) cout << x << ' ' << y << endl;
#define print3(x, y, z) cout << x << ' ' << y << ' ' << z << endl;
using namespace std;

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<string> dict(n);
    for (int i = 0; i < n; i++) cin >> dict[i];

    vector<string> dictMin(dict);
    vector<string> dictMax(dict);
    for (int i = 0; i < n; i++) {
        sort(dictMin[i].begin(), dictMin[i].end());
        sort(dictMax[i].begin(), dictMax[i].end(), [](char a, char b){return a > b;});
    }
    // for (string s: dictMin) print1(s)
    // for (string s: dictMax) print1(s)
    for (int i = 0; i < n; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < m; k++) {
                if (dictMin[i][k] < dictMax[j][k]) goto loopEnd;
            }
            ok = false;
            loopEnd:;
        }
        if (ok) cout << 1;
        else cout << 0;
    }

    return 0;
}
