#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,ans;
int n,m;
char op[100005];
int a[100005];
int b[100005];
int d[100005];
int dd[100005];
int fl[100005];
void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++) dd[i]=d[i];
		for(int i=1;i<=m;i++)
		{
			if(op[i]=='U') d[a[i]]=3;
			if(op[i]=='T') d[a[i]]=1;
			if(op[i]=='F') d[a[i]]=2;
			if(op[i]=='+') d[a[i]]=d[b[i]];
			if(op[i]=='-')
			{
				if(d[b[i]]==1) d[a[i]]=2;
				else if(d[b[i]]==2) d[a[i]]=1;
				else if(d[b[i]]==3) d[a[i]]=3;
			}
		}
		int fl=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i]!=dd[i]) fl=1;
			d[i]=dd[i];
		}
		if(!fl)
		{
			for(int i=1;i<=n;i++)
			{
				if(d[i]==3) fl++;
			}
			ans=min(ans,fl);
		}
		return;
	}
	d[x]=1;
	dfs(x+1);
	d[x]=2;
	dfs(x+1);
	d[x]=3;
	dfs(x+1);
}
signed main()
{
	// system("deff run2.ans 4.out");
	// return 0;
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	if(c<=2)
	{
		while(t--)
		{
			ans=1e9;
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				cin>>op[i];
				if(op[i]!='+'&&op[i]!='-') cin>>a[i];
				else cin>>a[i]>>b[i];
			}
			dfs(1);
			cout<<ans<<endl;
		}
		return 0;
	}
	if(c<=4)
	{
		while(t--)
		{
			ans=0;
			cin>>n>>m;
			for(int i=1;i<=m;i++)
			{
				cin>>op[i];
				if(op[i]!='+'&&op[i]!='-') cin>>a[i];
				else cin>>a[i]>>b[i];
			}
			for(int i=1;i<=m;i++)
			{
				if(op[i]=='U') d[a[i]]=3;
				if(op[i]=='T') d[a[i]]=1;
				if(op[i]=='F') d[a[i]]=2;
			}
			for(int i=1;i<=n;i++)
			{
				if(d[i]==3) ans++;
				d[i]=0;
			}
			cout<<ans<<endl;
		}
		return 0;
	}
}