#include <bits/stdc++.h>
#define rep(i, b, s) for(int i = (b); i <= (s); ++i)
#define per(i, b, s) for(int i = (b); i >= (s); --i)
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

const int N = 1e5 + 5;

int n;
ll a[N], b[N], c[N], d[N];
int tim[N];
int t[N]; pii p[N];
int dep[N], fa[N];
int top[N], siz[N], son[N];
int dfn[N], tot;
vector<int> e[N];
bool vis[N];

struct Tree {
    int tr[N];

    void build() { memset(tr, 0, sizeof tr); }
    int lb(int x) { return x & (-x); }
    void upd(int x, int v) {
        if(!x) return ;
	while(x <= n) tr[x] += v, x += lb(x);
    }
    int qry(int x) {
	int res = 0;
	while(x) res += tr[x], x -= lb(x);
	return res;
    }
} ttr;

void dfs(int u, int f) {
    fa[u] = f; siz[u] = 1;
    dep[u] = dep[f] + 1;
    for(int v : e[u]) if(v != f) {
	    dfs(v, u);
	    siz[u] += siz[v];
	    if(siz[son[u]] < siz[v]) son[u] = v;
	}
}

void dfs2(int u, int tt) {
    top[u] = tt; dfn[u] = ++tot;
    if(!son[u]) return ;

    dfs2(son[u], tt);
    for(int v : e[u]) if(v != son[u] && v != fa[u]) dfs2(v, v);
}

bool cal(int i, int l, int x) {
    if(b[i] * (x - l + 1) >= a[i]) return 1;
    return (a[i] - b[i] * (x - l + 1) + c[i] - 1) / c[i] <= 1ll * (l + x) * (x - l + 1) / 2;
    // b[i] * (x - l + 1) + (l + x)*(x - l + 1)/2 * c[i] >= a[i]
}

ll calc(int i, int l, int x) {
    if(l > tim[i]) return x - l + 1;
    int tt = min(tim[i], x);
    return b[i] * (tt - l + 1) - 1ll * (l + tt) * (tt - l + 1) / 2 * d[i] + x - tt;
}

int get(int i, int x) {
    int l = 1, r = x, ans = 1;
    while(l <= r) {
	int mid = l + r >> 1;
	if(cal(i, mid, x)) ans = mid, l = mid + 1;
	else r = mid - 1;
    }
    return ans;
}

int get2(int i, int x) {
    int l = 1, r = x, ans = 1;
    while(l <= r) {
	int mid = l + r >> 1;
	if(calc(i, mid, x) >= a[i]) ans = mid, l = mid + 1;
	else r = mid - 1;
    }
    return ans;
}

void update(int x) {
    while(x) {
	ttr.upd(dfn[x], 1);
	ttr.upd(dfn[top[x]] - 1, -1);
	x = fa[top[x]];
    }
}

bool chk(int x) {
    ttr.build();
    rep(i, 1, n) {
	vis[i] = 0;
	if(c[i] > 0) {
	    if(!cal(i, 1, x)) return 0;
	    t[i] = get(i, x);
	    // b[i]*x + x*(x+1)*c[i]/2 < a[i]
	}
	else if(!c[i]) {
	    if(b[i] * x < a[i]) return 0;
	    t[i] = x - (a[i] + b[i] - 1) / b[i] + 1;
	}
	else {
	    int tt = min(tim[i], x);
	    if(calc(i, 1, x) < a[i]) return 0;
	    t[i] = get2(i, x);
	}
    }
    rep(i, 1, n) p[i] = mp(i, t[i]);
    sort(p + 1, p + n + 1, [&](const pii &a, const pii &b) { return a.se < b.se; });
    // rep(i, 1, n) cout << p[i].fi << ' ' << p[i].se << '\n';
    rep(i, 1, n) {
        update(p[i].fi);
	if(p[i].se != p[i + 1].se && ttr.qry(n) > p[i].se) return 0;
    }
    return 1;
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    rep(i, 1, n) {
	cin >> a[i] >> b[i] >> c[i];
	if(c[i] < 0) {
	    d[i] = -c[i];
	    tim[i] = (b[i] - 1) / d[i];
	    // cout << tim[i] << '\n';
	}
    }
    rep(i, 1, n - 1) {
	int u, v;
	cin >> u >> v;
	e[u].pb(v), e[v].pb(u);
    }
    dfs(1, 0);
    dfs2(1, 1);

    // chk(5);
    // return 0;
    
    int l = n + 1, r = 1e9, ans = 1e9;
    while(l <= r) {
	int mid = l + r >> 1;
	if(chk(mid)) ans = mid, r = mid - 1;
	else l = mid + 1;
    }
    cout << ans << '\n';
    // cout << (long double)clock() / CLOCKS_PER_SEC << '\n';
    return 0;
}
