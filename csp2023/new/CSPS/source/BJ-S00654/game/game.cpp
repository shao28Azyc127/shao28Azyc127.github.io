/*
I believe that I am who I am
Unique and unstoppable
Not afraid of loneliness
Not afraid of wind and waves
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e6, V = 26;

int n;
int a[N + 5];

int match[N + 5], cnt[N + 5];
int lst[N + 5][V + 5];

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		char c;
		scanf(" %c", &c);
		a[i] = c - 'a' + 1;
	}

	for (int i = 1; i <= n; i++)
	{
		match[i] = lst[i - 1][a[i]];
		if (match[i])
		{
			cnt[i] = cnt[match[i] - 1] + 1;
			for (int j = 1; j <= V; j++)
				lst[i][j] = lst[match[i] - 1][j];
			lst[i][a[i]] = i;
		}
		lst[i][a[i]] = i;
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += cnt[i];
	printf("%lld\n", ans);
	return 0;
}