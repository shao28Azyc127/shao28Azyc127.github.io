#include <cstdio>
const int NX = 200005;
int c = 0, t = 0, n = 0, m = 0, pt = 0, pf = 0, pu = 0, a[NX] = {};
int bf[NX] = {};
char v = 0;
inline int ngt(int x)
{
	return x == pt ? pf : x == pf ? pt : x == pu ? pu : x > n ? x - n : x + n;
}
inline int bfnd(int x)
{
	if (bf[x] == bf[bf[x]])
		return bf[x];
	else
		return bf[x] = bfnd(bf[x]);
}
inline int bcnn(int x, int y)
{
	return bfnd(x) == bfnd(y);
}
inline void bunn(int x, int y)
{
	if (!bcnn(x, y))
		bf[bfnd(x)] = bfnd(y);
}
int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
	{
		int s = 0;
		scanf("%d%d", &n, &m);
		pt = n * 2 + 1, pf = n * 2 + 2, pu = n * 2 + 3;
		for (int i = 1; i <= n * 2 + 3; i++)
			 a[i] = bf[i] = i;
		for (int i = 1; i <= m; i++)
		{
			int x = 0, y = 0;
			scanf(" %c", &v);
			if (v == '+' || v == '-')
				scanf("%d%d", &x, &y);
			else
				scanf("%d", &x);
			if (v == 'T')
				a[x] = pt;
			else if (v == 'F')
				a[x] = pf;
			else if (v == 'U')
				a[x] = pu;
			else if (v == '+')
				a[x] = a[y];
			else if (v == '-')
				a[x] = ngt(a[y]);
		}
		for (int i = 1; i <= n; i++)
			bunn(i, a[i]), bunn(ngt(i), ngt(a[i]));
		for (int i = 1; i <= n; i++)
			if (bcnn(i, ngt(i)) || bcnn(i, pu))
				s++;
		printf("%d\n", s);
	}
	return 0;
}
