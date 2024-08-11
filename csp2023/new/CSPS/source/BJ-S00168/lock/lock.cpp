# include <bits/stdc++.h>
using namespace std;

int n, a[10][10], t[10];

bool check()
{
	for (int p = 2; p <= n; p++)
	{
		bool chk = 0;
		int cnt = 0;
		for (int i = 1; i <= 5; i++)
		{
			if (t[i] != a[p][i]) cnt++;
		}
		if (cnt == 1)
		{
			chk = 1;
		}
		else if (cnt == 2)
		{
			for (int i = 1; i <= 4; i++)
			{
				for (int j = 1; j <= 9; j++)
				{
					bool f = 0;
					a[p][i] = (a[p][i] + j) % 10;
					a[p][i + 1] = (a[p][i + 1] + j) % 10;
					for (int k = 1; k <= 5; k++)
						if (a[p][k] != t[k]) f = 1;
					a[p][i] = (a[p][i] + 10 - j) % 10;
					a[p][i + 1] = (a[p][i + 1] + 10 - j) % 10;
					if (f == 0)
					{
						chk = 1;
						break;
					}
				}
			}
		}
		else chk = 0;
		if (chk == 0)
			return 0;
	}
	return 1;
}

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 5; j++)
			cin >> a[i][j];
	}
	if (n == 1)
	{
		cout << 81 << endl;
	}
	int cnt = 0;
	for (int i = 1; i <= 5; i++) t[i] = a[1][i];
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			t[i] = (t[i] + j) % 10;
			if (check())
			{
				cnt++;
			}
			t[i] = a[1][i];
		}
	}
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			t[i] = (t[i] + j) % 10;
			t[i + 1] = (t[i + 1] + j) % 10;
			if (check())
			{
				cnt++;
			}
			t[i] = a[1][i];
			t[i + 1] = a[1][i + 1];
		}
	}
	cout << cnt << endl;
	return 0;
}
