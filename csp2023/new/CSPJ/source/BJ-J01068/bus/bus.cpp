#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
const ll MAX=1e4+7;
ll n,m,k;
ll t[MAX][MAX];
struct node
{
	ll u,ans;
};
queue<node> q;
ll bfs()
{
	q.push((node){1,k});
	while(!q.empty())
	{
		node cur=q.front();
		q.pop();
		if((cur.u==n)&&(cur.ans%k)==0)
		{
			return cur.ans;
		}
		for(ll i=1;i<=n;i++)
		{
			ll u=cur.u;
			if(t[u][i]!=-1&&cur.ans>=t[u][i])
			{
				q.push((node){i,cur.ans+1});
			}
		}
	}
	return -1;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	memset(t,255,sizeof(t));
	for(ll i=1;i<=m;i++)
	{
		ll u,v,d;
		cin>>u>>v>>d;
		t[u][v]=d;
	}
	cout<<bfs();
	return 0;
}
