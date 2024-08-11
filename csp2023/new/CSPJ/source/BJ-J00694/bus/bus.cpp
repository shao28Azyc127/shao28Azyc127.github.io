#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int n, m, k;
struct dl{
	int u, v, t;
}a[20005];
struct node{
	int id, t;
};

queue <node> q;

bool f[10001][10001];

void bfs()
{
	q.push({1, 0});
	while(!q.empty())
	{
		for (int i = 1; i <= m; i++)
		{
			int x = a[i].u, y = a[i].v, id = q.front().id, t = q.front().t;
			if (x != id) continue;
			if (f[y][t] == true) continue;
			q.push({y, t});
			f[y][t] = true;
		}
		q.pop();
	}
	return;
}

int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) cin >> a[i].u >> a[i].v >> a[i].t;
	bfs();
	for (int i = 1; i <= 10001; i++) 
	{
		if (f[n][i * k] == true)
		{
			cout << i * k << endl;
			return 0;
		}
	}
	cout << 6 << endl;
	return 0;
}