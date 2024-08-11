#include <bits/stdc++.h>
using namespace std;
#define int long long
int read();
const int N = 8003;
int n, a[N], t[N];
bool f[N][N];

signed main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n;
	char ch;
	for (int i = 1;i <= n;i++) cin >> ch, a[i] = ch, t[i] = 1e9;
	int ans = 0;
	for (int i = 1;i < n;i++)
		if (a[i] == a[i + 1]) f[i][i + 1] = true, ans += f[i][i + 1], t[i + 1] = i;
	for (int len = 3;len <= n;len++)
		for (int i = 1;i <= n - len + 1;i++)
		{
			int j = i + len - 1;
			if (a[i] == a[j]) f[i][j] |= f[i + 1][j - 1];
			if (a[i] == a[i + 1]) f[i][j] |= f[i + 2][j];
			if (a[j] == a[j - 1]) f[i][j] |= f[i][j - 2];
			int tmp = t[j];
			if (tmp != 1e9 && f[i][tmp - 1]) f[i][j] = true;
			ans += f[i][j];
			if (f[i][j]) t[j] = min(i, t[j]);
		}
	cout << ans;
	return 0;
}

int read()
{
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	int sum = 0;
	while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - '0', ch = getchar();
	return sum;
}
