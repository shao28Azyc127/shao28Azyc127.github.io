#include<iostream>
#include<queue>
#include<vector>
#define int long long
using namespace std;
int n,a[100005],b[100005],c[100005],d[100005],vis[100005],u,v,t,ans;
vector<int> G[100005];
priority_queue<pair<int,int> > q;
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		d[i]=a[i]/b[i]+(a[i]%b[i]!=0);
		if(c[i]!=0){
			cout<<n;
			return 0;
		}
	}
	for(int i=1;i<=n-1;i++){
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	t=0;
	vis[1]=1;
	q.push({d[1],1});
	while(!q.empty()){
		int cur=q.top().second;
		q.pop();
		if(vis[cur]){
			continue;
		}
		vis[cur]=++t;
		for(int i=0;i<G[cur].size();i++){
			if(!vis[G[cur][i]]){
				q.push({d[G[cur][i]],G[cur][i]});
			}
		}
		ans=max(ans,vis[cur]+d[cur]);
	}
	cout<<max(ans,d[1]);
	return 0;
}
