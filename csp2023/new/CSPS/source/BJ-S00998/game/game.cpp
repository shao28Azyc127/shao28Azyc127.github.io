#include <cstdio>
const int NX = 2e6 + 5;
int n, a[NX];
namespace s2
{
	int b[30][NX] = {}, bl[30] = {}, d[NX] = {0}, z[NX], zl;
	long long s = 0;
	char c;
	bool chk(int x, int y)
	{
		zl = 0;
		for (int i = x; i <= y; i++)
			if (zl && z[zl] == a[i])
				zl--;
			else
				z[++zl] = a[i];
		return !zl;
	}
	int main()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = bl[a[i]]; j >= 1; j--)
				if (chk(b[a[i]][j] + 1, i - 1))
					d[i] = d[b[a[i]][j] - 1] + 1, s += d[i], j = 0;
			b[a[i]][++bl[a[i]]] = i;
		}
		printf("%lld\n", s);
		return 0;
	}
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%d", &n);
	char c;
	for (int i = 1; i <= n; i++)
		scanf(" %c", &c), a[i] = c - 'a' + 1;
	s2::main();
	return 0;
}
