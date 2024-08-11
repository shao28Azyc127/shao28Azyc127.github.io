#include <bits/stdc++.h>

using namespace std;

int x[500005], y[500005], ox[500005], oy[500005];
int mn[500005][20], mx[500005][20], lg[500005];
char t[500005];
int qmx(int l, int r)
{
	int k = lg[r - l + 1];
	return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
int qmn(int l, int r)
{
	int k = lg[r - l + 1];
	return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}

int main()
{
	freopen("expand.in", "r", stdin);
	freopen("expand.out", "w", stdout);
	int c, n, m, q, Q, i, j, kx, ky, u, v, p, l, r, mid;
	scanf("%d%d%d%d", &c, &n, &m, &Q);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", x + i);
		ox[i] = x[i];
	}
	for(i = 1; i <= m; i++)
	{
		scanf("%d", y + i);
		oy[i] = y[i];
	}
	for(i = 2; i <= max(n, m); i++)
		lg[i] = lg[i >> 1] + 1;
	for(q = 0; q <= Q; q++)
	{
		for(i = 1; i <= n; i++)
			x[i] = ox[i];
		for(i = 1; i <= m; i++)
			y[i] = oy[i];
		if(q)
		{
			scanf("%d%d", &kx, &ky);
			for(i = 1; i <= kx; i++)
			{
				scanf("%d%d", &u, &v);
				x[u] = v;
			}
			for(i = 1; i <= ky; i++)
			{
				scanf("%d%d", &u, &v);
				y[u] = v;
			}
		}
		for(i = n; i >= 1; i--)
		{
			mn[i][0] = mx[i][0] = x[i];
			for(j = 1; j <= lg[n - i + 1]; j++)
			{
				mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
				mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
			}
		}
		p = 1;
		for(i = 1; i <= m; i++)
		{
			if(y[i] <= x[p])
			{
				l = 1;
				r = p - 1;
				while(l <= r)
				{
					mid = (l + r) >> 1;
					if(y[i] <= qmn(mid, p))
						r = mid - 1;
					else
						l = mid + 1;
				}
			}
			else
			{
				l = p + 1;
				r = n;
				while(l <= r)
				{
					mid = (l + r) >> 1;
					if(y[i] <= qmx(p + 1, mid))
						r = mid - 1;
					else
						l = mid + 1;
				}
			}
			p = r;
			if(!p)
				break;
		}
		if(p == n)
		{
			t[q] = '1';
			continue;
		}
		for(i = m; i >= 1; i--)
		{
			mn[i][0] = mx[i][0] = y[i];
			for(j = 1; j <= lg[m - i + 1]; j++)
			{
				mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
				mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
			}
		}
		p = 1;
		for(i = 1; i <= n; i++)
		{
			if(x[i] <= y[p])
			{
				l = 1;
				r = p - 1;
				while(l <= r)
				{
					mid = (l + r) >> 1;
					if(x[i] <= qmn(mid, p))
						r = mid - 1;
					else
						l = mid + 1;
				}
			}
			else
			{
				l = p + 1;
				r = m;
				while(l <= r)
				{
					mid = (l + r) >> 1;
					if(x[i] <= qmx(p + 1, mid))
						r = mid - 1;
					else
						l = mid + 1;
				}
			}
			p = r;
			if(!p)
				break;
		}
		if(p == m)
		{
			t[q] = '1';
			continue;
		}
		t[q] = '0';
	}
	printf("%s\n", t);
	return 0;
}