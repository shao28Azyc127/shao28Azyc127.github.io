#include<stdio.h>
#include<vector>
using namespace std;
const int NR=1e5+5;
int a[NR];
int T,F,U;int n;
int fei(int x)
{
	if(x==T) return F;
	if(x==F) return T;
	if(x==U) return U;
	return x>n?x-n:x+n;
}
int fa[NR<<1];
int getfa(int x) {return x==fa[x]?x:fa[x]=getfa(fa[x]);}
bool flag[NR<<1];
int vis[NR<<1];
bool GG;
struct Edge
{
	int v,nxt;
}g[NR<<1];
int fte[NR<<1],gsz;
void adde(int u,int v)
{
	g[++gsz]=(Edge){v,fte[u]};
	fte[u]=gsz;
}
vector<int> ve;
void dfs(int x)
{
	ve.push_back(x);
	if(x==getfa(U)) GG=1;
	for(int i=fte[x];i;i=g[i].nxt)
	{
		int y=g[i].v;
		if(vis[y]==-1) vis[y]=vis[x]^1,dfs(y);
		else if(vis[y]==vis[x]) GG=1;
	}
}
int main()
{
	freopen("tribool.in","r",stdin);
	freopen("tribool.out","w",stdout);
	int C,TT;scanf("%d%d",&C,&TT);
	while(TT--)
	{
		int m;
		scanf("%d%d",&n,&m);
		T=2*n+1,F=2*n+2,U=2*n+3;
		for(int i=1;i<=n;++i) a[i]=i;
		for(int i=1;i<=m;++i)
		{
			char ch;scanf(" %c",&ch);
			if(ch=='T')
			{
				int x;scanf("%d",&x);
				a[x]=T;
			}
			if(ch=='F')
			{
				int x;scanf("%d",&x);
				a[x]=F;
			}
			if(ch=='U')
			{
				int x;scanf("%d",&x);
				a[x]=U;
			}
			if(ch=='+')
			{
				int x,y;scanf("%d%d",&x,&y);
				a[x]=a[y];
			}
			if(ch=='-')
			{
				int x,y;scanf("%d%d",&x,&y);
				a[x]=fei(a[y]);
			}
		}
		//for(int i=1;i<=n;++i) printf("%d ",a[i]);
		//puts("");
		for(int i=1;i<=U;++i) 
		{
			fa[i]=i;
			flag[i]=0;
			vis[i]=-1;
		}
		for(int i=1;i<=n;++i) fa[getfa(i)]=getfa(a[i]);
		gsz=0;
		for(int i=1;i<=U;++i) fte[i]=0;//,printf("%d ",getfa(i));
		//puts("");
		for(int i=1;i<=n;++i)
		{
			adde(getfa(i),getfa(i+n));
			adde(getfa(i+n),getfa(i));
		}
		
		for(int i=1;i<=U;++i) if(vis[i]==-1)
		{
			ve.clear();
			GG=0;
			vis[i]=0;
			dfs(i);
			if(GG)
			{
				for(int j=0;j<ve.size();++j) flag[ve[j]]=1;
			}
		}
		//flag[getfa(U)]=1;
		int ans=0;
		for(int i=1;i<=n;++i) if(flag[getfa(i)]) ++ans;//,printf("%d\n",i);
		printf("%d\n",ans);
	}
	return 0;
}