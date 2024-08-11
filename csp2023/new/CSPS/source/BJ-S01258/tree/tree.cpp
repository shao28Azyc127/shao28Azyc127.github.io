/*flower*/
#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128_t;
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	int n;
	std::cin >> n;
	std::vector<i64> a(n), b(n), c(n);
	for(int i = 0; i < n; i ++) {
		std::cin >> a[i] >> b[i] >> c[i];
	}
	std::vector<std::vector<int>> G(n);
	for(int i = 1; i < n; i ++) {
		int u, v;
		std::cin >> u >> v;
		u --, v --;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	std::vector<int> limit(n), fa(n);
	std::function<void(int, int)> dfs = [&] (int u, int par) {
		for(auto v : G[u]) if(v != par) {
			dfs(v, u);
			limit[u] = std::min(limit[u], limit[v] - 1);
		}
	};
	auto check = [&] (int x) {	
		for(int i = 0; i < n; i ++) {
			if(i64 last = b[i] + c[i] * x; last >= 1) {
				int l = 0, r = x, ans = -1;
				while(l <= r) {
					int mid = l + r >> 1;
					if(i128(mid + 1) * (2 * last - mid * c[i]) >= 2 * a[i]) {
						ans = mid, r = mid - 1;
					} else {
						l = mid + 1;
					}
				}
				if(ans == -1) return false;
				limit[i] = x - ans;
			} else {
				i64 pos = (b[i] - 1) / (- c[i]);
				assert(pos <= x);
				int l = 0, r = x, ans = -1;
				assert(1ll * b[i] + 1ll * c[i] * pos >= 1);
				while(l <= r) {
					int mid = l + r >> 1;
					i128 w = (mid <= pos ?  2 * (x - pos) + i128(pos - mid + 1) * (b[i] + c[i] * mid + b[i] + c[i] * pos) : 2 * (x - mid + 1));
					if(w >= 2 * a[i]) {
						ans = mid, l = mid + 1;
					} else {
						r = mid - 1;
					}
				}
				if(ans == -1) return false;
				limit[i] = ans;
			}
		}
		dfs(0, 0);
		std::sort(limit.begin(), limit.end());
		for(int i = 0; i < n; i ++) {
			if(limit[i] <= i) {
				return false;
			}
		}
		return true;
	};
	int l = 0, r = 1e9, ans = -1;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) ans = mid, r = mid -1;
		else l = mid + 1;
	}
	std::cout << ans << '\n';
	return 0; 
}