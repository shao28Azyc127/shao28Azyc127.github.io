#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int c, t, n, m, ans, cnt, tot;
int ch[N], d[N];

int is[N];

bool vis[N];

//stack <int> q;

struct Ques {
	char op;
	int x, y;
} q[N];

vector <int> adj[N];

bool check() {
	for(int i = 1; i <= n; i++)
		d[i] = ch[i];
	for(int i = 1; i <= m; i++)
		if(q[i].op == '+')
			d[q[i].x] = d[q[i].y];
		else if(q[i].op == '-')
			d[q[i].x] = 1 - d[q[i].y];
		else if(q[i].op == 'U')
			d[q[i].x] = -1;
		else if(q[i].op == 'F')
			d[q[i].x] = 0;
		else
			d[q[i].x] = 1;
	for(int i = 1; i <= n; i++)
		if(ch[i] == d[i] || (ch[i] == -1 && ch[i] + d[i] == 1))
			continue;
		else
			return 0;
	return 1;
}

void dfs(int stp) {
	if(stp == n + 1) {
		if(!check())
			return;
		int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(ch[i] == -1)
				cnt++;
		ans = min(ans, cnt);
		return;
	}
	ch[stp] = 0, dfs(stp + 1);
	ch[stp] = 1, dfs(stp + 1);
	ch[stp] = -1, dfs(stp + 1);
}

void sol1() {
	while(t--) {
		cin >> n >> m;
		ans = n;
		for(int i = 1; i <= m; i++) {
			cin >> q[i].op >> q[i].x;
			if(q[i].op == '+' || q[i].op == '-')
				cin >> q[i].y;
		}
		dfs(1);
		cout << ans << "\n";
	}
}

void sol2() {
	while(t--) {
		cin >> n >> m;
		ans = 0;
		for(int i = 1; i <= m; i++) {
			cin >> q[i].op >> q[i].x;
			if(q[i].op == 'U')
				ch[q[i].x] = -1;
			else if(q[i].op == 'F')
				ch[q[i].x] = 0;
			else
			ch[q[i].x] = 1;
		}
		for(int i = 1; i <= n; i++)
			ans += (ch[i] == -1);
		cout << ans << "\n";
	}
}

/*void tar(int u) {
	dfn[u] = low[u] = ++cnt;
	vis[u] = 1, s.push(u);
	for(auto v : adj[u])
		if(!dfn[v])
			tar(v), low[u] = min(low[u], low[v]);
		else if(vis[v])
			low[u] = min(low[u], dfn[v]);
	if(dfn[u] == low[u]) {
		siz[++tot] = 1, bel[u] = tot, vis[u] = 0, qwq[tot] |= (is[u] != 0);
		while(q.top() != u)
			siz[tot]++, bel[q.top()] = tot, vis[q.top()] = 0, qwq[tot] |= (is[q.top()] != 0), q.pop();
		q.pop();
	}
}
*/
void sol3() {
	while(t--) {
		cin >> n >> m;
		ans = 0;
		for(int i = 1; i <= n; i++)
			is[i] = 0;
		cnt = tot = 0;
		for(int i = 1; i <= m; i++) {
			cin >> q[i].op >> q[i].x;
			if(q[i].op == '+')
				cin >> q[i].y, is[q[i].y] = is[q[i].x];
			if(q[i].op == 'U')
				is[q[i].x] = -1;
		}	
		for(int i = 1; i <= m; i++)
			if(q[i].op == '+' && is[q[i].y])
				is[q[i].x] = -1;
			else if(q[i].op == '+')
				is[q[i].x] = 0;
		for(int i = 1; i <= n; i++)
			if(is[i])
				ans++;
		cout << ans << "\n";
	}
}

int main() {
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	if(c <= 2) {
		sol1();
		return 0;
	}
	if(c >= 3 && c <= 4) {
		sol2();
		return 0;
	}
	if(c >= 5 && c <= 6) {
		sol3();
		return 0;
	}
	/*if(c >= 7 && c <= 8) {
		sol4();
		return 0;
	}
	sol5();*/
	return 0;
}
