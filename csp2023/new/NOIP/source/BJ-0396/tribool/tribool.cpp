#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
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
int n,m,a[N],p[N],q[N],b[N],ans;
char v[N],f[N];
bool check()
{
	for(int i=1;i<=n;i++) b[i]=a[i];
	for(int i=1;i<=m;i++)
	{
		if(v[i]=='+')
		{
			b[p[i]]=b[q[i]];
		}
		if(v[i]=='-')
		{
			if(b[q[i]]==1) b[p[i]]=2;
			else if(b[q[i]]==2) b[p[i]]=1;
			else if(b[q[i]]==3) b[p[i]]=3;
		}
		if(v[i]=='F') b[p[i]]=2;
		if(v[i]=='U') b[p[i]]=3;
		if(v[i]=='T') b[p[i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=a[i]) return 0;
	}
	return 1;
}
void dfs(int dep)
{
	if(dep==n+1)
	{
		if(check()) 
		{
			int cnt=0;
			for(int i=1;i<=n;i++) if(a[i]==3) cnt++;
			ans=min(ans,cnt);
		}
		return;
	}
	a[dep]=1;dfs(dep+1);
	a[dep]=2;dfs(dep+1);
	a[dep]=3;dfs(dep+1);
}
signed main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	c=read(),t=read();
	if(c==1||c==2)
	{
		while(t--)
		{
			ans=1e8;
			n=read(),m=read();
			for(int i=1;i<=m;i++)
			{
				cin>>v[i];
				if(v[i]=='-'||v[i]=='+') p[i]=read(),q[i]=read();
				else p[i]=read();
			}
			dfs(1);
			cout<<ans<<endl;
		}
	}
	if(c==3||c==4)
	{
		int cnt=0;
		n=read(),m=read();
		for(int i=1;i<=m;i++)
		{
			char h; int j;
			cin>>h>>j;
			f[j]=h;
		}
		for(int i=1;i<=n;i++)
		{
			if(f[i]=='U') cnt++;
		}
		cout<<cnt;
	}
	return 0;
}