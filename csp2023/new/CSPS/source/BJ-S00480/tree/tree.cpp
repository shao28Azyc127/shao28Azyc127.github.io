#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<iostream>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define dF(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;
int read(){
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
const int maxn=141141;
vector<int>g[maxn];
int n;
ll a[maxn],b[maxn],c[maxn],d[maxn];
namespace subtask1{
	ll f[maxn];
	void dfs(int u,int fa){
		
		for(int v:g[u]) if(v^fa){
			dfs(v,u);
		}
	}
	void solve(){
		F(i,1,n) d[i]=(b[i]+a[i]-1)/b[i];
		dfs(1,0);
		cout<<f[1];
	}
}
vector<vector<int>>all;
void dfs(vector<int>vec){
	if((int)vec.size()==n) return all.pb(vec),void();
	vector<int>nxt;
	vector<bool>vis(n+1,0);
	for(int i:vec) vis[i]=1;
	for(int i:vec) for(int j:g[i]) if(!vis[j]) nxt.pb(j);
	for(int i:nxt){
		vec.pb(i);
		dfs(vec);
		vec.pop_back();
	}
}
__int128 calc(ll l,ll r){
	return (r*(r+1)/2)-(l*(l-1)/2);
}
ll gettim(ll i,ll j){
	if(c[i]==0) return (b[i]+a[i]-1)/b[i];
	if(c[i]>0){
		ll l=j,r=100000000,ans=j;
		while(l<=r){
			ll mid=(l+r)>>1;
			if((calc(j,mid)*c[i]+(__int128)b[i]*(mid-j+1))>=a[i]) r=mid-1,ans=mid;
			else l=mid+1;
		}
		return ans;
	}
	else{
		ll x=-c[i];
		ll tt=(b[i]+x-1)/x;
		tt--;
		ll l=j,r=1000000000,ans=j;
		while(l<=r){
			ll mid=(l+r)>>1;
			ll tot=0;
			ll P=min(mid,tt);
			if(P>=j) tot+=(P-j+1)*b[i];
			tot+=(ll)calc(j,P)*c[i];
			if(mid>tt) tot+=mid-max(j-1,tt);
			if(tot>=a[i]) r=mid-1,ans=mid;
			else l=mid+1;
		}
		return ans;
	}
}
ll calc(vector<int>vec){
	int cnt=0;
	ll ans=0;
	for(int i:vec){
		++cnt;
		ans=max(ans,gettim(i,cnt));
	}
	return ans;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	F(i,1,n) cin>>a[i]>>b[i]>>c[i];
	F(i,1,n-1){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int>vec;
	vec.pb(1);
	dfs(vec);
	ll ans=1e18;
	for(vector<int>i:all) ans=min(ans,calc(i));
	cout<<ans;
}
