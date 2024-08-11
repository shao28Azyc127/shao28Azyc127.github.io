#include <bits/stdc++.h>
#define ll long long
#define y1 jiajia
using namespace std;
void read(int &x) {
	int f = 1; x = 0; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) {x = x * 10 + ch - 48; ch = getchar();}
	x *= f;
}
void read(ll &x) {
	ll f = 1; x = 0; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) {x = x * 10 + ch - 48; ch = getchar();}
	x *= f;
}
struct edge {
	int v, nxt;
} e[200005];
int head[100005], cnt;
ll a[100005], b[100005], c[100005];
int dat[100005];
void add_edge(int u, int v) {
	++cnt;
	e[cnt].v = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
bool chk(int x, ll l, ll r) {
	__int128 tmp = 0;
	if (c[x] >= 0) {
		tmp = b[x] + l * c[x] + b[x] + r * c[x];
		tmp = tmp * (r - l + 1); tmp /= 2; 
		if (tmp >= a[x]) return 1;
		return 0;
	} else if (b[x] + l * c[x] <= 1 && b[x] + r * c[x] <= 1) {
		if (r - l + 1 >= a[x]) return 1;
		return 0;
	} else if (b[x] + l * c[x] > 1 && b[x] + r * c[x] > 1) {
		tmp = b[x] + l * c[x] + b[x] + r * c[x];
		tmp = tmp * (r - l + 1); tmp /= 2; 
		if (tmp >= a[x]) return 1;
		return 0;
	} else {
		ll m = (b[x] - 1 - c[x] - 1) / (-c[x]);
		//if (m > r || m < l) cerr << "QWQ";
		tmp = b[x] + l * c[x] + b[x] + (m - 1) * c[x];
		tmp = tmp * (m - l); tmp /= 2;
		tmp += r - m + 1;
		if (tmp >= a[x]) return 1;
		return 0;
	}
}
int n;
int nd[100005];
int fa[100005];
void dfs1(int u, int f) {
	fa[u] = f;
	for (int i = head[u]; i; i = e[i].nxt) {
		if (e[i].v == f) continue;
		dfs1(e[i].v, u);
		nd[u] = min(nd[u], nd[e[i].v] - 1);
	}
}
bool check(int m) {
	for (int i = 1; i <= n; i++) {
		int L = 1, R = min(m, n + n + 5), M;
		while (L < R) {
			M = (L + R + 1) >> 1;
			if (chk(i, M, m)) L = M;
			else R = M - 1;
		}
		if (!chk(i, 1, m)) return 0;
		nd[i] = L;
	}
	//cout << m << '\n';
	//for (int i = 1; i <= n; i++) cout << nd[i] << ' ' ;
	//cout << '\n';
	dfs1(1, 1);
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(-nd[1], 1));
	int tm = 0;
	while (!pq.empty()) {
		++tm;
		int u = pq.top().second; pq.pop();
		if (nd[u] < tm) return 0;
		for (int i = head[u]; i; i = e[i].nxt) {
			if (e[i].v == fa[u]) continue;
			pq.push(make_pair(-nd[e[i].v], e[i].v));
		}
	}
	return 1;
}
int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]); read(b[i]); read(c[i]);
	}
	for (int i = 1; i < n; i++) {
		int u, v; read(u); read(v);
		add_edge(u, v);
		add_edge(v, u);
	}
	int L = n, R = 1000000000, M;
	while (L < R) {
		M = (L + R) >> 1;
		if (check(M)) R = M;
		else L = M + 1;
	}
	cout << L << '\n';
	return 0;
}