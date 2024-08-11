#include<bits/stdc++.h>
using namespace std;
int a[2005][2005];
int n,m,k,minn=1000000000;
void dfs(int no,int time)
{
	if(no==n)
	{
		if(time%k==0)
		{
			minn=min(minn,time);
			return ;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(a[no][i]!=-1&&a[no][i]<=time)
		{
			dfs(i,time+1);
		}
	}
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int x,y,maxx=-1;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]=-1;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>a[x][y];
		maxx=max(maxx,a[x][y]);
	}
	maxx=k*ceil(maxx/double(k));
	for(int i=0;i<=maxx;i+=k)
	{
		dfs(1,i);
	}
	if(minn==1000000000)minn=-1;
	cout<<minn;
}
