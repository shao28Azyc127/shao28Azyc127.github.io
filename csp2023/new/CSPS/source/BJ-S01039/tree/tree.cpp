#include<bits/stdc++.h>
using namespace std;
#define int long long

const int nr = 1e5;
int n, a[nr], b[nr], c[nr];
vector<int> adj[nr];

namespace _subtask1
{
	void solve()
	{
		// sigma(x = i + 1 ~ k)(bi + x * ci)>=a[i]
		// <=> sigma(bi) + sigma(i + 1 ~ k) * c[i] >= a[i]
		// <=> (k - i) * bi + (k + i + 1) * (k - i) / 2 * c[i] >= a[i];
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int l = i + 1, r = 1e18, k = 0;
			while (l <= r)
			{
				int mid = (l + r) / 2;
				if ((mid - i) * b[i] + (mid + i + 1) * (mid - i) * c[i] / 2 >= a[i]) k = mid, r = mid - 1;
				else l = mid + 1;
			}
			ans = max(ans, k);
		}
		cout << ans << endl;
	}
}

signed main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	bool islian = true;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if (u + 1 != v) islian = false;
	}
	if (islian) _subtask1::solve();
	return 0;
}