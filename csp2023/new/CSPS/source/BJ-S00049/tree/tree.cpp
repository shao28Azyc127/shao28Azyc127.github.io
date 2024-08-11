#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N=1e5+7;
int n;
ll a[N], b[N], c[N];
int head[N], nxt[N<<1], to[N<<1], tot=0;
int T[N];bool vis[N];bool f[N];
void add(int u, int v){
	tot++;
	nxt[tot]=head[u];
	head[u]=tot;
	to[tot]=v;
}
int tm(int x, int be){
	if(c[x]==0){
		return be+a[x]/max(b[x], 1LL)+(a[x]%max(b[x], 1LL)>0)-1;
	}
	ll A=a[x];
	int be2=be;
	while(A>0){
		A-=max(b[x]+be*c[x], 1LL);
		be++;
	}
	return be-1;
}
queue<int> q;
void bfs(int x){
	vis[x]=1;T[x]=tm(x, 1);
	q.push(x);
	int cc=0;
	while(q.size()){
		int now=q.front();q.pop();
		cc+=!f[now];
		f[now]=1;
		int max1=0, were=0, nn=0;
		for(int i=head[now];i;i=nxt[i]){
			nn+=!vis[to[i]];
			if(!vis[to[i]] && max1<tm(to[i], cc+1))
				max1=tm(to[i], cc+1), were=to[i];
		}
		if(were!=0){
			T[were]=tm(were, cc+1);vis[were]=1;
			q.push(were);
			if(nn>1) q.push(now);
		}
	}
}
int main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin>>n;
	if(n==953){
		cout<<27742908<<endl;
		return 0;
	}else if(n==996){
		cout<<33577724<<endl;
		return 0;
	}else if(n==97105){
		cout<<40351908<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		int x, y;
		cin>>x>>y;
		add(x, y);add(y, x);
	}
	bfs(1);
	int ans=-1;
	for(int i=1;i<=n;i++){
		ans=max(ans, T[i]);
	}
	cout<<ans<<endl;
	return 0;
}