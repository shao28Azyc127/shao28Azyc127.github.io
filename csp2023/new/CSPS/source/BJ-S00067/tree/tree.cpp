#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
const int NR=1e5+5;
LL a[NR];
int b[NR],c[NR];
struct Edge
{
	int v,nxt;
}g[NR<<1];
int fte[NR],gsz;
void adde(int u,int v)
{
	g[++gsz]=(Edge){v,fte[u]};
	fte[u]=gsz;
}
int dp[(1<<20)+5];
int getd(int x,int y)
{
	int l=1,r=1e9,res=1e9+1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if((LL)c[x]*(mid+y-1)+b[x]>=1)
		{
			if((y+y+mid-1ll)*mid/2*(__int128)c[x]+b[x]*1ll*mid>=a[x]) res=mid,r=mid-1;
			else l=mid+1;
		}
		else
		{
			int t=(b[x]-1)/(-c[x]);
			//if(x==4&&y==3) printf("%d\n",t);
			if(t<y) t=y-1;
			if((y+y+(t-y+1)-1ll)*(t-y+1)/2*(__int128)c[x]+b[x]*1ll*(t-y+1)+y+mid-1-t>=a[x]) res=mid,r=mid-1;
			else l=mid+1;
		}
	}
	return res;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%d%d",a+i,b+i,c+i);
	}
	bool B=1;
	for(int i=1;i<n;++i)
	{
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);
		adde(v,u);
		B&=(u==i&&v==i+1);
	}
	if(B)
	{
		int ans=0;
		for(int i=1;i<=n;++i) ans=max(ans,getd(i,i)+i-1);
		printf("%d\n",ans);
		return 0;
	}
	dp[1]=getd(1,1);
	/*
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			printf("%d %d %d\n",i,j,getd(i,j));
	*/
	for(int i=2;i<(1<<n);++i)
	{
		int ct=__builtin_popcount(i);
		if(ct==1) continue;
		for(int j=1;j<=n;++j)
		{
			if((i>>(j-1))&1)
			{
				int x=i^(1<<(j-1));
				if(dp[x]>1e9) continue;
				bool flag=0;
				for(int k=fte[j];k;k=g[k].nxt)
				{
					int y=g[k].v;
					if((x>>(y-1))&1) {flag=1;break;}
				}
				if(flag) dp[i]=min(dp[i],max(dp[x],getd(j,ct)+ct-1));
			}
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
	return 0;
}