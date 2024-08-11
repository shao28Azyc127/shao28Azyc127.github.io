#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
int c,n,m,q;
int x[500005],y[500005];
int ax[500005],bx[500005];
int ay[500005],by[500005];
int kx,ky;
int minx=1e9,miny=1e9;
int maxx=0,maxy=0;
int minposx=0,maxposx=0;
int minposy=0,maxposy=0;
int vx[500005],vy[500005];
int px[500005],py[500005];
int flag;
int main()
{
	freopen("expand.in","r",stdin);
	freopen("expand.out","w",stdout);
	scanf("%d%d%d%d",&c,&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		if(minx>x[i])
		{
	    	minx=x[i];
	    	minposx=i;
    	}
    	if(maxx<x[i])
		{
	    	maxx=x[i];
	    	maxposx=i;
    	}
    	ax[i]=maxx;
    	bx[i]=minx;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&y[i]);
		if(miny>y[i])
		{
	    	miny=y[i];
	    	minposy=i;
    	}
    	if(maxy<y[i])
		{
	    	maxy=y[i];
	    	maxposy=i;
    	}
    	ay[i]=maxy;
    	by[i]=miny;
	}
	
	
	if(x[1]>y[1]&&x[n]>y[m])flag=1;
	else if(x[1]<y[1]&&x[n]<y[m])flag=-1;
	else flag=0;
	
	int ans=1;
	if(flag==0)printf("0");
	else if(flag==1)
	{
		if(maxx<=miny)ans=0;
		else
		{
			for(int i=1;i<=max(maxposx,minposy);i++)
			{
				if(by[i]>=ax[i])ans=0;
			}
		}
		for(int i=maxposx+1;i<=n;i++)
		{
			if(x[i]<=miny)ans=0;
		}
		printf("%d",ans);
	}
	else
	{
		if(maxy<=minx)ans=0;
		else
		{
			for(int i=1;i<=max(minposx,maxposy);i++)
			{
				if(bx[i]>=ay[i])ans=0;
			}
		}
		for(int i=maxposy+1;i<=m;i++)
		{
			if(y[i]<=minx)ans=0;
		}
		printf("%d",ans);
	}
	
	while(q--)
	{
		minx=1e9,miny=1e9;
		maxx=0,maxy=0;
		minposx=0,maxposx=0;
		minposy=0,maxposy=0;
		scanf("%d%d",&kx,&ky);
		for(int j=1;j<=kx;j++)
		{
			scanf("%d%d",&px[j],&vx[j]);
			swap(x[px[j]],vx[j]);
		}
		for(int i=1;i<=n;i++)
	    {
		    if(minx>x[i])
		    {
	        	minx=x[i];
	        	minposx=i;
    	    }
			if(maxx<x[i])
			{
				maxx=x[i];
				maxposx=i;
			}
			ax[i]=maxx;
			bx[i]=minx;
		}
		for(int j=1;j<=ky;j++)
		{
			scanf("%d%d",&py[j],&vy[j]);
			swap(y[py[j]],vy[j]);
		}
		for(int i=1;i<=m;i++)
		{
			if(miny>y[i])
			{
				miny=y[i];
				minposy=i;
			}
			if(maxy<y[i])
			{
				maxy=y[i];
				maxposy=i;
			}
			ay[i]=maxy;
			by[i]=miny;
		}
		
		
		
		if(x[1]>y[1]&&x[n]>y[m])flag=1;
	    else if(x[1]<y[1]&&x[n]<y[m])flag=-1;
	    else flag=0;
	    
	    ans=1;
	    if(flag==0)printf("0");
		else if(flag==1)
		{
			if(maxx<=miny)ans=0;
			else
			{
				for(int i=1;i<=max(maxposx,minposy);i++)
				{
					if(by[i]>=ax[i])ans=0;
				}
			}
			for(int i=maxposx+1;i<=n;i++)
			{
				if(x[i]<=miny)ans=0;
			}
			printf("%d",ans);
		}
		else
		{
			if(maxy<=minx)ans=0;
			else
			{
				for(int i=1;i<=max(minposx,maxposy);i++)
				{
					if(bx[i]>=ay[i])ans=0;
				}
			}
			for(int i=maxposy+1;i<=m;i++)
			{
				if(y[i]<=minx)ans=0;
			}
			printf("%d",ans);
		}
		
		for(int j=1;j<=ky;j++)
		{
			swap(y[py[j]],vy[j]);
		}
		for(int j=1;j<=kx;j++)
		{
			swap(x[px[j]],vx[j]);
		}
	}
	return 0;
}
