#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define nrep(i, a, b) for(int i = (a); i >= (b); --i)
#define endl() putchar('\n')
using namespace std;

#define int ll

typedef long long ll;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
    while(ch >= '0' && ch <= '9') x = (x << 1) +(x << 3) + (ch ^ 48), ch = getchar();
    return x * f;
}

const int N = 2e5 + 10;
const ll MAXN = 2e9 + 10, INF = 1e17;

struct Event {
    ll x, y, v;
};
vector<Event> all, eve[N << 3];

int Case, T, Ts;

namespace SEG {
    static const int N = :: N << 6;
    ll s[N], add[N]; int ls[N], rs[N];
    int alloc;

    void init() {
        memset(s, 0, sizeof s);
        memset(add, 0, sizeof add);
        memset(ls, 0, sizeof ls);
        memset(rs, 0, sizeof rs);
    }

    inline int make() {
        int x = ++alloc;
        add[x] = s[x] = ls[x] = rs[x] = 0;
        return x;
    }

    inline void maketag(int x, ll v) {
        s[x] += v, add[x] += v;
    }

    inline void pushup(int x) {
        s[x] = max(s[ls[x]], s[rs[x]]) + add[x];
    }

    void update(int &x, ll l, ll r, ll v, ll ql = 0, ll qr = MAXN) {
        if(r < ql || qr < l) return;
        if(!x) x = make();
        if(l <= ql && qr <= r) return maketag(x, v);
        ll mid = (ql + qr) >> 1;
        update(ls[x], l, r, v, ql, mid);
        update(rs[x], l, r, v, mid + 1, qr);
        pushup(x);
    }

    ll query(int x, ll l, ll r, ll ql = 0, ll qr = MAXN) {
        if(r < ql || qr < l) return 0;
        if(!x) return 0;
        if(l <= ql && qr <= r) return s[x];
        ll mid = (ql + qr) >> 1;
        return max(query(ls[x], l, r, ql, mid), query(rs[x], l, r, mid + 1, qr)) + add[x];
    }
}

vector<ll> visited;

ll n, m, k, d;
int root_f, root_g;

void push(ll x) {
    rep(i, 0, 1) if(x + i > 0 && x + i <= n + 1) visited.push_back(x + i);
}
void push1(ll x) {
    rep(i, 0, 0) if(x + i > 0 && x + i <= n + 1) visited.push_back(x + i);
}

int getid(ll x) {
    return lower_bound(visited.begin(), visited.end(), x) - visited.begin();
}

void sub2_brute() {
//    print(Ts);
    SEG ::alloc = 0;
//    SEG ::init();
    root_f = SEG ::make();
    root_g = SEG ::make();

    all.clear();
    visited.clear();
    n = read(), m = read(), k = read(), d = read();
    rep(i, 1, m) {
        ll x = read(), y = read(), v = read();
        all.push_back({x, y, v});
        push(x);
//        push(x + k);
//        push(x - k);
        push1(x - y);
    }

    visited.push_back(n + 1);
//    rep(i, 1, n) visited.push_back(i);
    sort(visited.begin(), visited.end());
    visited.resize(unique(visited.begin(), visited.end()) - visited.begin());
    for(auto &p : all) eve[getid(p.x)].push_back(p);

//    f[0] = g[0] = 0;
    ll cnt = 0;
    for(int i : visited) {
        ll cur_f = 0, cur_g = 0;
        cur_f = max(cur_f, SEG ::query(root_f, max(0ll, i - k - 1), i - 1) + d);
        cur_f = max(cur_f, SEG ::query(root_g, 0ll, i - 1) + i * d);
        cur_g = cur_f - i * d;
//        if(++cnt % 1000 == 0) print(i, cur_f, cur_g);
        SEG ::update(root_f, i, i, cur_f);
        SEG ::update(root_g, i, i, cur_g);
//        print(i);
//        rep(j, max(0ll, i - k - 1), i - 1) f[i] = max(f[i], f[j] + d);
//        rep(j, max(0ll, i - k - 1), i - 1) f[i] = max(f[i], g[j] + (i - j) * d);
//        g[i] = f[i];
        int id = getid(i);
        for(auto &p : eve[id]) SEG ::update(root_f, max(0ll, i - k - 1), i - p.y, p.v);
//        for(auto &p : eve[id]) rep(j, max(0ll, i - k - 1), i - p.y) f[j] += p.v;
    }
    rep(i, 0, visited.size()) eve[i].clear();
    ll ans = -d * (n + 1) + SEG ::query(root_f, n + 1, n + 1);
    printf("%lld\n", ans);
}


void solve() {
    n = read(), m = read(), k = read(), d = read();
    rep(i, 0, n + 1) eve[i].clear();
    rep(i, 1, m) {
        ll x = read(), y = read(), v = read();
        eve[x].push_back({x, y, v});
    }
}

signed main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);

    Case = read(), T = read();
    for(Ts = 1; Ts <= T; ++Ts) {
        sub2_brute();
    }
    return 0;
}
