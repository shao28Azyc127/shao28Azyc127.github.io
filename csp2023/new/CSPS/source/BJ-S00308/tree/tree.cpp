#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
vector<int> g[N];
int a[N],b[N],c[N],h[N];
int ans;
void dfs(int now,int father,int x){
	ans=max(ans,int(x+ceil(a[now]*1.0/max(b[now],1))));
	for(auto v:g[now]){
		if(v!=father){
			dfs(v,now,x+1);
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	int u,v;
	for(int i=1;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,-1,0);
	cout<<ans;
}
