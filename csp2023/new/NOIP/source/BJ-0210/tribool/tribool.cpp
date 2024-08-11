#include <bits/stdc++.h>

using namespace std;

int n, m;
int val[11], tmp[11];
int ans = 10000000;

struct opt
{
	int type, x, y;
}opt[11];

int simulate()
{
	for (int i = 1; i <= n; i++) tmp[i] = val[i];
	for (int i = 1; i <= m; i++)
	{
		int cx = opt[i].x, cy = opt[i].y, mode = opt[i].type;
		if (mode == 1) tmp[cx] = 51;
		else if (mode == 2) tmp[cx] = 49;
		else if (mode == 3) tmp[cx] = 50;
		else if (mode == 4) tmp[cx] = tmp[cy];
		else tmp[cx] = 100 - tmp[cy];
	}
	int uc = 0;
	for (int i = 1; i <= n; i++)
	{
//		cerr << tmp[i] << ' ' << val[i] << endl;
		if (tmp[i] != val[i]) 
		{
			return 100000000;
		}
		else if (tmp[i] == 50) uc++;
	}
	return uc;
}

void DFS(int cur)
{
	if (cur == n)
	{
		int cura = simulate();
//			cerr << endl;
//		cerr << cura << endl;
		ans = min(ans, cura);
		return;
	}
	for (int i = 49; i <= 51; i++)
	{
		val[cur + 1] = i;
		DFS(cur + 1);
	}
}

void Solve()
{
	string mode;
	cin >> n >> m;
	ans = 10000000;
	for (int i = 1; i <= n; i++) val[i] = 932045;
	for (int i = 1; i <= m; i++)
	{	
		cin >> mode;
		if (mode[0] == 'T') cin >> opt[i].x, opt[i].type = 1;
		else if (mode[0] == 'F') cin >> opt[i].x, opt[i].type = 2;
		else if (mode[0] == 'U') cin >> opt[i].x, opt[i].type = 3;
		else if (mode[0] == '+') cin >> opt[i].x >> opt[i].y, opt[i].type = 4;
		else cin >> opt[i].x >> opt[i].y, opt[i].type = 5;
	}
	DFS(0);
	cout << ans << endl;
	cerr << endl;
	return;
}

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) Solve();
	return 0;
}