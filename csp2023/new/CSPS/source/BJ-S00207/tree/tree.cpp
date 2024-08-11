#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 100005
#define ll long long
#define i128 __int128
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
ll read() {
	ll w = 0, x = 0; char ch = getchar();
	while(!isdigit(ch)) w |= ch == '-', ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return w ? -x : x;
}
int n;
ll a[maxn], b[maxn], c[maxn], p[maxn];
vector<int> G[maxn];
int lim[maxn], sub[maxn];
int fa[maxn], anc[maxn], dep[maxn];
int find(int x) {
	return x == anc[x] ? x : anc[x] = find(anc[x]);
}
void dfs(int x) {
	dep[x] = dep[fa[x]] + 1;
	for (auto V: G[x]) if(V ^ fa[x]) {
		fa[V] = x, dfs(V);
	}
}
int calc(int id, ll l, ll r) {
	if(l > p[id]) return r - l + 1 >= a[id];
	i128 res = 0;
	if(r > p[id]) res += (r - p[id]) * 2, r = p[id];
	i128 F = b[id] + (i128)l * c[id], S = b[id] + (i128)r * c[id];
	if(F >= a[id] || S >= a[id]) return 1;
	res += (F + S) * (r - l + 1);
	//if(id == 2) printf("%lld %lld %lld %lld %lld %lld\n", res, a[id], F, S, l, r);
	return res >= a[id] * 2;
}
vector<int> buc[maxn * 3];
int chk(ll t) {
	ru(i, 1, 3 * n) buc[i].clear();
	ru(i, 1, n) {
		if(!calc(i, 1, t)) return 0;
		if(calc(i, 2 * n, t)) lim[i] = 2 * n;
		else {ll l = 1, r = 2 * n;
		while(l < r) {
			ll mid = (l + r) / 2;
			if(!calc(i, mid + 1, t)) r = mid;
			else l = mid + 1; 
		}
		lim[i] = min((ll)2 * n, l);
		}
		if(lim[i] < dep[i]) return 0;
		sub[i] = 1;
		anc[i] = i;
		//printf("! %d %d\n", i, lim[i]);
		if(i != 1) buc[lim[i] + sub[i]].push_back(i);
	}
	ru(i, 1, 3 * n) while(!buc[i].empty()) {
		int x = buc[i].back(); buc[i].pop_back();
		if(x != anc[x] || i != lim[x] + sub[x]) continue;
		int y = find(fa[x]);
		lim[y] = min(lim[y], lim[x] - sub[y]);
		sub[y] += sub[x];
		anc[x] = y;
		if(y != 1) buc[lim[y] + sub[y]].push_back(y);
	}
	//assert(sub[1] == n);
	//ru(i, 1, n) assert(find(i) == 1);
	return lim[1] >= 1;
}
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = read();
	ru(i, 1, n) {
		a[i] = read(), b[i] = read(), c[i] = read();
		//scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
		if(c[i] < 0) p[i] = (b[i] - 1) / (-c[i]);
		else p[i] = 2e18;
	}
	ru(i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v), G[v].push_back(u);
	}
	dfs(1);
	//chk(2e18); return 0;
	//chk(5);return 0;
	ll l = n, r = 2e18;
	while(l < r) {
		ll mid = (l + r) / 2;
		if(chk(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n", l);
	return 0;
}