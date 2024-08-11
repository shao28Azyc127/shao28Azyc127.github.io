#include <bits/stdc++.h>
using namespace std;

const int N=2e5+25;

int head[N],nex[N],to[N],len[N],indx=0;

void add_edge(int x,int y,int z)
{
	indx++;
	nex[indx]=head[x];
	to[indx]=y;
	len[indx]=z;
	head[x]=indx;
}

void add(int x,int y,int z)
{
	add_edge(x,y,z);
	add_edge(y,x,z);
}

int col[N],op[N],x[N],sum;
bool vis[N];

bool dfs(int x,int val)
{
	if(vis[x])
	{
		if(col[x]==val)
			return true;
		return false;
	}

	vis[x]=true, col[x]=val, sum++;
	bool ans=true;
	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(len[i]==1)
		{
			if(!dfs(y,val))
				ans=false;
		}
		else
		{
			if(!dfs(y,-val))
				ans=false;
		}
	}
	return ans;
}

void work()
{
	memset(vis,0,sizeof(vis));
	memset(head,0,sizeof(head));
	memset(col,0,sizeof(col));
	memset(op,0,sizeof(op));
	memset(x,0,sizeof(x));
	indx=0;

	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		op[i]=1, x[i]=i;

	for(int i=1;i<=m;i++)
	{
		char v[3];
		scanf("%s",v);
		if(v[0]=='T' || v[0]=='F' || v[0]=='U')
		{
			int id;
			scanf("%d",&id);
			op[id]=0;
			if(v[0]=='T')
				x[id]=1;
			else if(v[0]=='U')
				x[id]=0;
			else
				x[id]=-1;
		}
		else if(v[0]=='+')
		{
			int a,b;
			scanf("%d %d",&a,&b);
			op[a]=op[b], x[a]=x[b];
		}
		else
		{
			int a,b;
			scanf("%d %d",&a,&b);
			op[a]=op[b], x[a]=x[b];
			if(op[a]==0)
				x[a]=-x[a];
			else
				op[a]=-op[a];
		}
	}

	for(int i=1;i<=n;i++)
		if(op[i]!=0)
			add(i,x[i],op[i]);

	int ans=0;
	for(int i=1;i<=n;i++)
		if(op[i]==0 && !vis[i])
		{
			sum=0;
			dfs(i,x[i]);
			if(x[i]==0)
				ans += sum;
		}

	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			sum=0;
			if(!dfs(i,-1))
				ans += sum;
		}

	printf("%d\n",ans);
}

int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--)
		work();
	return 0;
}