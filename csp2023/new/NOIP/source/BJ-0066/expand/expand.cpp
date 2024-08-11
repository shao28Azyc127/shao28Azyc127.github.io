#include <bits/stdc++.h>
#define rep(i, b, s) for(int i = (b); i <= (s); ++i)
#define per(i, b, s) for(int i = (b); i >= (s); --i)
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 4e4 + 5;

int testnumber, n, m, q, fl;
int a[N], b[N], x[N], y[N];
int f[2005][2005];
bitset<N> vis[N];

void dfs(int ux, int uy) {
    if(fl) return ;
    vis[ux][uy] = 1;
    if(ux == n && uy == m) {
	fl = 1;
	return ;
    }
    if(ux != n && x[ux + 1] != y[uy] && (x[ux + 1] < y[uy]) == (x[1] < y[1]) && !vis[ux + 1][uy]) dfs(ux + 1, uy);
    if(uy != m && x[ux] != y[uy + 1] && (x[ux] < y[uy + 1]) == (x[1] < y[1]) && !vis[ux][uy + 1]) dfs(ux, uy + 1);
}

void solve() {
    if(x[1] == y[1] || x[n] == y[m]) {
	cout << '0';
	return ;
    }
    if((x[1] < y[1]) == (x[n] > y[m])) {
	cout << '0';
	return ;
    }
    if(testnumber <= 7) {
	int k = (x[1] < y[1]);
	memset(f, 0, sizeof f);
	f[1][1] = 1;
	rep(i, 1, n) rep(j, 1, m) {
	    if(!f[i][j]) continue;
	    if(x[i + 1] != y[j] && (x[i + 1] < y[j]) == k) f[i + 1][j] = 1;
	    if(x[i] != y[j + 1] && (x[i] < y[j + 1]) == k) f[i][j + 1] = 1;
	}
	cout << f[n][m];
	return ;
    }
    fl = 0;
    rep(i, 1, n) vis[i].reset();
    dfs(1, 1);
    cout << fl;
}

int main() {
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> testnumber >> n >> m >> q;
    rep(i, 1, n) cin >> a[i], x[i] = a[i];
    rep(i, 1, m) cin >> b[i], y[i] = b[i];
    solve();
    while(q--) {
	rep(i, 1, n) x[i] = a[i];
	rep(i, 1, m) y[i] = b[i];
	int kx, ky; cin >> kx >> ky;
	while(kx--) {
	    int p, v;
	    cin >> p >> v;
	    x[p] = v;
	}
	while(ky--) {
	    int p, v;
	    cin >> p >> v;
	    y[p] = v;
	}
	solve();
    }
    cout << '\n';
    // cout << (long double)clock() / CLOCKS_PER_SEC << '\n';
    return 0;
}
