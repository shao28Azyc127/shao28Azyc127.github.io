// rui_er is kawaii!!!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 mt(time(0));
inline int randint(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(mt);
}

#ifndef RUIER
ifstream fin("run.in");
ofstream fout("run.out");
#define cin fin
#define cout fout
#endif

const int N = 100005;
const ll inf = 0x1f1f1f1f1f1f1f1fll;

int test_case, T, n, m, k, d;
vector<tuple<int, int>> challenges[N];
vector<tuple<int, int, int>> qwq;
vector<int> pos;

struct Node {
    ll val, mx, tag;
    int rnd, sz, lc, rc;
    Node(ll a = -inf, int b = 0) : val(a), mx(a), tag(0), rnd(randint(1, 2000000000)), sz(b), lc(0), rc(0) {}
};
struct FHQTreap {
    Node t[N];
    int rt, sz;
    FHQTreap() {
        t[0] = Node();
        rt = sz = 0;
    }
    int new_node(ll val) {
        t[++sz] = Node(val, 1);
        return sz;
    }
    void pushup(int u) {
        t[u].sz = t[t[u].lc].sz + 1 + t[t[u].rc].sz;
        t[u].mx = max({t[t[u].lc].mx, t[u].val, t[t[u].rc].mx});
    }
    void pushdown(int u) {
        if(t[u].tag) {
            if(t[u].lc) {
                t[t[u].lc].tag += t[u].tag;
                t[t[u].lc].val += t[u].tag;
                t[t[u].lc].mx += t[u].tag;
            }
            if(t[u].rc) {
                t[t[u].rc].tag += t[u].tag;
                t[t[u].rc].val += t[u].tag;
                t[t[u].rc].mx += t[u].tag;
            }
            t[u].tag = 0;
        }
    }
    void split(int u, int lim, int& x, int& y) {
        if(!u) {x = y = 0; return;}
        pushdown(u);
        if(t[t[u].lc].sz >= lim) {
            y = u;
            split(t[u].lc, lim, x, t[u].lc);
        }
        else {
            x = u;
            split(t[u].rc, lim - t[t[u].lc].sz - 1, t[u].rc, y);
        }
        pushup(u);
    }
    int merge(int u, int v) {
        if(!u || !v) return u | v;
        if(t[u].rnd < t[v].rnd) {
            pushdown(u);
            t[u].rc = merge(t[u].rc, v);
            pushup(u);
            return u;
        }
        else {
            pushdown(v);
            t[v].lc = merge(u, t[v].lc);
            pushup(v);
            return v;
        }
    }
    template<typename... T>
    int merge(int u, int v, T... w) {
        return merge(merge(u, v), w...);
    }
}fhq;

struct SegmentTree {
    int sum[2000005], mxl[2000005], mxr[2000005], ans[2000005], lc[2000005], rc[2000005], rt, sz;
    void init() {
        for(int i = 1; i <= sz; ++i) {
            sum[i] = mxl[i] = mxr[i] = ans[i] = lc[i] = rc[i] = 0;
        }
        rt = sz = 0;
    }
    void pushup(int u, int l, int r) {
        int mid = (l + r) >> 1;
        sum[u] = sum[lc[u]] + sum[rc[u]];
        mxl[u] = (sum[lc[u]] == mid - l + 1) ? (sum[lc[u]] + mxl[rc[u]]) : mxl[lc[u]];
        mxr[u] = (sum[rc[u]] == r - mid) ? (sum[rc[u]] + mxr[lc[u]]) : mxr[rc[u]];
        ans[u] = max({ans[lc[u]], ans[rc[u]], mxr[lc[u]] + mxl[rc[u]]});
    }
    void insert(int& u, int l, int r, int ql, int qr) {
        if(!u) u = ++sz;
        if(sum[u] == r - l + 1) return;
        if(ql <= l && r <= qr) {
            sum[u] = mxl[u] = mxr[u] = ans[u] = r - l + 1;
            return;
        }
        int mid = (l + r) >> 1;
        if(ql <= mid) insert(lc[u], l, mid, ql, qr);
        if(qr > mid) insert(rc[u], mid + 1, r, ql, qr);
        pushup(u, l, r);
    }
    int query(int u, int l, int r, int ql, int qr) {
        if(!u) return 0;
        if(sum[u] == r - l + 1) return min(r, qr) - max(l, ql) + 1;
        if(ql <= l && r <= qr) return sum[u];
        int mid = (l + r) >> 1, ans = 0;
        if(ql <= mid) ans += query(lc[u], l, mid, ql, qr);
        if(qr > mid) ans += query(rc[u], mid + 1, r, ql, qr);
        return ans;
    }
}sgt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> test_case >> T; T; --T) {
        cin >> n >> m >> k >> d;
        if(n <= 100000 && m <= 100000) {
            for(int i = 1; i <= m; ++i) {
                int x, y, v;
                cin >> x >> y >> v;
                if(y <= k) {
                    challenges[x].emplace_back(y, v);
                    pos.push_back(x);
                }
            }
            fhq = FHQTreap();
            for(int j = 0; j <= k; ++j) {
                fhq.rt = fhq.merge(fhq.rt, fhq.new_node(j == 0 ? 0 : -inf));
            }
            for(int i = 1; i <= n; ++i) {
                ll val = fhq.t[fhq.rt].mx;
                int L, R;
                fhq.split(fhq.rt, k, L, R);
                fhq.t[R] = Node(val, 1);
                fhq.t[L].tag -= d;
                fhq.t[L].val -= d;
                fhq.t[L].mx -= d;
                fhq.rt = fhq.merge(R, L);
                for(tuple<int, int> c : challenges[i]) {
                    int y = get<0>(c), v = get<1>(c);
                    int L, R;
                    fhq.split(fhq.rt, y, L, R);
                    fhq.t[R].tag += v;
                    fhq.t[R].val += v;
                    fhq.t[R].mx += v;
                    fhq.rt = fhq.merge(L, R);
                }
            }
            cout << fhq.t[fhq.rt].mx << '\n';
            for(int i : pos) challenges[i].clear();
            pos.clear();
        }
        else {
            for(int i = 1; i <= m; ++i) {
                int x, y, v;
                cin >> x >> y >> v;
                int l = x - y + 1, r = x;
                if(y <= k) qwq.emplace_back(l, r, v);
            }
            ll ans = 0;
            while(1.0 - 1.0 * clock() / CLOCKS_PER_SEC >= 0.08 * T) {
                shuffle(qwq.begin(), qwq.end(), mt);
                ll now = 0;
                sgt.init();
                for(tuple<int, int, int> c : qwq) {
                    int l = get<0>(c), r = get<1>(c), v = get<2>(c);
                    int cnt = (r - l + 1) - sgt.query(1, 1, n, l, r);
                    sgt.insert(sgt.rt, 1, n, l, r);
                    if(sgt.ans[sgt.rt] > k) break;
                    now += v;
                    ans = max(ans, now);
                    if(1.0 - 1.0 * clock() / CLOCKS_PER_SEC < 0.08 * T) break;
                }
            }
            cout << ans << '\n';
            qwq.clear();
        }
    }
    cout.flush();
    return 0;
}