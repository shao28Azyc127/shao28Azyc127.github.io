#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 3;
const int M = 333;
int n, m;
int a[N][M], mn[N], mx[N];
char s[N];
bool ch(int x)
{
	for(int i = 1; i <= n; i ++) if(mx[i] <= mn[x] && i != x) return 0;
	return 1;
}
int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	if(m == 1)
	{
		int minn, minx = 10101;
		for(int i = 1; i <= n; i ++)
		{
			char c;
			cin >> c;
			s[i] = c;
			if(c < minx)
			{
				minx = c;
				minn = i;
			}
		}
		for(int i = 1; i <= n; i ++)
		{
			if(s[i] == minx) cout << '1';
			else cout << '0';
		}
		cout << endl;
		return 0;
	}
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= m; j ++)
		{
			char c;
			cin >> c;
			a[i][j] = c - 'a';
		}
	}
	int mxn = 1010101;
	for(int i = 1; i <= n; i ++)
	{
		mn[i] = min(a[i][1] * 26 + a[i][2], a[i][2] * 26 + a[i][1]);
		mx[i] = max(a[i][1] * 26 + a[i][2], a[i][2] * 26 + a[i][1]);
		mxn = min(mxn, mx[i]);
	}
	for(int i = 1; i <= n; i ++)
	{
		if(ch(i)) cout << '1';
		else cout << '0';
	}
	cout << endl;
	return 0;
}