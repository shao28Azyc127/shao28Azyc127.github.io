#include<bits/stdc++.h>
using namespace std;
int c,t;

struct mis
{
	int typ;
	int pos,from;
};

int getnum(char c)
{
	if(c=='T')
	return 1;
	if(c=='F')
	return 2;
	if(c=='U')
	return 3;
	if(c=='+')
	return 4;
	if(c=='-')
	return 5;
	return 0;
}
char ttt[100];
int lis[20]={},aftlis[20]={};
mis td[100010]={};
int lis2[100010];
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d %d",&c,&t);
	if(1<=c&&c<=2)
	{
		while(t--)
		{
			int n,m;
			scanf("%d %d",&n,&m);
			memset(lis,0,sizeof(lis));
			memset(aftlis,0,sizeof(aftlis));
			memset(td,0,sizeof(td));
			for(int i=1;i<=m;i++)
			{
				cin>>ttt;
				td[i].typ=getnum(ttt[0]);
				if(td[i].typ==4||td[i].typ==5)
				scanf("%d%d",&td[i].pos,&td[i].from);
				else
				scanf("%d",&td[i].pos);
			}
			int minu=n;
			for(int i=0;i<pow(3,n);i++)
			{
				int k=i,tagu=0;
				for(int j=1;j<=n;j++)
				{
					lis[j]=k%3;
					aftlis[j]=lis[j];
					k/=3;
					if(lis[j]==2)
					tagu++;
				}
				
				for(int j=1;j<=m;j++)
				{
					if(td[j].typ==1)
					aftlis[td[j].pos]=0;
					if(td[j].typ==2)
					aftlis[td[j].pos]=1;
					if(td[j].typ==3)
					aftlis[td[j].pos]=2;
					if(td[j].typ==4)
					aftlis[td[j].pos]=aftlis[td[j].from];
					if(td[j].typ==5)
					{
						if(aftlis[td[i].from]==2)
						aftlis[td[j].pos]=aftlis[td[j].from];
						else
						aftlis[td[j].pos]=1-aftlis[td[j].from];
					}
				}
				bool flag=1;
				for(int j=1;j<=n;j++)
				{
					if(lis[j]!=aftlis[j])
					{
						flag=0;
						break;
					}
				}
				if(flag)
				minu=min(minu,tagu);
			}
			printf("%d\n",minu);
		}
	}
	else if(3<=c&&c<=4)
	{
		while(t--)
		{
			memset(lis2,0,sizeof(lis2));
			int n,m;
			scanf("%d %d",&n,&m);
			for(int i=1;i<=m;i++)
			{
				int p;
				cin>>ttt;
				scanf("%d",&p);
				lis2[p]=getnum(ttt[0]);
				
			}
			int cnt=0;
			for(int i=1;i<=n;i++)
			if(lis2[i]!=2)
			cnt++;
			printf("%d\n",cnt);
		}
	}
	else
	{
		while(t--)
		{
			memset(lis2,0,sizeof(lis2));
			int n,m;
			scanf("%d %d",&n,&m);
			for(int i=1;i<=m;i++)
			{
				cin>>ttt;
				td[i].typ=getnum(ttt[0]);
				if(td[i].typ==4)
				scanf("%d%d",&td[i].pos,&td[i].from);
				else
				scanf("%d",&td[i].pos);
			}
			
			for(int j=1;j<=m;j++)
			{
				if(td[j].typ==3)
				lis2[td[j].pos]=2;
				else
				lis2[td[j].pos]=lis2[td[j].from];
			}
			int cnt=0;
			for(int i=1;i<=n;i++)
			if(lis2[i]!=2)
			cnt++;
			printf("%d\n",cnt);
		}
	}
	return 0;
}
/*
1 3
3 3
- 2 1
- 3 2
+ 1 3
3 3
- 2 1
- 3 2
- 1 3
2 2
T 2
U 2
*/
