#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
typedef pair<int,int> pii;
const int MX=1e9;
const int NR=1e5+5;
int n;
int a[NR],b[NR],c[NR];
vector<int>e[NR];
namespace subA{
	int mnd[NR],f[NR];
	struct node{int v,id;};
	bool operator < (node x,node y){
		return x.v<y.v;
	}
	priority_queue<node>q;
	void dfs0(int u,int fath){
		mnd[u]=(a[u]-1ll)/b[u]+1ll;
		for(int i=0;i<e[u].size();++i){
			int v=e[u][i];
			if(v==fath)continue;
			dfs0(v,u);
			mnd[u]=max(mnd[v],mnd[u]);
		}
	}
	bool vis[NR];
	void dfs(int u,int fath,int d){
		for(int i=0;i<e[u].size();++i){
			int v=e[u][i];
			if(vis[v])continue;
			q.push({mnd[v],v});
		}
		while(!q.empty()){
			int v=q.top().id;q.pop();
			if(vis[v])continue;
			else{
				vis[v]=true;
				f[v]=d;
				dfs(v,u,d+1);
				break;
			}
		}
	}
	int w[NR];
	void solve(){
		int ans=0;
		dfs0(1,0);
		f[1]=1,vis[1]=true;
		// for(int i=1;i<=n;++i)
		// 	cout<<mnd[i]<<" ";
		// cout<<endl;
		dfs(1,0,2);
		for(int i=1;i<=n;++i){
			// cout<<f[i]<<" ";
			w[f[i]]=i;
		}
		for(int i=1;i<=n;++i)
			ans=max(ans,max(0ll,a[w[i]]-(n-i+1)));
		cout<<ans+n<<endl;
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	bool c0=true;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i]>>c[i];
		if(c[i])c0=false;
	}
	for(int i=1,u,v;i<n;++i)
		cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
	if(c0){subA::solve();return 0;}
	return 0;
}