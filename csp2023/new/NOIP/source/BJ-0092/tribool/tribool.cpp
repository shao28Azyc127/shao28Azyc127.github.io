#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1e5 + 5;

char ans[MAXN];
int n, m;
struct Node {char ch; int id; bool tag;} a[MAXN];
struct DSU {
    int fa[MAXN << 1];
    void init() {for (int i = 1; i <= n + n; i++) fa[i] = i;}
    int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
    void merge(int x, int y) {
        x = find(x), y = find(y);
        fa[x] = y;
    }
}dsu;
char flip(char ch) {
    if (ch == 'T') return 'F';
    if (ch == 'F') return 'T';
    return 'U';
}

void work() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = {0, i, 1}, ans[i] = 0;
    while (m--) {
        char op; int x, y; cin >> op >> x;
        if (op == 'T') a[x].ch = 'T';
        if (op == 'F') a[x].ch = 'F';
        if (op == 'U') a[x].ch = 'U';
        if (op == '+') cin >> y, a[x] = a[y];
        if (op == '-') {
            cin >> y, a[x] = a[y];
            if (a[y].ch) a[x].ch = flip(a[x].ch);
            else a[x].tag ^= 1;
        }
    }
    dsu.init();
    for (int i = 1; i <= n; i++) {
        if (a[i].ch) ans[i] = a[i].ch;
        else {
            int j = a[i].id; bool tag = a[i].tag;
            if (!tag) dsu.merge(i, j + n), dsu.merge(i + n, j);
            else dsu.merge(i, j), dsu.merge(i + n, j + n);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i]) continue;
        if (dsu.find(i) == dsu.find(i + n)) {
            int j = dsu.fa[i]; ans[i] = 'U';
            if (j > n) j -= n;
            ans[j] = 'U';
        }
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i]) {
            if (ans[i] == 'U') tot++;
            continue;
        }
        int j = dsu.find(i);
        if (j > n) j -= n;
        if (ans[j] == 'U') {tot++; continue;}
        j = dsu.find(i + n);
        if (j > n) j -= n;
        if (ans[j] == 'U') tot++;
    }
    cout << tot << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int cid, t; cin >> cid >> t;
    while (t--) work();
    return 0;
}