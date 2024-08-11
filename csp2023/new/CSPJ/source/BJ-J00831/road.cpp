#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,d,v[100010],a[100010];
ll sum[100010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>d;
	for(int i=2;i<=n;++i)cin>>v[i];
	for(int i=2;i<=n;++i)sum[i]=sum[i-1]+v[i];//u->v sum[v]-sum[u]
	for(int i=1;i<=n;++i)cin>>a[i];
	a[n]=-1;
	ll ans=0,nw=0;
	vector<int>q;
	for(int i=n;i>=1;--i){
		while(!q.empty()&&a[i]<=a[q.back()])q.pop_back();
		q.push_back(i);
	}
	while(q.size()>1){
		int x=q.back();q.pop_back();
		int y=q.back();
		ll nwans=(sum[y]-sum[x]-nw+d-1)/d;
		ans+=nwans*a[x];nw+=nwans*d,nw-=sum[y]-sum[x];
	}
	cout<<ans<<endl;
	return 0;
}