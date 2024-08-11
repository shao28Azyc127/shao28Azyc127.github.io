#include <cstdio>
#include <cstring>
int n, u, m, l[105], r[105], a = 0;
long long v;
char c[105], e[105][105];
int main()
{
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
	scanf("%d", &n);
	for (int nn = 1; nn <= n; nn++)
	{
		scanf("%d", &u);
		if (u == 1)
		{
		}
		else if (u == 2)
		{
			m++, scanf(" %s %s", c, e[m]), c[0] = (c[0] == 'b' ? 1 : c[0] == 's' ? 2 : c[0] == 'i' ? 4 : 8),
			l[m] = a + (c[0] - a % c[0]) % c[0], a = r[m] = l[m] + c[0];
		}
		else if (u == 3)
		{
			scanf(" %s", c);
			for (int i = 1; i <= m; i++)
				if (!strcmp(c, e[i]))
					printf("%d\n", l[i]);
		}
		else
		{
			int f = 1;
			scanf("%lld", &v);
			for (int i = 1; i <= m; i++)
				if (l[i] <= v && v < r[i])
					printf("%s\n", e[i]), f = 0, i = m + 1;
			if (f)
				printf("ERR\n");
		}
	}
	return 0;
}
