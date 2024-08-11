#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct tree
{
	long long maxx,add;
};
tree a[800000];
inline void update(int p)
{
	a[p].maxx=max(a[p<<1].maxx,a[(p<<1)|1].maxx)+a[p].add;
}
void add(int l,int r,int ll,int rr,int v,int p)
{
	if(r<ll||l>rr)
	{
		return;
	}
	if(ll<=l&&r<=rr)
	{
		a[p].maxx+=v,a[p].add+=v;
		return;
	}
	int mid=l+r>>1;
	add(l,mid,ll,rr,v,p<<1);
	add(mid+1,r,ll,rr,v,(p<<1)|1);
	update(p);
}
void change(int l,int r,int x,long long v,int p)
{
	if(l==r)
	{
		a[p].maxx=v;
		return;
	}
	int mid=l+r>>1;
	x<=mid?change(l,mid,x,v,p<<1)
	:change(mid+1,r,x,v,(p<<1)|1);
	update(p);
}
long long query(int l,int r,int ll,int rr,int p)
{
	if(r<ll||l>rr)
	{
		return -1e18;
	}
	if(ll<=l&&r<=rr)
	{
		return a[p].maxx;
	}
	int mid=l+r>>1;
	return max(query(l,mid,ll,rr,p<<1),
	query(mid+1,r,ll,rr,(p<<1)|1))+a[p].add;
}
int Task,T,n,m,k,d,x[100010],y[100010],z[100010],p[200010];
vector<int> e[200010];
long long f[200010];
int main()
{
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>Task>>T;
	while(T--)
	{
		cin>>n>>m>>k>>d;
		for(int i=1;i<=m;i++)
		{
			cin>>x[i]>>y[i]>>z[i];
			p[i]=x[i]+1,p[m+i]=x[i]-y[i];
		}
		sort(p+1,p+(m<<1)+1);
		int num=unique(p,p+(m<<1)+1)-p-1;
		for(int i=0;i<=num;i++)
		{
			e[i].clear();
		}
		for(int i=1;i<=m;i++)
		{
			e[lower_bound(p,p+num+1,x[i]+1)-p].emplace_back(i);
		}
		memset(a,0,sizeof(a));
		for(int i=1;i<=num;i++)
		{
			for(int j=0;j<e[i].size();j++)
			{
				int t=e[i][j];
				int P=lower_bound(p,p+num+1,x[t]-y[t])-p;
				add(0,num,0,P,z[t],1);
			}
			int P=lower_bound(p,p+num+1,p[i]-1-k)-p;
			f[i]=max(f[i-1],query(0,num,P,i-1,1)-(long long)d*(p[i]-1));
			change(0,num,i,f[i]+(long long)d*p[i],1);
		}
		cout<<f[num]<<endl;
	}
	return 0;
}