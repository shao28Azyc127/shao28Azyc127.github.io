#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int C, T, n, m, x[N];

int idx(char c) {
    if(c == 'T') return 2e5 + 1;
    else if(c == 'F') return 2e5 + 2;
    else if(c == 'U') return 2e5 + 3;
}

int oppo(int u) {
    if(u > 2e5) {
        if(u == 2e5 + 3) return u;
        else if(u == 2e5 + 2) return 2e5 + 1;
        else return 2e5 + 2;
    }
    else if(u <= n) return u + n;
    else return u - n;
}

struct UFS {
    int fa[N], sz[N];
    void init() {
        for(int i = 1; i <= 2 * n; i++) fa[i] = i, sz[i] = 1;
        for(int i = 2e5 + 1; i <= 2e5 + 3; i++) fa[i] = i, sz[i] = 1;
    }
    int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x, y);
        fa[x] = y, sz[y] += sz[x];
    }
} ufs;

void MAIN() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) x[i] = i;
    ufs.init();
    while(m--) {
        char typ; cin >> typ;
        int i, j;
        if(typ == 'T' || typ == 'U' || typ == 'F') {
            cin >> i;
            x[i] = idx(typ);
        }
        else {
            cin >> i >> j;
            if(typ == '+') x[i] = x[j];
            else x[i] = -x[j];
        }
    }
    for(int i = 1; i <= n; i++) if(x[i] < 0) {
        if(x[i] == -(2e5 + 1)) x[i] = 2e5 + 2;
        else if(x[i] == -(2e5 + 2)) x[i] = 2e5 + 1;
        else if(x[i] == -(2e5 + 3)) x[i] = 2e5 + 3;
        else x[i] = n - x[i];
    }
    for(int i = 1; i <= n; i++) {
        ufs.merge(i, x[i]), ufs.merge(oppo(i), oppo(x[i]));
        if(ufs.find(i) == ufs.find(oppo(i)) || ufs.find(x[i]) == ufs.find(oppo(x[i]))) ufs.merge(i, 2e5 + 3);
    }
    cout << (ufs.sz[ufs.find(2e5 + 3)] - 1) / 2 << '\n';
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios :: sync_with_stdio(0), cin.tie(0);
    cin >> C >> T;
    while(T--) MAIN();
    return 0;
}