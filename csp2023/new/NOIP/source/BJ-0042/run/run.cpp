#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int NR=1e5+5;
int x[NR],y[NR],v[NR];
namespace SegT
{
	LL maxx[NR<<2];
	LL add[NR<<2];
	void push_up(int x)
	{
		int ls=x<<1,rs=x<<1|1;
		maxx[ls]+=add[x],maxx[rs]+=add[x];
		add[ls]+=add[x],add[rs]+=add[x];
		add[x]=0;
	}
	void build(int x,int l,int r)
	{
		add[x]=0;
		if(l==r) {maxx[x]=0;return;}
		int ls=x<<1,rs=x<<1|1;
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		maxx[x]=max(maxx[ls],maxx[rs]);
	}
	void modify(int x,int l,int r,int nl,int nr,LL k)
	{
		if(nl<=l&&r<=nr)
		{
			add[x]+=k,maxx[x]+=k;
			return;
		}
		push_up(x);
		int ls=x<<1,rs=x<<1|1;
		int mid=(l+r)>>1;
		if(nl<=mid) modify(ls,l,mid,nl,nr,k);
		if(nr>mid) modify(rs,mid+1,r,nl,nr,k);
		maxx[x]=max(maxx[ls],maxx[rs]);
	}
	LL query(int x,int l,int r,int nl,int nr)
	{
		if(nl<=l&&r<=nr) return maxx[x];
		push_up(x);
		int ls=x<<1,rs=x<<1|1;
		int mid=(l+r)>>1;
		LL res=-1e18;
		if(nl<=mid) res=max(res,query(ls,l,mid,nl,nr));
		if(nr>mid) res=max(res,query(rs,mid+1,r,nl,nr));
		return res;
	}
}
vector<int> ve[NR];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int C,T;scanf("%d%d",&C,&T);
	while(T--)
	{
		int n,m,k,d;scanf("%d%d%d%d",&n,&m,&k,&d);
		for(int i=1;i<=n;++i) ve[i].clear();
		for(int i=1;i<=m;++i) scanf("%d%d%d",x+i,y+i,v+i),ve[x[i]].push_back(i);
		SegT::build(1,0,n);
		for(int i=1;i<=n;++i)
		{
			LL res=SegT::query(1,0,n,0,i-1);
			SegT::modify(1,0,n,i,i,res);
			if(i>=k+1) SegT::modify(1,0,n,i-k-1,i-k-1,-(LL)1e18);
			SegT::modify(1,0,n,0,i-1,-d);
			for(int j=0;j<ve[i].size();++j)
			{
				SegT::modify(1,0,n,0,i-y[ve[i][j]],v[ve[i][j]]);
			}
			//printf("%lld\n",SegT::query(1,0,n,3,3));
		}
		printf("%lld\n",SegT::query(1,0,n,0,n));
	}
	return 0;
}