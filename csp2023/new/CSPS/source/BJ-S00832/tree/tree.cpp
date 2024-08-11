#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100010],b[100010],c[100010];
vector<int> e[100010];
bool flag2=1,flag3=1,flag4=1;
int need[100010];
bool dp[1<<20];
int fa[100010];
int find(int x)
{
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x;
}
bool check(int mid)
{
	for(int i=1; i<=n; ++i)
	{
		int el=1,er=n,mmid,ans=-1;
		while(el<=er)
		{
			mmid=el+er>>1;
			int nowans=0;
			if(c[i]<0)
			{
				int wz=min((b[i]-1)/(-c[i]),mid);
				if(mmid<=wz) nowans+=(wz-mmid+1)*b[i]+(mmid+wz)*(wz-mmid+1)/2*c[i];
				nowans+=mid-wz;
			}
			else nowans+=(mid-mmid+1)*b[i]+(mmid+mid)*(mid-mmid+1)/2*c[i];
			if(nowans>=a[i]) ans=mmid,el=mmid+1;
			else er=mmid-1;
		}
		if(ans==-1) return 0;
		need[i]=ans;
	}
//	for(int i=1; i<=n; ++i) cout<<need[i]<<' '; cout<<'\n';
	if(n<=20)
	{
		dp[0]=1;
		for(int i=1; i<(1<<n); ++i) dp[i]=0;
		for(int i=1; i<(1<<n); i+=2)
		{
			for(int j=1; j<=n; ++j) fa[j]=j;
			for(int j=1; j<=n; ++j)
			{
				if(!(i>>j-1&1)) continue;
				for(int k:e[j])
				{
					if(i>>k-1&1) fa[find(j)]=find(k);
				}
			}
			int same=0; bool flag=1;
			for(int j=1; j<=n; ++j)
			{
				if(i>>j-1&1)
				{
					if(same==0) same=find(j);
					else if(same!=find(j)) { flag=0; break; }
				}
			}
			if(flag)
			{
				for(int j=1; j<=n; ++j)
				{
					if((i>>j-1&1) && __builtin_popcount(i)<=need[j]) dp[i]|=dp[i^(1<<j-1)];
				}
			}
		}
		return dp[(1<<n)-1];
	}
	else if(flag2)
	{
		for(int i=1; i<=n; ++i)
		{
			if(i>need[i]) return 0;
		}
		return 1;
	}
	else if(flag4)
	{
		if(need[1]<=0) return 0;
		sort(need+2,need+n+1);
		for(int i=2; i<=n; ++i)
		{
			if(i>need[i]) return 0;
		}
		return 1;
	}
	return 0;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; ++i) cin>>a[i]>>b[i]>>c[i];
	for(int i=1; i<=n-1; ++i)
	{
		int u,v; cin>>u>>v;
		e[u].push_back(v),e[v].push_back(u);
		flag2&=(u==i && v==i+1);
		flag4&=(u==1);
	}
	int el=n,er=2e9,mid,ans=0;
	while(el<=er)
	{
		mid=el+er>>1;
		if(check(mid)) ans=mid,er=mid-1;
		else el=mid+1;
	}
	cout<<ans;
	return 0;
}