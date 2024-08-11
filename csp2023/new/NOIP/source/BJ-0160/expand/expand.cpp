#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=2010;
int xx[N],yy[N],x[N],y[N];
int c,n,m,q,tmp1[N],tmp2[N];
bool f[N][N];
void sol()
{
	if(x[1]==y[1])
	{
		putchar(48);
		for(int i=1;i<=n;i++)x[i]=xx[i];
		for(int i=1;i<=m;i++)y[i]=yy[i];
		return;
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=m;j++)f[i][j]=0;
	bool fl=0;
	if(x[1]<y[1])
	{
		for(int i=1;i<=n;i++)tmp1[i]=x[i];
		for(int i=1;i<=m;i++)tmp2[i]=y[i];
		for(int i=1;i<=n;i++)y[i]=tmp1[i];
		for(int i=1;i<=m;i++)x[i]=tmp2[i];
		swap(n,m);
		fl=1;
	}
	//x[1]>y[1]
	
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==n&&j==m)continue;
			if(!f[i][j])continue;
			if(i<n&&x[i+1]>y[j])f[i+1][j]|=f[i][j];
			if(j<m&&x[i]>y[j+1])f[i][j+1]|=f[i][j];
		}
	}
	putchar(f[n][m]^48);
	if(fl)swap(n,m);
	for(int i=1;i<=n;i++)x[i]=xx[i];
	for(int i=1;i<=m;i++)y[i]=yy[i];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	c=read(),n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++)x[i]=xx[i]=read();
	for(int i=1;i<=m;i++)y[i]=yy[i]=read();
	sol();
	for(int i=1;i<=q;i++)
	{
		int kx=read(),ky=read();
		for(int i=1;i<=kx;i++){int a=read(),b=read();x[a]=b;}
		for(int i=1;i<=ky;i++){int a=read(),b=read();y[a]=b;}
		sol();
	}
	return 0;
}
/*
100 + 100 + 25 + 100

NOIP，该如何评价这个词呢

他是小学时难题的代言
他是初一时意外的惊喜
他是初二时命运的玩笑
他是初三时满怀的希望
他是高一时绝望的队线

他，是希望。
希望，是人类最宝贵的东西。

The last chance, but not the last time

AFO - After OI, but never be away from OI.

感谢 NOIP，感谢 OI 在我人生中留下了永远无法忘却的记忆。
感谢路上的所有人。
*/