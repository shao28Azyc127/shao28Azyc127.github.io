#include <bits/stdc++.h>
using namespace std;

int a[605][605];
int n, m, k, ans;
void ctt(int cur)
{
	queue <int> q;
	q.push(cur);
	long long cnt = k;
	while (!q.empty())
	{
		int k = q.front();
		q.pop();
		for (int i = 1; i <= n; i++)
		{
//			if (i == 3)
//			{
//				cout << a[k][i] << " " << cnt << " " << k << endl;
//			}
			if (a[k][i] != 1e9 && cnt >= a[k][i] && i != k)
			{
//				cout << "000" << k << " " << i << endl;
//				cout << "111" << a[k][i] << " " << cnt << endl;
				if (i == n && cnt % k == 0)
				{
					cout << cnt << endl;
					return;
				}
				q.push(i);
//				cout << i << endl;
				cnt++;
			}
		}
	}
	cout << -1 << endl;
	return;
}
int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	int u, v, f;
	cin >> n >> m >> k;
	for (int i = 1; i <= 604; i++)
	{
		for (int j = 1; j <= 604; j++)
		{
			a[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> f;
		a[u][v] = f;
		a[v][u] = f;
	}
	ctt(1);
	return 0;
}
