#include<bits/stdc++.h>
using namespace std;
long long a[10010][10010], ans = 1e9;
long long n, m, k;
struct node{
	long long n, s;
};
void bfs(){
	long long cnt = 0;
	queue<node> q;
	node b;
	b.n = 1;
	b.s = 0;
	q.push(b);
	while (!q.empty()){
		//cout << q.size() << "  ";
		long long s = q.size();
		for (int i = 1; i <= s; i++){
			node u = q.front();
			q.pop();
			//cout << u.n << ' ';
			if (u.n == n){
				if (cnt % k == 0) ans = min(ans, u.s + cnt);
				//cout << cnt << ' ';
				continue;
			}
			for (int j = 1; j <= n; j++){
				if (a[u.n][j] != -1){
					node b;
					b.n = j;
					b.s = u.s;
					if (a[u.n][j] > cnt + b.s) b.s += k;
					q.push(b);
				}
			}
		}
		//cout << endl;
		cnt++;
	}
}
int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	memset(a, -1, sizeof(a));
	long long u, v, w;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		a[u][v] = w;
	}
	bfs();
	if (ans == 1e9) cout << -1;
	else cout << ans;
	return 0;
}