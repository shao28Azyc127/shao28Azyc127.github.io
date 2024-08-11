#include <bits/stdc++.h>
using namespace std;
int v[100000], vs[100000] = {0}, a[100005];
int main()
{
	int d, n, x, mi, minn;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	x = 0;
	mi = n - 1;
	for(int i = 1; i < n; ++i)
	{
		cin >> v[i];
		vs[i] = vs[i - 1] + v[i];
	}
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	while(mi > 1)
	{
		int m1 = mi;
		minn = a[mi];
		for(int i = m1 - 1; i >= 1; i--)
		{
			if(a[i] < minn)
			{
				minn = a[i];
				mi = i;
			}
		}
		if(m1 == mi)
		{
			x += (vs[m1] - vs[mi - 1]) * minn / d;
			mi--;
		}
		else
			x += (vs[m1] - vs[mi - 1]) * minn / d;
	}
	cout << x << endl;
	return 0;
}