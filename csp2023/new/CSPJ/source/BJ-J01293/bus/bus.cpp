#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m, k;	
int g[5010][10010];
int ans = 2e9;
bool vis[5010];

void dfs(int t, int pl)
{
	if (vis[pl]) return ;
	if (pl == n)
	{
		if (t % k == 0)
			ans = min(ans, t);
		return ;
	}
	vis[pl] = true;
	for (int i = 1; i <= n; i++)
		if (g[pl][i] >= 0 && t >= g[pl][i]) dfs(t + 1, i);
	vis[pl] = false;
}

int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	memset(g, -1, sizeof g);
	for (int i = 1; i <= m; i++)
	{
		int u, v, a;
		cin >> u >> v >> a;
		g[u][v] = a;
	}
	dfs(k, 1);
	if (ans == 2e9) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}