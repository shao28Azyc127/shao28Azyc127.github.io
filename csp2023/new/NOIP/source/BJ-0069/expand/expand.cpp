#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
const int N=5e5+5;
int tid,n,m,q;
int num[2][N];
namespace sub1
{
	const int M=2005;
	int dp[M][M];
	int solve(int id,int nn,int mm)
	{
		int i,j;
		memset(dp,0,sizeof(dp));
		dp[1][1]=1;
		for(i=1;i<=nn;i++)
		{
			for(j=1;j<=mm;j++)
			{
				if(i<nn) {
					if(j<mm&&num[id][i+1]>num[id^1][j+1])
						dp[i+1][j+1]|=dp[i][j];
					if(num[id][i+1]>num[id^1][j])
						dp[i+1][j]|=dp[i][j];
				}
				if(j<mm) {
					if(num[id][i]>num[id^1][j+1])
						dp[i][j+1]|=dp[i][j];
				}
			}
		}
		return dp[nn][mm];
	}
	int tnum[2][M];
	void sol()
	{
		int i,j,k,p;
		if(num[0][1]>num[1][1]) {
			if(num[0][n]>num[1][m]) printf("%d",solve(0,n,m));
			else printf("0");
		}
		else if(num[0][1]==num[1][1]) printf("0");
		else {
			if(num[0][n]<num[1][m]) printf("%d",solve(1,m,n));
			else printf("0");
		}
		for(i=1;i<=n;i++) tnum[0][i]=num[0][i];
		for(i=1;i<=m;i++) tnum[1][i]=num[1][i];
		
		int x,y;
		for(i=1;i<=q;i++)
		{
			for(j=1;j<=n;j++) num[0][j]=tnum[0][j];
			for(j=1;j<=m;j++) num[1][j]=tnum[1][j];
			scanf("%d%d",&x,&y);
			// cout<<"adfb "<<x<<" "<<y<<endl;	
			for(j=1;j<=x;j++) {
				scanf("%d%d",&k,&p);
				num[0][k]=p;
			}
			for(j=1;j<=y;j++) {
				scanf("%d%d",&k,&p);
				num[1][k]=p;
			}
			
			if(num[0][1]>num[1][1]) {
				if(num[0][n]>num[1][m]) printf("%d",solve(0,n,m));
				else printf("0");
			}
			else if(num[0][1]==num[1][1]) printf("0");
			else {
				if(num[0][n]<num[1][m]) printf("%d",solve(1,m,n));
				else printf("0");
			}
		}
		puts("");
		return;	
	}
}
namespace sub2
{
	int tnum[N],mn[N],mx[N];
	int solve(int id,int nn,int mm)
	{
		int i,j;
		// cout<<id<<" "<<nn<<" "<<mm<<endl;
		for(i=1;i<=mm;i++) tnum[i]=num[id^1][i],mn[i]=i;
		sort(tnum+1,tnum+1+mm);
		sort(mn+1,mn+1+mm,[](int i,int j){ return num[0][i]<num[0][j]||(num[0][i]==num[0][j]&&i<j);});
		mn[0]=mm+1;
		for(i=1;i<=mm;i++)
		{
			mx[i]=max(mx[i-1],mn[i]);
			mn[i]=min(mn[i],mn[i-1]);
		}
		int now=1,mxx;
		for(i=1;i<=nn;i++) {
			j=lower_bound(tnum+1,tnum+1+mm,num[id][i])-tnum-1;
			if(j==0) return false;
			if(mx[j]<now) return false;
			//cout<<i<<" "<<j<<" "<<mn[j]<<" "<<mx[j]<<" "<<num[1][i]<<" "<<tnum[j]<<" "<<now<<endl;
			if(now<mn[j]) {
				for(;now<mn[j];now++)
					if(num[id^1][now]>=mxx) return false;
				mxx=0;
			}
			mxx=max(mxx,num[id][i]);
		}
		//exit(0);
		return true;
	}
	pii stk[2][N];
	int top[2]={0};
	void sol()
	{
		int i,j,k,p;
		if(num[0][1]>num[1][1]) {
			if(num[0][n]>num[1][m]) printf("%d",solve(0,n,m));
			else printf("0");
		}
		else if(num[0][1]==num[1][1]) printf("0");
		else {
			if(num[0][n]<num[1][m]) printf("%d",solve(1,m,n));
			else printf("0");
		}
		
		int x,y;
		for(i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			for(j=1;j<=x;j++)
			{
				scanf("%d%d",&k,&p);
				stk[0][++top[0]]=mkp(k,num[0][k]);
				num[0][k]=p;
			}
			for(j=1;j<=y;j++) 
			{
				scanf("%d%d",&k,&p);
				stk[1][++top[1]]=mkp(k,num[1][k]);
				num[1][k]=p;
			}
						
			if(num[0][1]>num[1][1]) {
				if(num[0][n]>num[1][m]) printf("%d",solve(0,n,m));
				else printf("0");
			}
			else if(num[0][1]==num[1][1]) printf("0");
			else {
				if(num[0][n]<num[1][m]) printf("%d",solve(1,m,n));
				else printf("0");
			}
		
			for(;top[0];--top[0])
				num[0][stk[0][top[0]].fi]=stk[0][top[0]].se;
			for(;top[1];--top[1])
				num[1][stk[1][top[1]].fi]=stk[1][top[1]].se;
		}
		puts("");
		return;
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&tid,&n,&m,&q);
	int i,j;
	for(i=1;i<=n;i++) scanf("%d",&num[0][i]);
	for(i=1;i<=m;i++) scanf("%d",&num[1][i]);
	if(tid<=7)	{
		sub1::sol();
		return 0;
	}
	sub2::sol();
	return 0;
}