#include <bits/stdc++.h>
using namespace std;
int v[20010],h[10010],ne[20010],w[20010],vis[10010],k,ans=0x3f3f3f3f,d,n;
void add(int x,int y,int z)
{
	v[++k]=y;
	ne[k]=h[x];
	h[x]=k;
	w[k]=z;
}
void dfs(int x,int s,int t)
{
	if(x==n)
	{
		if(s%d==0)
			ans=min(ans,(t+d-1)/d*d+s);
		return;
	}
	for(int i=h[x];i;i=ne[i])
	{
		int y=v[i];
		if(!vis[y])
		{
			vis[y]=1;
			dfs(y,s+1,max(t,w[i]-s));
			vis[y]=0;
		}
	}
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int m,i,a,b,c;
	cin>>n>>m>>d;
	for(i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		add(a,b,c);
	}
	vis[1]=1;
	dfs(1,0,0);
	if(ans==0x3f3f3f3f)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}
