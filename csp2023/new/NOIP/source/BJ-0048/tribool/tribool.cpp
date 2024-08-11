#include<bits/stdc++.h>
using namespace std;

const int NR = 2e5;

int sid, T, n, m, ans2;
int ans[NR + 5], fa[NR + 5], sz[NR + 5];
bool f[NR + 5];

int find(int u) {
    return fa[u] == u ? u : fa[u] = find(fa[u]);
}

inline int rev(int x) {
    if(x <= n) {
        return x + n;
    }
    else if(x <= n * 2) {
        return x - n;
    }
    else if(x == n * 2 + 1) {
        return n * 2 + 2;
    }
    else if(x == n * 2 + 2) {
        return n * 2 + 1;
    }
    else {
        return x;
    }
}

void work() {
    cin >> n >> m;
    ans2 = 0;
    for(int i = 1; i <= n * 2 + 3; i++) {
        ans[i] = i;
        fa[i] = i;
        f[i] = 0;
        sz[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        sz[i] = 1;
    }
    for(int i = 1; i <= m; i++) {
        char op;
        int x, y;
        cin >> op >> x;
        if(op == 'T') {
            ans[x] = 2 * n + 1;
        }
        else if(op == 'F') {
            ans[x] = 2 * n + 2;
        }
        else if(op == 'U') {
            ans[x] = 2 * n + 3;
        }
        else if(op == '+') {
            cin >> y;
            ans[x] = ans[y];
        }
        else {
            cin >> y;
            ans[x] = rev(ans[y]);
        }
    }
    for(int i = 1; i <= n; i++) {
        int u = find(i), v = find(ans[i]);
        if(u != v) {
            fa[v] = u;
            sz[u] += sz[v];
        }
        u = find(rev(i)), v = find(rev(ans[i]));
        if(u != v) {
            fa[v] = u;
            sz[u] += sz[v];
        }
    }
    for(int i = 1; i <= n; i++) {
        int u = find(i), v = find(i + n);
        if(u == v) {
            f[u] = 1;
        }
    }
    f[find(n * 2 + 3)] = 1;
    for(int i = 1; i <= n * 2 + 3; i++) {
        if(f[i]) {
            ans2 += sz[i];
        }
    }
    cout << ans2 << '\n';
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> sid >> T;
    while(T--) work();

    return 0;
}