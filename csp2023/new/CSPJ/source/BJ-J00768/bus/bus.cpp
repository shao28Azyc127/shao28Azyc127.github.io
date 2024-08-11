#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+9;
int n, m, k;
struct node{
	int to, op;
};
vector<node> g[N];
int dfn[N], low[N], tm, tot, f[N], cm[N], dis[N],run;
stack<int> s;
bool vis[N];
bool in[N];

stack<int> com;
bool kil, kk;
queue<int> q;
bool flag = 1;
int main(){
	cin>>n>>m>>k;
	if(k!=1) flag = 0;
	for(int i=1; i<=m; ++i){
		int v1, v2, a;
		scanf("%d%d%d", &v1, &v2, &a);
		g[v1].push_back({v2, a});
		if(a) flag = 0;
	}
	if(flag){
		q.push(1);
		vis[1] = 1;
		while(!q.empty()){
			int t = q.front();
			q.pop();
			for(int i=0; i<g[t].size(); ++i){
				int x = g[t][i].to;
				if(vis[x]) continue;
				q.push(x);
				vis[x] = 1;
				dis[x] = dis[t] + 1;
				if(x==n){
					printf("%d", dis[x]);
					return 0;
				}
			}
		}
		printf("-1");
		return 0;
	}
	if(!kk) printf("-1");
	return 0;
}
