#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN = 1e5 + 5;

void read(int &x) {
    x = 0; int f = 1; char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar())
        x = x * 10 + ch - 48;
    x *= f;
}
void write(LL x, char end = 0) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else write(x / 10), putchar(x % 10 + 48);
    if (end) putchar(end);
}
void chkmax(LL &x, LL y) {if (y > x) x = y;}

int n, m, k, d, cid;

struct Node {int len, v;};
vector<Node> vec[MAXN];
vector<LL> sum[MAXN];
LL f[1005][1005];

struct Treap {int sz, ls, rs, pri; LL val, mx, add;} t[MAXN << 1];
int rt, tott;
void pushup(int p) {
    t[p].sz = 1, t[p].mx = t[p].val;
    if (t[p].ls) t[p].sz += t[t[p].ls].sz, t[p].mx = max(t[p].mx, t[t[p].ls].mx);
    if (t[p].rs) t[p].sz += t[t[p].rs].sz, t[p].mx = max(t[p].mx, t[t[p].rs].mx);
}
void pushdown(int p) {
    if (!t[p].add) return;
    if (t[p].ls) t[t[p].ls].val += t[p].add, t[t[p].ls].mx += t[p].add, t[t[p].ls].add += t[p].add;
    if (t[p].rs) t[t[p].rs].val += t[p].add, t[t[p].rs].mx += t[p].add, t[t[p].rs].add += t[p].add;
    t[p].add = 0;
}
void split(int p, int k, int &x, int &y) {
    if (!p) {x = y = 0; return;}
    pushdown(p);
    if (k <= t[t[p].ls].sz) y = p, split(t[p].ls, k, x, t[p].ls);
    else x = p, split(t[p].rs, k - t[t[p].ls].sz - 1, t[p].rs, y);
    pushup(p);
}
int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (t[x].pri < t[y].pri) {
        pushdown(x), t[x].rs = merge(t[x].rs, y), pushup(x);
        return x;
    }
    pushdown(y), t[y].ls = merge(x, t[y].ls), pushup(y);
    return y;
}
int create(LL v) {t[++tott] = {1, 0, 0, rand(), v, v, 0}; return tott;}
void insert(LL v) {rt = merge(create(v), rt);}
void add(int l, int r, LL v) {
    int x, y, z; split(rt, l, x, y), split(y, r - l + 1, y, z);
    t[y].val += v, t[y].mx += v, t[y].add += v;
    rt = merge(merge(x, y), z);
}

void sub2() {
    tott = rt = 0;
    memset(t, 0, sizeof(t));
    read(n), read(m), read(k), read(d);
    for (int i = 1; i <= n; i++) vec[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y, v; read(x), read(y), read(v);
        vec[x].push_back({y, v});
    }
    for (int i = 1; i <= k; i++) insert(-1e18);
    insert(0);
    for (int i = 1; i <= n; i++) {
        LL val = t[rt].mx;
        int x, y; split(rt, k, x, y), rt = x, insert(val);
        add(1, k, -d);
        for (auto [len, v] : vec[i]) {
            if (len > k) continue;
            add(len, k, v);
        }
    }
    write(t[rt].mx, '\n');
}

void sub1() {
    read(n), read(m), read(k), read(d);
    for (int i = 1; i <= n; i++) vec[i].clear();
    for (int i = 1; i <= m; i++) {
        int x, y, v; read(x), read(y), read(v);
        vec[x].push_back({y, v});
    }
    for (int i = 1; i <= n; i++) {
        sort(vec[i].begin(), vec[i].end(), [](Node x, Node y) {return x.len < y.len;});
        sum[i].resize(vec[i].size() + 1);
        for (int j = 1; j <= vec[i].size(); j++)
            sum[i][j] = sum[i][j - 1] + vec[i][j - 1].v;
    }
    memset(f, ~0x3f, sizeof(f)), f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) chkmax(f[i][0], f[i - 1][j]);
        int p = 0;
        for (int j = 1; j <= k; j++) {
            while (p < vec[i].size() && vec[i][p].len <= j) p++;
            f[i][j] = f[i - 1][j - 1] + sum[i][p] - d;
        }
    }
    LL ans = 0;
    for (int i = 0; i <= k; i++) ans = max(ans, f[n][i]);
    write(ans, '\n');
}

void subB() {
    read(n), read(m), read(k), read(d);
    LL ans = 0;
    for (int i = 1; i <= m; i++) {
        int len, r, v; read(r), read(len), read(v);
        if (len > k) continue;
        ans += max(0ll, v - (LL)d * len);
    }
    write(ans, '\n');
}

int main() {
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int t; read(cid), read(t);
    while (t--) {
        if (cid <= 9) sub1();
        else if (cid <= 14) sub2();
        else if (cid == 17 || cid == 18) subB();
    }
    return 0;
}