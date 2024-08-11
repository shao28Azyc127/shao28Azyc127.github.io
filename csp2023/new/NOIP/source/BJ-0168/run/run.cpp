#include <bits/stdc++.h>
using namespace std;

namespace S36
{
	const int NR = 1010;
	long long c[NR][NR], f[NR][NR], g[NR];
	
	void solve()
	{
		int n, m, k, d;
		scanf("%d%d%d%d", &n, &m, &k, &d);
		memset(c, 0, sizeof(c));
		while (m--)
		{
			int x, y, v;
			scanf("%d%d%d", &x, &y, &v);
			c[x][y] += v;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= min(i, k); j++)
				c[i][j] += c[i][j - 1];
		memset(f, -0x3f, sizeof(f));
		memset(g, -0x3f, sizeof(g));
		g[0] = f[0][0] = 0;
		for (int i = 1; i <= n; i++)
		{
			f[i][0] = g[i - 1];
			for (int j = 1; j <= min(i, k); j++)
				f[i][j] = max(f[i][j], f[i - 1][j - 1] - d + c[i][j]);
			for (int j = 0; j <= min(i, k); j++)
				g[i] = max(g[i], f[i][j]);
		}
		printf("%lld\n", g[n]);
	}
}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	if (c <= 9) {while (t--) S36::solve(); return 0;}
	return 0;
}