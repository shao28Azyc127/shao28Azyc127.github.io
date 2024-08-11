#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;
int c,n,m,q,x[MAXN],y[MAXN],a[MAXN],b[MAXN],u,v,kx,ky;
bool dp[MAXN][MAXN];
string ans;
inline int read()
{
	int p=1,q=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		q=(q<<1)+(q<<3)+(ch^48),ch=getchar();
	return p*q;
}
void solve()
{
	// cout<<n<<' '<<m<<endl;
	// for(int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
	// for(int i=1;i<=m;i++) cout<<b[i]<<' ';cout<<endl;
	memset(dp,0,sizeof(dp));
	if(a[1]>b[1])
	{
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				dp[i][j]=((dp[i-1][j-1]|dp[i-1][j]|dp[i][j-1])&(a[i]>b[j]));
		if(dp[n][m]) ans+='1';
		else ans+='0';
	}
	else
	{
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				dp[i][j]=((dp[i-1][j-1]|dp[i-1][j]|dp[i][j-1])&(a[i]<b[j]));
		if(dp[n][m]) ans+='1';
		else ans+='0';
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) x[i]=read(),a[i]=x[i];
	for(int i=1;i<=m;i++) y[i]=read(),b[i]=y[i];
	solve();
	while(q--)
	{
		for(int i=1;i<=n;i++) a[i]=x[i];
		for(int i=1;i<=n;i++) b[i]=y[i];
		kx=read(),ky=read();
		while(kx--)
		{
			u=read(),v=read();
			a[u]=v;
		}
		while(ky--)
		{
			u=read(),v=read();
			b[u]=v;
		}
		solve();
	}
	cout<<ans;
	return 0;
}