#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4+10;
struct Way {
	long long pos , step , wait;
};
struct Node {
	long long ind , val;
};
int n , m , k;
vector<Node> e[MAXN];
vector<Way> method;
void Bfs() {
	queue<Way> q;
	q.push({1 , 0 , 0});
	while(!q.empty()) {
		Way tmp = q.front();	q.pop();
//printf("Way : 1 -> %lld  step:%lld  have to wait for %lld min\n" , tmp.pos , tmp.step , tmp.wait);
		if(tmp.pos == n) {
//printf("End.\n");
			if(tmp.step%k == 0) 
				method.push_back(tmp);
			continue;
		}
//printf("%lld have %ld edges\n" , tmp.pos , e[tmp.pos].size());
		for(int i = 0;i < e[tmp.pos].size();i++) {
			q.push({e[tmp.pos][i].ind , tmp.step+1 , max(tmp.wait , e[tmp.pos][i].val - tmp.step)});
//printf("Node %lld can go to %lld\n" , tmp.pos , e[tmp.pos][i].ind);
		}
	} 
}
long long ans = 1e18;
int main() {
	freopen("bus.in" , "r" , stdin);
	freopen("bus.out" , "w" , stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) {
		int u , v , w;
		cin >> u >> v >> w;
		e[u].push_back({v , w});
	}
	Bfs();
	if(method.size() == 0) 
		cout << -1 << endl;
	else {
		for(int i = 0;i < method.size();i++) {
			ans = min(ans , method[i].step + (method[i].wait%k==0?0:k) + method[i].wait - method[i].wait%k);
//printf("method %d : wait for %lld min , stay for %lld min\n" , i , method[i].wait , method[i].step + (method[i].wait%k==0?0:k) + method[i].wait - method[i].wait%k);
		}
		cout << ans << endl;
	}
	return 0;
}