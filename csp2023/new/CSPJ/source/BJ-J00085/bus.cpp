#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int dis[10010],n,m,k;
bool vis[10010];
vector<int> edg[10010];
bool flag=true;
void solve1(){
	memset(dis,0x3f,sizeof(dis));
	q.push(1);
	dis[1]=0;
	vis[1]=true;
	while(!q.empty()){
		int cur=q.front();q.pop();
		for(int i=0;i<edg[cur].size();i++){
			int to=edg[cur][i];
			if(vis[to])continue;
			dis[to]=dis[cur]+1;
			vis[to]=true;
			q.push(to);
		}
	}
	if(dis[n]!=0x3f3f3f3f)cout<<dis[n];
	else cout<<-1;
}
void solve2(){
	cout<<-1;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,a;
		cin>>u>>v>>a;
		edg[u].push_back(v);
		if(a!=0)flag=false;
	}
	if(flag)solve1();
	else solve2();
}