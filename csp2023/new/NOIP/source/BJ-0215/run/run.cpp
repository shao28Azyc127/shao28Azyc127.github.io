#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const int inf = 2e18;
int n, m, k, d;
namespace sub1
{
	int f[2][N];
	struct node { int t, v; };
	vector<node> v[N];
	int dp();
}
namespace sub2
{
	int cnt = 0;
	struct node { int l, r, v; }a[N];
	int solve();
}

signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int C, T;
	cin >> C >> T;
	while (T--)
	{
		cin >> n >> m >> k >> d;
		if (C <= 14)
		{
			using namespace sub1;
			int x, y, z;
			for (int i = 1;i <= n;i++) v[i].clear();
			for (int i = 1;i <= m;i++)
				cin >> x >> y >> z, v[x].push_back({y, z});
			cout << dp() << endl;
		}
		else if (C == 17 || C == 18)
		{
			using namespace sub2;
			cnt = 0;
			int x, y, z;
			for (int i = 1;i <= m;i++)
			{
				cin >> x >> y >> z;
				if (y <= k && z - d * y > 0) a[++cnt].l = x - y + 1, a[cnt].r = x, a[cnt].v = z - d * y;
			}
			cout << solve() << endl;
		}
		else cout << "Good Luck!" << endl;
	}
	return 0;
}

int sub2::solve()
{
	int ans = 0, p = 1;
	while (p <= cnt)
	{
		int maxn = a[p].v, sum = a[p].r - a[p].l + 1, num = maxn, lp = p, rp = p + 1;
		while (a[rp].r + 1 == a[rp - 1].l && rp > lp)
		{
			if (sum + a[rp].r - a[rp].l <= k) num += a[rp++].v;
			else num -= a[lp++].v, sum -= a[lp].r - a[lp].l + 1;
			maxn = max(maxn, num);
		}
		ans += maxn;
		p++;
	}
	return ans;
}

namespace sub1
{

int dp()
{
	int t = 0; // t ^ 1 is current, t is last one
	f[0][0] = 0;
	int maxn = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = 0;j <= min(k, i);j++)
		{
			if (j == 0) f[t ^ 1][j] = maxn;
			else
			{
				f[t ^ 1][j] = f[t][j - 1] - d;
				for (auto x:v[i])
					if (x.t <= j) f[t ^ 1][j] += x.v;
			}
			maxn = max(maxn, f[t ^ 1][j]);
		}
		t ^= 1;
	}
	int ans = -inf;
	for (int i = 0;i <= min(k, n);i++) ans = max(ans, f[t][i]);
	return ans;
}

}
