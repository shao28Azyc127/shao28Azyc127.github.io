#include <bits/stdc++.h>
#define F(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
typedef long long LL;
const int mxn = 100010;
int n, lst, nxt[mxn];
LL m, dis[mxn], cst[mxn], ans, tmp = 1000000000;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %lld", &n, &m);
	F(i, 2, n) scanf("%lld", &dis[i]);
	F(i, 2, n) dis[i] += dis[i-1];
	F(i, 1, n)
	{
		scanf("%lld", &cst[i]);
		if (cst[i] < tmp)
		{
			nxt[lst] = i;
			tmp = cst[i];
			lst = i;
		}
	}
	nxt[lst] = n;
	lst = 1; tmp = 0ll;
	while (lst != n)
	{
		int to = nxt[lst];
		LL d = dis[to] - dis[lst] - tmp;
		LL a = d / m + (d % m != 0);
		ans += a * cst[lst];
		tmp = tmp + a * m - (dis[to] - dis[lst]);
		lst = to;
	}
	printf("%lld\n", ans);
	return 0;
}