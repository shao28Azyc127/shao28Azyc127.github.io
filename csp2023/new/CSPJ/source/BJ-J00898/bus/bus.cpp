#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[20010][5],ans=4;
void dfs(int x,int t)
{
	if(x==n&&ans%k==0) return;
	for(int i=1;i<=m;i++)
	{
		if(a[i][1]==x)
		{
			if(a[i][3]<=t)
			{
				dfs(a[i][2],a[i][3]);
				ans++;
			}
		}
	}
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	dfs(1,k);
	cout<<ans;
	return 0;
}
