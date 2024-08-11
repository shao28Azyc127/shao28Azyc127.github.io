#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5+10;
const long long inf = 4e18;
int n, lst;
long long a[NR];
int b[NR], c[NR], d[NR], t[NR];
vector<int> g[NR];

inline long long sum(int b, int c, int l, int r)
{
	register int len = r - l + 1;
	if (len < 1) return 0;
	if (b + 1ll * l * c < 1) return len; 
	if (b + 1ll * r * c < 1) return sum(b, c, l, (b - 1) / (-c)) + (r - (b - 1) / (-c));
	register long long k = ((1ll * (l + r) * len) >> 1), C = 1ll * b * len;
	if (c > (inf - C) / k) return inf;
	return k * c + C; 
}

inline void dfs(int x, int fa)
{
	for (register int i(0); i < g[x].size(); ++i)
	{
		register int y = g[x][i];
		if (fa == y) continue;
		dfs(y, x);
		d[x] = min(d[x], d[y] - 1);
	}
}

inline bool check(int x)
{
	register int mx = 0, mn = 1e9;
	for (register int i(1); i <= n; ++i)
	{
		register int l(1), r(x);
		if (lst < x) l = d[i];
		else r = d[i];
		while (l <= r)
		{
			register int mid = (l + r) >> 1;
			if (b[i] + c[i] * x >= a[i] || sum(b[i], c[i], mid, x) >= a[i]) 
				l = mid + 1, d[i] = mid;
			else r = mid - 1;
		}
		mx = max(mx, d[i]);
		mn = min(mn, d[i]);
	}
	if (n > mx) return false;
	if (n < mn) return true;
	dfs(1, 0);
	memcpy(t, d, sizeof(t));
	sort(t + 1, t + n + 1);
	for (register int i(1); i <= n; ++i)
		if (i > t[i]) return false;
	return true;
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);	
	scanf("%d", &n);
	register bool flag = true;
	for (register int i(1); i <= n; ++i)
		scanf("%lld%d%d", a + i, b + i, c + i), flag &= (!c[i]);
	for (register int i(1); i < n; ++i)
	{
		register int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	register int l = 1, r = 1e9, ans = 0;
	while (l <= r)
	{
		register int mid = (l + r) >> 1;
		if (check(mid))
			r = mid - 1, ans = mid;
		else l = mid + 1;
		lst = mid;
	}
	printf("%d\n", ans);
	return 0;
}