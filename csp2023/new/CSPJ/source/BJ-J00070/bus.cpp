#include <iostream>
#include <queue>
#include <cstdio>
#include <map>
using namespace std;
const int N=1e4+7, M=2e4+7;
const int oo=9e4;
typedef pair<int, int> PII;
int n, m, k;
int head[N], nxt[M], len[M], a[M], to[M], tot=0;
int ans=oo*10;
priority_queue<PII, vector<PII>, greater<PII> > q;
map<PII, bool> ma;
void add(int u, int v, int w, int l){
	tot++;
	nxt[tot]=head[u];
	head[u]=tot;
	to[tot]=v;
	a[tot]=w;
	len[tot]=l;
}
void bfs(int x){
	q.push(make_pair(0, x));
	ma[make_pair(0, x)]=1;
	while(!q.empty()){
		PII now=q.top();q.pop();
		int u=now.second, t=now.first;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i], w=len[i], t2=a[i];
			if(t>=t2 && !ma[make_pair(t+w, v)] && t+w<=oo){
				if(v==n && (t+w)%k==0)
					ans=min(ans, t+w);
				q.push(make_pair(t+w, v));
				ma[make_pair(t+w, v)]=1;
			}
		}
	}
}
int main(){
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u, v, w;
		cin>>u>>v>>w;
		add(u, v, w, 1);//µ¥Ïò±ß
	}
	add(1, 1, 0, k);
	bfs(1);
	cout<<ans<<endl;
	return 0;
}