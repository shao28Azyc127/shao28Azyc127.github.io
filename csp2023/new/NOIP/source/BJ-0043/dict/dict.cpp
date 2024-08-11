#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define maxn 3005
using namespace std;
int n, m;
char s[maxn], smax[maxn], smin[maxn];
int main () {
    freopen ("dict.in", "r", stdin);
    freopen ("dict.out", "w", stdout);
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        cin >> s;
        smax[i] = 'a'-1, smin[i] = 'z'+1;
        for (int j = 0; j < m; j++)
            smax[i] = max (smax[i], s[j]), smin[i] = min (smin[i], s[j]);
    }
    for (int i = 1; i <= n; i++) {
        char minmax = 'z'+1;
        for (int j = 1; j <= n; j++)
            if (j != i) minmax = min (minmax, smax[j]);
        printf ("%d", smin[i] < minmax);
    }
    puts("");
    return 0;
}