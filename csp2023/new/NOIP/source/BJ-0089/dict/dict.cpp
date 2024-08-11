#include<bits/stdc++.h>

using namespace std;

const int N = 3e3 + 7;

int n, m, f[N], g[N];
char tmp[N];
string str[N], mx[N], pre, suf;

signed main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> tmp;
		sort(tmp, tmp + m, greater<char>());
		mx[i] = tmp;
		sort(tmp, tmp + m);
		str[i] = tmp;
	}
	f[1] = 1; g[n] = 1;
	pre = mx[1]; suf = mx[n];
	for(int i = 2; i <= n; i++)
	{
		f[i] = str[i] < pre;
		pre = (pre < mx[i] ? pre : mx[i]);
	}
	for(int i = n - 1; i >= 1; i--)
	{
		g[i] = str[i] < suf;
		suf = (suf < mx[i] ? suf : mx[i]);
	}
	for(int i = 1; i <= n; i++)
		cout << (f[i] & g[i]);
	cout << endl;
	return 0;
}
