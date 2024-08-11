#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

const int N = 1e4 + 10;
const int M = 2e4 + 10;

vector<int> can[N];
int a[M];

int ans = INT_MAX;

int n, m, k;

void dfs(int step, int time)
{
//	printf("%d %d\n", step, time);
	if (step == n)
	{
		if (time % k == 0)
			ans = min(ans, time);
		return;
	}
	for (auto next : can[step])
	{
		if (time >= a[step])
			dfs(next, time + 1);
	}
}

int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	int sum = 0;
	int maxn = -1;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d%d", &u, &v, a + i);
		can[u].push_back(v);
		maxn = max(maxn, a[i]);
	}
	maxn = max(maxn, k);
	for (int i = 0; i <= ceil(1.0 * maxn / k); i++)
		dfs(1, i * k);
	if (ans != INT_MAX)
		printf("%d\n", ans);
	else
		printf("-1\n");
	return 0;
}