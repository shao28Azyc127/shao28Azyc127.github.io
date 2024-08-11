#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;
const int NR=2e3+5;
const int MR=5e5+5;
int dp[NR][NR];
int yuanshix[MR],yuanshiy[MR];
int x[MR],y[MR];
int C;
int Q;
bool Ret;
bool ans;
clock_t st;
void dfs(int nwx,int nwy,int n,int m)
{
	clock_t stt=clock();
	if(nwx==n&&nwy==m) {ans=1;Ret=1;return;}
	if((double)(clock()-st)/CLOCKS_PER_SEC>0.016) {Ret=1;return;}
	//if(!(rand()|63)) return;
	int t=rand()&1;
	if(t)
	{
		if(nwx<n&&x[nwx+1]<y[nwy]) {dfs(nwx+1,nwy,n,m);if(Ret) return;}
		if(nwy<m&&x[nwx]<y[nwy+1]) {dfs(nwx,nwy+1,n,m);if(Ret) return;}
	}
	else
	{
		if(nwy<m&&x[nwx]<y[nwy+1]) {dfs(nwx,nwy+1,n,m);if(Ret) return;}
		if(nwx<n&&x[nwx+1]<y[nwy]) {dfs(nwx+1,nwy,n,m);if(Ret) return;}
	}
	
}
void solve(int n,int m)
{
	if(C<=7)
	{
		if(x[1]>y[1]) 
		{
			swap(n,m);
			for(int i=1;i<=n||i<=m;++i) swap(x[i],y[i]);
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				dp[i][j]=0;
				if(x[i]>=y[j]) continue;
				if(i==1&&j==1) dp[i][j]=1;
				else if(i==1) dp[i][j]=dp[i][j-1];
				else if(j==1) dp[i][j]=dp[i-1][j];
				else dp[i][j]=(dp[i-1][j-1]|dp[i-1][j]|dp[i][j-1]);
			}
		/*
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j) printf("%d",dp[i][j]);
			puts("");
		}
		*/
		putchar(dp[n][m]+'0');
		return;
	}
	/*
	if(C<=14)
	{
		int maxx=1;
		for(int i=2;i<=n;++i) if(x[i]>x[maxx]) maxx=i;
		int res=m+1;
		for(int i=1;i<=m;++i) if(x[maxx]<y[i]) {res=i;break;}
		if(res==m+1) {putchar('0');return;}
		int nwx=1,nwy=1;
		
	}
	*/
	if(x[1]>y[1]) 
	{
		swap(n,m);
		for(int i=1;i<=n||i<=m;++i) swap(x[i],y[i]);
	}
	if(x[1]==y[1]) {putchar('0');return;}
	/*
	int nwx=1,nwy=1;
	//int T=100000;
	//printf("%d\n",T);
	while(T--)
	{
		nwx=1,nwy=1;
		for(int i=1;i<=n+m-2;++i)
		{
			int t=rand()&1;
			if(t)
			{
				if(nwx<n&&x[nwx+1]<y[nwy]) ++nwx;
				else if(nwy<m&&x[nwx]<y[nwy+1]) ++nwy;
				else break;
			}
			else
			{
				if(nwy<m&&x[nwx]<y[nwy+1]) ++nwy;
				else if(nwx<n&&x[nwx+1]<y[nwy]) ++nwx;
				else break;
			}
		}
		if(nwx==n&&nwy==m) {putchar('1');return;}
	}
	putchar('0');
	*/
	Ret=ans=0;
	st=clock();
	dfs(1,1,n,m);
	if(ans) {putchar('1');return;}
	Ret=ans=0;
	st=clock();
	dfs(1,1,n,m);
	if(ans) {putchar('1');return;}
	Ret=ans=0;
	st=clock();
	dfs(1,1,n,m);
	printf("%d",ans);
}
int main()
{
	srand(19248);
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int n,m,q;scanf("%d%d%d%d",&C,&n,&m,&q);
	Q=q;
	for(int i=1;i<=n;++i) scanf("%d",x+i),yuanshix[i]=x[i];
	for(int i=1;i<=m;++i) scanf("%d",y+i),yuanshiy[i]=y[i];
	solve(n,m);
	while(q--)
	{
		int kx,ky;scanf("%d%d",&kx,&ky);
		for(int i=1;i<=n;++i) x[i]=yuanshix[i];
		for(int i=1;i<=m;++i) y[i]=yuanshiy[i];
		while(kx--)
		{
			int p,q;scanf("%d%d",&p,&q);
			x[p]=q;
		}
		while(ky--)
		{
			int p,q;scanf("%d%d",&p,&q);
			y[p]=q;
		}
		solve(n,m);
	}
	puts("");
	return 0;
}