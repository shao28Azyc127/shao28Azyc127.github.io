#include <cstdio>

using namespace std;

int cnt[100005];
int a[6];

int main()
{	
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
	int n, i, j, k, l, v, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= 5; j++)
			scanf("%d", a + j);
		for(j = 1; j <= 5; j++)
			for(k = 1; k <= 9; k++)
			{
				v = 0;
				for(l = 1; l <= 5; l++)
					v = 10 * v + ((a[l] + (j == l) * k) % 10);
				cnt[v]++;
				if(j == 5)
					continue;
				v = 0;
				for(l = 1; l <= 5; l++)
					v = 10 * v + ((a[l] + (j == l || j + 1 == l) * k) % 10);
				cnt[v]++;
			}
	}
	for(i = 0; i <= 100000; i++)
		if(cnt[i] == n)
			ans++;
	printf("%d\n", ans);
	return 0;
}