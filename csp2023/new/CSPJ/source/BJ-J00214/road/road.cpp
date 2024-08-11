#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

typedef pair<int,int> pii;
const int MAXN=100010;
const long long INF=1e15;
pii A[MAXN];
int v[MAXN],a[MAXN];
int n,d;
long long dis[MAXN];
long long cs[MAXN];
long long dp[MAXN];//min cost to buy iL
int mc[MAXN*100];
int li[MAXN]={0};

bool L()
{
	for(int i=1;i<=n;i++) if(a[i]<a[1]) return 0;
	return 1;
}

bool B()
{
	for(int i=1;i<n;i++) if(v[i]%d!=0) return 0;
	return 1;
}

bool cmp(pii a,pii b)
{
	return (a.first!=b.first?a.first<b.first:a.second<b.second);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>d;
	for(int i=1;i<n;i++) cin>>v[i];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		A[i]=make_pair(a[i],i);
	}
	if(L())
	{
		int s=0;
		for(int i=1;i<n;i++) s+=v[i];
		int m=(s%d==0?s/d:s/d+1);
		cout<<a[1]*m;
		return 0;
	}
	if(B())
	{
		sort(A+1,A+n+1,cmp);
		dis[n]=0;
		for(int i=n-1;i>=1;i--) dis[i]=dis[i+1]+v[i];
		int ans=0;
		int prs=n;
		for(int i=1;i<=n;i++)
		{
		//	cout<<a[i].first<<'\t'<<a[i].second<<endl;
			if(A[i].second<prs)
			{
				int pd=dis[A[i].second]-dis[prs];
				int l=(pd%d==0?pd/d:pd/d+1);
				ans+=l*A[i].first;
				prs=A[i].second;
			//	cout<<prs<<' '<<ans<<endl;
			}
		}
		cout<<ans;
	}
	for(int i=1;i<=n;i++) dis[i+1]=dis[i]+v[i];
	for(int i=1;i<=n;i++) {cs[i]=(dis[i]%d==0?dis[i]/d:dis[i]/d+1); /*cout<<cs[i]<<endl;*/}
	for(long long i=1;i<=cs[n];i++) dp[i]=INF;
	li[1]=a[1];
	for(int i=2;i<=n;i++) {li[i]=min(li[i-1],a[i]); /*cout<<li[i]<<endl;*/}
	mc[0]=a[1];
	for(int i=1;i<n;i++)
		for(int j=cs[i];j<=cs[i+1];j++) {mc[j]=li[i];/* cout<<j<<' '<<mc[j]<<endl;*/}
	for(long long i=1;i<=cs[n];i++)
	{
		for(long long j=0;j<i;j++) dp[i]=min(dp[i],dp[j]+mc[j]*(i-j));
	}
	cout<<dp[cs[n]];
	return 0;
}
