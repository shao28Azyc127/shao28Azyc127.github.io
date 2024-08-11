#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,q,x0[50001],y0[50001],x2[50001],y2[50001];
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x2[i]);
		x0[i]=x2[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&y2[i]);
		y0[i]=y2[i];
	}
	while(q--)
	{
		int kx,ky;
		scanf("%d%d",&kx,&ky);
		for(int i=1;i<=kx;i++)
		{
			int px,vx;
			scanf("%d%d",&px,&vx);
			x0[px]=vx;
		}
		for(int i=1;i<=ky;i++)
		{
			int py,vy;
			scanf("%d%d",&py,&vy);
			y0[py]=vy;
		}
		if(x0[n]>=y0[m])
			cout<<0;
		else
		{
			int p=n-1;
			for(int i=m;i>=2;i--)
			{
				for(int j=p;j>=2;j--)
				{
					if(y0[i]>x0[j])
						p=j;
					else
						break;
				}
			}
			if(p==2)
				cout<<1;
			else
				cout<<0;
		}
		
		for(int i=1;i<=n;i++)
			x0[i]=x2[i];
		for(int i=1;i<=m;i++)
			y0[i]=y2[i];
	}
	return 0;
}
