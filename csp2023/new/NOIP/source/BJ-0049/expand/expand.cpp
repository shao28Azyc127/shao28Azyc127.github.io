#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>

#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif

#define maxn 500055
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

using namespace std;

int cid, n, m, q, a[maxn], b[maxn], a1, an, b1, bm, c[maxn], d[maxn], f[2005][2005];

struct node {
    int l, r, mn, mx;
};

struct sgt {
    node a[maxn * 4];
    void build(int id, int l, int r, int* p) {
        a[id].l = l, a[id].r = r;
        if(l == r) {
            a[id].mn = a[id].mx = p[l];
            return ;
        }
        int mid = (l + r) >> 1;
        build(id * 2, l, mid, p); build(id * 2 + 1, mid + 1, r, p);
        a[id].mn = min(a[id * 2].mn, a[id * 2 + 1].mn), a[id].mx = max(a[id * 2].mx, a[id * 2 + 1].mx);
    }
    void modify(int id, int x, int v) {
        if(a[id].l == a[id].r) {
            if(a[id].l == x) a[id].mn = a[id].mx = v;
            return ;
        }
        int mid = (a[id].l + a[id].r) >> 1;
        if(x <= mid) modify(id * 2, x, v);
        else modify(id * 2 + 1, x, v);
        a[id].mn = min(a[id * 2].mn, a[id * 2 + 1].mn), a[id].mx = max(a[id * 2].mx, a[id * 2 + 1].mx);
    }
    int findl(int id, int v, bool tp) {
        if(a[id].l == a[id].r) {
            if(tp ? (a[id].mx >= v) : (a[id].mn <= v)) return a[id].l;
            return inf;
        }
        if((tp && a[id * 2].mx >= v) || (!tp && a[id * 2].mn <= v)) return findl(id * 2, v, tp);
        else return findl(id * 2 + 1, v, tp);
    }
    int findr(int id, int v, bool tp) {
        if(a[id].l == a[id].r) {
            if(tp ? (a[id].mx >= v) : (a[id].mn <= v)) return a[id].l;
            return -inf;
        }
        if((tp && a[id * 2 + 1].mx >= v) || (!tp && a[id * 2 + 1].mn <= v)) return findr(id * 2 + 1, v, tp);
        else return findr(id * 2, v, tp);
    }
    int query(int id, int l, int r, bool tp) {
        if(a[id].l == l && a[id].r == r) {
            return tp ? a[id].mx : a[id].mn;
        }
        int mid = (a[id].l + a[id].r) >> 1;
        if(r <= mid) return query(id * 2, l, r, tp);
        else if(l > mid) return query(id * 2 + 1, l, r, tp);
        else return tp ? max(query(id * 2, l, mid, tp), query(id * 2 + 1, mid + 1, r, tp)) : min(query(id * 2, l, mid, tp), query(id * 2 + 1, mid + 1, r, tp));
    }
} A, B;

bool work() {
    if(n <= 2000 && m <= 2000) {
        for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) f[i][j] = 0;
        f[1][1] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(i > 1) if((c[i] > d[j]) == (c[i - 1] > d[j]) && c[i] != d[j]) f[i][j] |= f[i - 1][j];
                if(j > 1) if((c[i] > d[j]) == (c[i] > d[j - 1]) && c[i] != d[j]) f[i][j] |= f[i][j - 1];
                
            }
        }
        return f[n][m];
    }
    //cout << a1 << ' ' << b1 << ',' << an << ' ' << bm << '\n';
    if(a1 == b1 || an == bm) {
        return false;
    }
    if((a1 > b1) != (an > bm)) return false;
    if(a1 > b1) {
        int al = A.query(1, 1, n, 0);
        int br = B.query(1, 1, n, 1);
        //cout << al << '-' << br << '\n';
        //cout << A.findl(1, al, 0) << ' ' << A.findr(1, br, 1) << ' ' << B.findl(1, al, 0) << ' ' << B.findr(1, br, 1) << '\n';
        if((A.findl(1, al, 0) <= A.findr(1, br, 1) && B.findl(1, al, 0) <= B.findr(1, br, 1)) || (A.findr(1, al, 0) >= A.findl(1, br, 1) && B.findr(1, al, 0) >= B.findr(1, br, 1))) return true;
        return false;
    }
    else {
        int ar = A.query(1, 1, n, 1);
        int bl = B.query(1, 1, n, 0);
        //cout << ar << '-' << bl << '\n';
        if((B.findl(1, bl, 0) <= B.findr(1, ar, 1) && A.findl(1, bl, 0) <= A.findr(1, ar, 1)) || (B.findr(1, bl, 0) >= B.findl(1, ar, 1) && A.findr(1, bl, 0) >= A.findr(1, ar, 1))) return true;
        return false;
    }
}
struct nd {
    int x, v;
};
stack<nd> oa, ob;

int main() {
    fopen("expand")
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> cid >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; c[i] = a[i];
    }
    A.build(1, 1, n, a);
    for(int j = 1; j <= m; j++) {
        cin >> b[j]; d[j] = b[j];
    }
    B.build(1, 1, m, b);
    a1 = a[1], an = a[n], b1 = b[1], bm = b[m];
    cout << work();
    while(q--) {
        int ka, kb, x, v;
        cin >> ka >> kb;
        a1 = a[1], an = a[n], b1 = b[1], bm = b[m];
        for(int i = 1; i <= ka; i++) {
            cin >> x >> v;
            if(x == 1) a1 = v;
            if(x == n) an = v;
            A.modify(1, x, v);
            c[x] = v;
            oa.push((nd){x, a[x]});
        }
        for(int i = 1; i <= kb; i++) {
            cin >> x >> v;
            if(x == 1) b1 = v;
            if(x == m) bm = v;
            B.modify(1, x, v);
            d[x] = v;
            ob.push((nd){x, b[x]});
        }
        cout << work();

        while(!oa.empty()) {
            A.modify(1, oa.top().x, oa.top().v);
            c[oa.top().x] = oa.top().v;
            oa.pop();
        }
        while(!ob.empty()) {
            B.modify(1, ob.top().x, ob.top().v);
            d[ob.top().x] = ob.top().v;
            ob.pop();
        }
    }
}