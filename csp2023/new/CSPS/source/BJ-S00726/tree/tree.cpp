#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= n; i++)

const int N = 1e5 + 5;
int n, ans;
long long a[N];
int b[N], c[N], u[N], v[N];
int ts(int x)
{
	int sum = x;
	long long gd = 0;
	while (gd < a[x])
	{
		sum++;
		gd += max(1LL * b[x] + 1LL * sum * c[x], 1LL * 1);
	}
	return sum;
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	rep(i, n)
	{
		cin >> a[i] >> b[i] >> c[i];
	}
	bool B = true;
	rep(i, n - 1)
	{
		cin >> u[i] >> v[i];
		if (u[i] + 1 != v[i])
		{
			B = false;
		}
	}
	if (B)
	{
		for (int i = 1; i <= n; i++)
		{
			ans = max(ans, ts(i));
		}
		cout << ans << endl;
		return 0;
	}
	
	return 0;
}