#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;

struct node
{
	long long a, b, c;
	vector<int> v;
	int st;
}a[NR];

int n;

bool vis[NR];
long long day;
long long ans = 1e18 + 1;

bool check(int day)
{
	for (int i = 1; i <= n; i++)
	{
		long long tmp = 0;
		int st = a[i].st;
		if (!vis[i]) return false;
		for (int j = st; j <= day; j++)
		{
			tmp = tmp + max(a[i].b + a[i].c * j, 1ll * 1);
		}
		if (tmp < a[i].a) return false; 
	}
	return true;
}

void solve(int u)
{
	vis[u] = 1;
	a[u].st = ++day;
	for (auto ed : a[u].v)
	{
		if (vis[ed]) continue;
		solve(ed);
	}
	if (check(day))
	{
		ans = min(ans, day);	
	}
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b >> a[i].c;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].v.push_back(v);
		a[v].v.push_back(u);
	}
	//solve(1);
	cout << n + 1 << '\n';
	return 0;
}