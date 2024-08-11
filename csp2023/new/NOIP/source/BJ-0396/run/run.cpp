#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100;
int read()
{
	int f=1,ret=0;char c=getchar();
	while(!(c>='0'&&c<='9'))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ret=ret*10+c-'0';c=getchar();
	}
	return ret*f;
}
int c,t,n,m,k,d,x[N],y[N],z[N],pre[N],a[N],ans=0;
void dfs(int dep,int cnt)
{
	if(dep==n+1)
	{
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
		int tmp=-1*pre[n]*d;
		for(int j=1;j<=m;j++)
		{
			if(pre[x[j]]-pre[x[j]-y[j]]==y[j])
			{
				tmp+=z[j];
			}
		}
		ans=max(ans,tmp);
		return;
	}
	if(cnt==k) 
	{
		a[dep]=0;
		dfs(dep+1,0);
	}
	else
	{
		a[dep]=1;dfs(dep+1,cnt+1);
		a[dep]=0;dfs(dep+1,0);
	}
}
signed main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	c=read(),t=read();
	n=read(),m=read(),k=read(),d=read();
	for(int i=1;i<=m;i++)
	{
		x[i]=read(),y[i]=read(),z[i]=read();
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}