#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 10000 + 10;
int n, m, k;
vector<pair<int, int>> g[maxn];
bool visited[maxn][100];
int dis[maxn][100];
struct DATA {
	int x, t;
	bool operator < (const DATA another) const {
		return dis[x][t] > dis[another.x][another.t];
	}
};
priority_queue<DATA> q;
void bfs() {
	/*
	for(int i = 0; i < k; i++) {
		visited[1][i] = true;
		dis[1][i] = i;
		q.push({1, i});
	}*/
	visited[1][0] = true;
	dis[1][0] = 0;
	q.push({1, 0});
	while(!q.empty()) {
		DATA u = q.top();
		q.pop();
		int x = u.x;
		int t = dis[u.x][u.t];
		if(x == n && t % k == 0) return;
		for(pair<int, int> pr : g[x]) {
			int y = pr.first;
			int a = pr.second;
			int nx = y;
			int nt = a <= t ? t + 1: (a - t + k - 1) / k * k + t + 1;
			if(!visited[nx][nt % k]) {
				//cout << x << " " << u.t << "(" << t << ")" << "->" << nx << " " << nt%k << "(" << nt << ")" << endl;
				visited[nx][nt % k] = true;
				dis[nx][nt % k] = nt;
				q.push({nx, nt % k});
			}
		}
	}
}
				
int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int u, v, a;
		cin >> u >> v >> a;
		g[u].push_back({v, a});
	}
	bfs();
	if(!visited[n][0]) cout << -1 << endl;
	else cout << dis[n][0] << endl;
	return 0;
}