#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int n;
int read()
{
	int x=0,f=1;
	char ch;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}int G[10001][10001];
void floyd()
{
	f(k,1,n)
		f(i,1,n)
			f(j,1,n)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int m,k;
	n=read();
	m=read();
	k=read();
	f(i,1,n)
		f(j,1,n)
		{
			if(i==j)
				G[i][j]=0;
			else
				G[i][j]=2e7;
		}
	f(i,1,m)
	{
		int u,v,a;
		u=read();
		v=read();
		a=read();
		G[u][v]=G[v][u]=1;
	}
	cout<<G[1][n];
	return 0;
}
