#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=10007;
vector<int> e[maxn];
int ans[maxn];
bool vis[maxn];

void bfs(){
	queue<int> q;
	q.push(1);
	ans[1]=0;
	vis[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(long unsigned i=0;i<e[u].size();i++){
			int v=e[u][i];
			if(vis[v]==false){
				q.push(v);
				ans[v]=ans[u]+1;
				vis[v]=1;
				if(v==n)return;
			}
		}
	}
}

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,a;
		cin>>u>>v>>a;
		e[u].push_back(v);
	}
	memset(ans,0x3f3f3f3f,sizeof(ans));
	bfs();
	int lon=ans[n];
	if(lon%k==0){
		cout<<lon;
	}else{
		cout<<k*(lon/k+1);
	}
	return 0;
}