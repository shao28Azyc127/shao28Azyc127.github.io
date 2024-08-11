#include<bits/stdc++.h>
using namespace std;
int n,m,k,v,u,s,mmax,mx=-1;
struct node{
	int v,k;
}p,t;
vector<node>mp[10010];
queue<node>q;
int bfs(int c){
	while(!q.empty())q.pop();
	q.push((node){1,c});
	while(!q.empty()){
		p=q.front();
		q.pop();
		for(int i=0;i<mp[p.v].size();i++){
			t=(node){mp[p.v][i].v,p.k+1};
			if(t.k>=mp[p.v][i].k){
				q.push(t);
				if(t.k%k==0 && t.v==n){
					return t.k;
				}
			}
		}
	}
	return -1;
}
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&s);
		mp[u].push_back((node){v,s});
		mmax=max(mmax,s);
	}
	for(int i=0;i<=mmax;i+=k){
		mx=max(mx,bfs(i));
	}
	cout<<mx;
	return 0;
}