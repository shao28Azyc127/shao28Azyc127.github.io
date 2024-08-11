#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,b[100010],c[100010],d[100010];
int fa[100010],f[100010],p[100010];
long long a[100010];
vector<int> e[100010];
void dfs(int now)
{
	for(int i=0;i<e[now].size();i++)
	{
		int t=e[now][i];
		if(t==fa[now])
		{
			continue;
		}
		fa[t]=now,dfs(t);
	}
}
inline __int128_t S(int x,int r)
{
	return r<d[x]?(__int128_t(r)*(r+1)>>1)*c[x]+(long long)r*b[x]
	:(__int128_t(d[x])*(d[x]+1)>>1)*c[x]+(long long)d[x]*b[x]+r-d[x];
}
inline bool judge(int x,int l,__int128_t r)
{
	return r-S(x,l-1)>=a[x];
}
inline bool cmp(int x,int y)
{
	return f[x]<f[y];
}
inline bool judge(int x)
{
	static bool mark[100010];
	for(int i=1;i<=n;i++)
	{
		int l=1,r=min(x,n),ans=0;
		__int128_t v=S(i,x);
		while(l<=r)
		{
			int mid=l+r>>1;
			judge(i,mid,v)?(l=(ans=mid)+1):(r=mid-1);
		}
		if(!ans)
		{
			return 0;
		}
		f[i]=ans,p[i]=i,mark[i]=0;
	}
	sort(p+1,p+n+1,cmp),mark[0]=1;
	for(int i=1,now=0;i<=n;i++)
	{
		int x=p[i];
		while(!mark[x])
		{
			mark[x]=1;
			x=fa[x],now++;
		}
		if(now>f[p[i]])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		d[i]=c[i]<0?(b[i]-1)/(-c[i]):1e9;
	}
	for(int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		e[x].emplace_back(y);
		e[y].emplace_back(x);
	}
	dfs(1);
	int l=1,r=1e9,ans;
	while(l<=r)
	{
		int mid=l+r>>1;
		judge(mid)?(r=(ans=mid)-1):(l=mid+1);
	}
	cout<<ans<<endl;
	return 0;
}