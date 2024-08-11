#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3005;
int n, m;
int str[MAXN][MAXN], tong[MAXN][35];
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            str[i][j] = (int)c;
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(str[i] + 1, str[i] + 1 + m);
        for (int j = 1; j <= m; j++) {
            tong[j][str[i][m - j + 1] - 96]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tong[j][str[i][m - j + 1] - 96]--;
        }
        bool f = true;
        for (int j = 1; j <= m; j++) {
            int t = str[i][j] - 96;
            for (int k = 1; k < t; k++) {
                if (tong[j][k] >= 1) {
                    f = false;
                    break;
                }
            }
            if (!f) break;
            if (tong[j][t] >= 1) continue;
            else break;
        }
        if (f) cout << 1;
        else cout << 0;
        for (int j = 1; j <= m; j++) {
            tong[j][str[i][m - j + 1] - 96]++;
        }
    }
    return 0;
}
