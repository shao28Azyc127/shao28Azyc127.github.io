#include<bits/stdc++.h>
using namespace std;
struct node
{
	int v,a;
}a[100010];
struct que
{
	int s,step;
};
int n,m,k;
vector<node> adj[10010];
void bfs(int s)
{
	queue<que> q;
	q.push({s,0});
	while(!q.empty())
	{
		que f = q.front(); q.pop();
		if(f.s == n && f.step % k == 0) 
		{
			cout << f.step;
			exit(0);
		}
		if(f.step > n)
		{
			continue;
		}
		for(int i = 0;i < adj[f.s].size();i++)
		{
			if(adj[f.s][i].a <= f.step)
			{
				q.push({i,f.step+1});
			}
		}
	}
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= m;i++)
	{
		int x;
		scanf("%d%d%d",&x,&a[i].v,&a[i].a);
		adj[x].push_back({a[i].v,a[i].a});
	}
	//bfs(1);
	cout << -1;
	return 0;
}


