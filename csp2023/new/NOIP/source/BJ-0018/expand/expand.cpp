#include <bits/stdc++.h>
using namespace std;
int n,m,q,x[2011],y[2011],tx[2011],ty[2011];bool dp[2011][2011];
bool solve()
{
	if(x[1]==y[1]||x[n]==y[m])return 0;
	//printf("x:");for(int i=1;i<=n;++i)printf("%d ",x[i]);putchar(10);
	//printf("y:");for(int i=1;i<=n;++i)printf("%d ",y[i]);putchar(10);
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)dp[i][j]=0;
	dp[1][1]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)if(i!=1||j!=1)
		{
			if((x[i]==y[j])||((x[i]<y[j])!=(x[1]<y[1])))continue;
			dp[i][j]=dp[i-1][j]|dp[i][j-1];
		}
	}
	return dp[n][m];
}
int main()
{
	freopen("expand.in","r",stdin);freopen("expand.out","w",stdout);
	scanf("%*d%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)scanf("%d",x+i),tx[i]=x[i];
	for(int i=1;i<=m;++i)scanf("%d",y+i),ty[i]=y[i];
	printf("%d",solve());
	while(q--)
	{
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int _=1;_<=kx;++_)
		{
			int p,v;scanf("%d%d",&p,&v);
			x[p]=v;
		}
		for(int _=1;_<=ky;++_)
		{
			int p,v;scanf("%d%d",&p,&v);
			y[p]=v;
		}
		printf("%d",solve());
		for(int i=1;i<=n;++i)x[i]=tx[i];
		for(int i=1;i<=m;++i)y[i]=ty[i];
	}
	putchar(10);
	fclose(stdin);fclose(stdout);return 0;
}