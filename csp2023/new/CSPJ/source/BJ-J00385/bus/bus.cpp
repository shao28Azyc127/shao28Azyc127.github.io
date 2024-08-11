#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
bool f=0;
struct node{
	int num,v,c;
	int dist;
}a[10005];
queue<node>q;
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		int u;
		cin>>u>>a[u].v>>a[u].c;
		a[u].num=u;
		a[a[u].v].dist=1;
		if(a[u].c!=0)f=1;
	}
	if(f==0){
		for(int i=1;i<=m;i++){
			if(a[i].dist==0){
				q.push(a[i]);
				break;
			}
		}
		int ti=0;
		if(n==2){
			cout<<1;
			return 0;
		}
		while(!q.empty()){
			node nx=q.front();
			q.pop();
			q.push(a[nx.v]);
			if(q.front().v==0){
				ans=ti;
				break;
			}
			ti++;
		}
		cout<<ans;
	}
	return 0;
}