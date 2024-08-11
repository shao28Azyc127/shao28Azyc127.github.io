#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,vis;
	int now,can;
}land[100005];
struct Edge{
	int to,next,w;
}edge[200005];
int head[100005],cnt,vis[100005],dis[100005],ans=1000000000;
inline void add(int u,int v){
	cnt++;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
int n;
bool check(){
	for(int i=1;i<=n;i++){
		if(land[i].a>land[i].c){
			return 0;
		}
	}
	return 1;
}
void work(int day){
	cout<<day<<"day"<<endl;
	for(int i=1;i<=n;i++){
		cout<<i<<":";
		if(land[i].vis){
			land[i].now+=max(land[i].b+day*land[i].c,1);
			cout<<land[i].now;
		}
		else cout<<0;
		cout<<" "<<land[i].can<<" "<<land[i].vis;
		cout<<endl;
	}
}
void dework(int day){
	for(int i=1;i<=n;i++){
		if(land[i].vis){
			land[i].now-=max(land[i].b+day*land[i].c,1);
		}
	}
}
inline void dfs(int day){
	if(day>=ans)return;
	if(check()){
		ans=min(ans,day);
		return;
	}
	for(int i=1;i<=n;i++){
		if(land[i].can&&land[i].vis==0){
			for(int j=head[i];j;j=edge[j].next)land[edge[j].to].can++;
			land[i].vis=1;
			work(day);
			dfs(day+1);
			dework(day);
			land[i].vis=0;
			for(int j=head[i];j;j=edge[j].next)land[edge[j].to].can--;
		}
		dfs(day+1);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>land[i].a>>land[i].b>>land[i].c;
	}
	for(int u,v,i=1;i<=n-1;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	land[1].vis=1;
	for(int i=head[1];i;i=edge[i].next)land[edge[i].to].can=1;
	work(1);
	dfs(2);
	cout<<ans;
	return 0;
}
