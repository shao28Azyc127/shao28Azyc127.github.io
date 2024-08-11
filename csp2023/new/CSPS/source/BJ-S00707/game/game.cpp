#include <cstdio>

using namespace std;

char s[3000005];
int dp[3000005], last[3000005];

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, i, p;
	long long ans = 0;
	scanf("%d", &n);
	scanf("%s", s + 1);
	p = 0;
	for(i = 1; i <= n; i++)
	{
		p = i - 1;
		while(p && s[p] != s[i])
			p = last[p];
		if(p)
			ans += (dp[i] = dp[--p] + 1);
		last[i] = p;
	}
	printf("%lld\n", ans);
	return 0;
}