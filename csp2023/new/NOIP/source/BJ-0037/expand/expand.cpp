/*
But thy eternal summer shall not fade,
Nor lose possession of that fair thou ow'st;
Nor shall death brag thou wander'st in his shade,
When in eternal lines to time thou grow'st:
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
using namespace std;

const int N = 5e5;

int TestId;
int n, m, q;
int x[N + 5], y[N + 5];

namespace BF
{
	const int NN = 2000;

	bool dp[NN + 5][NN + 5];
	int _x[NN + 5], _y[NN + 5];

	bool check(int a[], int lena, int b[], int lenb)//a > b
	{
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= lena; i++)
		{
			for (int l = 1, r = l; l <= lenb; l = r + 1)
			{
				r = l;
				if (a[i] <= b[l])
					continue;
				while (r + 1 <= lenb && a[i] > b[r + 1])
					r++;

				int p = l - 1;
				while (!dp[i - 1][p] && p <= r)
					p++;
				for (int t = max(l, p); t <= r; t++)
					dp[i][t] = 1;
			}
		}
		return dp[lena][lenb];
	}

	void calc()
	{
		bool ok = check(_x, n, _y, m);
		if (!ok)
			ok = check(_y, m, _x, n);

		if (ok)
			printf("1");
		else
			printf("0");
		return ;
	}
	void solve()
	{
		for (int t = 1; t <= n; t++)
			_x[t] = x[t];
		for (int t = 1; t <= m; t++)
			_y[t] = y[t];
		calc();

		for (int T = 1, kx, ky; T <= q; T++)
		{
			scanf("%d%d", &kx, &ky);
			for (int t = 1; t <= n; t++)
				_x[t] = x[t];
			for (int t = 1; t <= m; t++)
				_y[t] = y[t];
			for (int t = 1, p, v; t <= kx; t++)
			{
				scanf("%d%d", &p, &v);
				_x[p] = v;
			}
			for (int t = 1, p, v; t <= ky; t++)
			{
				scanf("%d%d", &p, &v);
				_y[p] = v;
			}
			calc();
		}
		printf("\n");
		return ;
	}
}

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);

	scanf("%d%d%d%d", &TestId, &n, &m, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", x + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", y + i);

	if (TestId <= 7)
		BF :: solve();
	return 0;
}
