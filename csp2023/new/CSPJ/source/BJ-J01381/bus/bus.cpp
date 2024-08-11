#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans=INT_MAX,mx,tot,mm;
long long v[20005],e[20005],nxt[20005],head[10005];
void add(int x,int y,int z)
{
	v[++tot]=y,e[tot]=z;
	nxt[tot]=head[x],head[x]=tot;
	return;
}
void dfs(int f,int t)
{
	if(f==n)
	{
		if(t<ans&&t%k==0)ans=t;
		else return;
	}
	for(int i=head[f];i>0;i=nxt[i])
	{
		if(e[i]<=t)dfs(v[i],t+1);
		else if(e[i]-t<mm)mm=e[i]-t;
	}
	return;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	long long a,b,c;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&c);
		if(c>mx)mx=c;
		add(a,b,c);
	}
	a=-k;
	while(a<mx)
	{
		a+=k;
		if(a<mm)continue;
		mm=INT_MAX;
		dfs(1,a);
	}
	if(ans==2147483647)printf("-1");
	else printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
