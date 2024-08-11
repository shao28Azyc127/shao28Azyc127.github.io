#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node{
	int v,nxt;
}bian[20004];
int head[10004];
int bnt;
void add(int u,int v){
	bian[++bnt]={v,head[u]};
	head[u]=bnt;
}
bool zg[10004];
void dfs(int u,int cnt){
	if(cnt==k){
		cout<<k<<endl;
		exit(0);
	}
	for(int i=head[u];i;i=bian[i].nxt){
		int v=bian[i].v;
		if(zg[v]){
			cout<<k<<endl;
			exit(0);
		}
		zg[v]=true;
		dfs(v,cnt+1);
		zg[v]=false;
	}
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int sf=0,u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v);
		if(w!=0)sf=1;
	}
	if(sf==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)zg[j]=false;
			zg[i]=true;
			dfs(i,0);
		}
	}
	cout<<-1<<endl;
	return 0;
}