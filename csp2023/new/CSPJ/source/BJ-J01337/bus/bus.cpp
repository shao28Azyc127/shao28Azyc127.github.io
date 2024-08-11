#include <bits/stdc++.h>
using namespace std;

struct edge
{
	int tlim;
	int to;
};

vector<edge> graph[100020];
edge edg;

int n, m, k, u, v, a, mint = INT_MAX;

void dfs(int p, int t, int cost)
{
	if (p == n)
	{
		if ((t + cost) % k == 0 && t + cost < mint)
		{
			mint = t + cost;
		}
		return;
	}
	int tmp = t;
	for (auto i = graph[p].begin(); i < graph[p].end(); i++)
	{
		if ((*i).tlim > t + cost)
		{
			t = (((*i).tlim - cost)/k+1)*k;
		}
		dfs((*i).to, t, cost + 1);
		t = tmp;
	}
}
int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> a;
		edg.tlim = a;
		edg.to = v;
		graph[u].push_back(edg);
	}
	dfs(1, 0, 0);
	if (mint = INT_MAX)
	{
		cout << -1;
	}
	else
	{
		cout << mint;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
