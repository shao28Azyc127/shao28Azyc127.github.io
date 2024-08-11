#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

namespace S1 {
    // task 1-3: n == 1
    void work () {
        printf ("81\n");
    }
}

namespace S2 {
    const int maxn = 1e6 + 5;

    int A, B, C, D, E, ans;
    int p[maxn];

    bool oneNot0 (int a, int b, int c, int d, int f) {
        if (a != 0 && b == 0 && c == 0 && d == 0 && f == 0) return true;
        return false;
    }

    bool twoNot0 (int a, int b, int c, int d, int f) {
        if (a != 0 && b != 0 && c == 0 && d == 0 && f == 0 && (a == b || a - b == 10 || a - b == -10)) return true;
        return false;
    }

    int to5 (int a, int b, int c, int d, int f) {
        return f + d * 10 + c * 100 + b * 1000 + a * 10000;
    }

    void work (int A, int B, int C, int D, int E) {
        for (int a = 0; a <= 9; a ++) {
            for (int b = 0; b <= 9; b ++) {
                for (int c = 0; c <= 9; c ++) {
                    for (int d = 0; d <= 9; d ++) {
                        for (int f = 0; f <= 9; f ++) {
                            int da = A - a;
                            int db = B - b;
                            int dc = C - c;
                            int dd = D - d;
                            int de = E - f;
                            if (da == 0 && db == 0 && dc == 0 && dd == 0 && de == 0) continue;
                            if (oneNot0(da, db, dc, dd, de) || oneNot0(db, da, dc, dd, de) || oneNot0(dc, da, db, dd, de) || oneNot0(dd, da, db, dc, de) || oneNot0(de, da, db, dc, dd)) {
                                p[to5(a, b, c, d, f)]++;
                            } else if (twoNot0(da, db, dc, dd, de) || twoNot0(db, dc, da, dd, de) || twoNot0(dc, dd, da, db, de) || twoNot0(dd, de, da, db, dc)) {
                                p[to5(a, b, c, d, f)]++;
                            }
                        }
                    }
                }
            }
        }
    }

    int getans (int n) {
        int ans = 0;
        for (int i = 1; i < 1e6; i ++) {
            if (p[i] == n) {
                ans ++;
            }
        }
        return ans;
    }
}

int n, a[15], b[15], c[15], d[15], f[15];

int main () {
    freopen ("lock.in", "r", stdin);
    freopen ("lock.out", "w", stdout);
    
    scanf ("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf ("%d%d%d%d%d", &a[i], &b[i], &c[i], &d[i], &f[i]);
    }
    if (n == 1) {
        S1::work();
        return 0;
    } else {
        for (int i = 1; i <= n; i ++) {
            S2::work (a[i], b[i], c[i], d[i], f[i]);
        }
        printf ("%d\n", S2::getans(n));
        return 0;
    }
    return 0;
}