#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=114514;

ll n,d;
ll v[N],a[N],dis[N];
ll dp[N];
inline ll opt(int i)
{
	if (i==1) return 0ll;
	if (dp[i]) return dp[i];
	ll mn=LLONG_MAX;
	for (int j=1;j<i;j++)
		mn=min(mn,opt(j)+ll(ceil(1.0*(dis[i]-dis[j])/d)*a[j]));
	return dp[i]=mn;
}

inline bool chk()
{
	ll minidx=1;
	for (int i=2;i<=n;i++)
		if (a[minidx]>a[i]) minidx=i;
	return minidx==1;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>d;
	for (int i=2;i<=n;i++) scanf("%lld",v+i),dis[i]=dis[i-1]+v[i];
	for (int i=1;i<=n;i++) scanf("%lld",a+i);
	if (chk())
	{
		cout<<ceil(1.0*dis[n]/d)*a[1]<<endl;
		return 0;
	} //11~13 15pts
	cout<<opt(n)<<endl;
	
	return 0;
}
