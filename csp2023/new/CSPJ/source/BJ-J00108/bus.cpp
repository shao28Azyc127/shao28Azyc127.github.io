#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,K=205;
ll n,m,k;
ll dp[N][K];
struct node{ll v,w;};
vector<node>g[N];
inline ll cg(ll x){
	return x%k;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
		g[u].push_back({v,w});
	}
	ll INF;memset(dp,0x3f,sizeof(dp));INF=dp[0][0];
	queue<pair<ll,ll> >q;q.push({1,0});
	dp[1][0]=0;
	while(!q.empty()){
		pair<ll,ll>now=q.front();q.pop();
		ll u=now.first,t=now.second;
		for(ll i=0;i<(ll)g[u].size();i++){
			ll v=g[u][i].v,a=g[u][i].w;
			if(dp[v][cg(t+1)]==INF){
				if(dp[u][cg(t)]>=a){
				//	ll wait=ceil(((double)a-dp[u][cg(t)])*1.00/k);
				//wait=wait*k;//cout<<"WAI"<<wait<<endl;
					dp[v][cg(t+1)]=dp[u][cg(t)]+1;
					q.push({v,cg(t+1)});
				}
			}
			if(dp[u][cg(t)]<a){
				ll wait=ceil(((double)a-dp[u][cg(t)])/k);
				wait*=k;
				//wait+dp[u][cg(t)]
				if(dp[v][cg(t+1)]>wait+dp[u][cg(t)]+1){
					dp[v][cg(t+1)]=wait+dp[u][cg(t)]+1;
					q.push({v,cg(t+1)});
				}
			}
		}
	}
	if(dp[n][0]==INF){
		cout<<-1;
	}
	else{cout<<dp[n][0];}
	return 0;
}
