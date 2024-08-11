#include <bits/stdc++.h>
using namespace std;

struct challenge
{
	int x,y,v;
};

const int NR=1e3;
const long long INF=9e18;
int c,t;
int n,m,k,d;
long long ans;
challenge ch[NR+5];
int cha[NR+5][NR+5],cnt[NR+5];


void dfs(int step,int row,long long val)
{
	if(row>k)
		return;	if(step==n+1)
	{
		
		for(int i=1;i<=min(n,k);i++)
			ans=max(ans,val);
	}
	dfs(step+1,0,val);
	val-=d;
	for(int i=1;i<=cnt[step];i++)
	{
		if(row>=ch[cha[step][i]].y)
			val+=ch[cha[step][i]].v;
	}
	dfs(step+1,row+1,val);
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int q=1;q<=t;q++)
	{	
		ans=-INF;
		scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&ch[i].x,&ch[i].y,&ch[i].v);
			cha[ch[i].x][++cnt[ch[i].x]]=i;
		}
		/*
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				memory[i][j]=-INF;*/
		dfs(1,0,0);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}