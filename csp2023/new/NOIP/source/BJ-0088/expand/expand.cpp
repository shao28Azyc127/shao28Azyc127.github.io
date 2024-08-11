#include<bits/stdc++.h>
using namespace std;
int C,n,m,Q;
int a[500010],b[500010];
int a_[500010][2],b_[500010][2];
bool dp[2010][2010];
bool solve1()
{
	memset(dp,0,sizeof(dp));
	if(a[1]>b[1]&&a[n]>b[m])
	{
		dp[1][1]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i]>b[j])
				{
					dp[i][j]|=(dp[i-1][j]|dp[i][j-1]);
				}
			}
		}
		return dp[n][m];
	}
	else if(a[1]<b[1]&&a[n]<b[m])
	{
		dp[1][1]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i]<b[j])
				{
					dp[i][j]|=(dp[i-1][j]|dp[i][j-1]);
				}
			}
		}
		return dp[n][m];
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&C,&n,&m,&Q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	if(C<=7)
	{
		printf("%d",solve1());
		while(Q--)
		{
			int an,bm;
			scanf("%d%d",&an,&bm);
			for(int i=1;i<=an;i++)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				a_[i][0]=x;
				a_[i][1]=a[x];
				a[x]=y;
			}
			for(int i=1;i<=bm;i++)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				b_[i][0]=x;
				b_[i][1]=b[x];
				b[x]=y;
			}
			printf("%d",solve1());
			for(int i=1;i<=an;i++) a[a_[i][0]]=a_[i][1];
			for(int i=1;i<=bm;i++) b[b_[i][0]]=b_[i][1];
		}
	}
	return 0;
}