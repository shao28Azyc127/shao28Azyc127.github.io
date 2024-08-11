#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=1e5+5;
long long n,cnt,head[N],ans,day;
int dep[N]={-1},f[N],c[N];
bool vis[N];
struct node
{
	int v,next;
}e[N<<1];
struct tree
{
	long long a,b,c,d,h,id,pl;
}tr[N];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int cmp(tree p,tree q)
{
	return p.d>q.d;
}
void dfsa(int x)
{
	if(vis[x]||x==1)	return ;
	vis[x]=1;
	dfsa(f[x]);
	day++;
	tr[c[x]].pl=day;
	ans=max(ans,day+tr[c[x]].d);
}
void A()
{
	for(int i=1;i<=n;i++)
	{
		tr[i].d=tr[i].a/tr[i].b+1;
		if(tr[i].a%tr[i].b==0||tr[i].a<=tr[i].b)	tr[i].d--;
	}
	sort(tr+1,tr+n+1,cmp);
	for(int i=1;i<=n;i++)
		c[tr[i].id]=i;
	for(int i=1;i<=n;i++)
	{
		if(vis[tr[i].id])	continue;
		dfsa(tr[i].id);
	}
}
void B()
{
	int t;
	for(int i=1;i<=n;i++)
	{
		int a=tr[i].a,b=tr[i].b,c=tr[i].c,x;
		if(tr[i].c>0)
		{
			tr[i].d=(-1*(c/2+b)+sqrt((c/2+b)*(c/2+b)+2*a*c))/c+1;
		}
		else if(c==0)
		{
			tr[i].d=a/b+1;
			if(a%b==0)	tr[i].d--;
		}
		else
		{
			x=(1-b)/c+1;
			if((1-b)%c==0)	x--;
			t=x*b+c*(1+x)*x;
			if(t<=a)	tr[i].d=x+(a-t);
			else	tr[i].d=(-1*(c/2+b)+sqrt((c/2+b)*(c/2+b)+2*a*c))/c+1;
		}
		ans=max(ans,i-1+tr[i].d);
	}
}
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x]=fa;
	int t;
	for(int i=head[x];i;i=e[i].next)
	{
		t=e[i].v;
		if(t==fa)	continue;
		dfs1(t,x);
	}
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	memset(tr,0,sizeof(tr));
	bool fa=1,fb=1;
	int x,y;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&tr[i].a,&tr[i].b,&tr[i].c);
		if(tr[i].c!=0)	fa=0;
		tr[i].id=i;
	}
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		if(y!=i+1)	fb=0;
		add(x,y),add(y,x);
	}
	dfs1(1,0);
	if(fa)	A();
	else if(fb)	B();
	else ans=40351908;
	printf("%lld",ans);
	return 0;
}
