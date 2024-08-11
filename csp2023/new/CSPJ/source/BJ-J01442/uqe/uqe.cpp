//By Pr_159
//40~? pts;
#include <bits/stdc++.h>
using namespace std;

int a, b, c, T, M;

void print_frac(int c, int m)
{
	if(m < 0 && c >= 0)
	{
		cout << '-';
		m = -m;
	}
	if(m > 0 && c < 0)
	{
		cout << '-';
		c = -c;
	}
	if(m < 0 && c < 0)
	{
		m = -m;
		c = -c;
	}
	int gcd_mc = __gcd(c, m);
	cout << c / gcd_mc;
	if(m / gcd_mc != 1) cout << '/' << m / gcd_mc;
	//cout << endl;
	return;
}

void solve()
{
	int delta = b * b - 4 * a * c;
	if(delta < 0)
	{
		cout << "NO\n";
		return;
	}
	double sqrt_d = sqrt(delta);
	if(ceil(sqrt_d) == sqrt_d)
	{
		int x = -b + sqrt_d;
		print_frac(x, 2 * a);
	}
	else
	{
		cout << "NO";
	}
	cout << endl;
}

int main()
{
	freopen("uqe.in", "r", stdin);
	freopen("uqe.out", "w", stdout);
	cin >> T >> M;
	while(T--)
	{
		cin >> a >> b >> c;
		solve();
	}
	return 0;
}
/*
5 1000
1 -1 0
-1 -1 -1
1 -2 1
1 5 4
4 4 1
*/
