#include <bits/stdc++.h>
using namespace std;

const int NR=200;
int n,m,con,q;
int a[10],b[10],c[10],d[10];

bool dfs(int x,int y,bool which)
{
	bool flag=false;
	if(x==n+1&&y==m+1)
		return true;
	if(x>n+1) return false;
	if(y>m+1) return false;
	if(which==true)
	{
		if(c[x]<=d[y])
			return false;
	}
	if(which==false)
	{
		if(c[x]>=d[y])
			return false;
	}
	if(dfs(x+1,y,which)||dfs(x,y+1,which))
		return true;
	return false;
}

int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&con,&n,&m,&q);
	if(con==1)
	{
		for(int i=1;i<=q+1;i++)
			printf("1");
		puts("");
	}

	if(con==2)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		if((a[1]-b[1])*(a[n]-b[m])>0)
			printf("1");
		else
			printf("0");
		for(int t=1;t<=q;t++)
		{
			int x,y;
			for(int i=1;i<=n;i++)
				c[i]=a[i];
			for(int i=1;i<=m;i++)
				d[i]=b[i];
			scanf("%d%d",&x,&y);
			for(int i=1;i<=x;i++)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				c[u]=v;
			}
			for(int i=1;i<=y;i++)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				d[u]=v;
			}
			if((c[1]-d[1])*(c[n]-d[m])>0)
				printf("1");
			else
				printf("0");
		}
		puts("");
	}
	if(con==3||con==4)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
				c[i]=a[i];
		for(int i=1;i<=m;i++)
				d[i]=b[i];
		if(dfs(1,1,bool(c[1]>d[1]))&&c[1]-d[1]!=0)
			cout<<1;
		else
			cout<<0;
		for(int t=1;t<=q;t++)
		{
			int x,y;
			for(int i=1;i<=n;i++)
				c[i]=a[i];
			for(int i=1;i<=m;i++)
				d[i]=b[i];
			scanf("%d%d",&x,&y);
			for(int i=1;i<=x;i++)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				c[u]=v;
			}
			for(int i=1;i<=y;i++)
			{
				int u,v;
				scanf("%d%d",&u,&v);
				d[u]=v;
			}
			if(dfs(1,1,bool(c[1]>d[1]))&&c[1]-d[1]!=0)
				cout<<1;
			else
				cout<<0;
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}