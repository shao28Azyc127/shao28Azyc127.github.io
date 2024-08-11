#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#define maxn 1000005
#define mod 998244353
#define ll long long
#define eps 1e-7
using namespace std;
int n;
int cnt[maxn], a[maxn], b[5];
int nxt (int x) {
    if (x < 9) return x+1;
    return 0;
}
int calc (int A, int B, int C, int D, int E) {
    return A*10000+B*1000+C*100+D*10+E;
}
int main () {
    freopen ("lock.in", "r", stdin);
    freopen ("lock.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf ("%d", b+j);
            a[i] = a[i]*10 + b[j];
        }
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 9; k++) {
                b[j] = nxt(b[j]);
                cnt[calc(b[0], b[1], b[2], b[3], b[4])]++;
            }
            b[j] = nxt(b[j]);
        }
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 9; k++) {
                b[j] = nxt(b[j]), b[j+1] = nxt(b[j+1]);
                cnt[calc(b[0], b[1], b[2], b[3], b[4])]++;
            }
            b[j] = nxt(b[j]), b[j+1] = nxt(b[j+1]);
        }
    }
    for (int i = 1; i <= n; i++) cnt[a[i]] = 0;
    int ans = 0;
    for (int i = 0; i <= 99999; i++)
        if (cnt[i] == n) ans++;
    printf ("%d\n", ans);
    return 0;
}