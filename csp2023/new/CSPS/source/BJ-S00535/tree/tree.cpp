#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,fl,sum,ans=0;
int a[100005];
int b[100005];
int c[100005];
int d[100005];
int lz[100005];
int vis[100005];
int fl2,fl3;
vector<int> t[100005];
priority_queue<pair<int,int> > q;
bool check(int x,int u)
{
	// cout<<x<<' '<<u<<' ';
	if(!c[u])
	{
		if(x*b[u]>=a[u]) return 1;
		return 0;
	}
	int fr=max(b[u]+c[u]*(u),1ll),ls;
	if(fr+(x-1)*c[u]<1) ls=fr%abs(c[u])+((fr%abs(c[u]))==0)*abs(c[u]);
	else ls=fr+(x-1)*c[u];
	int xiangshu=abs(fr-ls)/abs(c[u])+1;
	// cout<<fr<<' '<<ls<<' '<<xiangshu<<endl;
	int cnt=(fr+ls)*xiangshu/2;
	cnt+=(x-xiangshu);
	if(cnt>=a[u]) return 1;
	return 0;
}
void dfs(int u,int fa,int now)
{
	d[u]=(a[u]+b[u]-1)/b[u]+now;
	for(int i=0;i<t[u].size();i++)
	{
		int v=t[u][i];
		if(v==fa) continue;
		dfs(v,u,now+1);
		d[u]=max(d[u],d[v]);
	}
}
void dfs1(int u,int fa)
{
	int l=1,r=1e9,flag=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		// cout<<mid<<' ';
		if(check(mid,u)) flag=mid,r=mid-1;
		else l=mid+1;
	}
	// cout<<endl;
	ans=max(ans,u+flag-1);
	// cout<<u<<' '<<flag<<endl;
	for(int i=0;i<t[u].size();i++)
	{
		int v=t[u][i];
		if(v==fa) continue;
		dfs1(v,u);
	}
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		if(c[i]) fl=1;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		t[u].push_back(v);
		t[v].push_back(u);
		if(u!=i||v!=i+1) fl2=1;
	}
	if(!fl)
	{
		dfs(1,0,0);
		for(int i=0;i<t[1].size();i++) q.push(make_pair(d[t[1][i]],t[1][i]));
		vis[1]=1;
		while(q.size())
		{
			ans=max(ans,sum+q.top().first);
			sum++;
			int x=q.top().first,y=q.top().second;
			vis[y]=1;
			q.pop();
			lz[y]++;
			for(int i=0;i<t[y].size();i++)
			{
				int v=t[y][i];
				if(vis[v]) continue;
				d[v]-=lz[y];
				lz[v]=lz[y];
				q.push(make_pair(d[v],v));
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(!fl2)
	{
		dfs1(1,0);
		cout<<ans<<endl;
	}
}