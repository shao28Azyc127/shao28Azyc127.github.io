#include <bits/stdc++.h>
using namespace std;

const int NR = 10;
int n, a[NR][6], b[6], cnt;

void dfs(int p)
{
	if (p > 5)
	{
		for (int i = 1; i <= n; i++)
		{
			int x = 0, y = 0;
			for (int j = 1; j <= 5; j++)
				if (a[i][j] != b[j] && !x) x = j;
				else if (a[i][j] != b[j] && !y) y = j;
				else if (a[i][j] != b[j]) return;
			if (!x || (y && y != x + 1)) return;
			if (y && (b[y] - a[i][y] + 10) % 10 != (b[x] - a[i][x] + 10) % 10) return;
		}
		cnt++;
		return;
	}
	for (int i = 0; i <= 9; i++)
		b[p] = i, dfs(p + 1);
}

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 5; j++)
			scanf("%d", a[i] + j);
	dfs(1);
	cout << cnt << endl;
	return 0;
}