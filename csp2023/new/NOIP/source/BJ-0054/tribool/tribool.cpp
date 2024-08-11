#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define nrep(i, a, b) for(int i = (a); i >= (b); --i)
#define endl() putchar('\n')
using namespace std;

typedef long long ll;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = (x << 1) +(x << 3) + (ch ^ 48), ch = getchar();
    return x * f;
}


const int N = 4e5 + 10;
int n, m;

struct node {
    int i, oppo;
    inline int id() {
        return oppo * (n + 4) + i;
    }
} a[N];

int fa[N << 1];

int find(int x) {
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y) {
    fa[find(x)] = find(y);
}

inline int id(int x, int k) {
    return k * (n + 4) + x;
}

void solve() {
    memset(a, 0, sizeof a);
    memset(fa, 0, sizeof fa);
    n = read(), m = read();
//    print(n, m);
    rep(i, 1, (n + 4) * 2) fa[i] = i;
    rep(i, 1, n + 3) a[i] = {i, 0};
    rep(i, 1, m) {
        char op; scanf(" %c", &op);
        int x = read(), y;
        if(op == 'T') a[x] = {n + 1, 0};
        if(op == 'F') a[x] = {n + 2, 0};
        if(op == 'U') a[x] = {n + 3, 0};
        if(op == '+') y = read(), a[x] = a[y];
        if(op == '-') y = read(), a[x] = {a[y].i, a[y].oppo ^ 1};
    }
//    rep(i, 1, n) print(a[i].i, a[i].oppo);
    rep(i, 1, n) merge(id(a[i].i, a[i].oppo), id(i, 0));
    rep(i, 1, n) merge(id(a[i].i, a[i].oppo ^ 1), id(i, 1));
    merge(id(n + 1, 0), id(n + 2, 1));
    merge(id(n + 2, 0), id(n + 1, 1));
    merge(id(n + 3, 0), id(n + 3, 1));
    int cnt = 0;
    rep(i, 1, n) {
        if(find(id(i, 0)) == find(id(i, 1))) cnt ++;
    }
    printf("%d\n", cnt);
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    int Case = read(), T = read();
    while(T--) solve();
    return 0;
}



















