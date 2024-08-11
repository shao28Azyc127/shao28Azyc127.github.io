#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
priority_queue<pair<int,pair<int,int>>> pq;
vector<pair<int,int>> g[10005];
int n,m,k,dis[10005][105];
bool vis[10005][105];
void bfs()
{
	pq.emplace(dis[1][0]=0,make_pair(1,0));
	while(pq.size())
	{
		auto u=pq.top().second;
		pq.pop();
		if(vis[u.first][u.second])	continue;
		vis[u.first][u.second]=1;
//		cout<<"extending ("<<u.first<<","<<u.second<<")="<<dis[u.first][u.second]<<"\n";
		for(auto e:g[u.first])
		{
			int tmp=e.second,d=dis[u.first][u.second];
			if(e.second<=d)	tmp=d;
			else
				if(tmp%k<d%k)	tmp=(tmp-tmp%k+d%k);
				else			tmp=(tmp-d%k+tmp%k+k);
			tmp++;
			if(tmp<dis[e.first][tmp%k])
//				cout<<"extend to ("<<e.first<<","<<tmp%k<<")="<<tmp<<endl,
				dis[e.first][tmp%k]=tmp,
				pq.emplace(-tmp,make_pair(e.first,tmp%k));
		}
	}
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0,u,v,w;i<m;i++)
		cin>>u>>v>>w,g[u].emplace_back(v,w);
	memset(dis,0x7f,sizeof dis);
	bfs();
	cout<<dis[n][0]<<endl;
}