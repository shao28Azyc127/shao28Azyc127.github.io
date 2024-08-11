#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

long long n,m,k;
vector<long long> g[10005],e[10005];
long long dis[10005],nt = 9e18,sum[10005];
struct node{
	long long num,t;
};
queue<node> q;
bool vis[10005];

void spfa(){
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	q.push((node){1,0});
	vis[1] = false;
	while(!q.empty()){
		long long u = q.front().num,t = q.front().t;
		q.pop();
		vis[u] = false;
		for(long long i = 0;i < g[u].size();i++){
			long long v = g[u][i];
			// if(v == n) cout << t + 1 << endl;
			long long fst_bus = max(0ll,e[u][i] - t);
			while(fst_bus % k != 0) fst_bus++;

			if(v == n && (t + 1) % k == 0){
				if(nt > max(dis[u],fst_bus) + t + 1){
					nt = max(dis[u],fst_bus) + t + 1;
				}
			}

			if(dis[v] > max(dis[u],fst_bus)){
				dis[v] = max(dis[u],fst_bus);
				if(!vis[v]){
					vis[v] = true;
					q.push((node){v,t + 1});
				}
			}
		}
	}
}

int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> n >> m >> k;
	for(long long i = 1;i <= m;i++){
		long long x,y,z;
		cin >> x >> y >> z;
		g[x].push_back(y);
		e[x].push_back(z);
	}

	spfa();

	if(nt == 9e18) cout << -1;
	else cout << nt;
}