#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5;
int c,T,n,m,ans,f[N+1];
bool vis[N+1],stp[N+1];
struct tribool
{
	int a;
	bool tf;
}sta[N+1];
int dfs(int x)
{
	if(f[x])
		return f[x];
	vis[x]=1;
	if(vis[sta[x].a])
		if(stp[sta[x].a]==stp[x])
			if(sta[x].tf)
				f[x]=-1;
			else
				f[x]=-3;
		else
			if(sta[x].tf)
				f[x]=-3;
			else
				f[x]=-1;
	else
	{
		int tmp;
		if(sta[x].tf)
		{
			stp[sta[x].a]=stp[x];
			f[x]=dfs(sta[x].a);
		}
		else
		{
			stp[sta[x].a]=!stp[x];
			tmp=dfs(sta[x].a);
			switch(tmp)
			{
				case -1:
					f[x]=-2;
					break;
				case -2:
					f[x]=-1;
					break;
				case -3:
					f[x]=-3;
					break;
			}
		}
	}
	vis[x]=0;
	return f[x];
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	ios::sync_with_stdio(0);
	int i,idx,tag;
	char op;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		for(i=1;i<=n;i++)
			sta[i]={i,1};
		memset(f,0,n*4+4);
		ans=0;
		for(i=1;i<=m;i++)
		{
			cin>>op;
			if(op=='U')
			{
				cin>>idx;
				sta[idx]={-3,1};
				f[idx]=-3;
			}
			if(op=='T')
			{
				cin>>idx;
				sta[idx]={-1,1};
				f[idx]=-1;
			}
			if(op=='F')
			{
				cin>>idx;
				sta[idx]={-2,1};
				f[idx]=-2;
			}
			if(op=='+')
			{
				cin>>idx>>tag;
				sta[idx]=sta[tag];
				f[idx]=f[tag];
			}
			if(op=='-')
			{
				cin>>idx>>tag;
				if(sta[tag].a==-3)
				{
					sta[idx]=sta[tag];
					f[idx]=-3;
				}
				else if(sta[tag].a==-2)
				{
					sta[idx]={-1,1};
					f[idx]=-1;
				}
				else if(sta[tag].a==-1)
				{
					sta[idx]={-2,1};
					f[idx]=-2;
				}
				else
				{
					sta[idx]={sta[tag].a,!sta[tag].tf};
					f[idx]=0;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!f[i])
			{
				stp[i]=1;
				dfs(i);
			}
			if(f[i]==-3)
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}