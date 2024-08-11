#include <bits/stdc++.h>

using namespace std;

char s[110005];
int to[110005], tp[110005], vis[110005];
int tag[110005];

int main()
{
	freopen("tribool.in", "r", stdin);
	freopen("tribool.out", "w", stdout);
	int c, t, n, m, i, j, p, u, v, ans;
	scanf("%d%d", &c, &t);
	while(t--)
	{
		ans = 0;
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n + 2; i++)
		{
			to[i] = i;
			tp[i] = vis[i] = tag[i] = 0;
		}
		tp[n + 2] = 1;
		for(i = 1; i <= m; i++)
		{
			scanf("%s%d", s + 1, &u);
			if(s[1] == '+' || s[1] == '-')
			{
				scanf("%d", &v);
				to[u] = to[v];
				tp[u] = tp[v] ^ (s[1] == '-');
			}
			else
			{
				to[u] = n + 1 + (s[1] == 'U');
				tp[u] = 0;
			}
		}
		for(i = 1; i <= n + 2; i++)
		{
			j = i;
			while(!vis[j])
			{
				vis[j] = i;
				j = to[j];
			}
			if(vis[j] != i)
			{
				tag[i] = tag[vis[j]];
				continue;
			}
			p = j;
			tag[i] = 0;
			do
			{
				tag[i] ^= tp[p];
				p = to[p];
			}
			while(p != j);
		}
		for(i = 1; i <= n; i++)
			ans += tag[i];
		printf("%d\n", ans);
	}
	return 0;
}