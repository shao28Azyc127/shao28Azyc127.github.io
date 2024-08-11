#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
namespace solve
{
	const int N=2000000+5;
	int n,ans;
	int f[10][6];
	int c[6],d[6];
	void dfs(int x)
	{
		if(x==6)
		{
			bool ok=1;
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=5;++j)
				{
					d[j]=((f[i][j]-c[j]+10)%10);
				}
				int cnt=0,l=0;
				bool fin=0;
				for(int j=1;j<=5;++j)
				{
					if(d[j]!=0&&cnt==0)
					{
						cnt=d[j];l++;
					}
					else if(d[j]!=0&&cnt!=0&&cnt==d[j])
					{
						if(fin) ok=0;
						l++;
						if(l>2) ok=0;
					}
					else if(d[j]!=0&&cnt!=0&&cnt!=d[j])
					{
						ok=0;
					}
					else
					{
						if(cnt!=0) fin=1;
					}
				}
				if(cnt==0) ok=0;
			}
			ans+=ok;
			/*if(ok)
			{
				for(int i=1;i<=5;++i) cout<<c[i]<<" ";
				cout<<endl;
			}*/
			return;
		}
		for(int i=0;i<=9;++i)
		{
			c[x]=i;
			dfs(x+1);
		}
		c[x]=0;
	}
	void main()
	{
		cin>>n;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=5;++j) cin>>f[i][j];
		}
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	solve::main();
	return 0;
}
