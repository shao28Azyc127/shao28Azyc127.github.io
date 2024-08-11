#include <bits/stdc++.h>
using namespace std;
int c,n,m,q,x[500010],y[500010],tx[500010],ty[500010];
bool f()
{
	int i=1,j=1;
	while(i<=n&&j<=m)
	{
		if(y[j]>x[i])
			i++;
		else if(y[j]<=x[i-1])
			return false;
		else
			j++;
	}
	if(j>m)
		return false;
	return true;
}
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	int i;
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(i=1;i<=m;i++)
		scanf("%d",&y[i]);
	if(n==1&&m==1)
	{
		if(x[1]!=y[1])
			printf("1");
		else
			printf("0");
		while(q--)
		{
			int kx,ky,p,v;
			scanf("%d%d",&kx,&ky);
			for(i=1;i<=n;i++)
				tx[i]=x[i];
			for(i=1;i<=m;i++)
				ty[i]=y[i];
			for(i=1;i<=kx;i++)
			{
				scanf("%d%d",&p,&v);
				tx[p]=v;
			}
			for(i=1;i<=ky;i++)
			{
				scanf("%d%d",&p,&v);
				ty[p]=v;
			}
			if(tx[1]!=ty[1])
				printf("1");
			else 
				printf("0");
		}
	}
	else if(c==2)
	{
		if(n==1)
			x[2]=x[1];
		if(m==1)
			y[2]=y[1];
		if((x[1]>y[1]&&x[2]>y[2])||(x[1]<y[1]&&x[2]<y[2]))
			printf("1");
		else
			printf("0");
		while(q--)
		{
			int kx,ky,p,v;
			scanf("%d%d",&kx,&ky);
			for(i=1;i<=n;i++)
				tx[i]=x[i];
			for(i=1;i<=m;i++)
				ty[i]=y[i];
			for(i=1;i<=kx;i++)
			{
				scanf("%d%d",&p,&v);
				tx[p]=v;
			}
			for(i=1;i<=ky;i++)
			{
				scanf("%d%d",&p,&v);
				ty[p]=v;
			}
			if(n==1)
				tx[2]=tx[1];
			if(m==1)
				ty[2]=ty[1];
			if((tx[1]>ty[1]&&tx[2]>ty[2])||(tx[1]<ty[1]&&tx[2]<ty[2]))
				printf("1");
			else 
				printf("0");
		}
	}
	else
	{
		if(f())
			printf("1");
		else
			printf("0");
		while(q--)
		{
			int kx,ky,p,v;
			scanf("%d%d",&kx,&ky);
			for(i=1;i<=n;i++)
				tx[i]=x[i];
			for(i=1;i<=m;i++)
				ty[i]=y[i];
			for(i=1;i<=kx;i++)
			{
				scanf("%d%d",&p,&v);
				tx[p]=v;
			}
			for(i=1;i<=ky;i++)
			{
				scanf("%d%d",&p,&v);
				ty[p]=v;
			}
			if(n==1)
				tx[2]=tx[1];
			if(m==1)
				ty[2]=ty[1];
			if(f())
				printf("1");
			else 
				printf("0");
		}
	}
	return 0;
}
