#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=0;
int n;
ll a[100005],b[100005],c[100005];
vector<int>v[100005];
ll calch(ll l,ll r,ll b,ll c){
	if(c>=0)return (r-l+1)*b+(l+r)*(r-l+1)/2*c;
	if(r<=(1-b)/c) return (r-l+1)*b+(l+r)*(r-l+1)/2*c;
	ll m=(1-b)/c;
	return (m-l+1)*b+(l+m)*(m-l+1)/2*c+(r-m);
}
ll calcmntime(ll l,ll r,ll a,ll b,ll c){
	ll mid;
	while(l<r){
		mid=l+r>>1;
		if(calch(l,mid,b,c)>=a)r=mid;
		else l=mid+1;
	}
	return l;
}
ll dp[100005],sz[100005];
bool cmp(pair<ll,ll>a,pair<ll,ll>b){
	return a.second+b.first<b.second+a.first;
}
void dfs(int now,int fa){
	dp[now]=(a[now]+b[now]-1)/b[now];
	sz[now]=1;
	vector<pair<ll,ll>>tmp;
	for(auto i:v[now]){
		if(i==fa)continue;
		dfs(i,now);
		sz[now]+=sz[i];
		tmp.push_back({dp[i],sz[i]});
	}
	sort(tmp.begin(),tmp.end(),cmp);
	ll sum=1;
	for(auto i:tmp){
		dp[now]=max(dp[now],sum+i.first);
		sum+=i.second;
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	bool tpa=1,tpb=1,tpd=1;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i],tpa&=!c[i];
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		tpb&=(y==x+1);
		tpd&=(x==1);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if(tpb){
		ll mx=0x3f3f3f3f3f3f3f3fll;
		for(int i=1;i<=n;i++){
			mx=max(mx,calcmntime(i,1e9,a[i],b[i],c[i]));
		}
		cout<<mx<<endl;
	}
	if(tpa){
		dfs(1,1);
		cout<<dp[1]<<endl;
	}
	return 0;
}