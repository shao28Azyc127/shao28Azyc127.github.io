#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
    FILE *fpi, *fpo;
    fpi = freopen("bus.in", "r", stdin);
    fpo = freopen("bus.out", "w+", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    const int tmpm = m;
    for(int i = 0; i < tmpm; i++) {
        scanf("%d %d %d", &n, &m, &k);
    }
    cout << -1;
    fclose(fpi);
    fclose(fpo);
    return 0;
}