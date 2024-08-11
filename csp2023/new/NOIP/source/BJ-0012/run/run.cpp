#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;

struct poi
{
	int x,y,v;
};

poi a[N];

bool cmp(poi a,poi b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.v<b.v;
}

struct node
{
	int l,r;
	long long add, Max;
};

node res[N*4];
int n,m;

void pushup(int rt)
{
	res[rt].Max=max(res[rt*2].Max,res[rt*2+1].Max);
}

void add(int rt,long long val)
{
	res[rt].add += val;
	res[rt].Max += val;
}

void pushdown(int rt)
{
	if(res[rt].add)
	{
		add(rt*2,res[rt].add);
		add(rt*2+1,res[rt].add);
		res[rt].add=0;
	}
}

void update(int rt,int l,int r,long long k)
{
	if(l<=res[rt].l && res[rt].r<=r)
	{
		add(rt,k);
		return;
	}

	pushdown(rt);
	int mid=(res[rt].l+res[rt].r)/2;
	if(l<=mid)
		update(rt*2,l,r,k);
	if(mid+1<=r)
		update(rt*2+1,l,r,k);
	pushup(rt);
}

long long query(int rt,int l,int r)
{
	if(l<=res[rt].l && res[rt].r<=r)
		return res[rt].Max;

	pushdown(rt);
	int mid=(res[rt].l+res[rt].r)/2;
	if(l>mid)
		return query(rt*2+1,l,r);
	if(mid+1>r)
		return query(rt*2,l,r);
	return max(query(rt*2,l,r),query(rt*2+1,l,r));
}

void build(int rt,int l,int r)
{
	res[rt].l=l, res[rt].r=r, res[rt].add=0;
	if(l==r)
	{
		res[rt].Max=0;
		return;
	}

	int mid=(l+r)/2;
	build(rt*2,l,mid);
	build(rt*2+1,mid+1,r);
	pushup(rt);
}

int t;

void work()
{
	int k,d;
	scanf("%d %d %d %d",&n,&m,&k,&d);
	memset(a,0,sizeof(a));
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].v);

	for(int i=1;i<=m;i++)
		a[m+i].x=a[i].x-a[i].y;

	m *= 2;
	sort(a+1,a+m+1,cmp);

	build(1,1,m);

	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i].v==0)
			update(1,i,i,ans+1ll*a[i].x*d);
		else
		{
			int l=1,r=i,pos=-1;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(a[mid].x<=a[i].x-a[i].y)
					pos=mid, l=mid+1;
				else
					r=mid-1;
			}

			update(1,1,pos,a[i].v);

			l=1,r=i,pos=-1;
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(a[mid].x>=a[i].x-k)
					pos=mid, r=mid-1;
				else
					l=mid+1;
			}

			ans=max(ans,query(1,pos,i)-1ll*a[i].x*d);
		}
	}
	printf("%lld\n",ans);
}

int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	int c,t;
	scanf("%d %d",&c,&t);
	while(t--)
		work();
	return 0;
}