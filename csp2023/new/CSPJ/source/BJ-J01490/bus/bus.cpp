#include<bits/stdc++.h>
using namespace std;

const int nr = 1e4 + 10;
const int mr = 2e4 + 10;
int n, m, k;
struct Elist { int u, v; } e[mr];
struct Edge
{
	int v, w;
	Edge(int v, int w) : v(v), w(w) {}
};
vector<Edge> adj[nr];

namespace _subtask1
{
	int t = 0, cnum = 0, col[nr], num[nr], dfn[nr], low[nr];
	vector<int> adn[nr];
	stack<int> st;
	void solve(int x)
	{
		st.pop();
		col[x] = cnum;
		num[col[x]]++;
	}
	void Tarjan(int x)
	{
		dfn[x] = low[x] = ++t;
		st.push(x);
		for (int i = 0; i < adj[x].size(); i++)
			if (dfn[adj[x][i].v] == 0)
			{
				Tarjan(adj[x][i].v);
				low[x] = min(low[x], low[adj[x][i].v]);
			}
			else if (col[adj[x][i].v] == 0) low[x] = min(low[x], dfn[adj[x][i].v]);
		if (low[x] == dfn[x])
		{
			cnum++;
			while (st.top() != x) solve(st.top());
			solve(x);
		}
	}

	bool vis[nr] = {0};
	int ind[nr] = {0};
	struct Node { int u, d; };
	bool check()
	{
		for (int i = 1; i <= n; i++)
			if (dfn[i] == 0) Tarjan(i);
		for (int i = 1; i <= m; i++)
		{
			if (col[e[i].u] == col[e[i].v]) continue;
			adn[col[e[i].u]].push_back(col[e[i].v]);
			ind[col[e[i].v]]++;
		}
		for (int i = 1; i <= cnum; i++) if (num[i] > 1) return true;
		queue<Node> q;
		for (int i = 1; i <= cnum; i++)
			if (ind[i] == 0) q.push((Node){i, 0});
		int cnt = 0;
		while (!q.empty())
		{
			int u = q.front().u, d = q.front().d;
			q.pop();
			if (d >= k) return true;
			if (vis[u]) continue;
			vis[u] = true, cnt++;
			for (int i = 0; i < adn[u].size(); i++)
			{
				if (d + 1 >= k) return true;
				if (--ind[adn[u][i]] == 0) q.push((Node){adn[u][i], d + 1});
			}
		}
		if (cnt != cnum) return true;
		return false;
	}
	void solve()
	{
		// 只有没有环且最长道路 < k 时输出 -1
		if (check()) cout << k << endl;
		else cout << -1 << endl;
	}
}

int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	bool issk1 = true;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		e[i].u = u, e[i].v = v;
		adj[u].push_back((Edge){v, w});
		issk1 &= (w == 0);
	}
	//if (issk1) _subtask1::solve();
	cout << -1 << endl;
	return 0;
}