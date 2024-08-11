#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
struct Node{
	int v,nxt;
}bian[100005];
int head[100005];
int bnt;
void add(int u,int v){
	bian[++bnt]={v,head[u]};
	head[u]=bnt;
}
int n,ans=0;
priority_queue<pair<int,int> >p;
void bfs(int u){
	p.push(make_pair(u,1));
	while(p.size()){
		u=p.top().first;
		int x=p.top().second;
		p.pop();
		for(int i=head[u];i;i=bian[i].nxt){
			int v=bian[i].v;
			ans=max(ans,x+(a[v]+b[v]-1)/b[v]);
			p.push(make_pair((a[v]+b[v]-1)/b[v],x+(a[v]+b[v]-1)/b[v]));
		}
	}
	
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int u,v,sf=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(c[i]!=0)sf=1;
	}
	for(int i=1;i<n;i++){
		cin>>u>>v;
		add(u,v);
	}
	if(sf==0){
		bfs(1);
		cout<<ans<<endl;
	}
	return 0;
}