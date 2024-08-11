#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int dp[N][N];
int c,n,m,q;
int x[N],y[N];
int nx[N][2],ny[N][2],tagx,tagy;
int ans[N],tagans=0;
int getans()
{
	int maxx=-999999999,maxy=-999999999;
	for(int i=1;i<=n;i++)
	maxx=max(maxx,x[i]);
	for(int i=1;i<=m;i++)
	maxy=max(maxy,y[i]);
	memset(dp,0,sizeof(dp));
	/*
	printf("%d %d\n",maxx,maxy);
	for(int i=1;i<=n;i++)
	printf("%d ",x[i]);
	for(int i=1;i<=m;i++)
	printf("%d ",y[i]);
	printf("\n");
	*/
	if(maxx>=maxy)
	{
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if((dp[i][j-1]||dp[i-1][j-1]||dp[i-1][j])&&x[i]>y[j])
			dp[i][j]=1;
			//else printf("%d %d %d %d\n",dp[i][j-1],dp[i-1][j-1],x[i],y[j]);
		}
		return dp[n][m];
	}
	else
	{
		dp[0][0]=1;
		for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if((dp[i][j-1]||dp[i-1][j-1]||dp[i-1][j])&&y[i]>x[j])
			dp[i][j]=1;
		}
		return dp[m][n];
	}
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	if(1<=c&&c<=7)
	{
		for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
		for(int i=1;i<=m;i++)
		scanf("%d",&y[i]);
		ans[++tagans]=getans();
		/*for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			printf("%d ",dp[i][j]);
			printf("\n");
		}*/
		while(q--)
		{
			int kx,ky;
			scanf("%d%d",&kx,&ky);
			for(int i=1;i<=kx;i++)
			scanf("%d%d",&nx[i][0],&nx[i][1]);
			for(int i=1;i<=ky;i++)
			scanf("%d%d",&ny[i][0],&ny[i][1]);
			
			for(int i=1;i<=kx;i++)
			swap(x[nx[i][0]],nx[i][1]);
			for(int i=1;i<=ky;i++)
			swap(y[ny[i][0]],ny[i][1]);
			
			ans[++tagans]=getans();
			
			for(int i=1;i<=kx;i++)
			swap(x[nx[i][0]],nx[i][1]);
			for(int i=1;i<=ky;i++)
			swap(y[ny[i][0]],ny[i][1]);
		}
		for(int i=1;i<=tagans;i++)
		printf("%d",ans[i]);
	}
	
	
	return 0;
}
