#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= n; i++)

int n;
int a[10][10];
int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	rep(i, n)
	{
		rep(j, 5)
		{
			cin >> a[i][j];
		}
	}
	if (n == 1)
	{
		cout << "81" << endl;
		return 0;
	}
	if (n == 2)
	{
		int cnt = 0;
		rep(i, 5)
		{
			if (a[1][i] != a[2][i]) cnt++;
		}
		if (cnt == 1)
		{
			cout << "10" << endl;
			return 0;
		}
	}
	
	return 0;
}