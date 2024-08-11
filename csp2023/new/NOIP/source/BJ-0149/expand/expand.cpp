#include<bits/stdc++.h>
using namespace std;
namespace solve
{
	int read()
	{
		int res=0;
		char c=0;
		while(c<'0' || c>'9') c=getchar();
		while(c>='0' && c<='9') res*=10,res+=c-'0',c=getchar();
		return res;
	}
	const int N=2000+5;
	int n,m,q;
	int x[N],y[N],xx[N],yy[N];
	bool block[N][N],vis[N][N];
	bool dfs(int i,int j)
	{
		if(i>n) return 0;
		if(j>m) return 0;
		if(block[i][j]) return 0;
		if(i==n&&j==m) return 1;
		if(vis[i][j]) return 0;
		vis[i][j]=1;
		return dfs(i+1,j)||dfs(i,j+1);
	}
	bool sol()
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(x[i]<=y[j]) block[i][j]=1;
				else block[i][j]=0;
				vis[i][j]=0;
				//cout<<block[i][j];
			}
			//cout<<endl;
		}
		if(dfs(1,1)) return 1;
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
			{
				if(x[i]>=y[j]) block[i][j]=1;
				else block[i][j]=0;
				vis[i][j]=0;
				//cout<<block[i][j];
			}
			//cout<<endl;
		}
		if(dfs(1,1)) return 1;
		return 0;
	}
	void main()
	{
		n=read();
		m=read();
		q=read();
		for(int i=1;i<=n;++i) x[i]=read();
		for(int i=1;i<=m;++i) y[i]=read();
		if(sol()) putchar('1');
		else putchar('0');
		while(q--)
		{
			for(int i=1;i<=n;++i) xx[i]=x[i];
			for(int i=1;i<=m;++i) yy[i]=y[i];
			int kx,ky;
			kx=read();
			ky=read();
			for(int i=1;i<=kx;++i)
			{
				int p,v;
				p=read();
				v=read();
				x[p]=v;
			}
			for(int i=1;i<=ky;++i)
			{
				int p,v;
				p=read();
				v=read();
				y[p]=v;
			}
			if(sol()) putchar('1');
			else putchar('0');
			for(int i=1;i<=n;++i) x[i]=xx[i];
			for(int i=1;i<=m;++i) y[i]=yy[i];
		}
	}
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	//freopen("log.txt","w",stderr);
	int c=solve::read();
	solve::main();
	return 0;
}
