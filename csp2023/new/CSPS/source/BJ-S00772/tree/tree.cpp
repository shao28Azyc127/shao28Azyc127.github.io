#include <bits/stdc++.h>
#define mp make_pair

using namespace std;
typedef long long ll;
typedef __int128 i128;
typedef pair<int, int> pii;
const int N = 100005, M = 200005;
int n;
int h[2][N], e[2][M], nxt[2][M], idx[2];
ll a[N], b[N], c[N];
int fat[N], Day[N];
int cnt[N], inDeg[N];

void add(int t, int a, int b) {
	e[t][idx[t]] = b, nxt[t][idx[t]] = h[t][a], h[t][a] = idx[t]++;
}

void dfs(int u, int fa) {
	fat[u] = fa;
	for(int i = h[0][u]; i != -1; i = nxt[0][i]) {
		int v = e[0][i];
		if(v == fa) continue;
		dfs(v, u);
	}
}

i128 Div(i128 a, i128 b) {
	return (a % b == 0 ? a / b : a / b + 1);
}

i128 calc(int i, i128 L, i128 R) {
	i128 x = b[i], y = c[i];
	if(y == 0) {
		return x * (R - L + 1);
	}
	else if(y > 0) {
		return x * (R - L + 1) + y * (R - L + 1) * (R + L) / 2;
	}
	else {
		i128 tf = Div(x - 1, -y);
		if(tf < 1) tf = 1;
		if(tf <= L) return R - L + 1;
		else if(tf > R) return x * (R - L + 1) + y * (R - L + 1) * (R + L) / 2;
		else return (R - tf + 1) + x * (tf - L) + y * (tf - L) * (tf + L - 1) / 2;
	}
}

bool chk(int K) {
	for(int i = 1; i <= n; ++i) {
		int l = 1, r = K, mid;
		Day[i] = -1;
		while(l <= r) {
			mid = (l + r) >> 1;
			if(calc(i, mid, K) >= a[i]) {
				l = mid + 1, Day[i] = mid;
			}
			else {
				r = mid - 1;
			}
		}
		if(Day[i] == -1) return false;
	}
	int now = K;
	priority_queue<pii> que;
	memcpy(inDeg, cnt, sizeof inDeg);
	for(int i = 1; i <= n; ++i) {
		if(inDeg[i] == 0) que.push(mp(Day[i], i));
	}
	while(!que.empty()) {
		int u = que.top().second; que.pop();
		now = min(now - 1, Day[u]);
		for(int i = h[1][u]; i != -1; i = nxt[1][i]) {
			int v = e[1][i];
			if(--inDeg[v] == 0) {
				que.push(mp(Day[v], v));
			}
		}
	}
	return now >= 1;
}

int main() {

    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> n;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int i = 1; i <= n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		add(0, u, v);
		add(0, v, u);
	}
	dfs(1, 0);
	for(int i = 2; i <= n; ++i) {
		add(1, i, fat[i]);
		++cnt[fat[i]];
	}
	int l = 1, r = 1e9, mid, ans = -1;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(chk(mid) == true) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	cout << ans << '\n';

	cout.flush();
	return 0;
}
