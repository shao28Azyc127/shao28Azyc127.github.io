#include <bits/stdc++.h>
using namespace std;

int c, n, m, q;

namespace S35
{
	const int NR = 2010;
	int x[NR], y[NR], tx[NR], ty[NR];
	int f[NR][NR][2];
	
	inline int cal()
	{
		if (x[1] < y[1] && x[n] > y[m]) return 0;
		if (x[1] > y[1] && x[n] < y[m]) return 0;
		int c = (x[1] < y[1]);
		for (int j = 1; j <= m; j++)
			f[0][j][c] = 0;
		for (int i = 1; i <= n; i++)
			f[i][0][c] = 0;
		f[0][0][c] = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				f[i][j][c] = ((c ? (x[i] < y[j]) : (x[i] > y[j])) && (f[i - 1][j][c] || f[i][j - 1][c] || f[i - 1][j - 1][c]));
		return f[n][m][c];
	}
	
	void solve()
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", x + i), tx[i] = x[i];
		for (int i = 1; i <= m; i++)
			scanf("%d", y + i), ty[i] = y[i];
		printf("%d", cal());
		while (q--)
		{
			int kx, ky;
			scanf("%d%d", &kx, &ky);
			vector<int> px(kx), vx(kx);
			vector<int> py(ky), vy(ky);
			for (int i = 0; i < kx; i++)
				scanf("%d%d", &px[i], &vx[i]), x[px[i]] = vx[i];
			for (int i = 0; i < ky; i++)
				scanf("%d%d", &py[i], &vy[i]), y[py[i]] = vy[i];
			printf("%d", cal());
			for (int i = 0; i < kx; i++)
				x[px[i]] = tx[px[i]];
			for (int i = 0; i < ky; i++)
				y[py[i]] = ty[py[i]];
		}
		exit(0);
	}
}

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &c, &n, &m, &q);
	if (c <= 7) S35::solve();
	return 0;
}