#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
struct triple
{
	int x,y,v;
	triple(){}
	triple(int x,int y,int v):x(x),y(y),v(v){}
	operator int(){return x;}
};
long long dp[1005][1005],ans;
triple order[100005];
int n,m,k,d,on;
void mian()
{
	cin>>n>>m>>k>>d;
	for(int i=0;i<m;i++)
		cin>>order[i].x>>order[i].y>>order[i].v;
	order[m]=triple(-1,-1,-1);
	on=ans=0;
	memset(dp,0xc0,sizeof dp);
	dp[0][0]=dp[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
			dp[i][j]=dp[i-1][j-1]-d;
		int olt=on,ort=on;
		while(order[ort].x==i)	ort++;
		for(int k=olt;k<ort;k++)
			for(int j=order[k].y;j<=::k;j++)
				dp[i][j]=max(dp[i][j],dp[order[k].x-order[k].y][j-order[k].y]-order[k].y+order[k].v);
		on=ort;
		for(int j=0;j<=k;j++)	dp[i+1][0]=max(dp[i+1][0],dp[i][j]);
		ans=max(ans,dp[i+1][0]);
	}
//	for(int i=0;i<=n;i++)
//		for(int j=0;j<=k;j++)
//			cout<<dp[i][j]<<" \n"[j==k];
	cout<<ans<<endl;
}
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)	mian();
}