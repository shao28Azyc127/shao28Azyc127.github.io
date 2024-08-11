#include <bits/stdc++.h>
using namespace std;

int a[100005];
int s[100005];
int p[100005];
int pp(int x, int y)
{
	if (x % y == 0)
	{
		return x / y;
	}
	else
	{
		return x / y + 1;
	}
}

struct st
{
	int l, c;
}f[100005];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	for (int i = 2; i <= n; i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		f[i].l = pp(s[i], d) * d;
	}
	int minn = 1e9;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		minn = min(minn, p[i]);
	}
//	cout << minn << endl;
	if (minn == p[1])
	{
		cout << f[n].l / d * minn << endl;
//		cout << "111" << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++)
	{
		int minn = 1e9;
		for (int j = 1; j <= i - 1; j++)
		{
			int h = (f[i].l - f[j].l) / d * p[j]; 
			minn = min(minn, f[j].c + h);
		}
		f[i].c = minn;
//		cout << f[i].c << endl;
	}
	cout << f[n].c << endl;
	return 0;
}
