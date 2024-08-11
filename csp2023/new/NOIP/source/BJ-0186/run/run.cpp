#include <cstdio>
#include <cstdlib>
using namespace std;

int c, t;
int n, m, k, d;
int x[100010], y[100010], v[100010];

void solve()
{
	scanf("%d%d%d%d", &n, &m, &k, &d);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d", x+i, y+i, v+i);
	long long ans=0;
	for (int i=1;i<=m;i++)
	{
		if (y[i]*d<v[i] && y[i]<=k)
			ans+=v[i]-y[i]*d;
	}
	printf("%lld\n", ans);
}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	scanf("%d%d", &c, &t);
	while (t--)
		solve();
	return 0;
}
