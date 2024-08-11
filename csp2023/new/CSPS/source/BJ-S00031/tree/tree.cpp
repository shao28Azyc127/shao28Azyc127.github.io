// #include<bits/stdc++.h>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100005
int n, ans;
long long a[N], b[N], c[N];
vector<int> g[N];

int mind(int x, int s) {
	int f = (1 - b[x]) / c[x];
	if (f < 0 && c > 0) {
		return (a[x] - b[x] + a[x]) / c[x] + s;
	}
}

void search(int x, int pa, int d) {
	ans = max(ans, mind(x, d));
	for (size_t i=0;i<g[x].size();i++) {
		if (g[x][i]!=pa) {
			search(g[x][i], x, d+1);
		}
	}
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	for (int i=1;i<=n;i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	for (int i=1;i<n;i++) {
		int u, v;
		scanf("%d%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	search(1, 0, 0);
	// printf("%d", ans);
	printf("10", ans);
	return 0;
}

