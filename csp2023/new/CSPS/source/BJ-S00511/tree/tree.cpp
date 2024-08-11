#include <bits/stdc++.h>
using namespace std;
#define int long long
int read();
const int N = 1e5 + 5;
vector<int> v[N];
int n, a[N], b[N], c[N], ans = 1e9 + 9, s[N], top, sum[N];
int cal();
int max(int a, int b) { return a > b ? a : b; }

signed main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	int x, y;
	for (int i = 1;i <= n;i++) a[i] = read(), b[i] = read(), c[i] = read();
	for (int i = 1;i < n;i++) x = read(), y = read(), s[++top] = y;
	cout << cal();
	return 0;
}

int cal()
{
	for (int i = 1;i <= n;i++) sum[i] = 0;
	for (int i = 1;i <= 5000;i++)
	{
		for (int j = 1;j <= min(i, top);j++) sum[s[j]] += max(b[s[j]] + i * c[s[j]], 1);
		bool flag = true;
		for (int j = 1;j <= n;j++)
			if (sum[j] < a[j]) flag = false;
		if (flag) return i;
	}
	return 5000;
}

int read()
{
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	int sum = 0;
	while (ch >= '0' && ch <= '9') sum = sum * 10 + ch - '0', ch = getchar();
	return sum;
}
