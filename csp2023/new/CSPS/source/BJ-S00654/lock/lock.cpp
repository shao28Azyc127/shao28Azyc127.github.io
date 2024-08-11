/*
We decide.
We choose.
As we decide and choose, so are our lives formed.
In the end, forming our own destiny is what ambition is about.
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 8, V = 1e5;

int n;
int cnt[V + 5];
int a[10], b[10];

int vis[V + 5], dfn;
void cpy()
{
	for (int i = 1; i <= 5; i++)
		b[i] = a[i];
	return ;
}
int calc()
{
	int res = 0;
	for (int i = 1; i <= 5; i++)
		res = res * 10 + b[i];
	return res;
}

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);

	scanf("%d", &n);
	for (int T = 1; T <= n; T++)
	{
		for (int i = 1; i <= 5; i++)
			scanf("%d", a + i);

		dfn++;
		for (int i = 1; i <= 5; i++)
		{
			for (int x = 1; x <= 9; x++)
			{
				cpy();
				b[i] = (b[i] + x) % 10;
				vis[calc()] = dfn;

				cpy();
				b[i] = (b[i] + 10 - x) % 10;
				vis[calc()] = dfn;
			}
		}

		for (int i = 1; i < 5; i++)
		{
			for (int x = 1; x <= 9; x++)
			{
				cpy();
				b[i] = (b[i] + x) % 10;
				b[i + 1] = (b[i + 1] + x) % 10;
				vis[calc()] = dfn;

				cpy();
				b[i] = (b[i] + 10 - x) % 10;
				b[i + 1] = (b[i + 1] + 10 - x) % 10;
				vis[calc()] = dfn;
			}
		}

		for (int i = 0; i < V; i++)
			cnt[i] += (vis[i] == dfn);
	}

	int ans = 0;
	for (int i = 0; i < V; i++)
		ans += (cnt[i] == n);
	printf("%d\n", ans);
	return 0;
}