#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;
int v[N], a[N];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, d;
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n - 1; i++)
		scanf("%d", v + i);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	long long ans = 0, run = 0;
	for (int i = 1; i < n; )
	{
		long long dd = 0;
		int j = i;
		while (a[j] >= a[i] && j < n)
		{
			dd += v[j];
			j++;
		}
		long long oil = ceil(1.0 * (dd - run) / d);
		ans += 1ll * oil * a[i];
		run = oil * d + run - dd;
	//	printf("i:%d j:%d dd:%d run:%d oil:%d\n", i, j, dd, run, oil);
		i = j;
	}
	printf("%lld\n", ans);
	return 0;
}