#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 3005;

int n, m;
string w[maxn];

bool cmp (char x, char y) {
    return int(x) < int(y);
}

// int work (int i) {
//     for (int j = 0; j < m; j ++) {
//         for (int k = 1; k <= n; k ++) {
//             if (i == k) continue;
//             if (cmp(w[k][m - j - 1], w[i][j])) {
//                 return 0;
//             } else if (cmp(w[i][j], w[k][m - j - 1])) {
//                 cout << w[i][j] << '@' << w[k][m-j-1] << endl;
//                 return 1;
//             }
//         }
//     }
//     return 1;
// }

int work (int i) {
    for (int k = 1; k <= n; k ++) {
        if (i == k) continue;
        bool f = false;
        for (int j = 0; j < m; j ++) {
            if (cmp(w[k][m - j - 1], w[i][j])) {
                f = false;
                break;
            } else if (cmp(w[i][j], w[k][m - j - 1])) {
                // cout << w[i][j] << '@' << w[k][m-j-1] << endl;
                f = true;
                break;
            }
        }
        if (!f) return 0;
    }
    return 1;
}

int main () {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> w[i];
        sort(w[i].begin(), w[i].end(), cmp);
    }
    for (int i = 1; i <= n; i ++) {
        if (work(i)) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << endl;

    return 0;
}