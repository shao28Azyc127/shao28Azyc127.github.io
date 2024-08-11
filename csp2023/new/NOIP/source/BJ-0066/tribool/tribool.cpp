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

const int N = 1e5 + 5;

int testnumber, T;
int n, m, c;
int tp[N], id[N], sta[N], t[N];
int to[] = {1, 0, 2};
int las[N];
vector<int> e[N], E[N], ee[N];
int dep[N], bel[N];
bool vis[N];

void dfs(int u) {
    vis[u] = 1; bel[u] = c;
    for(int v : E[u]) if(!vis[v]) dfs(v);
}

void dfs2(int u) {
    vis[u] = 1;
    for(int v : ee[u]) {
	if(vis[v]) continue;
	dep[v] = dep[u] + 1;
	dfs2(v);
    }
}

void dfs3(int u) {
    vis[u] = 1, las[u] = 2;
    for(int v : e[u]) if(!vis[v]) dfs3(v);
    for(int v : E[u]) if(!vis[v]) dfs3(v);
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> testnumber >> T;
    while(T--) {
	c = 0;
	cin >> n >> m;
	rep(i, 1, n) {
	    e[i].clear(), E[i].clear(); ee[i].clear();
	    tp[i] = 3, id[i] = i, sta[i] = 0;
	    las[i] = -1; dep[i] = 0;
	    vis[i] = 0; bel[i] = 0;
	}
	while(m--) {
	    char op; cin >> op;
	    if(op == '+') {
		int x, y; cin >> x >> y;
		tp[x] = tp[y], id[x] = id[y], sta[x] = sta[y];
	    }
	    else if(op == '-') {
		int x, y; cin >> x >> y;
		if(tp[y] == 3) tp[x] = 3, id[x] = id[y], sta[x] = !sta[y];
		else tp[x] = to[tp[y]];
	    }
	    else {
		int x; cin >> x;
		if(op == 'U') tp[x] = 2;
		else tp[x] = (op == 'F');
	    }
	}
	int ans = 0;
	rep(i, 1, n) {
	    if(tp[i] == 3) {
		if(!sta[i]) E[i].pb(id[i]), E[id[i]].pb(i);
		else e[i].pb(id[i]), e[id[i]].pb(i);
	    }
	    else las[i] = tp[i];
	}
	rep(i, 1, n) if(!vis[i]) {
	    ++c; t[c] = i;
	    dfs(i);
	}
	memset(vis, 0, sizeof vis);
	rep(u, 1, n) for(int v : e[u]) ee[bel[u]].pb(bel[v]);
	rep(i, 1, c) if(!dep[i]) dfs2(i);
	memset(vis, 0, sizeof vis);
	rep(u, 1, c) for(int v : ee[u]) if(abs(dep[u] - dep[v]) % 2 == 0) las[t[u]] = las[t[v]] = 2;
	rep(i, 1, n) if(las[i] == 2) dfs3(i);
	rep(i, 1, n) if(las[i] == 2) ++ans;
	cout << ans << '\n';
    }
    return 0;
}
