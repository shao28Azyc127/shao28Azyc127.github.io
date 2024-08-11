#include<bits/stdc++.h>
using namespace std;
#define int long long

const int nr = 1e5 + 10;
int n, d, w[nr], v[nr];
int pre[nr], mn[nr], mnpos[nr], pos[nr];

int Solve(int start, int end, int oracle) 
{ return max((int)ceil(1.0 * (pre[end] - pre[start] - oracle) / d), 0ll); }

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> d;
	for (int i = 1; i < n; i++) { cin >> w[i]; pre[i + 1] = pre[i] + w[i]; }
	for (int i = 1; i <= n; i++) cin >> v[i];
	mn[0] = 9e18;
	for (int i = 1; i <= n; i++) 
		if (v[i] < mn[i - 1]) mn[i] = v[i], mnpos[i] = i;
		else mn[i] = mn[i - 1], mnpos[i] = mnpos[i - 1];
	pos[++pos[0]] = n;
	int cur = n - 1;
	while (cur >= 1)
	{
		pos[++pos[0]] = mnpos[cur];
		cur = mnpos[cur] - 1;
	}
	int ans = 0, oracle = 0;
	for (int i = pos[0]; i > 1; i--)
	{
		ans += Solve(pos[i], pos[i - 1], oracle) * v[pos[i]];
		oracle = oracle + Solve(pos[i], pos[i - 1], oracle) * d - (pre[pos[i - 1]] - pre[pos[i]]);
	}
	cout << ans << endl;
	return 0;
}