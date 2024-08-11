#include <bits/stdc++.h>

using namespace std;

int mx[3005], mn[3005];
char s[3005], t[3005];

int main()
{
	freopen("dict.in", "r", stdin);
	freopen("dict.out", "w", stdout);
	int n, m, i, j, x, y;
	scanf("%d%d", &n, &m);
	x = 26;
	y = 0;
	for(i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		mn[i] = 26;
		for(j = 1; j <= m; j++)
		{
			mn[i] = min(mn[i], s[j] - 'a');
			mx[i] = max(mx[i], s[j] - 'a');
		}
		if(mx[i] < x)
		{
			x = mx[i];
			y = 0;
		}
		y += (mx[i] == x);
	}
	for(i = 1; i <= n; i++)
		t[i] = (mn[i] < x || (mn[i] == x && mx[i] == x && y == 1)) + '0';
	printf("%s\n", t + 1);
	return 0;
}