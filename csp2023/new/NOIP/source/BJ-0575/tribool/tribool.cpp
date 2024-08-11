#include <bits/stdc++.h>
using namespace std;

const int NR=1e5;

struct ope
{
	char ch;
	int a,b;
} op[NR+5];


int c,t;
int n,m;
int tr[15],af[15],ans;//T1,F0,U2
char cover[NR+5];

bool check()
{
	for(int i=1;i<=n;i++)
		af[i]=tr[i];
	for(int i=1;i<=m;i++)
	{
		if(op[i].ch=='T')
			af[op[i].a]=1;
		if(op[i].ch=='F')
			af[op[i].a]=0;
		if(op[i].ch=='U')
			af[op[i].a]=2;
		if(op[i].ch=='+')
			af[op[i].a]=af[op[i].b];
		if(op[i].ch=='-')
		{
			if(af[op[i].b]==2)
				af[op[i].a]=2;
			else
				af[op[i].a]=1-af[op[i].b];
		}
	}
	for(int i=1;i<=n;i++)
		if(af[i]!=tr[i])
			return false;
	return true;
}

void dfs(int step)
{
	if(step==n+1)
	{
		if(check())
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(tr[i]==2)
					cnt++;
			ans=min(ans,cnt);
		}
		return;
	}
	for(int i=0;i<=2;i++)
	{
		tr[step]=i;
		dfs(step+1);
	}
	return;
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	scanf("%d%d",&c,&t);

	if(c==1||c==2)
	{
		
		for(int q=1;q<=t;q++)
		{
			scanf("%d%d",&n,&m);
			ans=n;
			for(int i=1;i<=m;i++)
			{
				scanf("%*c");
				scanf("%c",&op[i].ch);
				if(op[i].ch=='T'||op[i].ch=='U'||op[i].ch=='F')
					scanf("%d",&op[i].a);
				else
					scanf("%d%d",&op[i].a,&op[i].b);
			}
		
			dfs(1);
			printf("%d\n",ans);
		}
	}

	if(c==3||c==4)
	{
		for(int q=1;q<=t;q++)
		{
			scanf("%d%d",&n,&m);
			int cnt=0;
			for(int i=1;i<=m;i++)
			{
				char cha;
				int x;
				scanf("%*c");
				scanf("%c",&cha);
				scanf("%d",&x);
				cover[x]=cha;
			}
			for(int i=1;i<=n;i++)
				if(cover[i]=='U')
					cnt++;
			printf("%d\n",cnt);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}