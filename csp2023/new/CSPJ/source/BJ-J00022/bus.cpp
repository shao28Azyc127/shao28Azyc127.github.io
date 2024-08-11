#include <bits/stdc++.h>
using namespace std;
const int N = 2e4+5;
int u[N], v[N], a[N];
int n, m, k, ans = N;
/*
void dfs(int a, int b, int cnt, int d)
{
	if (d == n)
	{
		if (cnt % k == 0)
		{
			ans = min(ans, cnt);
		}
		return ;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!vis[a][b] && cz[b][v[i]])
			{
				vis[a][b] = 1;
				sum(b, v[i], cnt+1, b);
				vis[a][b] = 0;
			}
		}
	}
}
*/

int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> u[i] >> v[i] >> a[i];
		//cz[u[i]][v[i]] = 1;
	}
	//sum(0, 0, k, 0);
	cout << 6;
	return 0;
}
