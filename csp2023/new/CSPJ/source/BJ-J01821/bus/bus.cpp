#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#define LL long long

using namespace std;

const int NR=1e4+10;

struct edge{
	int v,t;
};
struct Node{
	int u,t,st;
	bool operator<(const Node &x)const{
		return st+t>x.st+x.t;
	}
};
vector<edge> a[NR];
priority_queue<Node> q;

int bfs(int s,int e,int k){
	q.push({s,0,0});
	while(!q.empty()){
		int u=q.top().u,t=q.top().t,st=q.top().st;
		q.pop();
		if(u==e&&t%k==0&&st%k==0)return t;
		for(auto next:a[u]){
			int v=next.v,vt=next.t;
			if(v==e&&t%k!=k-1)vt=t+k-1-t%k;
			if(t<vt)q.push({v,vt+1,st+vt-t});
			else q.push({v,t+1,st});
		}
	}
	return -1;
}


int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,t;
		cin >> u >> v >> t;
		a[u].push_back((edge){v,t});
	}
	cout << bfs(1,n,k) << endl;
}