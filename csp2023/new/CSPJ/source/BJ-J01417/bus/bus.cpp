#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10005;
int cnt, head[N];
int n, m, k;
struct edge {
	int v, w, next;
} e[N << 1];
void add(int u, int v, int w) {
	e[++cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
struct node {
	int u, i;
	ll d;
	node(int a, int b, ll c) {
		u = a, i = b, d = c;
	}
	bool operator < (const node &b) const {
		return d > b.d;
	}
};
inline ll qz(ll a, ll b) {
	return a / b + !!(a % b);
}
bool vis[N][105];
ll dis[N][105];
void dij() {
	priority_queue<node> q;
	q.push(node(1, 0, 0));
	while (q.size()) {
		int u = q.top().u, r = q.top().i;
		ll d = q.top().d;
		q.pop();
		if (vis[u][r])
			continue;
		//cerr << u << ' ' << r << "!\n";
		dis[u][r] = d;
		vis[u][r] = 1;
		for (int i = head[u]; i; i = e[i].next) {
			int v = e[i].v;
			if (!vis[v][(r + 1) % k]) {
				q.push(node(v, (r + 1) % k, (d >= e[i].w ? d : d + qz(e[i].w - d, k) * k) + 1));
			}
		}
	}
}
int main() {
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	memset(dis, -1, sizeof(dis));
	dij();
	printf("%lld\n", dis[n][0]);
	return 0;
}
/*
 * 参与编写本程序名单：farfar、rafraf、nearnear、closeclose、arfarf、frafra、farraf、fararf、farfra、afrafr、rfarfa、......
 * 
 * 特此鸣谢
*/
