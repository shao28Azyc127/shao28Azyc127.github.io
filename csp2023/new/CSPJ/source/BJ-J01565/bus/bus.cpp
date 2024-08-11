#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("bus.in");
ofstream cout("bus.out");

long long n, k, ans = -1;
int a[10010][10010];
bool b[10010][10010];

void dfs(int x, long long t)
{
	if (x == n && t % k == 0)
	{
		if (ans == -1)
			ans = t;
		else
			ans = min(ans, t);
		return ;
	}
	int c;
	for (int i = 1; i <= n; i++)
		if (b[x][i] && t >= a[x][i])
		{
			c = a[x][i];
			a[x][i] = 0;
			dfs(i, t + 1);
			a[x][i] = c;
		}
}

int main()
{
	int m;
	int u, v;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> u >> v >> a[u][v];
		b[u][v] = 1;
	}
	if (n <= 10)
	{
		dfs(1, k);
		cout << ans;
	}
	else
		cout << -1;
	return 0;
}