#include <cstdio>
const int NX = 500005;
int c = 0, n = 0, m = 0, q = 0, kx = 0, ky = 0, u = 0, v = 0;
int oa[NX] = {}, ob[NX] = {};
int a[NX] = {}, b[NX] = {};
namespace slv1
{
	const int MX = 2005;
	int d[MX][MX] = {1};
	int main()
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				d[i][j] = 0;
				if (d[i - 1][j - 1] || d[i - 1][j] || d[i][j - 1])
				{
					if ((a[1] > b[1] && a[i] > b[j]) || (a[1] < b[1] && a[i] < b[j]))
						d[i][j] = 1;
				}
			}
		return d[n][m];
	}
}
int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	scanf("%d%d%d%d", &n, &n, &m, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), oa[i] = a[i];
	for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]), ob[i] = b[i];
	if (c <= 7)
		printf("%d", slv1::main());
	while (q--)
	{
		scanf("%d%d", &kx, &ky);
		for (int i = 1; i <= n; i++)
			a[i] = oa[i];
		for (int i = 1; i <= m; i++)
			b[i] = ob[i];
		for (int i = 1; i <= kx; i++)
			scanf("%d%d", &u, &v), a[u] = v;
		for (int i = 1; i <= ky; i++)
			scanf("%d%d", &u, &v), b[u] = v;
		if (c <= 7)
			printf("%d", slv1::main());
	}
	printf("\n");
	return 0;
}
