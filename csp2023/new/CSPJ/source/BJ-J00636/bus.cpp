#include<bits/stdc++.h>
using namespace std;
const int N=2e4+7;
int n,m,k;
vector<int> edge[N];
int dis[N],vis[N];
queue<int> q;
void bfs(int s)
{
	q.push(s);
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		for(auto i:edge[s])
		{
			if(!vis[i])
			{
				dis[i]=dis[s]+1;
				q.push(i);
			}
		}
	}
	if(dis[n]%k==0) cout<<dis[n]<<endl;
	else cout<<-1<<endl;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,a;
		cin>>u>>v>>a;
		edge[u].push_back(v);
	}
	bfs(1);
	return 0;
}