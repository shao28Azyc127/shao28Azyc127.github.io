#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=2e5+10,M=N<<1;
int head[N],ver[M],nxt[M],tot=0,edge[M];//0:same   1:different
void add(int x,int y,int z)
{
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
	edge[tot]=z;
}
int cnt;//the nunber of v
int val[N];//<=n:a[i]  >n:v[i]
bool f[N];//0:same  1:different
int v[N];
int a[N];
bool vis[N];
int col[N];
bool dfs(int x)
{
	bool f=1;
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i],z=edge[i],t=col[x]^z;
		if(vis[y]&&col[y]!=t)f=0;
		if(!vis[y])
		{
			col[y]=t;
			f&=dfs(y);
		}
	}
	return f;
}
bool vis1[N];int zzt=0;
void dfs1(int x)//连通块大小
{
	zzt++;vis1[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		if(vis1[y])continue;
		dfs1(y);
	}
}
#define c(x) memset(x,0,sizeof(x))
void dfs2(int x)
{
	vis1[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i],z=edge[i];
		if(vis1[y])continue;
		if(val[x]==2)val[y]=2;
		else val[y]=val[x]^z;
		dfs2(y);
	}
}
void sol()
{
	int n=read(),m=read();
	c(val),c(f),c(v),c(a),c(vis),c(col),c(vis1),c(head);
	cnt=0;
	tot=0;
	for(int i=1;i<=n;i++)val[i]=i;
	for(int i=1;i<=m;i++)
	{
		char str[5];scanf("%s",str);
		//0:F  1:T  2:U
		if(str[0]=='T')
		{
			int x=read();
			v[++cnt]=1;
			val[x]=cnt+n;
			f[x]=0;
		}
		else if(str[0]=='F')
		{
			int x=read();
			v[++cnt]=0;
			val[x]=cnt+n;
			f[x]=0;
		}
		else if(str[0]=='U')
		{
			int x=read();
			v[++cnt]=2;
			val[x]=cnt+n;
			f[x]=0;
		}
		else if(str[0]=='+')
		{
			int x=read(),y=read();//a[x]=a[y]
			val[x]=val[y];
			f[x]=f[y];
		}
		else if(str[0]=='-')
		{
			int x=read(),y=read();//a[x]=!a[y]
			val[x]=val[y];
			f[x]=!f[y];
		}
	}
	for(int i=1;i<=n;i++)vis[i]=0;
	int ans=0;
	for(int i=1;i<=cnt;i++)val[n+i]=v[i];
	for(int i=1;i<=n;i++)
	{
		int t=val[i];
		add(i,t,f[i]),add(t,i,f[i]);
	}
	for(int i=n+1;i<=n+cnt;i++)dfs2(i);
	for(int i=1;i<=n;i++)if(vis1[i]&&val[i]==2)ans++;
	c(vis1);
	for(int i=1;i<=n;i++)
	{
		zzt=0;
		if(vis[i])continue;
		if(!dfs(i))
		{
			dfs1(i);
			ans+=zzt;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int c=read(),T=read();
	for(int i=1;i<=T;i++)sol();
	return 0;
}