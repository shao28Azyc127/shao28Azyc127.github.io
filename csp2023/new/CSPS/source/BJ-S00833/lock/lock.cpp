#include <bits/stdc++.h>
using namespace std;

int n;
int a[10][6];
int cal[200000];
int tmp[10];
int ans;

void solve1()
{
	int ttt = 100000 + a[1][1] + a[1][2] * 10 + a[1][3] * 100 + a[1][4] * 1000 + a[1][5] * 10000;
	for (int i = 0; i <= 9; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (i == a[1][j]) continue;
			int kkk = ttt;
			ttt = ttt - a[1][j] * tmp[j] + i * tmp[j];
			cal[ttt]++;
			ttt = kkk;
			//cout << ttt << '\n';
		}
	}
	
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			int x = j, y = j + 1;
			int kkk = ttt;
			int t1 = (a[1][x] + i) % 10, t2 = (a[1][y] + i) % 10;
			ttt = ttt - a[1][x] * tmp[x] - a[1][y] * tmp[y] + t1 * tmp[x] + t2 * tmp[y];
			cal[ttt]++;
			ttt = kkk;
		}
	}
	
	for (int i = 100000; i <= 199999; i++)
		if (cal[i]) ans++;
	cout << ans << '\n';
}

void solve2()
{

	for (int k = 1; k <= n; k++)
	{
		int ttt = 100000 + a[k][1] + a[k][2] * 10 + a[k][3] * 100 + a[k][4] * 1000 + a[k][5] * 10000;
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 1; j <= 5; j++)
			{
				if (i == a[k][j]) continue;
				int kkk = ttt;
				ttt = ttt - a[k][j] * tmp[j] + i * tmp[j];
				cal[ttt]++;
				ttt = kkk;
				//cout << ttt << '\n';
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		int ttt = 100000 + a[k][1] + a[k][2] * 10 + a[k][3] * 100 + a[k][4] * 1000 + a[k][5] * 10000;
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 4; j++)
			{
				int x = j, y = j + 1;
				int kkk = ttt;
				int t1 = (a[k][x] + i) % 10, t2 = (a[k][y] + i) % 10;
				ttt = ttt - a[k][x] * tmp[x] - a[k][y] * tmp[y] + t1 * tmp[x] + t2 * tmp[y];
				cal[ttt]++;
				ttt = kkk;
			}
		}
	}
	for (int i = 100000; i <= 199999; i++)
		if (cal[i] == n) ans++;
	cout << ans << '\n';
}


int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= 5; j++)
			cin >> a[i][j];
	
	tmp[1] = 1;
	for (int i = 2; i <= 5; i++)
		tmp[i] = 10 * tmp[i - 1];

	if (n == 1) solve1();
	else if (n == 2) solve2();
	else solve2();
	return 0;
}