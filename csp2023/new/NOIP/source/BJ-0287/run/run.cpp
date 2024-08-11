#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+10;
int c,t;
int n,m,k,d;
ll dp[N][N];
ll sub1[N][N];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(1<=c&&c<=9)
	{
		while(t--)
		{
			scanf("%d%d%d%d",&n,&m,&k,&d);
			memset(dp,0,sizeof(dp));
			memset(sub1,0,sizeof(sub1));
			for(int i=1;i<=m;i++)
			{
				int x,y,v;
				scanf("%d%d%d",&x,&y,&v);
				for(int j=y;j<=k;j++)
				sub1[x][j]+=v;
			}
			ll maxn=0;
			for(int i=1;i<=n;i++)
			{
				dp[i][0]=maxn;
				for(int j=1;j<=k&&j<=i;j++)
				{
					dp[i][j]=dp[i-1][j-1]+sub1[i][j]-d;
					maxn=max(maxn,dp[i][j]);
				}
			}
			printf("%lld\n",maxn);
		}
	}
	
	return 0;
}
/*
1 1
3 2 2 1
2 2 4
3 2 3
*/
