#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
struct node
{
	int sgn;
	int start,end;
}a[100005];
int g[100005];
int C,T;
int n,m;
char v;
int x,y;
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&C,&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%c",&v);
			if(v=='U'||v=='T'||v=='F')
			{
				scanf("%d",&x);
				if(v=='U')g[i]=0;
				else if(v=='T')g[i]=1;
				else if(v=='F')g[i]=-1;
			}
			else
			{
			    scanf("%d%d",&x,&y);
			    a[i].end=y;
				a[i].start=x;
			    if(v=='+')
			    {
					a[i].sgn*=1;
					
				}
				else if(v=='-')
			    {
					a[i].sgn*=-1;
				}
		    }
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int i=1;i<=100005;i++)
			{
				if(a[i].sgn==-1)
				{
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
