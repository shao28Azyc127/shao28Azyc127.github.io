#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5;
struct node{
	int u,v,next;
	int a;
}edge[N];
int head[N];
int cnt=0;
void add(int u,int v,int a){
	++cnt;
	edge[cnt].u=u;
	edge[cnt].v=v;
	edge[cnt].a=a;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
bool vis[N];
int n,m,k;
int ans=INT_MAX;
void dfs(int now,int t,int c){
	if(now==n){
		int s=t/k+k*(t%k>0);
		if((s+c)%k==0){
			ans=min(ans,s+c);
		}
	}
	for(int i=head[now];i!=0;i=edge[i].next){
		int v=edge[i].v;
		if(!vis[v]){
			if(c<edge[i].a){
				t=max(t,edge[i].a-c);
			}
			if(t+c+1>ans) continue;
			vis[v]=true;
			dfs(v,t,c+1);
			vis[v]=false;
		}
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,a;
		cin>>u>>v>>a;
		add(u,v,a);
	}
	dfs(1,0,0);
	if(ans==INT_MAX){
		cout<<-1;
	}
	else cout<<ans;
	return 0;
}
