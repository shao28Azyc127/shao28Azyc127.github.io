//BJ-0019

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, s, t) for(int i = (s); i <= (t); ++i)
#define per(i, s, t) for(int i = (t); i >= (s); --i)
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 5;

int n, m;
int a[N];
int cnt, vis[N];
bool ok[N], okk;
vector<int> adj[N];

inline void dfs1(int u, int c) {
	if(!vis[u]) {
		vis[u] = c;
		for(int v : adj[u]) {
			int c0 = c;
			if(v < 0) v = -v, c0 ^= 3;
			dfs1(v, c0);
		}
	} else if(vis[u] != c) ok[u] = 0;
}

inline void dfs2(int u) {
	if(!ok[u]) okk = 0;
	if(vis[u]) return;
	vis[u] = 1;
	++cnt;
	for(int v : adj[u]) dfs2(abs(v));
}

void solve() {
	cin >> n >> m;
	rep(i, 1, n) vis[i] = 0, ok[i] = 1, adj[i].clear();
	rep(i, 1, n) a[i] = i;
	while(m--) {
		char ch; cin >> ch;
		if(ch == '+') {
			int i, j; cin >> i >> j;
			a[i] = a[j];
		} else if(ch == '-') {
			int i, j; cin >> i >> j;
			a[i] = -a[j];
		} else {
			int i; cin >> i;
			if(ch == 'T') a[i] = n+1;
			else if(ch == 'F') a[i] = -n-1;
			else a[i] = 0;
		}
	}
	rep(i, 1, n) if(a[i] == -n-1) a[i] = n+2;
	//rep(i, 1, n) cerr << i << " = " << a[i] << "\n";
	rep(i, 1, n) {
		if(a[i] == 0) ok[i] = 0;
		else if(a[i] <= n) {
			if(a[i] < 0) adj[i].pb(a[i]), adj[-a[i]].pb(-i);
			else adj[i].pb(a[i]), adj[a[i]].pb(i);
		}
	}
	rep(i, 1, n) if(a[i] > n) dfs1(i, a[i]-n);
	rep(i, 1, n) if(!vis[i]) dfs1(i, 1);
	rep(i, 1, n) vis[i] = 0;
	int ans = 0;
	rep(i, 1, n) if(!vis[i]) {
		cnt = 0, okk = 1;
		dfs2(i);
		if(okk) ans += cnt;
	}
	cout << n-ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);

	int id, t; cin >> id >> t;
	while(t--) solve();

	return 0;
}