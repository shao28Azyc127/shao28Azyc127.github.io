#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector <int> g, f, t;

int ra(int a, int b) {
    int k = a + b;
    if (k >= 10) k = ((9 + ((k % 9) - 1)) % 9);
    return k;
}

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a[6];
        for (int j = 1; j <= 5; j++) scanf("%d", &a[j]);
        for (int j = 1; j <= 5; j++) {
            for (int k = 0; k <= 9; k++) {
                if (k == a[j]) continue;
                int tmp = 0;
                for (int l = 1; l < j; l++) {
                    tmp += a[l];
                    tmp *= 10;
                }
                tmp += k;
                tmp *= 10;
                for (int l = j + 1; l <= 5; l++) {
                    tmp += a[l];
                    tmp *= 10;
                }
                g.push_back(tmp);
            }
        }
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 9; k++) {
                int tmp = 0;
                for (int l = 1; l < j; l++) {
                    tmp += a[l];
                    tmp *= 10;
                }
                tmp += ra(a[j], k);
                tmp *= 10;
                tmp += ra(a[j + 1], k);
                tmp *= 10;
                for (int l = j + 2; l <= 5; l++) {
                    tmp += a[l];
                    tmp *= 10;
                }
                g.push_back(tmp);
            }
        }
        if (i != 1) {
            for (int j = 0; j < g.size(); j++) {
                for (int k = 0; k < f.size(); k++) {
                    if (g[j] == f[k]) t.push_back(g[j]);
                }
            }
            ans = t.size();
            f.clear();
            for (int j = 0; j < t.size(); j++) {
                f.push_back(t[i]);
            }
            t.clear();
            g.clear();
        }
        else {
            for (int j = 0; j < g.size(); j++) {
                f.push_back(g[j]);
            }
            g.clear();
            ans = f.size();
        }
    }
    printf("%d", ans);
    return 0;
}
