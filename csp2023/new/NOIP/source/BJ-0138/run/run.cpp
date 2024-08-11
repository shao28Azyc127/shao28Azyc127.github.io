#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void read(T &x){
    x = 0; bool F = 0; char c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
    for (;isdigit(c);c = getchar()) x = x*10+(c^48);
    if (F) x = -x;
}

const int M = 5e6, N = 1e5+100;
int ls[M], rs[M]; ll lazy[M], Max[M];
vector<PII> ask[N];
int n, m, k, d, c, t;
int cnt;

inline void upd(int p){Max[p] = max(Max[ls[p]], Max[rs[p]]);}

inline void pushdown(int p){
    if (lazy[p]){
        if (!ls[p]) ls[p] = ++cnt; if (!rs[p]) rs[p] = ++cnt;
        lazy[ls[p]] += lazy[p], lazy[rs[p]] += lazy[p];
        Max[ls[p]] += lazy[p], Max[rs[p]] += lazy[p];
        lazy[p] = 0;
    }
}

void Clear(int p){
    if (ls[p]) Clear(ls[p]);
    if (rs[p]) Clear(rs[p]);
    ls[p] = rs[p] = lazy[p] = Max[p] = 0;
}

void modify(int &p, int l, int r, int ql, int qr, ll val){
    if (!p) p = ++cnt; if (ql<=l && r<=qr){lazy[p] += val; Max[p] += val; return;}
    int mid = l+r>>1; pushdown(p);
    if (ql<=mid) modify(ls[p], l, mid, ql, qr, val);
    if (mid<qr) modify(rs[p], mid+1, r, ql, qr, val);
    upd(p);
}

inline void solve(){
    read(n), read(m), read(k), read(d);
    int l, r, v, root = 0;
    if (c == 17 || c == 18){
        ll ans = 0;
        for (int i = 1;i<=m;i++){
            read(r), read(l), read(v);
            if (l>k) continue;
            ans += max(v-1ll*l*d, 0ll);
        }
        printf("%lld\n", ans);
        return;
    }
    for (int i = 1;i<=n;i++) ask[i].clear();
    for (int i = 1;i<=m;i++) read(r), read(l), read(v), ask[r].push_back({r-l+1, v});
    for (int i = 1;i<=n;i++){
        modify(root, 0, n, i, i, Max[root]);
        modify(root, 0, n, 0, i-1, -d);
        if (i>=k+1) modify(root, 0, n, i-k-1, i-k-1, -1e16);
        for (auto x: ask[i]){
            modify(root, 0, n, 0, x.first-1, x.second);
        }
    }
    printf("%lld\n", Max[root]);
    cnt = 0; Clear(root);
}

int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    read(c), read(t);
    while (t--) solve();
    return 0;
}
/*
self check:
1. long long
2. size of array
3. code for testing
4. initializing
5. freopen
*/
