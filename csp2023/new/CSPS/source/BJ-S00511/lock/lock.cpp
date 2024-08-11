#include <bits/stdc++.h>
using namespace std;
#define int long long
int read();
const int N = 20;
int a[N][N], n, t[N], ans;
void dfs(int step);
bool check();

signed main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	n = read();
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= 5;j++)
			a[i][j] = read();
	dfs(1);
	cout << ans;
	return 0;
}

bool check()
{
	for (int i = 1;i <= n;i++)
	{
		int x = 0, y = 0, z = 0;
		for (int j = 1;j <= 5;j++)
			if (a[i][j] != t[j])
			{
				z++;
				if (z == 1) x = j;
				if (z == 2) y = j;
				if (z == 3) return false;
			}
		if (z == 0) return false;
		if (z == 1) continue;
		if (y - x != 1) return false;
		bool flag = false;
		for (int k = 0;k <= 9;k++)
			if ((t[x] + k) % 10 == a[i][x] && (t[x + 1] + k) % 10 == a[i][x + 1]) flag = true;
		if (!flag) return false;
	}
	return true;
}

void dfs(int step)
{
	if (step == 6)
	{
		ans += check();
		return;
	}
	for (int i = 0;i <= 9;i++) t[step] = i, dfs(step + 1);
}

int read()
{
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	int sum = 0;
	while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - '0', ch = getchar();
	return sum;
}
