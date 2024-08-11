#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 1e5 + 10;
struct jkl{
	int ne,to,w;
}e[maxn];
int h[maxn],tot = 0;
void add(int u,int v,int w) {
	e[++tot] = (jkl){h[u],v,w};
	h[u] = tot;
}
struct node{
	int x;
};
ll dis[maxn][110];
ll a[maxn][110];
int n,m,k;
ll c(ll x) {
	if (x == -1) return k - 1;
	return x;
} 
ll c1(ll x) {
	return x + (k - x % k) % k;
}
int main() {
	freopen("bus.in", "r",stdin);
	freopen("bus.out","w", stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1; i <= m; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	queue<node> q;
	q.push((node){1});
	memset(dis,0x3f,sizeof(dis));
	memset(a,0,sizeof(a));
	dis[1][0] = 0;
	ll ans = 0x3f3f3f3f;
	while (!q.empty()) {
		int u = q.front().x;
		q.pop();
		if (u == n) {
			ans = min(ans, dis[n][0] + a[n][0]);
			continue;
		}
		for (int i = h[u]; i; i = e[i].ne) {
			int v = e[i].to;
			int t = 0;
			for (int j = 0; j < k; j++) {
				ll w = max(a[u][c(j - 1)],c1(e[i].w - dis[u][c(j - 1)]));
				if (a[v][j] + dis[v][j] > c1(w) + dis[u][c(j - 1)] + 1) {
					a[v][j] = w;
					dis[v][j] = dis[u][c(j - 1)] + 1;
					t = 1;
				}
			}
			if (t) q.push((node){v});
		} 
	}
	if (ans == 0x3f3f3f3f) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
