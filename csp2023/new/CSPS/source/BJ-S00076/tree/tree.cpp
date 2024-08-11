#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,a[N],b[N],c[N];
vector<ll>g[N];
vector<ll>opt;
bool vis[N];
ll ans=1e15;
double t1,t2;
ll t[N];
bool chk(){
	for(int i=1;i<=n;i++){
		if(t[i]<a[i])return 0;
	}
	return 1;
}
ll cal(){
	ll x=0;
	//~ memset(t,-1,sizeof(a));
	for(int i=0;i<(int)opt.size();i++){
		ll u=opt[i];x++;//cout<<"X";
		t[u]=0;
		for(int j=0;j<=i;j++){
			t[opt[j]]+=max(b[opt[j]]+c[opt[j]]*x,1ll);
		}
	}
	while(!chk()){
		x++;//cout<<"MO";
		for(int i=1;i<=n;i++){
			t[i]+=max(b[i]+c[i]*x,1ll);
		}
	}
	return x;
}
ll T=0;
void dfs(ll s){
	T++;
	//cout<<"TTT"<<T<<endl;
	//cout<<"S"<<s<<' '<<opt.size()<<endl;
	if((clock()-t1)>990){printf("%lld",ans);exit(0);}
	if(s==n){
		//cout<<"O";
		ans=min(ans,cal());return;
	}
	for(int i=0;i<opt.size();i++)
	{
		ll u=opt[i];
		for(int j=0;j<g[u].size();j++){
			
			ll v=g[u][j];
			//cout<<u<<' '<<v<<endl;
			if(vis[v])continue;
			vis[v]=1;
			opt.push_back(v);
			dfs(s+1);
			vis[v]=0;
			//cout<<opt.size()<<endl;
			opt.pop_back();
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);}
	for(int i=1;i<n;i++){
		ll u,v;scanf("%lld%lld",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vis[1]=1;
	opt.push_back(1);
	t1=clock();
	dfs(1);
	printf("%lld",ans);
	return 0;
}
