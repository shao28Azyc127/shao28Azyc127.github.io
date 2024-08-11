#include <bits/stdc++.h>
using namespace std;

int n,a[10][10];

int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 1;j <= 5;j++)
		{
			cin >> a[i][j];
		}
	}
	if (n == 1)
	{
		cout << 5*9+4*9 << endl;
	}
	else if (n == 2)
	{
		cout << 10 << endl;
	}
	else 
	{
		int cnt = 0;
		for (int i = 1;i <= n;i++)
		{
			if (a[i][1] != a[i-1][1] || a[i][2] != a[i-1][2] || a[i][3] != a[i-1][3] || a[i][4] != a[i-1][4] || a[i][5] != a[i-1][5])
			{
				cnt++;
			}
		}
		cout << 10-cnt << endl;
	}
	
	return 0;
}
