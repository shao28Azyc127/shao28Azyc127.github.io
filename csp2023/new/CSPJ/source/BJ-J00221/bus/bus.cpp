#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define MAXN 10003
#define MAXM 2*MAXN
int head[MAXM],nxt[MAXM],to[MAXM],ti[MAXM],idx=0,n,m,k;
bool visit[MAXN];
void add(int u,int v,int t){
	to[++idx]=v;
	nxt[idx]=head[u];
	head[u]=idx;
	ti[idx]=t;
}
int ans=0x3f3f3f3f;
void dfs(int x,int cur){
	visit[x]=true;
	if(x==n){
		ans=std::min(ans,cur);
		return ;
	}
	for(int i=head[x];i;i=nxt[i])
		if(!visit[to[i]]){
			if(cur>=ti[i]){
				dfs(to[i],cur);
				visit[to[i]]=false;
			}
			dfs(to[i],cur+1);
			visit[to[i]]=false;
		}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,t;
		cin>>u>>v>>t;
		add(u,v,t);
	}
	dfs(1,k);
	if(ans!=0x3f3f3f3f)	cout<<ans+ans%k+k<<endl;
	else	cout<<-1<<endl;
	return 0;
}
