#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,nn,mm,q;
int x[500005];
int y[500005];
int xx[500005];
int yy[500005];
int dp[205][205];
int work()
{
	memset(dp,0,sizeof(dp));
	if(x[1]<y[1])
	{	for(int i=1;i<=max(n,m);i++) swap(x[i],y[i]);
		swap(n,m);
	}
	if(x[1]==y[1]) return 0;
	dp[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(y[i]>=x[j]) continue;
			if(dp[i][j-1]||dp[i-1][j-1]||dp[i-1][j]) dp[i][j]=1;
		}
	}
	if(dp[n][m]) return 1;
	return 0;
}
signed main()
{
	// system("deff expand2.ans 3.out");
	// return 0;
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>nn>>mm>>q;
	n=nn,m=mm;
	for(int i=1;i<=n;i++) cin>>xx[i],x[i]=xx[i];
	for(int i=1;i<=m;i++) cin>>yy[i],y[i]=yy[i];
	if(c<=5)
	{
		cout<<work();
		while(q--)
		{
			n=nn,m=mm;
			for(int i=1;i<=n;i++) x[i]=xx[i];
			for(int i=1;i<=m;i++) y[i]=yy[i];
			int op1,op2,op3,op4;
			cin>>op1>>op2;
			for(int i=1;i<=op1;i++)
			{
				cin>>op3>>op4;
				x[op3]=op4;
			}
			for(int i=1;i<=op2;i++)
			{
				cin>>op3>>op4;
				y[op3]=op4;
			}
			cout<<work();
		}
		return 0;
	}
}