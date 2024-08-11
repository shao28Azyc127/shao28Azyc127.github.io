#include<cstdio>
const int N=2010;
int x[N],y[N],a[N],b[N];
bool f[N][N];
int n,m,q;
inline void solve()
{
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) f[i][j]=false;
	if(a[1]>b[1]&&a[n]>b[m])
	{
		f[1][1]=true;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(a[i]>b[j]&&(f[i-1][j]||f[i][j-1]||f[i-1][j-1])) f[i][j]=true;
		putchar(f[n][m]?'1':'0');
	}
	else if(a[1]<b[1]&&a[n]<b[m])
	{
		f[1][1]=true;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(a[i]<b[j]&&(f[i-1][j]||f[i][j-1]||f[i-1][j-1])) f[i][j]=true;
		putchar(f[n][m]?'1':'0');
	}
	else putchar('0');
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%*d%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),x[i]=a[i];
	for(int i=1;i<=m;++i) scanf("%d",&b[i]),y[i]=b[i];
	solve();
	while(q--)
	{
		for(int i=1;i<=n;++i) a[i]=x[i];
		for(int i=1;i<=m;++i) b[i]=y[i];
		int c,d,p,q;
		scanf("%d%d",&c,&d);
		while(c--) scanf("%d%d",&p,&q),a[p]=q;
		while(d--) scanf("%d%d",&p,&q),b[p]=q;
		solve();
	}
	puts("");
	return 0;
}