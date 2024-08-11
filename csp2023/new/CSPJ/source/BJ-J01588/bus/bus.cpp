#include <bits/stdc++.h>
using namespace std;
vector <pair<int, int> > g[100010];
struct node {
	int v, w;
};
priority_queue <node > q;
bool operator <(const node a, const node b) {return a.w > b.w;}
int dis[10010], mem[10010];
int cnt, vis[110], n, m, k, Min = 1e9, Max;
void dfs(int x, int sum) {
	if(x == n) {
		if(sum % k == 0) Min = min(Min, sum);
		return ;
	}
	for(auto i : g[x]) {
		if(sum < i.second || vis[i.first]) continue;
		vis[i.first] = 1;
		dfs(i.first, sum + 1);
		vis[i.first] = 0;
	}
	
}
int main() {
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	while(m--) {
		int x, y, z; cin >> x >> y >> z;
		g[x].push_back({y, z});
		Max = max(Max, z);
		if(!z) ++cnt;
	}
	if(n <= 10 || cnt == m) {
		for(int i = 0; i <= Max; i += k) {
			memset(vis, 0, sizeof vis);
			dfs(1, i);
		}
	}
	cout << Min;
}
