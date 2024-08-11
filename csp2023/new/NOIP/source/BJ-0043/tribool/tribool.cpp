#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 400005
using namespace std;
int C, T;
int n, m;
struct node {
    int typ, val;
} a[maxn];
int calc (char c) {
    if (c == 'T') return 1;
    if (c == 'F') return -1;
    return 0;
}
int fa[maxn];
int getf (int x) { return (fa[x] == x) ? x : (fa[x] = getf(fa[x])); }
void merge (int x, int y) {
    int fx = getf(x), fy = getf(y);
    if (fx != fy) fa[fx] = fy;
}
int main () {
    freopen ("tribool.in", "r", stdin);
    freopen ("tribool.out", "w", stdout);
    scanf ("%d %d", &C, &T);
    while (T--) {
        scanf ("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            a[i] = (node){1, i}, fa[i] = i, fa[i+n] = i+n;
        for (int i = 1; i <= m; i++) {
            char v; int k1, k2;
            cin >> v >> k1;
            if (v == 'T' || v == 'F' || v == 'U') a[k1] = (node){0, calc(v)};
            else if (v == '+') {
                scanf ("%d", &k2);
                if (a[k2].typ == 0) a[k1] = (node){0, a[k2].val};
                else a[k1] = (node){a[k2].typ, a[k2].val};
            } else {
                scanf ("%d", &k2);
                if (a[k2].typ == 0) a[k1] = (node){0, -a[k2].val};
                else a[k1] = (node){-a[k2].typ, a[k2].val};
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i].typ == 1) merge (i, a[i].val), merge (i+n, a[i].val+n);
            if (a[i].typ == -1) merge (i, a[i].val+n), merge(i+n, a[i].val);
            if (a[i].typ == 0 && a[i].val == 0) merge (i, i+n);
        }
        for (int i = 1; i <= n; i++)
            if (getf(i) == getf(i+n)) ans++;
        printf ("%d\n", ans);
    }
    return 0;
}