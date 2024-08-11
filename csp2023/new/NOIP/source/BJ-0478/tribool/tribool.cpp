#include<bits/stdc++.h>
#include<cstdio>
#include<map>
using namespace std;
const int N=1e5+5;
int q,T,n,m;
map<char,int> mp;
int a[N],cnt,head[N],tmm[N],b[N],c[N];
bool vis[N];
struct node
{
	int t,v,w,next;
}e[N<<1];
struct op
{
	int x,y,w,type;
}p[N];
void add(int u,int v,int w,int t)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	e[cnt].t=t;
	head[u]=cnt;
}
int dfs(int x,int t)
{
	int tmax=0;
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].t<t&&e[i].t>e[tmax].t)	tmax=i;
	}
	if(x==0)	return -1;
	if(tmax==0)
	{
		if(!vis[x]) b[x]=-1*b[x];
		vis[x]=1;
		return 1;
	}
	if(dfs(e[tmax].v,e[tmax].t)==-1)	b[x]=b[e[tmax].v]*e[tmax].w;
	return 1;
}
void go(int x,int t)
{
	int tmax=0;
	for(int i=head[x];i;i=e[i].next)
	{
		if(e[i].t<t&&e[i].t>e[tmax].t)	tmax=i;
	}
	if(tmax==0)
	{
		b[x]=0;
		return ;
	}
	go(e[tmax].v,e[tmax].t);
	b[x]=0;
	return ;
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int x,y;
	char h;
	mp['T']=1,mp['F']=-1,mp['U']=0;
	cin>>q>>T;
	while(T--)
	{
		int ans=0;
		memset(a,0x3f,sizeof(a));
		memset(tmm,0,sizeof(tmm));
		memset(head,0,sizeof(head));
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(e,0,sizeof(e));
		b[0]=1;
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>h;
			if(h=='T'||h=='F'||h=='U')
			{
				cin>>x;
				a[x]=mp[h];
				tmm[x]=i;
				add(0,x,mp[h],i);
				p[i].type=1,p[i].x=x,p[i].w=mp[h];
			}
			else if(h=='+')
			{
				cin>>x>>y;
				a[x]=a[y];
				tmm[x]=i;
				add(x,y,1,i);
				p[i].type=2,p[i].x=x,p[i].y=y;
			}
			else
			{
				cin>>x>>y;
				a[x]=-1*a[y];
				tmm[x]=i;
				add(x,y,-1,i);
				p[i].type=3,p[i].x=x,p[i].y=y;
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i]==1||a[i]==0||a[i]==-1)	c[i]=b[i]=a[i];
			else	c[i]=b[i]=1;
		for(int i=1;i<=m;i++)
			if(p[i].type==1)	b[p[i].x]=p[i].w;
			else if(p[i].type==2)	b[p[i].x]=b[p[i].y];
			else	b[p[i].x]=b[p[i].y]*-1;
		for(int k=1;k<=100;k++)
		{
		for(int i=1;i<=n;i++)
			if(b[i]!=c[i])	dfs(i,tmm[i]);
		for(int i=1;i<=m;i++)
			if(p[i].type==1)	b[p[i].x]=p[i].w;
			else if(p[i].type==2)	b[p[i].x]=b[p[i].y];
			else	b[p[i].x]=b[p[i].y]*-1;
		for(int i=1;i<=n;i++)	c[i]=b[i];
		for(int i=1;i<=m;i++)
			if(p[i].type==1)	b[p[i].x]=p[i].w;
			else if(p[i].type==2)	b[p[i].x]=b[p[i].y];
			else	b[p[i].x]=b[p[i].y]*-1;
		}
		for(int i=1;i<=n;i++)
			if(b[i]!=c[i])	go(i,tmm[i]);
		for(int i=1;i<=m;i++)
			if(p[i].type==1)	b[p[i].x]=p[i].w;
			else if(p[i].type==2)	b[p[i].x]=b[p[i].y];
			else	b[p[i].x]=b[p[i].y]*-1;
		for(int i=1;i<=n;i++)	if(b[i]==0)	ans++;
		cout<<ans<<endl;
	}
	return 0;
}
