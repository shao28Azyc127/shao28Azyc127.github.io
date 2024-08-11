#include<bits/stdc++.h>
#define ll long long
#define re register
using namespace std;
inline int read()
{
	int res=0,op=0;
	char ch=getchar();
	while(!isdigit(ch))
	{
		op|=ch=='-';
		ch=getchar();
	}
	while(isdigit(ch))
	{
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return op?-res:res;
}
inline void write(int x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}
int n,m,q,a[2005],b[2005],ta[2005],tb[2005];
bool f[2005][2005];
inline bool check()
{
	memset(f,0,sizeof(f));
	f[0][m]=1;
	for(re int i=1;i<=n;++i)
	{
		for(re int j=1;j<=m;++j) f[i][j]|=a[i]>b[j]&&(f[i-1][(j+m-2)%m+1]||f[i][(j+m-2)%m+1]||i!=1&&f[i-1][j]);
		for(re int j=1;j<=m;++j) f[i][j]|=a[i]>b[j]&&(f[i-1][(j+m-2)%m+1]||f[i][(j+m-2)%m+1]||i!=1&&f[i-1][j]);
	}
	if(f[n][m]) return 1;
	memset(f,0,sizeof(f));
	f[0][m]=1;
	for(re int i=1;i<=n;++i)
	{
		for(re int j=1;j<=m;++j) f[i][j]|=a[i]<b[j]&&(f[i-1][(j+m-2)%m+1]||f[i][(j+m-2)%m+1]||i!=1&&f[i-1][j]);
		for(re int j=1;j<=m;++j) f[i][j]|=a[i]<b[j]&&(f[i-1][(j+m-2)%m+1]||f[i][(j+m-2)%m+1]||i!=1&&f[i-1][j]);
	}
	return f[n][m];
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	read();
	n=read();
	m=read();
	q=read();
	for(re int i=1;i<=n;++i) ta[i]=a[i]=read();
	for(re int i=1;i<=m;++i) tb[i]=b[i]=read();
	putchar(check()+'0');
	while(q--)
	{
		int kx=read(),ky=read();
		while(kx--)
		{
			int x=read();
			a[x]=read();
		}
		while(ky--)
		{
			int x=read();
			b[x]=read();
		}
		putchar(check()+'0');
		for(re int i=1;i<=n;++i) a[i]=ta[i];
		for(re int i=1;i<=m;++i) b[i]=tb[i];
	}
	return 0;
}