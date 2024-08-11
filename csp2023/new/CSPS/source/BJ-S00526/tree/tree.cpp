#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define N 100011
using namespace std;
int n,b[N],c[N],tim[N],T[N];ll a[N],tR,TT[N];
lll calc(int i,int l,int r)
{
	if(c[i]>=0)return (lll)(tR-1ll*l*(l-1)/2)*c[i]+1ll*b[i]*(r-l+1);
	if(r<=T[i])return (lll)(tR-1ll*l*(l-1)/2)*c[i]+1ll*b[i]*(r-l+1);
	if(l>T[i])return r-l+1;
	return (lll)(TT[i]-1ll*l*(l-1)/2)*c[i]+1ll*b[i]*(T[i]-l+1)+r-T[i];
}
/*
lll calc(lll c,lll b,ll a)
{
	
}
*/
int gettim(int i,int lim)
{
	int L=1,R=n,ans=0;tR=1ll*lim*(lim+1)/2;
	while(L<=R)
	{
		int M=L+R>>1;
		//printf("calc(%d,[%d,%d]):%lld\n",i,M,lim,(ll)calc(i,M,lim));
		if(calc(i,M,lim)>=a[i])ans=M,L=M+1;else R=M-1;
	}
	//printf("gettim(i:%d lim:%d) ans:%d\n",i,lim,ans);
	return ans;
}
struct edge{int v,next;edge(){}edge(int _v,int _next){v=_v;next=_next;}}e[N*2];int head[N],sz;
void init(){memset(head,-1,sizeof(head));sz=0;}void insert(int u,int v){e[++sz]=edge(v,head[u]);head[u]=sz;}
void dfs(int u,int f)
{
	for(int i=head[u];~i;i=e[i].next)if(e[i].v^f)dfs(e[i].v,u),tim[u]=min(tim[u],tim[e[i].v]-1);
}
int buc[N];
bool check(int M)
{
	for(int i=1;i<=n;++i)
	{
		if(!(tim[i]=gettim(i,M)))return 0;
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)buc[i]=0;
	for(int i=1;i<=n;++i)if(tim[i]<=0)return 0;else ++buc[i];
	for(int i=1;i<=n;++i)
	{
		if((buc[i]+=buc[i-1])>i)return 0;
	}
	//printf("tim:");for(int i=1;i<=n;++i)printf("%d ",tim[i]);putchar(10);
	return 1;
}
int main()
{
	freopen("tree.in","r",stdin);freopen("tree.out","w",stdout);
	scanf("%d",&n);init();for(int i=1;i<=n;++i)scanf("%lld%d%d",a+i,b+i,c+i),T[i]=c[i]?(b[i]-1)/-c[i]:0,TT[i]=1ll*T[i]*(T[i]+1)/2;
	for(int i=1;i<n;++i){int u,v;scanf("%d%d",&u,&v);insert(u,v);insert(v,u);}
	int L=n,R=1e9,ans=1e9;
	while(L<=R)
	{
		int M=L+R>>1;
		if(check(M))ans=M,R=M-1;else L=M+1;
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);return 0;
}