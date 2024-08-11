//By Pr_159
//stack memory overflow -> 20~100 pts
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;

struct edge
{
	int v, a;
};

vector <edge> Adj[N];
int n, m, k, u, v, a, ans = (1 << 30);

void dfs(int u, int t)
{
	if(u == n && t % k == 0)
	{
		ans = min(ans, t);
		return;
	}
	for(auto v : Adj[u])
	{
		//printf("v.a = %d\n", v.a);
		if(t + 1 < v.a)
		{
			//for(int i = 1; ; i++)
			{
				//if(t + i * k >= v.a)
				{
					//printf("t = %d, dfs(%d, %d)\n", t, v.v, t + i * k);
					//dfs(v.v, t + i * k + 1);
					//break;
				}
			}
			int tmp = ceil(((double)v.a - t) / k);
			dfs(v.v, t + tmp * k + 1);
		}
		else
		{
			//printf("t = %d, dfs(%d, %d)\n", t, v.v, t + 1);
			dfs(v.v, t + 1);
		}
	}
}

int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v >> a;
		Adj[u].push_back({v, a});
	}
	dfs(1, 0);
	if(ans == (1 << 30)) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}
/*
5 5 3
1 2 0
2 5 1
1 3 0
3 4 3
4 5 1
*/
