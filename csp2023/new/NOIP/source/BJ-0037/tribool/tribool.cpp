/*
Sometime too hot the eye of heaven shines,
And often is his gold complexion dimm'd;
And every fair from fair sometime declines,
By chance or nature's changing course untrimm'd;
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5, SZ = N * 5;

int n, m;

int tot;//n + 1: T, n + 2: F, n + 3: U
int id[N + 5];
int fa[SZ + 5], w[SZ + 5];
int find(int x)
{
	if (fa[x] == x)
		return x;
	int f = fa[x];
	fa[x] = find(fa[x]);
	w[x] ^= w[f];
	return fa[x];
}

int ffa[SZ + 5];
int find_new(int x)
{
	if (ffa[x] == x)
		return x;
	ffa[x] = find_new(ffa[x]);
	return ffa[x];
}
void connect(int u, int v)//u -> v
{
	u = find_new(u), v = find_new(v);
	ffa[u] = v;
	return ;
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n + 3; i++)
		fa[i] = id[i] = i, w[i] = 0;
	tot = n + 3;

	for (int i = 1, u, v; i <= m; i++)
	{
		char c;
		scanf(" %c", &c);
		if (c != '+' && c != '-')
		{
			scanf("%d", &u);
			id[u] = ++tot, w[tot] = 0;
			if (c == 'T')
				fa[tot] = n + 1;
			else if (c == 'F')
				fa[tot] = n + 2;
			else
				fa[tot] = n + 3;
		}
		else if (c == '+')
		{
			scanf("%d%d", &u, &v);
			int ori = id[v];//u = v !
			id[u] = ++tot, w[tot] = 0;
			fa[tot] = ori;
		}
		else
		{
			scanf("%d%d", &u, &v);
			int ori = id[v];
			id[u] = ++tot;
			fa[tot] = ori, w[tot] = 1;
		}
	}

	for (int i = 1; i <= n + 3; i++)
	{
		ffa[i] = i;
		ffa[i + n + 3] = i + n + 3;
	}
	for (int i = 1; i <= n; i++)
	{
		find(id[i]);
		int f = fa[id[i]], weight = w[id[i]];

		if (f <= n)
		{
			if (weight == 0)
			{
				connect(i, f);
				connect(i + n + 3, f + n + 3);
			}
			else
			{
				connect(i, f + n + 3);
				connect(i + n + 3, f);
			}
		}
		else
		{
			if (f == n + 1)//T
			{
				if (weight == 0)
				{
					connect(i, n + 1);
					connect(i + n + 3, n + 2);
				}
				else
				{
					connect(i, n + 2);
					connect(i + n + 3, n + 1);
				}
			}
			else if (f == n + 2)
			{
				if (weight == 1)
				{
					connect(i, n + 1);
					connect(i + n + 3, n + 2);
				}
				else
				{
					connect(i, n + 2);
					connect(i + n + 3, n + 1);
				}
			}
			else
			{
				connect(i, i + n + 3);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (find_new(i) == find_new(i + n + 3))
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return ;
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);

	int c, T;
	scanf("%d%d", &c, &T);
	while (T--)
		solve();
	return 0;
}
