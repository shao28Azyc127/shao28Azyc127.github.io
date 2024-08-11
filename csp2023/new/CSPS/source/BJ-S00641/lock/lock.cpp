#include <bits/stdc++.h>

using namespace std;

long long n, a[10], b[10], c[10], d[10], e[10], ha[10][10][10][10][10][10], cnt, k;

int h1[1000];
int h2[1000];

int p(int x, int y)
{
	if (x + y < 0) return 10 + x + y;
	else if (x + y > 9) return x + y - 10;
	else return x + y;
}

int main()
{
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	for (int i = 1; i <= 9; i ++ )
	{
		h1[++ k] = i;
		h2[k] = 0;
		h1[++ k] = 0;
		h2[k] = i;
		h1[++ k] = i;
		h2[k] = i;
		//~ h1[++ k] = -i;
		//~ h2[k] = i;
		//~ h1[++ k] = i;
		//~ h2[k] = -i;
		h1[++ k] = -i;
		h2[k] = -i;
	}
	cin >> n;
	for (int i = 1; i <= n; i ++ )
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
	}
	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j <= k; j ++ )
		{
			//~ cout << h1[j] << ' ';
			//~ cout << h2[j] << endl;
			if (ha[i][p(a[i], h1[j])][p(b[i], h2[j])][c[i]][d[i]][e[i]] == 0)
			{
				ha[i][p(a[i], h1[j])][p(b[i], h2[j])][c[i]][d[i]][e[i]] = 1;
				//~ cout << p(a[i], h1[j]) << ' ' << p(b[i], h2[j]) << ' ' << c[i] << ' ' << d[i] << ' ' << e[i] << endl;
			}
			if (ha[i][a[i]][p(b[i], h1[j])][p(c[i], h2[j])][d[i]][e[i]] == 0)
			{
				ha[i][a[i]][p(b[i], h1[j])][p(c[i], h2[j])][d[i]][e[i]] = 1;
				//~ cout << a[i] << ' ' << p(b[i], h1[j]) << ' ' << p(c[i], h2[j]) << ' ' << d[i] << ' ' << e[i] << endl;
			}
			if (ha[i][a[i]][b[i]][p(c[i], h1[j])][p(d[i], h2[j])][e[i]] == 0)
			{
				ha[i][a[i]][b[i]][p(c[i], h1[j])][p(d[i], h2[j])][e[i]] = 1;
				//~ cout << a[i] << ' ' << b[i] << ' ' << p(c[i], h1[j]) << ' ' << p(d[i], h2[j]) << ' ' << e[i] << endl;
			}
			if (ha[i][a[i]][b[i]][c[i]][p(d[i], h1[j])][p(e[i], h2[j])] == 0)
			{
				ha[i][a[i]][b[i]][c[i]][p(d[i], h1[j])][p(e[i], h2[j])] = 1;
				//~ cout << a[i] << ' ' << b[i] << ' ' << c[i] << ' ' << p(d[i], h1[j]) << ' ' << p(e[i], h2[j]) << endl;
			}
		}
	}
	for (int i = 0; i <= 9; i ++ )
	{
		for (int j = 0; j <= 9; j ++ )
		{
			for (int k = 0; k <= 9; k ++ )
			{
				for (int l = 0; l <= 9; l ++ )
				{
					for (int m = 0; m <= 9; m ++ )
					{
						for (int o = 1; o <= n; o ++ )
						{
							if (ha[o][i][j][k][l][m] == 0)
							{
								break;
							}
							if (o == n) cnt ++;
						}
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}

