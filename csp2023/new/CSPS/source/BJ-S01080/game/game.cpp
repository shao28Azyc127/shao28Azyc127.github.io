#include<bits/stdc++.h>

using namespace std;

const int N = 2e6 + 7;

int n, dp[N], near[N], tmp[26], tr[N];
long long ans;
char ch[N];

int main()
{
	#ifndef DEBUG
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	#endif
	scanf("%d%s", &n, &ch);
	for(int i = 0; i < 26; i++)
		tmp[i] = -1;
	for(int i = 0; i < n; i++)
	{
		tr[i] = -1;
		near[i] = tmp[ch[i] - 'a'];
		tmp[ch[i] - 'a'] = i;
	}
	for(int i = 1; i < n; i++)
	{
		int a = near[i], b = i - 1;
		while(a >= 0 && b >= 0)
		{
			while(b > a) b = tr[b] - 1;
			if(b == a)
			{
				if(a)
					dp[i] = 1 + dp[a - 1];
				else dp[i] = 1;
				tr[i] = a;
				ans += dp[i];
				break;
			}
			a = near[a];
		}
	}
	/*
	for(int i = 0; i < n; i++)
		printf("%d %d %d\n", dp[i], tr[i], near[i]);
	*/
	printf("%lld\n", ans);
	return 0;
}
